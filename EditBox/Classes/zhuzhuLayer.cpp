//
//  zhuzhuLayer.cpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#include "zhuzhuLayer.hpp"




bool zhuzhuLayer::init() {
    EditBox *box = EditBox::create(Size(100, 30), Scale9Sprite::create("ControlSwith_on.png"));
    box->setDelegate(this);
    box->setPlaceHolder("输入密码");
    box->setColor(Color3B::GREEN);
    box->setReturnType(EditBox::KeyboardReturnType::DONE);
    box->setInputFlag(EditBox::InputFlag::PASSWORD);
    box->setInputMode(EditBox::InputMode::URL);
    box->setPosition(Vec2(100,200));
    this->addChild(box);
    return true;
}


void zhuzhuLayer::editBoxEditingDidBegin(EditBox* editBox) {
    CCLOG("editBox %p DidBegin !", editBox);

}



void zhuzhuLayer::editBoxEditingDidEnd(EditBox* editBox)  {
}


void zhuzhuLayer::editBoxTextChanged(EditBox* editBox, const std::string& text) {
}


void zhuzhuLayer::editBoxReturn(EditBox* editBox) {
    CCLOG("editBox %p return !", editBox);

}




