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
    if ( !Scene::init() )
    {
        return false;
    }

	//sprite1 = Monster::create("CyanSquare.png");
	//sprite1->setPosition(Vec2(240, 160) + Vec2(-50, 0));
	//sprite1->setPr(10);
	//sprite1->setPrWiththis(false);
	//this->addChild(sprite1);

	//sprite2 = Monster::create("MagentaSquare.png");
	//sprite2->setPosition(Vec2(240, 160));
	//sprite2->setPr(20);
	//sprite2->setPrWiththis(false);
	//this->addChild(sprite2);

	//sprite3 = Monster::create("YellowSquare.png");
	//sprite3->setPosition(Vec2(240, 160) + Vec2(+50, 0));
	//sprite3->setPr(30);
	//sprite3->setPrWiththis(false);
	//this->addChild(sprite3);

	sprite1 = Monster::create("CyanSquare.png");
	sprite1->setPosition(Vec2(240, 160) + Vec2(-50, 0));
	sprite1->setPr(10);
	sprite1->setPrWiththis(false);
	this->addChild(sprite1);

	sprite2 = Monster::create("MagentaSquare.png");
	sprite2->setPosition(Vec2(240, 160));
	sprite2->setPr(20);
	sprite2->setPrWiththis(false);
	this->addChild(sprite2);

	sprite3 = Monster::create("YellowSquare.png");
	sprite3->setPosition(Vec2(240, 160) + Vec2(+50, 0));
	sprite3->setPr(30);
	sprite3->setPrWiththis(false);
	sprite2->addChild(sprite3);

    return true;
}

//void HelloWorld::createBullet()
//{
//	pBullet = Sprite::create("ball.png");
//	pBullet->setPosition(Vec2(40, 160));
//	this->addChild(pBullet);
//
//	auto AForward = MoveBy::create(3, Vec2(300, 0));
//	auto A = Sequence::create(Place::create(Vec2(40,160)), AForward, nullptr);
//	auto rep = RepeatForever::create(A);
//
//	pBullet->runAction(rep);
//}
//
//void HelloWorld::myTick(float f)
//{
//	if (pBullet == nullptr)
//	{
//		log("Bullet Null");
//		this->createBullet();
//		return;
//	}
//
//	//간단한 충돌체크
//	//if (pBullet->getBoundingBox().intersectsRect(pEnemy->getBoundingBox()))
//	//{
//	//	log("C Check");
//	//	pBullet->removeFromParentAndCleanup(true);
//	//	pBullet = nullptr;
//	//}
//
//	//정확한 충돌체크
//	auto rect = pEnemy->getBoundingBox();
//	auto newRect = Rect(pEnemy->getPosition().x - 10, pEnemy->getPosition().y, pEnemy->getContentSize().width, pEnemy->getContentSize().height);
//
//	if (pBullet->getBoundingBox().intersectsRect(newRect))
//	{
//		log("cccccccccc");
//
//		auto blink = Blink::create(1, 3);
//		pEnemy->runAction(blink);
//
//		pBullet->removeFromParentAndCleanup(true);
//		pBullet = nullptr;
//
//		this->removeChild(pBullet);
//	}
//}

