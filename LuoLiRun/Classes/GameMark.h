//
//  GameMark.h
//  LuoLiRun
//
//  Created by iMac on 2014-05-13.
//
//

#ifndef __LuoLiRun__GameMark__
#define __LuoLiRun__GameMark__

#include "cocos2d.h"
using namespace cocos2d;

class GameMark : public Node
{
public:
    GameMark(void);
    virtual ~GameMark(void);
    
    virtual void onEnter();
    virtual void onExit();
    
    //CCArray *bits;
    Vector<Node *> bits;
    int mark;
    void addnumber(int var);
    Texture2D* ui;
};


#endif /* defined(__LuoLiRun__GameMark__) */
