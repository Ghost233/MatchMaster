//
//  GameScene.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "GameScene.h"

#include "GameMapLayer.h"
#include "GameController.h"

GameScene::GameScene()
{
    
}

GameScene::~GameScene()
{
    
}

GameScene* GameScene::create()
{
    GameScene* temp = new GameScene();
    temp->init();
    temp->autorelease();
    return temp;
}

bool GameScene::init()
{
    n = MAPN;
    m = MAPM;
    
    mapLayer = GameMapLayer::create(n, m);
    mapLayer->setPosition(BLANKX, BLANKY);
    
    this->addChild(mapLayer);
    
    controller = GameController::create();
    controller->setGameMapLayer(mapLayer);
    this->addChild(controller);
    
    return true;
}
