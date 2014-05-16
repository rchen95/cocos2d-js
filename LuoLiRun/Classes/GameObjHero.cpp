//
//  GameObjHero.cpp
//  LuoLiRun
//
//  Created by iMac on 2014-05-13.
//
//

#include "GameObjHero.h"
#include "GameMainScene.h"
GameObjHero::GameObjHero(void)
{
}

GameObjHero::~GameObjHero(void)
{
}

Rect GameObjHero::rect()
{
    Size s = Size(100,125);
    return Rect(-s.width / 2, -s.height / 2, s.width, s.height);
}

/*
void GameObjHero::touchDelegateRetain()
{
    this->retain();
}

void GameObjHero::touchDelegateRelease()
{
    this->release();
}*/
void GameObjHero::onEnter()
{
    Node::onEnter();
    this->setContentSize(Size(85,90));
    Director* pDirector = Director::getInstance();
    
    //pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    // Register Touch Event
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(GameObjHero::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameObjHero::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameObjHero::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    
    Sprite * obj = Sprite::create("s_hurt.png");
    hurt = obj->getTexture();
    obj = CCSprite::create("s_jump.png");
    jump = obj->getTexture();
    mainsprite = Sprite::create("s_1.png");
    //动画
    Animation * animation = Animation::create();
    animation->addSpriteFrameWithFile("s_1.png");
    animation->addSpriteFrameWithFile("s_2.png");
    animation->addSpriteFrameWithFile("s_3.png");
    animation->addSpriteFrameWithFile("s_4.png");
    animation->addSpriteFrameWithFile("s_5.png");
    animation->addSpriteFrameWithFile("s_6.png");
    animation->setDelayPerUnit(0.1f);
    animation->setRestoreOriginalFrame(true);
    //运行奔跑动画
    mainsprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
    state = 0;
    addChild(mainsprite);
}

void GameObjHero::setState(short var){
    if(state == var)
        return;
    state = var;
    switch(state){
        case 1://跳跃
            this->stopAllActions();
            mainsprite->stopAllActions();
            mainsprite->setTexture(jump);
            this->runAction(CCSequence::create(CCJumpBy::create(2.5,Point(0,0),100,1),CCCallFunc::create(this, callfunc_selector(GameObjHero::jumpend)),NULL));
            break;
        case 2://受伤
            this->stopAllActions();
            mainsprite->stopAllActions();
            mainsprite->setTexture(hurt);
            this->runAction(CCSequence::create(CCBlink::create(3, 10),CCCallFunc::create(this, callfunc_selector(GameObjHero::hurtend)),NULL));
            ((GameMain *)this->getParent())->setover();
            break;
        case 0://奔跑动画
            this->stopAllActions();
            mainsprite->stopAllActions();
            CCAnimation * animation = CCAnimation::create();
            animation->addSpriteFrameWithFile("s_1.png");
            animation->addSpriteFrameWithFile("s_2.png");
            animation->addSpriteFrameWithFile("s_3.png");
            animation->addSpriteFrameWithFile("s_4.png");
            animation->addSpriteFrameWithFile("s_5.png");
            animation->addSpriteFrameWithFile("s_6.png");
            animation->setDelayPerUnit(0.1f);
            animation->setRestoreOriginalFrame(true);
            mainsprite->runAction(CCRepeatForever::create(CCAnimate::create(animation)));
            break;
    }
}
void GameObjHero::jumpend(){
    setState(0);
}

void GameObjHero::hurtend(){
    setState(0);
}

void GameObjHero::onExit()
{
    Director* pDirector = Director::getInstance();
    //pDirector->getTouchDispatcher()->removeDelegate(this);
    Node::onExit();
}

bool GameObjHero::containsTouchLocation(Touch* touch)
{
    //return CCRect::CCRectContainsPoint(rect(), convertTouchToNodeSpaceAR(touch));
	return rect().containsPoint(convertTouchToNodeSpaceAR(touch));
}

bool GameObjHero::onTouchBegan(Touch* touch, Event* event)
{
    if(((GameMain *)this->getParent())->isover)
        return false;
    //设置运动状态
    setState(1);
    return true;
}

void GameObjHero::onTouchMoved(Touch* touch, Event* event)
{
}

void GameObjHero::onTouchEnded(Touch* touch, Event* event)
{
}
