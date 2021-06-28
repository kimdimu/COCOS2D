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

    //auto visibleSize = Director::getInstance()->getVisibleSize();
    //Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//
    ///////////////////////////////
    //// 2. add a menu item with "X" image, which is clicked to quit the program
    ////    you may modify it.
	//
    //// add a "close" icon to exit the progress. it's an autorelease object
    //auto closeItem = MenuItemImage::create(
    //                                       "CloseNormal.png",
    //                                       "CloseSelected.png",
    //                                       CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	//
    //if (closeItem == nullptr ||
    //    closeItem->getContentSize().width <= 0 ||
    //    closeItem->getContentSize().height <= 0)
    //{
    //    problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    //}
    //else
    //{
    //    float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
    //    float y = origin.y + closeItem->getContentSize().height/2;
    //    closeItem->setPosition(Vec2(x,y));
    //}
	//
    //// create menu, it's an autorelease object
    //auto menu = Menu::create(closeItem, NULL);
    //menu->setPosition(Vec2::ZERO);
    //this->addChild(menu, 1);
	//
    ///////////////////////////////
    //// 3. add your codes below...
	//
    //// add a label shows "Hello World"
    //// create and initialize a label
	//
    //auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    //if (label == nullptr)
    //{
    //    problemLoading("'fonts/Marker Felt.ttf'");
    //}
    //else
    //{
    //    // position the label on the center of the screen
    //    label->setPosition(Vec2(origin.x + visibleSize.width/2,
    //                            origin.y + visibleSize.height - label->getContentSize().height));
	//
    //    // add the label as a child to this layer
    //    this->addChild(label, 1);
    //}
	//
    //// add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
    //if (sprite == nullptr)
    //{
    //    problemLoading("'HelloWorld.png'");
    //}
    //else
    //{
    //    // position the sprite on the center of the screen
    //    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	//
    //    // add the sprite as a child to this layer
    //    this->addChild(sprite, 0);
    //}
	
	//-----------------------------------------------------------------------------------------------------------menus

	auto wlayer = LayerColor::create(Color4B(100, 100, 100, 255));
	this->addChild(wlayer);

	auto pMan = Sprite::create("grossini.png");
	auto wBox = Sprite::create("white-512x512.png");
	auto pMan1 = Sprite::create("grossini.png");
	auto pMan2 = Sprite::create("grossini.png");
	auto pMan3 = Sprite::create("grossini.png");

	auto visibleSize = Director::getInstance()->getVisibleSize();


	auto label = Label::createWithSystemFont("hell", "", 70, Size(200, 100), TextHAlignment::CENTER, TextVAlignment::CENTER);
	auto label1 = Label::createWithSystemFont("dimu", "", 90, Size(200, 100), TextHAlignment::RIGHT, TextVAlignment::TOP);
	auto label2 = Label::createWithSystemFont("babo", "", 60, Size(200, 100), TextHAlignment::CENTER, TextVAlignment::CENTER);
	auto label3 = Label::createWithSystemFont("hoe1", "", 50, Size(200, 100), TextHAlignment::CENTER, TextVAlignment::CENTER);

	TTFConfig ttc("fonts/Paint Boy.ttf", 30);
	auto label4 = Label::createWithTTF(ttc, "dimumu");

	Size pManSize = pMan->getContentSize();

	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Size winSize = Director::getInstance()->getWinSize();
	pMan->setPosition(Point(winSize.width/8, 0));
	

	label->setPosition(Vec2(0, 160));
	label->setColor(Color3B::ORANGE);
	label->setAnchorPoint(Vec2(0, 0.5));
	
	label1->setPosition(Vec2(240, 320));
	label1->setColor(Color3B::BLACK);
	label1->setAnchorPoint(Vec2(0.5, 1));
	
	label2->setPosition(Vec2(240, 0));
	label2->setColor(Color3B::BLUE);
	label2->setAnchorPoint(Vec2(0.5, 0));
	
	label3->setPosition(Vec2(480, 160));
	label3->setColor(Color3B::MAGENTA);
	label3->setAnchorPoint(Vec2(1, 0.5));
	
	label4->setPosition(Vec2(240, 160));
	label4->setColor(Color3B::RED);
	label4->setAnchorPoint(Vec2(0.5, 0.5));

	wBox->setTextureRect(Rect(0, 0, 50, 10));
	wBox->setPosition(Vec2(pManSize.width / 2, pManSize.height + 10));
	wBox->setColor(Color3B::RED);

	//wBox->setScale(2.0f);
	//wBox->setOpacity(100);
	//wBox->setRotation(45);

	//-----------------------------------------------------------------------------------------------------------menus

	//menu1
	auto item_1 = MenuItemFont::create("play", CC_CALLBACK_1(HelloWorld::menuCallback, this));
	auto item_2 = MenuItemFont::create("score", CC_CALLBACK_1(HelloWorld::menuCallback, this));
	item_1->setPosition(Vec2(0, 0));
	item_1->setAnchorPoint(Vec2(0, 0));
	item_2->setPosition(Vec2(480, 320));
	item_2->setAnchorPoint(Vec2(1, 1));
	auto menu = Menu::create(item_1, item_2, NULL);
	//menu->alignItemsVertically();
	this->addChild(menu);
	menu->setPosition(Vec2::ZERO);

	//menu2
	auto m_3 = MenuItemFont::create("me 1", CC_CALLBACK_1(HelloWorld::doClick, this));
	m_3->setColor(Color3B(0, 0, 0));
	auto m_4 = MenuItemFont::create("me 2", CC_CALLBACK_1(HelloWorld::doClick, this));
	m_4->setColor(Color3B(0, 0, 0));
	m_3->setTag(1);
	m_4->setTag(2);
	auto menu1 = Menu::create(m_3, m_4, nullptr);
	m_3->setPosition(Vec2(480, 0));
	m_3->setAnchorPoint(Vec2(1, 0));
	m_4->setPosition(Vec2(0, 320));
	m_4->setAnchorPoint(Vec2(0, 1));
	//menu1->alignItemsVertically();
	this->addChild(menu1);
	menu1->setPosition(Vec2::ZERO);

	//menu3
	auto pmi1 = MenuItemImage::create("btn-play-normal.png", "btn-play-selected.png", CC_CALLBACK_1(HelloWorld::doClick1, this));
	auto pmi2 = MenuItemImage::create("btn-highscores-normal.png", "btn-highscores-selected.png", CC_CALLBACK_1(HelloWorld::doClick2, this));
	auto menuIMG = Menu::create(pmi1, pmi2, nullptr);
	pmi1->setPosition(Vec2(480, 270));
	pmi1->setAnchorPoint(Vec2(1, 1));
	pmi2->setPosition(Vec2(480, 100));
	pmi2->setAnchorPoint(Vec2(1, 0.5));
	menuIMG->setPosition(Vec2::ZERO);
	this->addChild(menuIMG);

	pMan->setPosition(Vec2(50, 230));
	pMan1->setPosition(Vec2(50, 130));
	pMan->setAnchorPoint(Vec2(0.5, 0.5));
	pMan1->setAnchorPoint(Vec2(0.5, 0.5));
	
	pMan1->setTag(100);
	pMan->setTag(100);

	pMan->addChild(wBox);
	this->addChild(pMan, 1);
	this->addChild(pMan1, 2);

	this->addChild(label, 5);
	this->addChild(label1, 5);
	this->addChild(label2, 5);
	this->addChild(label3, 5);
	this->addChild(label4);

	auto actionTo = MoveTo::create(3.0, Vec2(300, 0));
	auto actionBy = MoveBy::create(1.0, Vec2(300, 0));
	auto actionToJ = JumpTo::create(3.0, Vec2(300, 0),50,5);
	auto actionByJ = JumpBy::create(3.0, Vec2(300, 0),50,5);
	auto actionToR = RotateTo::create(3.0, 270);
	auto actionByR = RotateBy::create(3.0, 270);
	auto actionToT = TintTo::create(3.0, 50,50, 50);
	auto actionByT = TintBy::create(3.0, 10,-30,10);
	
	auto actionMV = MoveBy::create(1.0, Vec2(100, -30));
	auto actionSP = Speed::create(actionMV->clone(), 1.0f);
	auto actionEI = EaseIn::create(actionMV, 3.0f);
	auto actionEO = EaseOut::create(actionMV,3.0f);
	auto actionEEI = EaseElasticIn::create(actionMV->clone(), 0.4f);
	auto actionEEO = EaseElasticOut::create(actionMV->clone(), 0.4f);
	auto actionEBI = EaseBounceIn::create(actionMV->clone());
	auto actionEBO = EaseBounceOut::create(actionMV->clone());
	auto actionDT = DelayTime::create(1.0);
	auto actionRV = actionMV->reverse();
	auto actionEIO = EaseInOut::create(actionRV,5.0f);
	auto actionDT2 = DelayTime::create(1.0);

	//auto actionCF = CallFunc::create(CC_CALLBACK_0(HelloWorld::UserFunction, this));
	auto actionCF = CallFunc::create(CC_CALLBACK_0(HelloWorld::UserFunction, this,pMan,  2, "love"));

	auto acSet1 = Sequence::create(actionBy, actionToJ, NULL);
	auto acSet2 = Spawn::create(actionByR, actionToJ, NULL);
	auto acSet3 = Sequence::create(actionMV, actionDT, actionRV,actionDT2, actionCF, NULL);

	auto actionRP = Repeat::create(acSet3,5);

	ccBezierConfig bC;
	bC.controlPoint_1 = Point(200, 250);
	bC.controlPoint_2 = Point(400, 150);
	bC.endPosition = Point(450, 50);
	auto action = BezierTo::create(3.0, bC);

	pMan-> runAction(actionRP);
	pMan1->runAction(acSet1); //여기에 acset3 부르면 이상해짐.. pman1의 acset3이 끝나면 pman이 RP를 시작함. 심지어 이동이 끊겨 보인다. 이유는?

	pMan->setLocalZOrder(3);
    return true;
}



