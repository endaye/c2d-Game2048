//
//  MovedTiled.cpp
//  Game2048
//
//  Created by Yuancheng Zhang on 6/29/16.
//
//

#include "MovedTiled.hpp"

// 在某个位置显示这个块
void MovedTiled::showAt(int r, int c)
{
    
}

// 移动模块到r行c列
void MovedTiled::moveTo(int r, int c)
{
    this->m_row = r;
    this->m_col = c;
    this->setPosition(Vec2(GAME_TILED_WIDTH  * c + GAME_TILED_BOARD_WIDTH * (c + 1),
                           GAME_TILED_HEIGHT * r + GAME_TILED_BOARD_WIDTH * (r + 1)));
}

bool MovedTiled::init()
{
    if (!Node::init())
    {
        return false;
    }
    // 背景层
    auto bk = LayerColor::create(Color4B(200, 200, 200, 255),
                                 GAME_TILED_WIDTH,
                                 GAME_TILED_HEIGHT);
    this->addChild(bk);
    // 数字层
    int n = rand() % 10;
    this->m_number = n > 0 ? 2 : 4;
    auto label = Label::create();
    label->setString(StringUtils::format("%d", this->m_number));
    label->setScale(3.0f);
    label->setColor(Color3B::BLACK);
    bk->addChild(label);
    label->setPosition(Vec2(GAME_TILED_WIDTH / 2,
                            GAME_TILED_HEIGHT / 2));
    return true;
}