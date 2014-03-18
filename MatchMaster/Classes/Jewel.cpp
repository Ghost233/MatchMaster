//
//  Jewel.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "Jewel.h"

Jewel::Jewel():x(-1), y(-1)
{
    
}

Jewel::~Jewel()
{
    
}

bool Jewel::init()
{
    return true;
}

bool Jewel::initWithJewelType(JewelType tempType)
{
    if (!this->init()) return false;
    type = tempType;
    return true;
}

void Jewel::destroyAnimation()
{
    auto action1 = FadeOut::create(0.5);
    auto action2 = ScaleBy::create(0.5, 1.5);
    auto action3 = Spawn::createWithTwoActions(action1, action2);
    auto action4 = CallFunc::create(CC_CALLBACK_0(Jewel::finalRemove, this));
    auto action5 = Sequence::createWithTwoActions(action3, action4);
    this->runAction(action5);
}

void Jewel::finalRemove()
{
    this->removeFromParentAndCleanup(true);
}

bool Jewel::fall(int targetX, int targetY)
{
    if (y == targetY) return false;
    float length = (y - targetY) * SPACEY;
    auto action1 = MoveBy::create(length / FALL_SPEED_PER_SECOND, Point(0, -length));
    y = targetY;
    this->runAction(action1);
    return true;
}
