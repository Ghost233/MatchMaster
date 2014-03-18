//
//  GameMapLayer.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__GameMapLayer__
#define __MatchMaster__GameMapLayer__

#include "GJewel.h"

#include "Jewel.h"

class GameMapLayer : public Layer
{
public:
    GameMapLayer();
    virtual ~GameMapLayer();
    
    static GameMapLayer* create(int n, int m);
    
    virtual bool init(int n, int m);
    
    vector<vector<Jewel*> > map;
    int width, height;
};

#endif /* defined(__MatchMaster__GameMapLayer__) */
