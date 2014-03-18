//
//  SpecialJewel.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "SpecialJewel.h"

SpecialJewel::SpecialJewel()
{
    
}

SpecialJewel::~SpecialJewel()
{
    
}

bool SpecialJewel::initWithFunction(SpecialFunction tempFunction)
{
    if (!Jewel::initWithJewelType(TypeSpecialJewel)) return false;
    function = tempFunction;
    return true;
}
