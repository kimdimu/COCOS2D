
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
	auto pMan = Sprite::create("grossini.png");
	pMan->setPosition(Vec2(150, 250));
	pMan->setTag(1);
	pMan->setLocalZOrder(1);
	addChild(pMan);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

    return true;
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event) {
	auto touchpoint = touch->getLocation();
	auto spr = (Sprite*)getChildByTag(1);
	if (spr->getBoundingBox().containsPoint(touchpoint))
	{
		countOn++;
		CCLOG("countOn: %d", countOn);
		spr->setScale(2);
	}
	else
	{
		countOff++;
		spr->setScale(1);
		CCLOG("countOff: %d", countOff);
	}
	return false;

}