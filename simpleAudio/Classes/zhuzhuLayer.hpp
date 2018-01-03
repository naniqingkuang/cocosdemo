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
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

using namespace cocos2d::extension;
#include <stdio.h>

class zhuzhuLayer : public cocos2d::Layer {
public:
    virtual bool init();
    
    CREATE_FUNC(zhuzhuLayer);

    void menuCallBack(Ref *sender);

};

#endif /* zhuzhuLayer_hpp */
