//
//  zhuzhuLayer.hpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#ifndef zhuzhuLayer_hpp
#define zhuzhuLayer_hpp
#include "cocos-ext.h"
#include "cocos2d.h"
using namespace cocos2d;

using namespace cocos2d::extension;
#include <stdio.h>

class zhuzhuLayer : public cocos2d::Layer, ScrollViewDelegate  {
public:
    virtual bool init();
    void menuCloseCallback(Ref* pSender);
    
    void test1(); //测试图片滚动

    

    void scrollImage(CCObject* sender); //test3的背包翻页
    
    void scrollViewDidScroll(ScrollView* view); //滚动时响应的回调函数
    void scrollViewDidZoom(ScrollView* view);   //放缩时响应的回调函数
    

    CREATE_FUNC(zhuzhuLayer);

};

#endif /* zhuzhuLayer_hpp */
