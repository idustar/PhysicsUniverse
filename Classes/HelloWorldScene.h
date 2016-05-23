#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    // implement the "static create()" method manually
	void asPosition(Point p);
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event*);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event*);
	CREATE_FUNC(HelloWorld);
	
	//void setPhyWorld(PhysicsWorld* world);

private:
	//PhysicsWorld* m_world;
	
};

#endif // __HELLOWORLD_SCENE_H__
