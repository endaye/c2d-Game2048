//
//  MovedTiled.hpp
//  Game2048
//
//  Created by Yuancheng Zhang on 6/29/16.
//
//

#ifndef MovedTiled_hpp
#define MovedTiled_hpp

#include "cocos2d.h"
#include "gamedefine.hpp"

USING_NS_CC;

class MovedTiled : public Node
{
public:
    int m_row;
    int m_col;
    int m_number;
    void showAt(int r, int c);  // 在某个位置显示这个块
    void moveTo(int r, int c);  // 移动模块到r行c列
    CREATE_FUNC(MovedTiled);
    bool init();
    
};

#endif /* MovedTiled_hpp */
