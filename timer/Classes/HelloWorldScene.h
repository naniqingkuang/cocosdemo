#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    
    //scheduleUpdate
    void update(float dt);
    
    //schedule(schedule_selector)
    void myupdate(float dt);
    
    //schedule(schedule_selector, interval)
    void myupdate2(float dt);
    
    //schedule(schedule_selector, interval, repeat, delay)
    void myupdate3(float dt);
    
    //scheduleOnce
    void myupdate4(float dt);
};

#endif // __HELLOWORLD_SCENE_H__
