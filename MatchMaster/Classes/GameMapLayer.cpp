//
//  GameMapLayer.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "GameMapLayer.h"

GameMapLayer::GameMapLayer()
{
    
}

GameMapLayer::~GameMapLayer()
{
    
}

GameMapLayer* GameMapLayer::create(int n, int m)
{
    GameMapLayer* temp = new GameMapLayer();
    temp->init(n, m);
    temp->autorelease();
    return temp;
}

bool GameMapLayer::init(int n, int m)
{
    width = n;
    height = m;
    for (int i = 0; i < width; ++i)
    {
        vector<Jewel*> temp;
        for (int j = 0; j < height; ++j)
        {
            temp.push_back(NULL);
        }
        map.push_back(temp);
    }
    
    return true;
}
