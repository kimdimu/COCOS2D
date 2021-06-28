#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "cocos2d.h"
USING_NS_CC;

using namespace experimental;
class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
	int audio;
    virtual bool init();
	void do1Click(Ref* pSender);
	void do2Click(Ref* pSender);
	bool onTouchBegan(Touch* touch, Event* event);
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
