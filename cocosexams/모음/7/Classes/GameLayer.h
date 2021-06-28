#ifndef __GL_SCENE_H__
#define __GL_SCENE_H__

#include "cocos2d.h"

class GL : public cocos2d::Layer
{
public:
//	static cocos2d::Scene* createScene();

	virtual bool init();

	void Goback(Ref* pSender);
	CREATE_FUNC(GL);
};

#endif // __HELLOWORLD_SCENE_H__
