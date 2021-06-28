#include "Monster.h"

USING_NS_CC;

Monster* Monster::create(const std::string& filename)
{
	Monster* sprite = new(std::nothrow)Monster(); // nothrow > ���� �߸� �����ɶ� ���α׷� �����ʵ���
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
		this->setPosition(this->getPosition() + touch->getDelta());//�̵�������
	};

	listener->onTouchEnded = [=](Touch* touch, Event* event)
	{
		log("touch end...");
		this->setColor(Color3B::WHITE);
	};

	if (_useNodePr)
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this); //�׷��� ����
	else
		_eventDispatcher->addEventListenerWithFixedPriority(listener, _fixedPr); // ������ �켱�������

	_listener = listener; //ȭ�� ���� �� ��ġ�ϸ� ������ ����� ȭ�� ������� ������ ����
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