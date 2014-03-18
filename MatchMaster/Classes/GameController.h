//
//  GameController.h
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#ifndef __MatchMaster__GameController__
#define __MatchMaster__GameController__

#include "GJewel.h"

class GameMapLayer;
class SpecialJewel;
class ScoreJewel;
class Jewel;

class GameController : public Layer
{
    GameMapLayer* mapLayer;
    
    vector<Jewel*> destroyArray;
    ScoreJewel* presentJewel;
    
    bool refreshing;
    
public:
    GameController();
    virtual ~GameController();
    
    static GameController* create();
    
    bool init();
    
    virtual void onEnter();

    void generator();
    
    virtual bool onTouchBegan(Touch *touch, Event *unused_event);
    virtual void onTouchMoved(Touch *touch, Event *unused_event);
    virtual void onTouchEnded(Touch *touch, Event *unused_event);
    
    void setGameMapLayer(GameMapLayer* tempMapLayer);
    
    Point convertToGameMap(Point location);
    bool isInTheGameMap(Point location);
    
    void crossBoom(SpecialJewel* jewel);
    void diagonalBoom(SpecialJewel* jewel);
    void lightingTheSame(SpecialJewel* jewel);
    
    bool combo(ScoreJewel* jewel);
    
    void crashJewel();
    void crashFinish();
    void refreshFinish();
    
    ScoreJewel* randomCreateScoreJewel();
};

#endif /* defined(__MatchMaster__GameController__) */
