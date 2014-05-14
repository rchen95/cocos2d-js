//
//  GameMenuScene.h
//  LuoLiRun
//
//  Created by iMac on 2014-05-12.
//
//

#ifndef __LuoLiRun__GameMenuScene__
#define __LuoLiRun__GameMenuScene__

#include "cocos2d.h"

using namespace cocos2d;

class GameMenu : public Layer
{
public:
    bool issound;
    
    MenuItemImage *soundItem;
    
    virtual bool init();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    //static Scene* scene();
    static Scene* createScene();
    
    void menuEnter();
    
    void menuNewGameCallback(Ref* pSender);
    
    void menuContinueCallback(Ref* pSender);
    
    void menuAboutCallback(Ref* pSender);
    
    void menuSoundCallback(Ref* pSender);
    
    CREATE_FUNC(GameMenu);
    
    void onEnterTransitionDidFinish();
    
    void onExitTransitionDidStart();
};

#endif /* defined(__LuoLiRun__GameMenuScene__) */
