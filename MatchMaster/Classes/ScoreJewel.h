//
//  ScoreJewel.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__ScoreJewel__
#define __MatchMaster__ScoreJewel__

#include "GJewel.h"

#include "Jewel.h"

typedef enum
{
    ScoreColorBlue,
    ScoreColorGreen,
    ScoreColorPink,
    ScoreColorYellow,
    ScoreColorPurple,
}ScoreColor;

class ScoreJewel : public Jewel
{
public:
    ScoreColor color;
    bool isCombo;
    
    ScoreJewel();
    virtual ~ScoreJewel();
    
    bool initWithScoreColor(ScoreColor tempColor);
};

#endif /* defined(__MatchMaster__ScoreJewel__) */
