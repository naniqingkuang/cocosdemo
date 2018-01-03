#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos-ext.h"
#include "cocos2d.h"
using namespace cocos2d::extension;


class HelloWorld : public cocos2d::Scene
{
private:
    cocos2d::Label *label;
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    
    void valueChanged(Ref*sender, Control::EventType type);
    void sliderValueChanged(Ref*sender, Control::EventType type);

    
};

#endif // __HELLOWORLD_SCENE_H__
