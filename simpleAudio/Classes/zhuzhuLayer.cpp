//
//  zhuzhuLayer.cpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#include "zhuzhuLayer.hpp"


//音效文件
//Android平台只支持OGG的音效格式
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#define EFFECT_FILE        "effect2.ogg"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
#define EFFECT_FILE        "effect1.raw"
#else
#define EFFECT_FILE        "effect1.wav"
#endif

//音乐文件
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE        "music.mid"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX )
#define MUSIC_FILE        "background.ogg"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
#define MUSIC_FILE        "background.wav"
#else
#define MUSIC_FILE        "background.mp3"
#endif



bool zhuzhuLayer::init() {

    Size size = Director::getInstance()->getVisibleSize();

    //加载背景音乐
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(MUSIC_FILE);
    //加载音效
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(EFFECT_FILE);
    
    
    //创建控制音乐音效的菜单按钮
    std::string testItems[] = {
        "play background music",
        "stop background music",
        "pause background music",
        "resume background music",
        "rewind background music",
        "is background music playing",
        
        "play effect",
        "play effect repeatly",
        "stop effect",
        "pause effect",
        "resume effect",
        "pause all effects",
        "resume all effects",
        "stop all effects",
        "unload effect",
        
        "add background music volume",
        "sub background music volume",
        "add effects volume",
        "sub effects volume"
    };
    
    Menu *menu = Menu::create();
    menu->setContentSize(Size(480, 1000));
    
    for (int i = 0; i < 19; i++) {
        Label *label = Label::createWithTTF(testItems[i].c_str(), "fonts/arial.ttf", 32);
        MenuItemLabel *menuLabel = MenuItemLabel::create(label, this, menu_selector(zhuzhuLayer::menuCallBack));
        menuLabel->setPosition(size.width/2, 1000 - (i + 1) * 50);
        menu->addChild(menuLabel,0,i);
    }
    
    
    ScrollView *scrollview = ScrollView::create(Size(480, 320),menu);
    scrollview->setDirection(ScrollView::Direction::VERTICAL);
    scrollview->setPosition(0, 0);
    menu->setPosition(Vec2(0, 320 - 1000));
    this->addChild(scrollview);
    
    
    
    
    return true;
}

void zhuzhuLayer::menuCallBack(Ref *sender) {
    int index = ((MenuItem *) sender)->getTag();
    int  m_soundID = 0;
    switch (index) {
        case 0:
            SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE);
            break;
        case 1:
            SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
            break;
        case 2:
            SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
            break;
        case 3:
            SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
            break;
        case 4:
            SimpleAudioEngine::sharedEngine()->rewindBackgroundMusic();
            break;
        case 5:
            if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying()) {
                CCLOG("background music is playing");
            } else {
                CCLOG("background music is not playing");
            }
            break;
            
            
            
            //音效控制
        case 6: m_soundID = SimpleAudioEngine::sharedEngine()->playEffect(EFFECT_FILE);        break; //播放音效，不循环
        case 7: m_soundID = SimpleAudioEngine::sharedEngine()->playEffect(EFFECT_FILE, true);  break; //播放音效，循环
        case 8: SimpleAudioEngine::sharedEngine()->stopEffect(m_soundID);                      break; //停止指定ID的音效
        case 9: SimpleAudioEngine::sharedEngine()->pauseEffect(m_soundID);                     break; //暂停指定ID的音效
        case 10: SimpleAudioEngine::sharedEngine()->resumeEffect(m_soundID);                   break; //恢复指定ID的音效
        case 11: SimpleAudioEngine::sharedEngine()->pauseAllEffects();                         break; //暂停所有音效
        case 12: SimpleAudioEngine::sharedEngine()->resumeAllEffects();                        break; //恢复所有音效
        case 13: SimpleAudioEngine::sharedEngine()->stopAllEffects();                          break; //停止所有音效
        case 14: SimpleAudioEngine::sharedEngine()->unloadEffect(EFFECT_FILE);                 break; //卸载音效
            
            //音量控制
        case 15:
            SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume() + 0.1f);
            break;
        case 16:
            SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume() - 0.1f);
            break;
        case 17:
            SimpleAudioEngine::sharedEngine()->setEffectsVolume(SimpleAudioEngine::sharedEngine()->getEffectsVolume() + 0.1f);
            break;
        case 18:
            SimpleAudioEngine::sharedEngine()->setEffectsVolume(SimpleAudioEngine::sharedEngine()->getEffectsVolume() - 0.1f);
            break;
        default:
            break;
    }
}


