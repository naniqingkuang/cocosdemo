//
//  zhuzhuLayer.cpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#include "zhuzhuLayer.hpp"




bool zhuzhuLayer::init() {
    //
    LayerColor *layerColor = LayerColor::create(Color4B(0,255,255,0));
    layerColor->setContentSize(Size(480,320));
    
    //
    ScrollView *scrollView = ScrollView::create(Size(480,320));
    scrollView->setContentSize(Size(600,800));
    scrollView->setViewSize(Size(480,200));
    scrollView->setDelegate(this);
    scrollView->setContainer(layerColor);
    scrollView->setTouchEnabled(true);
    scrollView->setDirection(ScrollView::Direction::VERTICAL);
    this->addChild(scrollView);
    
    // sprite
    Sprite *sprite = Sprite::create("war copy.png");
    sprite->setPosition(240,100);
    sprite->setContentSize(Size(100, 100));
    sprite->setVisible(true);
    layerColor->addChild(sprite);
    scrollView->setBounceable(true);

    //
    Sprite *sprite2 = Sprite::create("war copy.png");
    sprite2->setPosition(240,400);
    sprite2->setContentSize(Size(100, 100));
    sprite2->setVisible(true);
    layerColor->addChild(sprite2);
    scrollView->setBounceable(true);
    
    
    
    
    return true;
}



void zhuzhuLayer::test1() {
    
}



void zhuzhuLayer::scrollImage(Ref* sender) {
    
}

void zhuzhuLayer::scrollViewDidScroll(ScrollView* view) {
    
}
void zhuzhuLayer::scrollViewDidZoom(ScrollView* view) {
    
}




