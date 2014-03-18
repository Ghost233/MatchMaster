//
//  PurpleJewel.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "PurpleJewel.h"

PurpleJewel::PurpleJewel()
{
    
}

PurpleJewel::~PurpleJewel()
{
    
}

PurpleJewel* PurpleJewel::create()
{
    PurpleJewel* temp = new PurpleJewel();
    temp->Sprite::initWithFile("purple.png");
    temp->initWithScoreColor(ScoreColorPurple);
    temp->autorelease();
    return temp;
}

bool PurpleJewel::init()
{
    return true;
}
