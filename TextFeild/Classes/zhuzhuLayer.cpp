//
//  zhuzhuLayer.cpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#include "zhuzhuLayer.hpp"




bool zhuzhuLayer::init() {
    
    TextFieldTTF *textFeild2 = TextFieldTTF::textFieldWithPlaceHolder("luoxiang", "./fonts/arial.ttf", 32);
    textFeild2->setPosition(100,200);
    textFeild2->setContentSize(Size(100,20));
    textFeild2->setDelegate(this);
    textFeild2->setTag(2);
    this->addChild(textFeild2);
    return true;
}


//bool zhuzhuLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
//    return true;
//}

bool zhuzhuLayer::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    return true;
}

void zhuzhuLayer::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) {
    Point point = touch->getLocation();
    TextFieldTTF *textFeild = (TextFieldTTF *)this->getChildByTag(2);
    Rect rect = Rect(textFeild->getPosition(),textFeild->getContentSize());
    if (rect.containsPoint(point)) {
        textFeild->attachWithIME();
    } else {
        textFeild->detachWithIME();
    }
    
}

void zhuzhuLayer::onEnter() {
    EventListenerTouchOneByOne *touchEvent = EventListenerTouchOneByOne::create();
    touchEvent->onTouchBegan = CC_CALLBACK_2(zhuzhuLayer::onTouchBegan,this);
    touchEvent->onTouchEnded = CC_CALLBACK_2(zhuzhuLayer::onTouchEnded,this);
    touchEvent->onTouchMoved = CC_CALLBACK_2(zhuzhuLayer::onTouchMoved,this);
    touchEvent->onTouchCancelled = CC_CALLBACK_2(zhuzhuLayer::onTouchCancelled,this);

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority((EventListener*)touchEvent, this);
    Layer::onEnter();
}

void zhuzhuLayer::onExit() {
    Director::getInstance()->getEventDispatcher()->removeAllEventListeners();
    Layer::onExit();
}

bool zhuzhuLayer::onTextFieldAttachWithIME(cocos2d::TextFieldTTF *sender) {
    return false;
}

bool zhuzhuLayer::onTextFieldInsertText(cocos2d::TextFieldTTF *sender, const char *text, size_t nLen) {
    CCLOG("%s",text);
}
