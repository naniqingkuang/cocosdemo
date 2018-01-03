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

    Sprite *sp1 = Sprite::create("HelloWorld.png");
    sp1->setPosition(30,320-30);
    sp1->setContentSize(Size(20,20));
    this->addChild(sp1,0,101);
    
    
    Sprite *sp2 = Sprite::create("HelloWorld.png");
    sp2->setPosition(30,320-100);
    sp2->setContentSize(Size(20,20));

    this->addChild(sp2,0,102);
    
    Sprite *sp3 = Sprite::create("HelloWorld.png");
    sp3->setPosition(30,320-170);
    sp3->setContentSize(Size(20,20));

    this->addChild(sp3,0,103);
    
    Sprite *sp4 = Sprite::create("HelloWorld.png");
    sp4->setPosition(30,320-240);
    sp4->setContentSize(Size(20,20));

    this->addChild(sp4,0,104);
    
    Sprite *sp5 = Sprite::create("HelloWorld.png");
    sp5->setPosition(30,320-310);
    sp5->setContentSize(Size(20,20));

    this->addChild(sp5,0,105);
    
    this->scheduleUpdate();
    this->schedule(schedule_selector(HelloWorld::myupdate));
    this->schedule(schedule_selector(HelloWorld::myupdate2), 1);
    this->schedule(schedule_selector(HelloWorld::myupdate3), 2, 40, 1);
    
    return true;
}

//scheduleUpdate
void HelloWorld::update(float dt)
{
    Sprite* sp = (Sprite*)this->getChildByTag(101); //获取 tag=100 的精灵
    sp->setPosition( sp->getPosition() + ccp(1,0) );    //每帧移动1
}

//schedule(schedule_selector)
void HelloWorld::myupdate(float dt)
{
    Sprite* sp1 = (Sprite*)this->getChildByTag(102); //获取 tag=101 的精灵
    sp1->setPosition( sp1->getPosition() + ccp(1,0) );   //每帧移动1
}

//schedule(schedule_selector, interval)
void HelloWorld::myupdate2(float dt)
{
    Sprite* sp2 = (Sprite*)this->getChildByTag(103); //获取 tag=102 的精灵
    sp2->setPosition( sp2->getPosition() + ccp(60,0) );  //每秒移动60
}

//schedule(schedule_selector, interval, repeat, delay)
void HelloWorld::myupdate3(float dt)
{
    Sprite* sp3 = (Sprite*)this->getChildByTag(104); //获取 tag=103 的精灵
    sp3->setPosition( sp3->getPosition() + ccp(60,0) );  //每秒移动60
}

//scheduleOnce
void HelloWorld::myupdate4(float dt)
{
    Sprite* sp4 = (CCSprite*)this->getChildByTag(105); //获取 tag=104 的精灵
    sp4->setPosition( sp4->getPosition() + ccp(100,0) ); //移动100
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
