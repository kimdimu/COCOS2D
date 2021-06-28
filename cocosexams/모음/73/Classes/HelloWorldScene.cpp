#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

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
	if (!Scene::init())
	{
		return false;
	}
	winsize = Director::getInstance()->getWinSize();
	
	ranypos = rand() % (int)winsize.height;
	ranxpos = rand() % (int)winsize.height;


	createItem1(ranypos, ranxpos);
	createItem2(ranxpos, ranypos);

	pEnemy = Sprite::create("grossini.png");
	pEnemy->setPosition(Vec2(300, 160));
	this->addChild(pEnemy);

	auto a1 = MoveBy::create(3, (Vec2(ranxpos, winsize.height)));
	auto a2 = MoveBy::create(3, (Vec2(winsize.width, ranypos)));
	auto a3 = MoveBy::create(3, (Vec2(ranxpos, 0)));
	auto a4 = MoveBy::create(3,(Vec2(0, ranypos)));
	auto s = Sequence::create(a1, a2, a3, a4, nullptr);
	auto aa = RepeatForever::create(s);

	pEnemy->runAction(a1);


	this->schedule(schedule_selector(HelloWorld::myTick));

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	score_lb = Label::createWithSystemFont("Score: ","",20);
	score_lb->setPosition(Vec2(winsize.width - 100, winsize.height - 30));
	score_lb->setColor(Color3B::BLUE);
	this->addChild(score_lb);

	return true;
}

void HelloWorld::createBullet(float x, float y)
{
	pBullet = Sprite::create("ball.png");
	pBullet->setPosition(Vec2(x, y));
	this->addChild(pBullet);

	auto AForward = MoveBy::create(3, Vec2(winsize.width, ranypos));
	ranypos = rand() % 200 - 100;
	auto A = Sequence::create(Place::create(Vec2(x, y)), AForward, nullptr);
	auto rep = RepeatForever::create(A);

	pBullet->runAction(rep);
}

void HelloWorld::createItem1(float x, float y)
{
	pItem1 = Sprite::create("Pea.png");
	pItem1->setPosition(Vec2(x, y));
	this->addChild(pItem1);

	auto AForward = MoveBy::create(3, Vec2(winsize.width, ranxpos));
	ranxpos = rand() % 100;
	auto A = Sequence::create(Place::create(Vec2(x, y)), AForward, nullptr);
	auto rep = RepeatForever::create(A);

	pItem1->runAction(rep);
}

void HelloWorld::createItem2(float x, float y)
{
	pItem2 = Sprite::create("r2.png");
	pItem2->setPosition(Vec2(x, y));
	this->addChild(pItem2);

	auto AForward = MoveBy::create(3, Vec2(winsize.width, ranypos));
	ranypos = rand() % 200 - 100;
	auto A = Sequence::create(Place::create(Vec2(x, y)), AForward, nullptr);
	auto rep = RepeatForever::create(A);

	pItem2->runAction(rep);
}

void HelloWorld::myTick(float f)
{
	//간단한 충돌체크
	//if (pBullet->getBoundingBox().intersectsRect(pEnemy->getBoundingBox()))
	//{
	//	log("C Check");
	//	pBullet->removeFromParentAndCleanup(true);
	//	pBullet = nullptr;
	//}

	if (pItem1 == nullptr)
	{
		ranxpos = rand() % (int)winsize.width;
		ranypos = rand() % (int)winsize.height;
		this->createItem1(ranxpos, ranypos);
	}
	if (pItem2 == nullptr)
	{
		ranypos = rand() % (int)winsize.height;
		ranxpos = rand() % (int)winsize.width;
		this->createItem2(ranxpos, ranypos);
	}


	if (pEnemy->getPosition().x <= 0 || pEnemy->getPosition().x >= winsize.width || pEnemy->getPosition().y <= 0 || pEnemy->getPosition().y > winsize.height)
	{
		pEnemy->setPosition(Vec2(winsize.width * 0.5f, winsize.height * 0.5f));
	}

	//정확한 충돌체크
	auto rect = pEnemy->getBoundingBox();
	auto newRect = Rect(pEnemy->getPosition().x - 10, pEnemy->getPosition().y- pEnemy->getContentSize().height*0.5f, pEnemy->getContentSize().width, pEnemy->getContentSize().height);

	if (pBullet != nullptr)
	{
		if (pBullet->getBoundingBox().intersectsRect(newRect))
		{
			score++;
			score_lb->setString(StringUtils::format("Score: %3d", score));
			CallFunc::create(CC_CALLBACK_0(HelloWorld::c1, this, pEnemy));


			pBullet->removeFromParentAndCleanup(true);
			pBullet = nullptr;

			this->removeChild(pBullet);
		}
		else if (pBullet->getPosition().x >= winsize.width || pBullet->getPosition().y >= winsize.height || pBullet->getPosition().y <= 0)
		{
			pBullet->removeFromParentAndCleanup(true);
			pBullet = nullptr;

			this->removeChild(pBullet);
		}
	}

	if (pItem1 != nullptr)
	{
		if (pItem1->getBoundingBox().intersectsRect(newRect))
		{
			score++;
			score_lb->setString(StringUtils::format("Score: %3d", score));

			CallFunc::create(CC_CALLBACK_0(HelloWorld::c1, this, pEnemy));


			pItem1->removeFromParentAndCleanup(true);
			pItem1 = nullptr;

			this->removeChild(pItem1);
		}
		else if (pItem1->getPosition().x >= winsize.width || pItem1->getPosition().y >= winsize.height || pItem1->getPosition().y <= 0)
		{
			pItem1->removeFromParentAndCleanup(true);
			pItem1 = nullptr;

			this->removeChild(pItem1);
		}
	}

	if (pItem2 != nullptr)
	{
		if (pItem2->getBoundingBox().intersectsRect(newRect))
		{
			score++;
			score_lb->setString(StringUtils::format("Score: %3d", score));

			CallFunc::create(CC_CALLBACK_0(HelloWorld::c1, this, pEnemy));

			pItem2->removeFromParentAndCleanup(true);
			pItem2 = nullptr;

			this->removeChild(pItem2);
		}
		else if (pItem2->getPosition().x >= winsize.width || pItem2->getPosition().y >= winsize.height || pItem2->getPosition().y <= 0)
		{
			pItem2->removeFromParentAndCleanup(true);
			pItem2 = nullptr;

			this->removeChild(pItem2);
		}
	}
}

bool HelloWorld::onTouchBegan(Touch* touch, Event* event) {
	auto touchpoint = touch->getLocation();
	auto spr = (Sprite*)getChildByTag(1);

	if (pBullet == nullptr)
	{
		log("Bullet Null");
		this->createBullet(touchpoint.x,touchpoint.y);
	}
	return false;

}

void HelloWorld::c1(Ref* Sender)
{
	auto rot = RotateBy::create(1, 360);
	pEnemy->runAction(rot);
	log("run callback");
}