//
//  PinkJewel.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "PinkJewel.h"

PinkJewel::PinkJewel()
{
    
}

PinkJewel::~PinkJewel()
{
    
}

PinkJewel* PinkJewel::create()
{
    PinkJewel* temp = new PinkJewel();
    temp->Sprite::initWithFile("pink.png");
    temp->initWithScoreColor(ScoreColorPink);
    temp->autorelease();
    return temp;
}

bool PinkJewel::init()
{
    return true;
}
