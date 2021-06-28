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

	//윈도우 사이즈
	winsize = Director::getInstance()->getWinSize();

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//랜덤 포즈
	ranypos = rand() % (int)winsize.height;
	ranxpos = rand() % (int)winsize.height;

	//배경 색 바꾸기
	auto wlayer = LayerColor::create(Color4B(220, 240, 255, 255));
	this->addChild(wlayer);

	//메뉴 버튼
	auto m_3 = MenuItemImage::create("btn-play-normal.png", "btn-play-selected.png", CC_CALLBACK_1(HelloWorld::doStartClick, this));
	auto m_4 = MenuItemImage::create("end1.PNG", "end2.PNG", CC_CALLBACK_1(HelloWorld::doEndClick, this));
	auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	m_3->setTag(1);
	m_4->setTag(2);
	closeItem->setTag(3);
	auto menu1 = Menu::create(m_3, m_4, closeItem, nullptr);
	m_3->setPosition(Vec2(480, 320));
	m_3->setAnchorPoint(Vec2(1, 1));
	m_4->setPosition(Vec2(0, 320));
	m_4->setAnchorPoint(Vec2(0, 1));
	closeItem->setPosition(Vec2(480, 0));
	closeItem->setAnchorPoint(Vec2(1, 0));
	this->addChild(menu1);
	menu1->setPosition(Vec2::ZERO);

	//디무월드 라벨
	auto label = Label::createWithTTF("Dimu's World", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(240, 320));
	label->setAnchorPoint(Vec2(0.5, 1));
	this->addChild(label, 1);

	//점수 라벨
	score_lb_normal = Label::createWithSystemFont("Score: ", "", 20);
	score_lb_normal->setPosition(Vec2(winsize.width - 240, winsize.height - 50));
	label->setAnchorPoint(Vec2(0.5, 1));
	score_lb_normal->setColor(Color3B::BLUE);
	this->addChild(score_lb_normal);

	score_lb_top = Label::createWithSystemFont("TopScore: ", "", 40);
	score_lb_top->setPosition(Vec2(winsize.width - 240, winsize.height - 70));
	label->setAnchorPoint(Vec2(0.5, 1));
	score_lb_top->setColor(Color3B::GREEN);
	this->addChild(score_lb_top);

	//이벤트 리스너
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);

	//스케쥴
	this->schedule(schedule_selector(HelloWorld::myTick));

	return true;
}

//터치 이벤트
bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	auto touchpoint = touch->getLocation();

	if (isStart)
	{
		pMan->stopAllActions();
		pMan->setRotation(0);
		auto a1 = MoveTo::create(2,Vec2(touchpoint.x, touchpoint.y));
		log("Penemy Move");

		pMan->runAction(a1);
	}
	return false;

}

//스케줄
void HelloWorld::myTick(float f)
{
	if (isStart)
	{
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

		auto rect = pMan->getBoundingBox();
		auto newRect = Rect(pMan->getPosition().x - 10, pMan->getPosition().y - pMan->getContentSize().height * 0.5f, pMan->getContentSize().width, pMan->getContentSize().height);

		if (pItem1 != nullptr)
		{
			if (pItem1->getBoundingBox().intersectsRect(newRect))
			{
				score+=3;
				score_lb_normal->setString(StringUtils::format("Score: %3d", score));
				
				pMan->stopAllActions();
				pMan->setRotation(0);
				auto rot = RotateBy::create(1, 360);
				pMan->runAction(rot);
				log("run callback");

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
				score_lb_normal->setString(StringUtils::format("Score: %3d", score));

				pMan->stopAllActions();
				pMan->setRotation(0);
				auto rot = RotateBy::create(1, 360);
				pMan->runAction(rot);
				log("run callback");

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
}

//아이템1 생성
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

//아이템2 생성
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

//시작 버튼 클릭
void HelloWorld::doStartClick(Ref* pSender)
{
	if (!isStart)
	{
		isStart = true;
		//플레이어캐릭터 생성
		pMan = Sprite::create("grossini.png");
		pMan->setPosition(Vec2(300, 160));
		this->addChild(pMan);
		//아이템 생성
		this->createItem1(ranxpos, ranypos);
		this->createItem2(ranxpos, ranypos);
	}
}

//중지 버튼 클릭
void HelloWorld::doEndClick(Ref* pSender)
{
	if (isStart)
	{
		//최고점수 저장
		if (topscore < score)
		{
			topscore = score;
			score_lb_top->setString(StringUtils::format("TopScore: %3d", topscore));
		}
		score = 0;
		score_lb_normal->setString(StringUtils::format("Score: %3d", score));

		isStart = false;
		this->removeChild(pMan, true);
		this->removeChild(pItem1, true);
		this->removeChild(pItem2, true);
	}
}

//종료 버튼 클릭
void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
