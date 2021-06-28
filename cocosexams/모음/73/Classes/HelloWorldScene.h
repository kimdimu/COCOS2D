#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	int score=0;
	float ranypos = 0;
	float ranxpos = 0;
	cocos2d::Size  winsize;
	void myTick(float f);
	cocos2d::Sprite* pEnemy;
	cocos2d::Sprite* pBullet;
	cocos2d::Sprite* pItem1;
	cocos2d::Sprite* pItem2;
	cocos2d::Label* score_lb;
	void createBullet(float x, float y);
	void createItem1(float x, float y);
	void createItem2(float x, float y);
	void c1(Ref* Sender);

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
