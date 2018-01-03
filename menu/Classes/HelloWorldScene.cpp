#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include <string.h>

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

    //
    Size size = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();
    Point center = Point(size.width/2, size.height/2);
    
    
   // MenuItemLabel
    Label *labelMenu1 = Label::createWithTTF("zhuzhu", "./fonts/arial.ttf", 50);
    MenuItemLabel *menuLabel = MenuItemLabel::create(labelMenu1);
    menuLabel->setPosition(Point(120,size.height - 50));
    
    MenuItemAtlasFont *menuAtlas = MenuItemAtlasFont::create("20080910", "fonts/digit.png", 20, 20, '0');
    menuAtlas->setPosition(Point(120,size.height-120));
    
    
    //MenuItemFont
    MenuItemFont *menuFont = MenuItemFont::create("menufont");
    menuFont->setTag(1);
    menuFont->setPosition(120, size.height-190);
    
    MenuItemFont *menuFont2 = MenuItemFont::create("chanel", this,menu_selector(HelloWorld::menuItemFont2Func));
    menuFont2->setFontSize(32);
    menuFont2->setPosition(Point(120,size.height-260));
    
    
    //menu
    Menu *menu = Menu::create(menuLabel,menuAtlas,menuFont,menuFont2, NULL);
    menu->setPosition(0, 0);
    this->addChild(menu,0,100);
    
    
    // Sprite
    Sprite *sp1 = Sprite::create("sp1.png");
    Sprite *sp2 = Sprite::create("sp2.png");
    Sprite *sp3 = Sprite::create("sp3.png");
    MenuItemSprite *menuSprite = MenuItemSprite::create(sp1,sp2,sp3);
    menuSprite->setPosition(size.width/2 + 50,size.height/2+50);
    menu->addChild(menuSprite);
    menuSprite->setTag(2);
    
    MenuItemImage *itemImage = MenuItemImage::create("CloseNormal.png", "CloseSelected.png");
    itemImage->setPosition(size.width/2 - 50,size.height/2 - 50);
    menu->addChild(itemImage);
    
    
    //menuitemtoggle
    MenuItemFont *menuItemFont3 = MenuItemFont::create("Toggle_Normal");
    MenuItemFont *menuItemFont4 = MenuItemFont::create("Toggle_Selected");
    MenuItemImage *menuItemImage2 = MenuItemImage::create("sp3.png", "sp1.png");
    MenuItemToggle *menuitemToggle = MenuItemToggle::createWithTarget(this, menu_selector(HelloWorld::menuItemToggleFunc), menuItemFont3,menuItemFont4,NULL);
    menuitemToggle->setPosition(size.width/2+50,size.height/2-50);
    menuitemToggle->addSubItem(menuItemImage2);
    menu->addChild(menuitemToggle);
    


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


void HelloWorld::menuItemFont2Func(Ref* sender) {
    MenuItemFont *itemFont = (MenuItemFont*)sender;
    Menu *menu = (Menu*)this->getChildByTag(100);
    
    MenuItemFont *fontItem1 = (MenuItemFont*) menu->getChildByTag(1);
    Label *label = (Label*) itemFont->getLabel();
    
    if (strcmp((label->getString().c_str()), "chanel") == 0) {
        fontItem1->setString("2222");
        label->setString("chane2");
    } else {
        fontItem1->setString("1111");
        label->setString("chane1");
    }
    

    
}
void HelloWorld::menuItemToggleFunc(Ref* sender) {
    MenuItemToggle *itemToggle = (MenuItemToggle*)sender;
    Menu *menu = (Menu*)this->getChildByTag(100);
    
    MenuItemSprite* menuItemSprite = (MenuItemSprite*)menu->getChildByTag(2);

    switch (itemToggle->getSelectedIndex()) {
        case 0:
            menuItemSprite->setEnabled(true);
            break;
        case 1:
            menuItemSprite->selected();
            break;
        case 2:
            menuItemSprite->setEnabled(false);
            break;
        default:
            break;
    }
}
