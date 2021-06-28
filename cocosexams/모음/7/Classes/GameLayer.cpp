#include "HelloWorldScene.h"
#include "GameLayer.h"

USING_NS_CC;

Scene* GL::createScene()
{
	return GL::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool GL::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto wlayer = LayerColor::create(Color4B(0, 255, 0, 255));
	this->addChild(wlayer);

	auto item1 = MenuItemFont::create("close s 2", CC_CALLBACK_1(GL::DoClose, this));
	auto m = Menu::create(item1, nullptr);
	m->setPosition(Vec2(240, 50));

	this->addChild(m);
	return true;
}
void DoClose(Ref* pSender)
{
	Director::getInstance()->popScene();
}

