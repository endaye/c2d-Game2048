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
    colorBack->setPosition(Point((GAME_SCREEN_WIDTH-tiledmapwidth)/2,
                                 (GAME_SCREEN_HEIGHT-tiledmapheight)/2));
    //std::cout<<colorBack->getAnchorPoint().x<<"  "<<colorBack->getAnchorPoint().y<<std::endl;
    this->addChild(colorBack);
    
    // 分数
    return true;
}
