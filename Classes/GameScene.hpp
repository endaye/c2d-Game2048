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
private:
    bool m_startMove;   // 是否开始触摸移动
    int m_x, m_y;       // 触摸开始的点
    LayerColor * colorBack;
    
public:
    E_MOVE_DIR m_dir;   // 移动方向
    int map[GAME_ROWS][GAME_COLS];      // 左下角为[0][0]，右上角为[3][3]
    Vector<MovedTiled *> m_allTiled;    // 保存所有块
    
    void moveAllTiled(E_MOVE_DIR dir);  // 移动所有的块
    void newMovedTiled();   // 产生新块
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    static Scene * createScene();
    CREATE_FUNC(Game);
    bool init();
};

#endif /* GameScene_hpp */