void HelloWorld::menuCallback(Ref* pSender)
{
	auto item = (MenuItemFont*)pSender;
	item->setColor(Color3B::RED);
}

void HelloWorld::doClick(Ref* pSender)
{
	auto item = (MenuItem*)pSender;
	int i = item->getTag();

	if (i == 1)
	{
		auto pman = Sprite::create("grossini.png");

		pman->setPosition(Vec2(100, 100));
		pman->setTag(11);

		this->addChild(pman);
	}
	else
	{
		auto pman = (Sprite*)getChildByTag(11);
		this->removeChild(pman, true);
	}
}
void HelloWorld::doClick1(Ref* pSender)
{
	log("첫 번쩨 메누");
}
void HelloWorld::doClick2(Ref* pSender)
{
	log("두 번쩨 메누");
}
void HelloWorld::doClick3(Ref* pSender)
{
	log("두 번쩨 메누");
}

void HelloWorld::UserFunction(Ref* pSender, long data, const char* str)
{
	log("user func");
	auto sp = (Sprite*)getChildByTag(100);
	sp->setVisible(false);

	auto lbl = Label::createWithSystemFont(str, "", 30);
	lbl->setColor(Color3B::YELLOW);
	lbl->setPosition(Vec2(400, 300));
	this->addChild(lbl);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
	 
    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
