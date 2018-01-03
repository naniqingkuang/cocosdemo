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
    Size size = Director::getInstance()->getVisibleSize();
    Point centerPint = Point(size.width/2,size.height/2);
    
    
    //  TTFLabel
    // 左上角
    Label *label = Label::createWithTTF("luomingzhuiluomingzhuluomingzhu", "./fonts/arial.ttf", 50,Size(480, 320),TextHAlignment::LEFT,TextVAlignment::TOP);
    label->setPosition(centerPint);
    label->setColor(Color3B::WHITE);
    
    label->setLineHeight(50);       // 行间距
    label->setAdditionalKerning(20);   //字间距
    label->enableOutline(Color4B::RED, 3);             //轮廓
    
    // 获取第几个sprite
    Sprite *sprite1 = label->getLetter(3);
    sprite1->runAction(RepeatForever::create(RotateBy::create(1.0f, 30)));
    sprite1->setColor(Color3B::GREEN);
    
    
    this->addChild(label);



    // label 2 ttflabel 左下角
    Label *ttfLabel = Label::createWithTTF("zhuzhuzhu", "./fonts/arial.ttf", 50,Size(480, 320),TextHAlignment::LEFT,TextVAlignment::BOTTOM);
    ttfLabel->setColor(Color3B::YELLOW);
    ttfLabel->setPosition(centerPint);
    ttfLabel->setColor(Color3B::WHITE);
    // 阴影
//    ttfLabel->enableShadow(Color4B::WHITE, Size(10, 10));
    //发光
    ttfLabel->enableGlow(Color4B::GREEN);
    this->addChild(ttfLabel);
    
    
    //createWithCharMap   --- png
    Label *labelMap = Label::createWithCharMap("./fonts/digit.png", 20, 20, '0');
    labelMap->setString("123");
    labelMap->setPosition(centerPint);
    this->addChild(labelMap);

    //createWithCharMap   --- texture
    Texture2D *texture2d = TextureCache::getInstance()->addImage("./fonts/digit.png");
    Label *labelMapText = Label::createWithCharMap(texture2d, 20, 20, '0');
    labelMapText->setString("8932");
    this->addChild(labelMapText);
    labelMapText->setPosition(Point(230,230));
//    labelMapText->setColor(Color3B::RED);
    
    
    
    // [createWithBMFont ]
    Label *labelBM = Label::createWithBMFont("./fonts/bitmapFontTest.fnt", "BMFont");
    this->addChild(labelBM);
    labelBM->setString("BMFont");
    labelBM->setPosition(200, 200);
    //为啥没用了？原来使用了getLetterby()
//    Sprite *spriteFont1 = (Sprite*)labelBM->getChildByTag(2);
//    spriteFont1->setScale(2);
//    spriteFont1->setColor(Color3B::RED);
    

    
    return true;
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
