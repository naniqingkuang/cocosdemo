//
//  zhuzhuLayer.cpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#include "zhuzhuLayer.hpp"




bool zhuzhuLayer::init() {

    Size size = Director::getInstance()->getVisibleSize();

    // 背景图片
    Sprite* bg = Sprite::create("HelloWorld.png");
    bg->setPosition(size/2);
    this->addChild(bg,-1);

   // 创建主题文字
    Sprite *gameTitle = Sprite::create("game_title copy.png");
    Size clipSize = gameTitle->getContentSize();
    
    // 创建底板的发光图片：spark
    Sprite *spark = Sprite::create("spark copy.png");
    spark->setPosition(-clipSize.width,0);
    
    // 创建裁剪节点
    ClippingNode *clipNode = ClippingNode::create();
    clipNode->setPosition(size/2);
    this->addChild(clipNode);
    
    clipNode->setAlphaThreshold(0.05f);
    clipNode->setContentSize(clipSize);
    
    clipNode->setStencil(gameTitle);
    clipNode->addChild(gameTitle,1);
    clipNode->addChild(spark,2);
    
    //左右移动
    MoveTo *moveAction = MoveTo::create(2.0, Vec2(clipSize.width,0));
    MoveTo *moveBackAction = MoveTo::create(2.0, Vec2(-clipSize.width, 0));
    spark->runAction(RepeatForever::create(Sequence::create(moveAction,moveBackAction, NULL)));
    return true;
}




