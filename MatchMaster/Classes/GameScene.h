//
//  GameScene.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__GameScene__
#define __MatchMaster__GameScene__

#include "GJewel.h"

class GameMapLayer;
class GameController;

class GameScene : public Scene
{
    int n;
    int m;
    
    GameMapLayer* mapLayer;
    GameController* controller;
    
public:
    GameScene();
    virtual ~GameScene();
    
    static GameScene* create();
    
    virtual bool init();
};

#endif /* defined(__MatchMaster__GameScene__) */
