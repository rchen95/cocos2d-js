#include "HelloWorldScene.h"
#include "cocostudio/CCSGUIReader.h"

const int UI_BUTTON_CLEAR = 10;
const int UI_BUTTON_START = 4;
const int UI_SLIDER_SPEED = 9;
const int UI_LOADINGBAR_LOADING = 8;
const int UI_LABELATLAS_LIFENUM = 6;


//USING_NS_CC;
//using namespace cocos2d::ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    /*
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
     */
    //Layout* layout = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("cocosui/CustomImageViewTest/NewProject_2_1.ExportJson"));
    
   // auto myLayout = cocostudio::GUIReader::shareReader()->widgetFromJsonFile("TestUI_1.json"); //alpha1中使用
    //uiLayer->addWidget(myLayout);
    //this->addChild(uiLayer);
    
    _uiLayer = Layer::create();
    addChild(_uiLayer);
    
    _widget = dynamic_cast<cocos2d::ui::Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("TestUI_1.json"));
    _uiLayer->addChild(_widget);
    
    Button* startBtn = dynamic_cast<Button*>(_widget->getChildByTag(UI_BUTTON_START));
    startBtn->addTouchEventListener(this,toucheventselector(HelloWorld::touchButton));
    
    Button* pauseBtn = dynamic_cast<Button*>(_widget->getChildByTag(UI_BUTTON_CLEAR));
    pauseBtn->addTouchEventListener(this,toucheventselector(HelloWorld::touchButton));
    
    return true;
}

//实现
void HelloWorld::touchButton(Ref *pSender,TouchEventType eventType)
{
    auto button = dynamic_cast<Button*>(pSender);
    int tag = button->getTag();
    switch(eventType)
    {
        case TouchEventType::TOUCH_EVENT_ENDED:
            if(tag == UI_BUTTON_START)
            {
                changeRunning();
            }
            else
            {
                clearRunning();
            }  
    }  
}

void HelloWorld::runningSchedule(float dt)
{
    int speed = dynamic_cast<Slider*>(_widget->getChildByTag(UI_SLIDER_SPEED))->getPercent();
    auto loadingBar = dynamic_cast<LoadingBar*>(_widget->getChildByTag(UI_LOADINGBAR_LOADING));
    int prc = loadingBar->getPercent() + speed / 15;
    if(prc > 100)
    {
        prc = 1;
    }
    loadingBar->setPercent(prc);
    
    
    auto numLabel = dynamic_cast<TextAtlas*>(_widget->getChildByTag(UI_LABELATLAS_LIFENUM));
    std::string str = numLabel->getStringValue();
    
    //numLabel-
    int num = std::atoi(str.c_str());
    num++;
    char buff[100];
    sprintf(buff,"%d",num);
    numLabel->setStringValue(buff);
    
    
}


void HelloWorld::clearRunning()
{
    if(m_isRunning)
    {
        changeRunning();
    }
    
    dynamic_cast<TextAtlas*>(_widget->getChildByTag(UI_LABELATLAS_LIFENUM))->setStringValue("1");
    dynamic_cast<LoadingBar*>(_widget->getChildByTag(UI_LOADINGBAR_LOADING))->setPercent(1);
    dynamic_cast<Slider*>(_widget->getChildByTag(UI_SLIDER_SPEED))->setPercent(1);
}

void HelloWorld::changeRunning()
{
    if(m_isRunning)
    {
        //pause
        this->unschedule(schedule_selector(HelloWorld::runningSchedule));
        m_isRunning = false;
        Button* button = dynamic_cast<Button*>(_widget->getChildByTag(UI_BUTTON_START));
        button->setTitleText("运行");
    }
    else
    {
        //start
        this->schedule(schedule_selector(HelloWorld::runningSchedule));
        m_isRunning = true;
        Button* button = dynamic_cast<Button*>(_widget->getChildByTag(UI_BUTTON_START));
        button->setTitleText("暂停");
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
