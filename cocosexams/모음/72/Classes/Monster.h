#pragma once
#include "cocos2d.h"

class Monster : public cocos2d::Sprite
{
public:
	static Monster* create(const std::string& filename);
	void setPr(int fixedPr);
	void setPrWiththis(bool useNodePr);
	void onEnter();
	void onExit();

private:
	cocos2d::EventListener* _listener;
	int _fixedPr;
	bool _useNodePr;
};