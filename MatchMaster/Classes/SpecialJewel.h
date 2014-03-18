//
//  SpecialJewel.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__SpecialJewel__
#define __MatchMaster__SpecialJewel__

#include "GJewel.h"

#include "Jewel.h"

typedef enum
{
    CrossBoom,
    DiagonalBoom,
    LightingTheSame,
}SpecialFunction;

class SpecialJewel : public Jewel
{
public:
    SpecialFunction function;
    
    SpecialJewel();
    virtual ~SpecialJewel();
    
    bool initWithFunction(SpecialFunction tempFunction);
    
    virtual void destroyAnimation() = 0;
};

#endif /* defined(__MatchMaster__SpecialJewel__) */
