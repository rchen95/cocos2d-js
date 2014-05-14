//
//  GameAboutScene.h
//  LuoLiRun
//
//  Created by iMac on 2014-05-13.
//
//

#ifndef __LuoLiRun__GameAboutScene__
#define __LuoLiRun__GameAboutScene__

#include "cocos2d.h"
using namespace cocos2d;
class GameAbout : public Layer
{
public:
    
    virtual bool init();
    
    virtual void onEnter();
    
    virtual void onExit();
    
    static Scene* scene();
    
    void menuBackCallback(Ref* pSender);
    
    CREATE_FUNC(GameAbout);
    
    void onEnterTransitionDidFinish();
    void onExitTransitionDidStart();
};


#endif /* defined(__LuoLiRun__GameAboutScene__) */
