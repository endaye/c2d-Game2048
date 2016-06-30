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
    float x = labelGame->getContentSize().width/2 + 30.0f;
    float y = GAME_SCREEN_HEIGHT - labelGame->getContentSize().height/2;
    labelGame->setPosition(Point(x, y));
    std::cout<<x<<"  "<<y<<std::endl;
    this->addChild(labelGame);
    labelGame->setScale(1.5f);
    
    // 初始化游戏网格
    int tiledmapwidth = GAME_TILED_WIDTH * GAME_COLS + GAME_TILED_BOARD_WIDTH * (GAME_COLS + 1);
    int tiledmapheight = GAME_TILED_HEIGHT * GAME_ROWS + GAME_TILED_BOARD_WIDTH * (GAME_ROWS + 1);
    auto colorBack = LayerColor::create(Color4B(170,170,170,255), tiledmapwidth, tiledmapheight);
    colorBack->setPosition(Point((GAME_SCREEN_WIDTH  - tiledmapwidth)  / 2,
                                 (GAME_SCREEN_HEIGHT - tiledmapheight) / 2));
    this->addChild(colorBack);
    
    // 初始化网格的每一块
    for (int row = 0; row < GAME_ROWS; row++)
    {
        for (int col = 0; col < GAME_COLS; col++)
        {
            auto layerTiled = LayerColor::create(Color4B(70, 70, 70, 255),
                                                 GAME_TILED_WIDTH,
                                                 GAME_TILED_HEIGHT);
            layerTiled->setPosition(Vec2(GAME_TILED_WIDTH  * col + GAME_TILED_BOARD_WIDTH * (col + 1),
                                         GAME_TILED_HEIGHT * row + GAME_TILED_BOARD_WIDTH * (row + 1)));
            colorBack->addChild(layerTiled);
        }
    }
    
    // 初始化数字块
    auto tiled = MovedTiled::create();
    int num = rand() % (GAME_ROWS * GAME_COLS);
    colorBack->addChild(tiled);
    tiled->moveTo(num / GAME_ROWS,  num % GAME_COLS);
    
    // 分数
    return true;
}
