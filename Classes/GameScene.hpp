//
//  GameScene.hpp
//  Game2048
//
//  Created by Yuancheng Zhang on 6/27/16.
//
//  游戏画面

#ifndef GameScene_hpp
#define GameScene_hpp

#include <iostream>
#include "cocos2d.h"
#include "gamedefine.hpp"
#include "MovedTiled.hpp"

USING_NS_CC;

class Game : Layer
{
public:
    static Scene * createScene();
    CREATE_FUNC(Game);
    bool init();
};

#endif /* GameScene_hpp */
