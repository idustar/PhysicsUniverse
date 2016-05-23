#include "HelloWorldScene.h"
//#include "cocostudio/CocoStudio.h"
//#include "ui/CocosGUI.h"

USING_NS_CC;

//using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
	scene->addChild(layer);
	//layer->setPhyWorld(scene->getPhysicsWorld());
    // add layer as a child to scene
    

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    /**  you can create scene with following comment code instead of using csb file.
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    **/
    
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }


	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
    /*
	//auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	auto label = Label::create("Hello World", "Arial", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);


	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);//设置要添加到节点中的物理body
	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	edgeNode->setPhysicsBody(body);//将物理body加入到创建的节点中
	scene->addChild(edgeNode); //场景中添加创建的物理节点


	*/
	auto keyBoardListener = EventListenerKeyboard::create();
	keyBoardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	keyBoardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::onKeyReleased, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyBoardListener, this);

	//定义世界的边界  
	auto body = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 5.0f); 
	auto edgeNode = Node::create(); 
	edgeNode->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	edgeNode->setPhysicsBody(body);
	this->addChild(edgeNode);

    setTouchEnabled(true);                                             
	//设置为单点触摸  
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);


	//Point location = Point(500, 500);
	//asPosition(location);

	auto sp = Sprite::create("circle1.png");
	sp->setTag(2);
	auto body1 = PhysicsBody::createBox(sp->getContentSize());
	body1->getShape(0)->setRestitution(1);
	body1->setDynamic(false);
	//auto body = PhysicsBody::createBox(sp->getContentSize());	
	//body->setLinearDamping(0.0f);
	sp->setPhysicsBody(body1);
	sp->setPosition(Point(480,320));
	//sp->getPhysicsBody()->removeAllShapes();
	this->addChild(sp);






    return true;
}




/*
void HelloWorld::addNewSpriteAtPosition(Point p)
{
	auto sprite = Sprite::create("circle.png");//创建精灵
	sprite->setTag(1);//设置精灵的便签值
	auto body = PhysicsBody::createCircle(sprite->getContentSize().width / 2);//创建一个附加在精灵身体上的圆形物理body
	sprite->setPhysicsBody(body);//将创建的body加到精灵身上
	sprite->setPosition(p);
	this->addChild(sprite);//添加精灵
}

*/
/*
void HelloWorld::setPhyWorld(PhysicsWorld* world) {
	m_world = world;
}
*/

bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	Point location = touch->getLocation();
	asPosition(location);
	return false;
}


void HelloWorld::asPosition(Point p)
{
	
	auto sp = Sprite::create("circle.png");
	sp->setTag(1);	
	auto body = PhysicsBody::createCircle(sp->getContentSize().width/2);
	body->getShape(0)->setRestitution(1);
	body->setMass(CCRANDOM_0_1());
	body->setVelocityLimit(300);
	//body->addShape(PhysicsShapeBox::create(sp->getContentSize(),PHYSICSBODY_MATERIAL_DEFAULT,Point(20,20)));
	//auto body = PhysicsBody::createBox(sp->getContentSize());	
	//body->setLinearDamping(0.0f);	
	sp->setPhysicsBody(body);
	sp->setPosition(p);
	sp->setRotation(CCRANDOM_0_1() * 360);
	//sp->getPhysicsBody()->removeAllShapes();
	this->addChild(sp);
	

	auto sp2 = Sprite::create("circle3.png");
	sp2->setTag(1);
	auto body2 = PhysicsBody::createCircle(sp2->getContentSize().width / 2);
	body2->getShape(0)->setRestitution(1);
	body2->setMass(CCRANDOM_0_1());
	body2->setVelocityLimit(300);
	//body->addShape(PhysicsShapeBox::create(sp->getContentSize(),PHYSICSBODY_MATERIAL_DEFAULT,Point(20,20)));
	//auto body = PhysicsBody::createBox(sp->getContentSize());	
	//body->setLinearDamping(0.0f);	
	sp2->setPhysicsBody(body2);
	sp2->setPosition(Point(p.x,p.y+30));
	sp2->setRotation(CCRANDOM_0_1() * 360);
	//sp->getPhysicsBody()->removeAllShapes();
	this->addChild(sp2);


	PhysicsJointDistance* joint = PhysicsJointDistance::construct(body, body2,
		Vec2(0, 0), Vec2(0, sp2->getContentSize().width / 2));
	this->getScene()->getPhysicsWorld()->addJoint(joint);
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event*)
{
	//log("%d", (int*)keyCode);
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW) {
		auto vec = this->getChildren();
		for (auto i : vec) {
			Point pp = i->getPhysicsBody()->getVelocity();
			i->getPhysicsBody()->setVelocity(Point(pp.x-50,pp.y));
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW) {
		auto vec = this->getChildren();
		for (auto i : vec) {
			Point pp = i->getPhysicsBody()->getVelocity();
			i->getPhysicsBody()->setVelocity(Point(pp.x + 50, pp.y));
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW) {
		auto vec = this->getChildren();
		for (auto i : vec) {
			Point pp = i->getPhysicsBody()->getVelocity();
			i->getPhysicsBody()->setVelocity(Point(pp.x, pp.y + 50));
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW) {
		auto vec = this->getChildren();
		for (auto i : vec) {
			Point pp = i->getPhysicsBody()->getVelocity();
			i->getPhysicsBody()->setVelocity(Point(pp.x, pp.y - 50));
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_Q) {
		auto vec = this->getChildren();
		for (auto i : vec) {
			i->getPhysicsBody()->setAngularVelocity(i->getPhysicsBody()->getAngularVelocity()-1);
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_W) {
		auto vec = this->getChildren();
		for (auto i : vec) {
			i->getPhysicsBody()->setAngularVelocity(i->getPhysicsBody()->getAngularVelocity() + 1);
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_A) {
		auto vec = this->getChildren();
		for (auto i : vec) {
			i->getPhysicsBody()->setGravityEnable(!i->getPhysicsBody()->isGravityEnabled());
		}
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_S) {
		auto vec = this->getChildren();
		for (auto i : vec) {
			//i->getPhysicsBody()->setRotationEnable(!i->getPhysicsBody()->isRotationEnabled());
		}
	}
	//this->getChildByTag(1)->getPhysicsBody()->removeAllShapes();
	//this->getChildByTag(1)->getPhysicsBody()->applyForce(Point(35, 36));
	//log("%d,%d", pp.x, pp.y);
	//asPosition(Point(CCRANDOM_0_1()*960, CCRANDOM_0_1() * 640));
	//playerPlane->onKeyPressed(keyCode);
}

void HelloWorld::onKeyReleased(EventKeyboard::KeyCode keyCode, Event*)
{
	//log("2");
	//asPosition(Point(CCRANDOM_0_1() * 960, CCRANDOM_0_1() * 640));
	//playerPlane->onKeyReleased(keyCode);
}