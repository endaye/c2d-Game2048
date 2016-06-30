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
    colorBack = LayerColor::create(Color4B(170,170,170,255), tiledmapwidth, tiledmapheight);
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
    
    // 初始化逻辑网格数组
    for (int i = 0; i < GAME_ROWS; i++)
    {
        for (int j = 0; j < GAME_COLS; j++)
        {
            map[i][j] = 0;  // 空白
        }
    }
    
    // 初始化数字块
    newMovedTiled();
    
    // 触摸的处理
    auto event = EventListenerTouchOneByOne::create();
    event->onTouchBegan = [&](Touch * tou, Event * eve) {
        m_x = tou->getLocation().x;
        m_y = tou->getLocation().y;
        m_startMove = true;
        return true;
    };
    event->onTouchMoved = [&](Touch * tou, Event * eve) {
        int x = tou->getLocation().x;
        int y = tou->getLocation().y;
        if (m_startMove && (abs(m_x-x)>10 || abs(m_y-y)>10))
        {
            m_startMove = false;
            E_MOVE_DIR dir;
            if (abs(m_x-x)>abs(m_y-y))
            {
                // 左右移动
                if (m_x < x)
                {
                    dir = E_MOVE_DIR::RIGHT;
                }
                else
                {
                    dir = E_MOVE_DIR::LEFT;
                }
            }
            else
            {
                // 上下移动
                if (m_y < y)
                {
                    dir = E_MOVE_DIR::UP;
                }
                else
                {
                    dir = E_MOVE_DIR::DOWN;
                }
            }
            moveAllTiled(dir);  // 移动所有可移动的元素块
        }
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(event, this);
    // 分数
    return true;
}

void Game::moveAllTiled(E_MOVE_DIR dir)
{
    // 移动所有块，消除
    switch (dir) {
        case DOWN:
            moveDown();
            break;
        case UP:
            moveUp();
            break;
        case LEFT:
            moveLeft();
            break;
        case RIGHT:
            moveRight();
            break;
        default:
            break;
    }
    // 播放音乐
    // 判定输赢
    // 产生新块
    newMovedTiled();
}

// 产生新块
void Game::newMovedTiled()
{
    auto tiled = MovedTiled::create();
    int freeCount = 16 - (int)m_allTiled.size();     // 屏幕上有多少个空白块
    if (freeCount == 0)
    {
        return;     // 没有空白区，不产生
    }
    int num = rand() % freeCount;   // 在空白块中产生一个随机数
    int row = 0;
    int col = 0;
    int count = 0;
    for (; row < GAME_ROWS; row++)
    {
        bool find = false;
        for (; col < GAME_COLS; col++)
        {
            if ( map[row][col] == 0)
            {
                count++;    // 记录是空白块的数量
                if (count == num)
                {
                    find = true;
                    break;
                }
            }
        }
        if (find)
        {
            break;
        }
    }
    colorBack->addChild(tiled);
    tiled->moveTo(num / GAME_ROWS, num % GAME_COLS);
    m_allTiled.pushBack(tiled);
    map[num / GAME_ROWS][num % GAME_COLS] = (int)m_allTiled.getIndex(tiled) + 1;

}

void Game::moveUp()
{
    // 移动所有的块
    for (int col = 0; col < GAME_COLS; col++)
    {
        for (int row = GAME_ROWS - 1; row >= 0; row--)
        {
            if (map[row][col] > 0)
            {
                for (int row1 = row; row1 < GAME_ROWS - 1; row1++)
                {
                    if (map[row1+1][col] == 0)
                    {
                        map[row1+1][col] = map[row1][col];
                        map[row1][col] = 0;
                        m_allTiled.at((ssize_t)(map[row1+1][col]-1))->moveTo(row1+1, col);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}

void Game::moveDown()
{
    
}
void Game::moveLeft()
{
    
}
void Game::moveRight()
{
    
}
