/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size winsize;

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);
	winsize = Director::getInstance()->getWinSize();
	////1
	//
	//
	//
	//
	//
	//
	//auto spr = Sprite::create("grossini_dance_01.png");
	//spr->setPosition(Vec2(100, 100));
	//this->addChild(spr);
	//
	//auto animation = Animation::create();
	//animation->setDelayPerUnit(0.3f); //«¡∑π¿”
	//
	//for (int i=1;i<15;i++)
	//{
	//	animation->addSpriteFrameWithFile(StringUtils::format("grossini_dance_%02d.png", i));
	//}
	//
	//auto animate = Animate::create(animation);
	//auto action = RepeatForever::create(animate);
	//spr->runAction(action);

	//2
	auto texture1 = Director::getInstance()->getTextureCache()->addImage("walk-cycle-animation.png");
	auto pMan = Sprite::createWithTexture(texture1, Rect(0, 0, 182, 318));
	pMan->setPosition(Point(240, 200));
	
	auto ani = Animation::create();
	ani->setDelayPerUnit(0.2f);
	for (int i = 0; i < 8; i++)
	{
		ani->addSpriteFrameWithTexture(texture1, Rect(i * 182, 0, 182, 318));
	}
	
	auto animate = Animate::create(ani);
	auto rep = RepeatForever::create(animate);
	////3
	//auto cache = SpriteFrameCache::getInstance();
	//cache->addSpriteFramesWithFile("gros.plist");
	//auto pMan = Sprite::createWithSpriteFrameName("grossini_dance_01.png");
	//
	//pMan->setPosition(Point(100, 100));
	//this->addChild(pMan);
	//auto anii = Animation::create();
	//anii->setDelayPerUnit(0.3f);
	//
	//for (int i = 1; i < 16; i++)
	//{
	//	auto frame = cache->getSpriteFrameByName(StringUtils::format("grossini_dance_%02d.png", i));
	//	anii->addSpriteFrame(frame);
	//}
	//
	//auto anim = Animate::create(anii);
	//auto action = RepeatForever::create(anim);
	//pMan->runAction(action);

	//auto it1 = MenuItemFont::create("start", CC_CALLBACK_1(HelloWorld::doStart, this));
	//it1->setColor(Color3B(0, 0, 0));
	//auto it2 = MenuItemFont::create("ps", CC_CALLBACK_1(HelloWorld::doPause, this));
	//it2->setColor(Color3B(0, 0, 0));
	//auto it3 = MenuItemFont::create("rs", CC_CALLBACK_1(HelloWorld::doResume, this));
	//it3->setColor(Color3B(0, 0, 0));
	//auto it4 = MenuItemFont::create("cg", CC_CALLBACK_1(HelloWorld::doChange, this));
	//it4->setColor(Color3B(0, 0, 0));
	//auto it5 = MenuItemFont::create("end", CC_CALLBACK_1(HelloWorld::RS, this));
	//it5->setColor(Color3B(0, 0, 0));

	//auto menu = Menu::create(it1, it2, it3, it4, it5, NULL);
	//menu->alignItemsVertically();
	//this->addChild(menu);

	nNum = 0;
	bChange = true;




    return true;
}

/*void  HelloWorld::doStart(Ref* sender, Ref* pman)
{
	this->addChild((Sprite*)pman);
}
void  HelloWorld::doPause(Ref* sender, Ref* pman, Ref* rep)
{
	(Sprite*)pman->runAction((RepeatForever*)rep);
}
void  HelloWorld::doStop(Ref* sender, Ref* pman)
{	
	auto acc = MoveBy::create(2.0, Vec2(0, 0));
	auto acs = Sequence::create(acc,CallFuncN::create(CC_CALLBACK_1(HelloWorld::RS, this)),NULL);
	(Sprite*)pman->runAction((MoveBy*)acc);
	
}
void  HelloWorld::doResume(Ref* sender)
{
	Director::getInstance()->getScheduler()->resumeTarget(this);

}
void  HelloWorld::doChange(Ref* sender)
{
	if (bChange)
	{
		bChange = false;
		this->unschedule(schedule_selector(HelloWorld::tick2));
	}
	else
	{
		bChange = true;
		this->unschedule(schedule_selector(HelloWorld::tick2));
		this->schedule(schedule_selector(HelloWorld::tick2), 2.0f);
	}
}*/

void HelloWorld::tick1(float f)
{
	log("t1");
}
void HelloWorld::tick2(float f)
{
	log("t2");

}
void HelloWorld::update(float f)
{

}
void HelloWorld::RS(Ref* sender)
{
	auto spr = (Sprite*)sender;
	this->removeChild(spr);
	log("aaa");
}