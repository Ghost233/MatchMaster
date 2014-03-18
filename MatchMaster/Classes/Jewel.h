//
//  Jewel.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__Jewel__
#define __MatchMaster__Jewel__

#include "GJewel.h"

typedef enum
{
    TypeScoreJewel,
    TypeSpecialJewel,
}JewelType;

class Jewel : public Sprite
{
public:
    JewelType type;
    int x;
    int y;
    
    Jewel();
    virtual ~Jewel();
    
    virtual bool init();
    virtual bool initWithJewelType(JewelType tempType);
    
    virtual void destroyAnimation();
    
    virtual void finalRemove();
    
    virtual bool fall(int targetX, int targetY);
};

#endif /* defined(__MatchMaster__Jewel__) */
