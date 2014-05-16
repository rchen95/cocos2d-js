//
//  GameObjMap.h
//  LuoLiRun
//
//  Created by iMac on 2014-05-14.
//
//

#ifndef __LuoLiRun__GameObjMap__
#define __LuoLiRun__GameObjMap__

#include "cocos2d.h"
#include "GameObjStar.h"

using namespace cocos2d;

class GameObjMap : public Node
{
public:
    GameObjMap(void);
    virtual ~GameObjMap(void);
    
    short state;
    
    virtual void onEnter();
    virtual void onExit();
    
    void bg1change();
    void bg2change();
    
    Vector<GameObjStar *> stars1;
    Vector<GameObjStar *> stars2;
};


#endif /* defined(__LuoLiRun__GameObjMap__) */
