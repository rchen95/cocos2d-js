//
//  GameMainScene.h
//  LuoLiRun
//
//  Created by iMac on 2014-05-14.
//
//

#ifndef __LuoLiRun__GameMainScene__
#define __LuoLiRun__GameMainScene__

#include "cocos2d.h"
#include "GameObjHero.h"
#include "GameObjMap.h"
#include "GameMark.h"

using namespace cocos2d;
class GameMain : public cocos2d::Layer
{
public:
    
    GameObjHero* hero;
    
    virtual bool init();
    bool isover;
    virtual void onEnter();
    
    virtual void onExit();
    
    void isherodrop();
    void setover();
    GameObjMap * map;
    GameMark *gamemark;
    Sprite *gameover;
    static cocos2d::Scene* scene();
    
    void menuBackCallback(Ref* pSender);
    
    CREATE_FUNC(GameMain);
    
    void update(float time);
    
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
    
    bool isCollion(Point p1, Point p2,int w1,int h1,int w2,int h2);
};

#endif /* defined(__LuoLiRun__GameMainScene__) */
