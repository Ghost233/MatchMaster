//
//  GreenJewel.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "GreenJewel.h"

GreenJewel::GreenJewel()
{
    
}

GreenJewel::~GreenJewel()
{
    
}

GreenJewel* GreenJewel::create()
{
    GreenJewel* temp = new GreenJewel();
    temp->Sprite::initWithFile("green.png");
    temp->initWithScoreColor(ScoreColorGreen);
    temp->autorelease();
    return temp;
}

bool GreenJewel::init()
{
    return true;
}
