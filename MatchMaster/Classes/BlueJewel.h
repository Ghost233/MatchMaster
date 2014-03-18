//
//  BlueJewel.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__BlueJewel__
#define __MatchMaster__BlueJewel__

#include "GJewel.h"

#include "ScoreJewel.h"

class BlueJewel : public ScoreJewel
{
public:
    BlueJewel();
    virtual ~BlueJewel();
    
    static BlueJewel* create();
    bool init();
};

#endif /* defined(__MatchMaster__BlueJewel__) */
