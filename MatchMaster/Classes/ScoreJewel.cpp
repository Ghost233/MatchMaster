//
//  ScoreJewel.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "ScoreJewel.h"

ScoreJewel::ScoreJewel():isCombo(false)
{
    
}

ScoreJewel::~ScoreJewel()
{
    
}

bool ScoreJewel::initWithScoreColor(ScoreColor tempColor)
{
    if (!Jewel::initWithJewelType(TypeScoreJewel)) return false;
    color = tempColor;
    return true;
}
