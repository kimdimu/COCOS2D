#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

	bool bChange;
	int nNum;
    virtual bool init();

	//Size winsize;

    // a selector callback			  
	//void doStart(Ref* sender, Ref* pman);
	//void doPause(Ref* sender , Ref* pman, Ref* rep);
	//void doStop(Ref* sender, Ref* pman);
	//void doResume(Ref* sender);
	//void doChange(Ref* sender);

	void tick1(float f);
	void tick2(float f);
	void update(float f);

	void RS(Ref* sender);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
