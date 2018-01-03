#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    //ªÒ»°ø… ”«¯”Ú≥ﬂ¥Á¥Û–°
    CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();
    //ªÒ»°ø… ”«¯”Úµƒ‘≠µ„Œª÷√
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    //∆¡ƒª’˝÷––ƒŒª÷√
    CCPoint midPos = ccp(mysize.width/2, mysize.height/2);
    
    
    //œ‘ æµ⁄“ª◊Èø™πÿµƒ◊¥Ã¨
    label = Label::createWithTTF("on", "./Fonts/arial.ttf", 32);
    label->setPosition( midPos - ccp(100, 0) );
    this->addChild(label);
    
    Sprite* bg1 = Sprite::create("ControlSwith_bg.png");
    Sprite* on1 = Sprite::create("ControlSwith_on.png");
    Sprite* off1 = Sprite::create("ControlSwith_off.png");
    Sprite* thumb1 = Sprite::create("ControlSwith_thumb.png");
    ControlSwitch *controlSwitch = ControlSwitch::create(bg1,on1,off1,thumb1);
    controlSwitch->setPosition(50, 50);
//    controlSwitch->setContentSize(Size(40, 20));
    controlSwitch->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::valueChanged), cocos2d::extension::Control::EventType::VALUE_CHANGED);
    this->addChild(controlSwitch);

    
    
    CCSprite* bg2 = CCSprite::create("switch-mask.png");
    CCSprite* on2 = CCSprite::create("switch-off.png");
    CCSprite* off2 = CCSprite::create("switch-on.png");
    CCSprite* thumb2 = CCSprite::create("switch-thumb.png");
    Label *labelOn = Label::createWithTTF("on", "./fonts/arial.ttf", 12);
    Label *labelOff = Label::createWithTTF("off", "./fonts/arial.ttf", 12);
    
    ControlSwitch *controlSwitch2 = ControlSwitch::create(bg2,on2,off2,thumb2,labelOn,labelOff);
    controlSwitch2->setPosition(50 ,100);
//    controlSwitch2->setContentSize(Size(40, 20));

    this->addChild(controlSwitch2);

    
    //ControlSlider
    Sprite *sp_b = Sprite::create("ControlSwith_bg.png");
    Sprite *sp_p = Sprite::create("ControlSwith_on.png");
    Sprite *sp_t = Sprite::create("ControlSwith_thumb.png");

    ControlSlider *controlSlier =ControlSlider::create(sp_b, sp_p, sp_t);
    controlSlier->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::sliderValueChanged), Control::EventType::VALUE_CHANGED);
    this->addChild(controlSlier);
    controlSlier->setPosition(50 ,200);
    controlSlier->setMinimumValue(0);
    controlSlier->setMaximumValue(100);
    controlSlier->setMinimumAllowedValue(20);
    controlSlier->setMaximumAllowedValue(90);
    
    
    Scale9Sprite *scaleSprite = Scale9Sprite::create("Icon.png", Rect(0, 0, 100, 30), Rect(0, 0, 100, 300));
    Label *label = Label::createWithTTF("zhuzhu click it", "./fonts/arial.ttf", 32);
    ControlButton *button1 = ControlButton::create(label, scaleSprite);
    button1->setPosition(300,100);
    button1->setTitleForState("hightl", Control::State::HIGH_LIGHTED);
//    button1->setContentSize(Size(100,30));
    this->addChild(button1);
    return true;
}


void HelloWorld::valueChanged(Ref*sender, Control::EventType type) {
    ControlSwitch *controlSwitch = (ControlSwitch*)sender;
    if (controlSwitch->isOn()) {
        label->setString("on");
    } else {
        label->setString("off");
    }
}

void HelloWorld::sliderValueChanged(Ref*sender, Control::EventType type) {
    ControlSlider *slider = (ControlSlider *)sender;
    char str[50];
    sprintf(str, "%f",slider->getValue());
    label->setString(str);
}
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
