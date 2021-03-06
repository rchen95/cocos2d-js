#include "HelloWorldScene.h"
#include "cocostudio/CCSGUIReader.h"

const int UI_BUTTON_CLEAR = 10;
const int UI_BUTTON_START = 4;
const int UI_SLIDER_SPEED = 9;
const int UI_LOADINGBAR_LOADING = 8;
const int UI_LABELATLAS_LIFENUM = 6;


const int UI_BUTTON_PLAY1 = 4;
const int UI_BUTTON_PLAY2 = 5;
const int UI_BUTTON_CONN = 6;
const int UI_BUTTON_CANCEL = 7;

const int AM_MYANIMATION=30;

int displayIndex;


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
    
    /*
    _widget = dynamic_cast<cocos2d::ui::Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("MyUI_1/MyUI_1.json"));
    _uiLayer->addChild(_widget);
    
    Button* play1Btn = dynamic_cast<Button*>(_widget->getChildByTag(UI_BUTTON_PLAY1));
    play1Btn->addTouchEventListener(this,toucheventselector(HelloWorld::touchButton));
    
    Button* play2Btn = dynamic_cast<Button*>(_widget->getChildByTag(UI_BUTTON_PLAY2));
    play2Btn->addTouchEventListener(this,toucheventselector(HelloWorld::touchButton));
    
    Button* connBtn = dynamic_cast<Button*>(_widget->getChildByTag(UI_BUTTON_CONN));
    connBtn->addTouchEventListener(this,toucheventselector(HelloWorld::touchButton));
    
    Button* cancelBtn = dynamic_cast<Button*>(_widget->getChildByTag(UI_BUTTON_CANCEL));
    cancelBtn->addTouchEventListener(this,toucheventselector(HelloWorld::touchButton));
    */
    
    
    cocostudio::ArmatureDataManager::getInstance()->addArmatureFileInfo("Animation2/Animation2.ExportJson");
    cocostudio::Armature* armature = cocostudio::Armature::create("Animation2");
    armature->setTag(AM_MYANIMATION);
    
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    
    armature->setPosition(Point(origin.x + visibleSize.width/2 ,
                                origin.y + visibleSize.height/2));
    this->addChild(armature);
    
    armature->getAnimation()->play("a2");
    
    
    auto listener = EventListenerTouchAllAtOnce::create();
    listener->onTouchesEnded = CC_CALLBACK_2(HelloWorld::onTouchesEnded, this);
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    //setTouchEnabled(true);
    
    return true;
}

void HelloWorld::onTouchesEnded(const std::vector<Touch*>&  touches, Event* event)
{
    ++displayIndex;
    displayIndex = (displayIndex) % 4;
    ((cocostudio::Armature*)getChildByTag(AM_MYANIMATION))->getBone("bone3")->changeDisplayByIndex(displayIndex, true);
}


//实现
void HelloWorld::touchButton(Ref *pSender,TouchEventType eventType)
{
    auto button = dynamic_cast<Button*>(pSender);
    
    /*int tag = button->getTag();
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
    }*/
    
    int tag = button->getTag();
    auto armature = (cocostudio::Armature*)getChildByTag(AM_MYANIMATION);
    switch (eventType)
    {
        case TouchEventType::TOUCH_EVENT_ENDED:
            if(tag == UI_BUTTON_PLAY1)
            {
                armature->getAnimation()->play("hit");
            }
            else if(tag ==UI_BUTTON_PLAY2)
            {
                armature->getAnimation()->play("hit2");
            }
            else if(tag == UI_BUTTON_CONN)
            {
                //will conn
                armature->getAnimation()->setMovementEventCallFunc(this,movementEvent_selector(HelloWorld::movementCallback));
            }
            else if(tag == UI_BUTTON_CANCEL)
            {
                //will dis conn
                armature->getAnimation()->setMovementEventCallFunc(this,nullptr);
            }
            break;
        default:
            break;
    }
}
                                                                   
void HelloWorld::movementCallback(cocostudio::Armature * armature, cocostudio::MovementEventType type, const char * name)
{
    if (type == cocostudio::LOOP_COMPLETE)
    {
        if (strcmp(name,"\x06hit") == 0)
        {
            cocostudio::Armature* arm = (cocostudio::Armature*) getChildByTag(AM_MYANIMATION);
            arm->getAnimation()->play("hit2");
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
