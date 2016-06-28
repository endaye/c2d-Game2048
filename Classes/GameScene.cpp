//
//  GameScene.cpp
//  Game2048
//
//  Created by Yuancheng Zhang on 6/27/16.
//
//

#include "GameScene.hpp"

Scene* Game::createScene()
{
    auto scene = Scene::create();
    auto layer = Game::create();
    scene->addChild(layer);
    return scene;
}

bool Game::init()
{
    if(!Layer::init())
    {
        return false;
    }
    // 初始化游戏标题
    auto labelGame = Label::createWithBMFont("fonts/futura-48.fnt", "2048");
    //labelGame->setPosition(Point(labelGame->getContentSize().width/2,GAME_SCREEN_HEIGHT-labelGame->getContentSize().height/2));
    float x = labelGame->getContentSize().width/2 + 30.0f;
    float y = GAME_SCREEN_HEIGHT - labelGame->getContentSize().height/2;
    labelGame->setPosition(Point(x, y));
    std::cout<<x<<"  "<<y<<std::endl;
    this->addChild(labelGame);
    labelGame->setScale(1.5f);
    // 初始化游戏网格
    // 分数
    return true;
}
