//
//  BlueJewel.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "BlueJewel.h"

BlueJewel::BlueJewel()
{
    
}

BlueJewel::~BlueJewel()
{
    
}

BlueJewel* BlueJewel::create()
{
    BlueJewel* temp = new BlueJewel();
    temp->Sprite::initWithFile("blue.png");
    temp->initWithScoreColor(ScoreColorBlue);
    temp->autorelease();
    return temp;
}

bool BlueJewel::init()
{
    return true;
}
