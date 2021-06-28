#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	cocos2d::Size  winsize;
	int score = 0;
	int topscore = 0;
	float ranypos = 0;
	float ranxpos = 0;
	bool isStart = false;

	cocos2d::Sprite* pMan;
	cocos2d::Sprite* pItem1;
	cocos2d::Sprite* pItem2;

	cocos2d::Label* score_lb_normal;
	cocos2d::Label* score_lb_top;

	void createItem1(float x, float y);
	void createItem2(float x, float y);

	void doStartClick(Ref* pSender);
	void doEndClick(Ref* pSender);

	void myTick(float f);

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
