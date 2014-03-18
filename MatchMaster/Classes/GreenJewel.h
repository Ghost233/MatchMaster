//
//  GreenJewel.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__GreenJewel__
#define __MatchMaster__GreenJewel__

#include "GJewel.h"

#include "ScoreJewel.h"

class GreenJewel : public ScoreJewel
{
public:
    GreenJewel();
    virtual ~GreenJewel();
    
    static GreenJewel* create();
    bool init();
};

#endif /* defined(__MatchMaster__GreenJewel__) */
