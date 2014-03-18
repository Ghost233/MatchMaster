//
//  YellowJewel.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "YellowJewel.h"

YellowJewel::YellowJewel()
{
    
}

YellowJewel::~YellowJewel()
{
    
}

YellowJewel* YellowJewel::create()
{
    YellowJewel* temp = new YellowJewel();
    temp->Sprite::initWithFile("yellow.png");
    temp->initWithScoreColor(ScoreColorYellow);
    temp->autorelease();
    return temp;
}

bool YellowJewel::init()
{
    return true;
}
