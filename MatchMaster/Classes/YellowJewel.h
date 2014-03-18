//
//  YellowJewel.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__YellowJewel__
#define __MatchMaster__YellowJewel__

#include "GJewel.h"

#include "ScoreJewel.h"

class YellowJewel : public ScoreJewel
{
public:
    YellowJewel();
    virtual ~YellowJewel();
    
    static YellowJewel* create();
    bool init();
};

#endif /* defined(__MatchMaster__YellowJewel__) */
