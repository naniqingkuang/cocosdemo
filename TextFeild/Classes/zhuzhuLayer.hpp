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

class zhuzhuLayer : public cocos2d::Layer,cocos2d::TextFieldDelegate  {
public:
    virtual bool init();
  virtual   bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    
  virtual   void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) ;
    
    virtual void onEnter();
    
    virtual void onExit();
    
  virtual   bool onTextFieldAttachWithIME(cocos2d::TextFieldTTF *sender) ;
    
  virtual   bool onTextFieldInsertText(cocos2d::TextFieldTTF *sender, const char *text, size_t nLen);
    CREATE_FUNC(zhuzhuLayer);

};

#endif /* zhuzhuLayer_hpp */
