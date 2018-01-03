//
//  zhuzhuLayer.cpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#include "zhuzhuLayer.hpp"




bool zhuzhuLayer::init() {

    Size size = Director::getInstance()->getVisibleSize();

    Sprite* bg = Sprite::create("HelloWorld.png");
    bg->setPosition(size/2);
    this->addChild(bg,-1);

   
    return true;
}


void zhuzhuLayer::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) {
    Size size = Director::getInstance()->getVisibleSize();
    
    
    // 画点
    DrawPrimitives::setPointSize(10);
    DrawPrimitives::setDrawColor4B(255, 0, 255, 255);
    DrawPrimitives::drawPoint(size/2);

    //直线
    glLineWidth(3);
    DrawPrimitives::drawLine(Vec2(0, 0), Vec2(size.width/2, size.height/2));


    // 圆
    glLineWidth(10);
    DrawPrimitives::drawCircle(Vec2(size.width/2, size.height/2), size.width/8, 3.14, 360, false, 1, 1);


    // 矩形
    DrawPrimitives::drawRect(Vec2(0, 0), Vec2(size.width/2, size.height/2));
    DrawPrimitives::drawSolidRect(Vec2(size.width/2, size.height/2), Vec2(size.width, size.height), Color4F(255.f, 255.f, 255.f, 0.5f));


    //多边形
    Point Polyarray[] = {Vec2(20, 20), Vec2(50, 0), Vec2(250, 100), Vec2(300, 100), Vec2(250, 50)};
    DrawPrimitives::drawPoly((const Vec2 *)Polyarray, 5, true);


    //贝塞尔曲线
    DrawPrimitives::drawQuadBezier(Vec2(0, size.height/2), Vec2(size.width*3/4, size.height/2), Vec2(size.width*3/4, size.height/8), 100);
}


