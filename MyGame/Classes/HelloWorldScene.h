#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class HelloWorld : public Layer
{
protected:
    Layer* _uiLayer;
    cocos2d::ui::Layout* _widget;
    
    bool m_isRunning;
    
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    
    void clearRunning();
    void changeRunning();
    void runningSchedule(float dt);
    void touchButton(Ref *pSender, cocos2d::ui::TouchEventType eventType);
    void movementCallback(cocostudio::Armature * armature, cocostudio::MovementEventType type, const char * name);
    void onTouchesEnded(const std::vector<Touch*>&  touches, Event* event);

    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
