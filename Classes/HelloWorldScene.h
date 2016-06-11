#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC_EXT;

class HelloWorld : public cocos2d::Layer, public EditBoxDelegate
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
	void makeToDo(int margin);

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	protected:
		virtual void editBoxReturn(EditBox* editBox);
};

#endif // __HELLOWORLD_SCENE_H__
