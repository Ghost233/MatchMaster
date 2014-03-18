//
//  PinkJewel.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__PinkJewel__
#define __MatchMaster__PinkJewel__

#include "GJewel.h"

#include "ScoreJewel.h"

class PinkJewel : public ScoreJewel
{
public:
    PinkJewel();
    virtual ~PinkJewel();
    
    static PinkJewel* create();
    bool init();
};

#endif /* defined(__MatchMaster__PinkJewel__) */
