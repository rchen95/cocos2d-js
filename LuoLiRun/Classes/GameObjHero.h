//
//  GameObjHero.h
//  LuoLiRun
//
//  Created by iMac on 2014-05-13.
//
//

#ifndef __LuoLiRun__GameObjHero__
#define __LuoLiRun__GameObjHero__

#include "cocos2d.h"
using namespace cocos2d;

// 在Cocos2d-x 3.0 beat 中 无法发现CCTargetedTouchDelegate问题
// http://blog.csdn.net/lingtianyulong/article/details/25697719
class GameObjHero : public Node  //, public CCTargetedTouchDelegate
{
public:
    GameObjHero(void);
    virtual ~GameObjHero(void);
    
    Sprite *mainsprite;
    Texture2D *hurt;
    Texture2D *jump;
    Point offset;
    short state;//0:正常 1：跳跃 2：受伤
    bool iscontrol;
    
    
    
    void setState(short var);
    Rect rect();
    virtual void onEnter();
    virtual void onExit();
    void jumpend();
    void hurtend();
    bool containsTouchLocation(Touch* touch);
    virtual bool onTouchBegan(Touch* touch, Event* event);
    virtual void onTouchMoved(Touch* touch, Event* event);
    virtual void onTouchEnded(Touch* touch, Event* event);
    
    //virtual void touchDelegateRetain();
    //virtual void touchDelegateRelease();
    
};

#endif /* defined(__LuoLiRun__GameObjHero__) */
