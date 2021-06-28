#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto  voidNode = Layer::create();
	this->addChild(voidNode);

	auto b1 = Sprite::create("1.png");
	b1->setAnchorPoint(Vec2(0, 0));
	b1->setPosition(Vec2(0, 0));

	auto b2 = Sprite::create("2.png");
	b2->setAnchorPoint(Vec2(0, 0));
	b2->setPosition(Vec2(500, 0));

	b1->getTexture()->setAliasTexParameters();
	b2->getTexture()->setAliasTexParameters();

	voidNode->addChild(b1);
	voidNode->addChild(b2);

	auto go = MoveBy::create(4, Vec2(-500, 0));

	auto seq = Sequence::create(go, Place::create(Vec2(0, 0)), NULL);
	auto ac = RepeatForever::create(seq);

	voidNode->runAction(ac);

	auto m_3 = MenuItemImage::create("btn-play-normal.png", "btn-play-selected.png", CC_CALLBACK_1(HelloWorld::do1Click, this));
	auto m_4 = MenuItemImage::create("end1.PNG", "end2.PNG", CC_CALLBACK_1(HelloWorld::do2Click, this));
	m_3->setTag(1);
	m_4->setTag(2);
	auto menu1 = Menu::create(m_3, m_4, nullptr);
	m_3->setPosition(Vec2(480, 320));
	m_3->setAnchorPoint(Vec2(1, 1));
	m_4->setPosition(Vec2(0, 320));
	m_4->setAnchorPoint(Vec2(0, 1));
	this->addChild(menu1,3);
	menu1->setPosition(Vec2::ZERO);

    return true;
}

void HelloWorld::do1Click(Ref* pSender)
{
	
}

void HelloWorld::do2Click(Ref* pSender)
{

}
