//
//  GameMenuScene.cpp
//  LuoLiRun
//
//  Created by iMac on 2014-05-12.
//
//

#include "GameMenuScene.h"
#include "GameAboutScene.h"
#include "GameMainScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* GameMenu::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto gameLayer = GameMenu::create();
    
    // add layer as a child to scene
    scene->addChild(gameLayer);
    
    // return the scene
    return scene;
}

bool GameMenu::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size size = Director::getInstance()->getWinSize();
    
    //菜单背景
    Sprite* bg = Sprite::create("MainMenu.png");
    //bg->setScale(0.5);
    bg->setPosition(Point(size.width/2, size.height/2) );
    this->addChild(bg, 0,0);
    
    //按钮
    auto *newGameItem = MenuItemImage::create("newgameA.png", "newgameB.png", CC_CALLBACK_1(GameMenu::menuNewGameCallback, this));
    //newGameItem->setScale(0.5);
    newGameItem->setPosition(Point(size.width / 2 + 40,size.height / 2 + 20));
    newGameItem->setEnabled(false);
    auto *continueItem = MenuItemImage::create("continueA.png", "continueB.png",CC_CALLBACK_1(GameMenu::menuContinueCallback, this));
    //continueItem->setScale(0.5);
    continueItem->setPosition(Point(size.width / 2 + 40,size.height / 2 - 50));
    continueItem->setEnabled(false);
    auto *aboutItem = MenuItemImage::create("aboutA.png", "aboutB.png", CC_CALLBACK_1(GameMenu::menuAboutCallback, this));
    //aboutItem->setScale(0.5);
    aboutItem->setPosition(Point(size.width / 2 + 40,size.height / 2 - 120));
    aboutItem->setEnabled(false);
    soundItem = MenuItemImage::create("sound-on-A.png", "sound-on-B.png", CC_CALLBACK_1(GameMenu::menuSoundCallback, this));
    //soundItem->setScale(0.5);
    soundItem->setEnabled(false);
    soundItem->setPosition(Point(40,40));
    auto mainmenu = Menu::create(newGameItem,continueItem,aboutItem,soundItem,NULL);
    mainmenu->setPosition(Point(0,0));
    this->addChild(mainmenu,1,3);
    
    issound = true;
    //初始化声音
    //SimpleAudioEngine::getInstance()->preloadBackgroundMusic( CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("background.mp3") );
    SimpleAudioEngine::getInstance()->preloadBackgroundMusic("background.mp3");
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
    //SimpleAudioEngine::getInstance()->playBackgroundMusic(std::string(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath("background.mp3")).c_str(), true);
    SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3");
    
    return true;
}


void GameMenu::onEnter(){
    Layer::onEnter();
    //入场动作
    Size size = CCDirector::getInstance()->getWinSize();
    Node* mainmenu = this->getChildByTag(3);
    mainmenu->setScale(0);
    mainmenu->runAction(Sequence::create(ScaleTo::create(0.5,1),CallFunc::create(CC_CALLBACK_0(GameMenu::menuEnter, this)),NULL));
}

void GameMenu::menuEnter(){
    Node* mainmenu = this->getChildByTag(3);
    //CCArray* temp = mainmenu->getChildren();
    Vector<Node*> temp = mainmenu->getChildren();
    
    for(int i = 0;i < (int)(temp.size());i ++)
    {
        
       //MenuItemImage *item = (MenuItemImage *)temp[i];
        MenuItemImage *item = (MenuItemImage *)temp.at(i);
      item->setEnabled(true);
    }

}

void GameMenu::onExit(){
    Layer::onExit();
}

void GameMenu::menuNewGameCallback(Ref* pSender)
{
    Director::getInstance()->setDepthTest(true);
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5,GameMain::scene(), false));
}

void GameMenu::menuContinueCallback(Ref* pSender)
{
    Director::getInstance()->setDepthTest(true);
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5,GameMain::scene(), false));
}

void GameMenu::menuAboutCallback(Ref* pSender)
{
    // setDepthTest：设置深度测试——可以用于自动处理遮挡关系
    Director::getInstance()->setDepthTest(true);
    Director::getInstance()->replaceScene(TransitionPageTurn::create(0.5,GameAbout::scene(), false));
}

void GameMenu::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    Director::getInstance()->setDepthTest(false);      ////////////////////
}

void GameMenu::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
}

void GameMenu::menuSoundCallback(Ref* pSender)
{
    //设置声音
    if(! issound){
        soundItem->setNormalImage(Sprite::create("sound-on-A.png"));
        soundItem->setDisabledImage(Sprite::create("sound-on-B.png"));
        //SimpleAudioEngine::getInstance()->playBackgroundMusic(std::string(CCFileUtils::getInstance()->fullPathFromRelativeFile("background.mp3")).c_str(), true);
        SimpleAudioEngine::getInstance()->playBackgroundMusic("background.mp3");
        issound = true;
    }else{
        soundItem->setNormalImage(Sprite::create("sound-off-A.png"));
        soundItem->setDisabledImage(Sprite::create("sound-off-B.png"));
        SimpleAudioEngine::getInstance()->stopBackgroundMusic();
        issound = false;
    }
}

