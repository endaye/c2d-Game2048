//
//  SplashScene.hpp
//  Game2048
//
//  Created by Yuancheng Zhang on 6/27/16.
//
//  一个三秒的国度画面

#ifndef SplashScene_hpp
#define SplashScene_hpp

#include "cocos2d.h"
#include <iostream>
#include "gamedefine.hpp"

USING_NS_CC;

class Splash:Layer
{
    bool init();
public:
    CREATE_FUNC(Splash);
    static Scene * createScene();
};

#endif /* SplashScene_hpp */
