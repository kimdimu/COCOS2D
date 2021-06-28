#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Monster.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	
	cocos2d::Size winsize;
	cocos2d::Sprite* pMan;
	cocos2d::Sprite* pMan2;

	Monster* sprite1;
	Monster* sprite2;
	Monster* sprite3;

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void reZorder(cocos2d::Sprite* sender);

    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
