#include "HelloWorldScene.h"

USING_NS_CC;
USING_NS_CC_EXT;

Size visibleSize;
Vec2 origin;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

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

	makeToDo(30);
	makeToDo(30 + 100 + 30);
	makeToDo(30 + 100 + 30 + 100 + 30);
	makeToDo(30 + 100 + 30 + 100 + 30 + 100 + 30);
	makeToDo(30 + 100 + 30 + 100 + 30 + 100 + 30 + 100 + 30);

    return true;
}

void HelloWorld::makeToDo(int margin) {
	auto editbox = EditBox::create(Size(500, 100), Scale9Sprite::create("green_edit.png"));
	editbox->setAnchorPoint(Point(0.5, 0));
	editbox->setPosition(Vec2(origin.x + visibleSize.width / 2, margin));
	editbox->setDelegate(this);
	editbox->setFontSize(30);
	this->addChild(editbox);
}

void HelloWorld::editBoxReturn(EditBox * editBox) {
	CCLOG("end");
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
