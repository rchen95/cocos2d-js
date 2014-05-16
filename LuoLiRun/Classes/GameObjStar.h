//
//  GameObjStar.h
//  LuoLiRun
//
//  Created by iMac on 2014-05-13.
//
//

#ifndef __LuoLiRun__GameObjStar__
#define __LuoLiRun__GameObjStar__

#include "cocos2d.h"
using namespace cocos2d;

class GameObjStar : public Node
{
public:
    GameObjStar(void);
    virtual ~GameObjStar(void);
    
    virtual void onEnter();
    virtual void onExit();
    
    short state;
    
    bool _visable;
    void set_visable(bool var);
    bool get_visable();
};

#endif /* defined(__LuoLiRun__GameObjStar__) */
