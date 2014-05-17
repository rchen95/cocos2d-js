//
//  GameAboutScene.cpp
//  LuoLiRun
//
//  Created by iMac on 2014-05-13.
//
//

#include "GameAboutScene.h"
#include "GameMenuScene.h"

using namespace cocos2d;

Scene* GameAbout::scene()
{
    Scene *scene = Scene::create();
    
    GameAbout *layer = GameAbout::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool GameAbout::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    Size size = Director::getInstance()->getWinSize();
    
    Sprite* bg = Sprite::create("back_1.png");
    //bg->setScale(0.6f);
    bg->setPosition( Point(size.width/2, size.height/2) );
    this->addChild(bg, 0,0);
    Sprite *kuang = Sprite::create("tb.png");
    //kuang->setScale(0.5);
    kuang->setRotation(90);
    kuang->setPosition(Point(size.width/2, size.height/2));
    this->addChild(kuang,2,2);
    
    char inf[256];
    sprintf(inf,"name:loli run\n\n program:shuoquan man\n\n art design:zuyi li\n\n company:hz books\n\n    powered by cocos2D-x");
    // CCLabelTTF *myjineng = CCLabelTTF::create(inf,CCSizeMake(400,400),kCCTextAlignmentLeft, "Marker Felt", 20);
	Label *myjineng=Label::createWithTTF(inf,"Marker Felt",20, Size(400,400),TextHAlignment::LEFT);
    myjineng->setAnchorPoint(Point(0,1));
    myjineng->setColor(Color3B(0,0,0));
    myjineng->setPosition(Point(200,260));
    this->addChild(myjineng);
    //关于标签
    Sprite*abouttitle = Sprite::create("about.png");
    //abouttitle->setScale(0.5);
    abouttitle->setPosition(Point(size.width/2, size.height - 20));
    this->addChild(abouttitle,3,3);
    //返回
    MenuItemImage *back = MenuItemImage::create("backA.png", "backB.png", CC_CALLBACK_1(GameAbout::menuBackCallback, this));
    //back->setScale(0.5);
    back->setPosition(Point(size.width - 20,size.height - 20));
    back->setEnabled(false);
    Menu* mainmenu = Menu::create(back,NULL);
    mainmenu->setPosition(Point(0,0));
    this->addChild(mainmenu,3,4);
    return true;
}

void GameAbout::menuBackCallback(Ref* pSender){
    Director::getInstance()->setDepthTest(true);
    Director::getInstance()->replaceScene(CCTransitionPageTurn::create(0.5,GameMenu::createScene(), true));
}

void GameAbout::onEnterTransitionDidFinish()
{
    Layer::onEnterTransitionDidFinish();
    Director::getInstance()->setDepthTest(false);
}

void GameAbout::onExitTransitionDidStart()
{
    Layer::onExitTransitionDidStart();
}
void GameAbout::onExit(){
    Layer::onExit();
}
void GameAbout::onEnter(){
    Layer::onEnter();
	Node* mainmenu = this->getChildByTag(4);
    Vector<Node*> temp = mainmenu->getChildren();
    ((MenuItemImage *)temp.at(0))->setEnabled(true);
}
