//
//  PurpleJewel.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__PurpleJewel__
#define __MatchMaster__PurpleJewel__

#include "GJewel.h"

#include "ScoreJewel.h"

class PurpleJewel : public ScoreJewel
{
public:
    PurpleJewel();
    virtual ~PurpleJewel();
    
    static PurpleJewel* create();
    bool init();
};

#endif /* defined(__MatchMaster__PurpleJewel__) */
