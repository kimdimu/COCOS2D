#include "Monster.h"

USING_NS_CC;

Monster* Monster::create(const std::string& filename)
{
	Monster* sprite = new(std::nothrow)Monster(); // nothrow > 몬스터 잘못 생성될때 프로그래 죽지않도록
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}

	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void Monster::onEnter()
{
	Sprite::onEnter();
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		log("touch bg...");
		Vec2 basepoint = touch->getLocation();

		Vec2 LocationInNode = this->convertToNodeSpace(touch->getLocation());

		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(LocationInNode))
		{
			this->setColor(Color3B::RED);
			return true;
		}
	};

	listener->onTouchMoved = [=](Touch* touch, Event* event)
	{
		log("touch mv...");
		this->setPosition(this->getPosition() + touch->getDelta());//이동한정보
	};

	listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		log("touch end...");
		this->setColor(Color3B::WHITE);
	};

	if (_useNodePr)
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this); //그려진 순서
	else
		_eventDispatcher->addEventListenerWithFixedPriority(listener, _fixedPr); // 지정된 우선순위대로

	_listener = listener; //화면 보일 때 터치하면 리스너 만들고 화면 사라지면 리스너 제거
}

void Monster::onExit()
{
	_eventDispatcher->removeEventListener(_listener);
	Sprite::onExit();
}

void Monster::setPr(int fixedPr)
{
	_fixedPr = fixedPr;
}

void Monster::setPrWiththis(bool useNodePr)
{
	_useNodePr = useNodePr;
}