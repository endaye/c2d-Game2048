//
//  SplashScene.cpp
//  Game2048
//
//  Created by Yuancheng Zhang on 6/27/16.
//
//

#include "SplashScene.hpp"

bool Splash::init()
{
    // 父类Layer的初始化
    if(!Layer::init())
    {
        return false;
    }
    // 显示游戏名称
    auto labelGame = Label::createWithBMFont("fonts/futura-48.fnt", "2048");
    labelGame->setPosition(Point(GAME_SCREEN_WIDTH/2, GAME_SCREEN_HEIGHT/2));
    this->addChild(labelGame);
    labelGame->setScale(1.5f);
    // 显示制作单位
    auto labelGameVec = Label::createWithBMFont("fonts/futura-48.fnt", "by endaye 2016.6.27");
    labelGameVec->setPosition(Point(GAME_SCREEN_WIDTH/2, GAME_SCREEN_HEIGHT/4));
    this->addChild(labelGameVec);
    labelGameVec->setScale(0.8f);
    return true;
}

Scene * Splash::createScene()
{
    // auto是C++11的关键字，auto关键字用于两种情况：
    // 声明变量时根据初始化表达式自动推断该变量的类型
    // 声明函数时函数返回值的占位符
    auto scene = Scene::create();
    auto layer = Splash::create();
    scene->addChild(layer);
    return scene;
}
