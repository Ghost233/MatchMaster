//
//  GameController.cpp
//  MatchMaster
//
//  Created by Ghost on 14-3-18.
//
//

#include "GameController.h"

#include "GameMapLayer.h"
#include "ScoreJewel.h"
#include "SpecialJewel.h"

#include "BlueJewel.h"
#include "PinkJewel.h"
#include "PurpleJewel.h"
#include "GreenJewel.h"
#include "YellowJewel.h"

GameController::GameController()
{
    
}

GameController::~GameController()
{
    
}

GameController* GameController::create()
{
    GameController* temp = new GameController();
    temp->init();
    temp->autorelease();
    return temp;
}

bool GameController::init()
{
    refreshing = true;
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    
    listener->onTouchBegan = CC_CALLBACK_2(GameController::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameController::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameController::onTouchEnded, this);
    
    _eventDispatcher->addEventListenerWithFixedPriority(listener, 1);
    
    return true;
}

void GameController::onEnter()
{
    Layer::onEnter();
    
    this->generator();
}

void GameController::generator()
{
    for (int i = 0; i < mapLayer->width; ++i)
    {
        for (int j = 0; j < mapLayer->height; ++j)
        {
            ScoreJewel* tempJewel = this->randomCreateScoreJewel();
            mapLayer->map[i][j] = tempJewel;
            
            tempJewel->x = i;
            tempJewel->y = j;
            tempJewel->setPosition(i * SPACEX + SPACEX / 2, j * SPACEY + SPACEY / 2 + mapLayer->height * SPACEY);
            tempJewel->runAction(MoveBy::create(0.5, Point(0, -mapLayer->height * SPACEY)));
        }
    }
    
    auto action1 = DelayTime::create(0.5);
//    auto action1 = MoveBy::create(0.5, Point(0, 0));
    auto action2 = CallFunc::create(CC_CALLBACK_0(GameController::crashFinish, this));
    auto action3 = Sequence::create(action1, action2, NULL);
    this->runAction(action3);
}

bool GameController::onTouchBegan(Touch *touch, Event *unused_event)
{
    if (refreshing) return false;
    
    destroyArray.clear();
    
    Point location = touch->getLocation();
    CCLOG("%f %f", location.x, location.y);
    location = this->convertToGameMap(location);
    CCLOG("%f %f", location.x, location.y);
    if (!this->isInTheGameMap(location)) return false;
    
    int x = location.x / SPACEX;
    int y = location.y / SPACEY;
    
    CCLOG("%d %d", x, y);
    
    Jewel* temp = mapLayer->map[x][y];
    
    switch (temp->type)
    {
        case TypeScoreJewel:
        {
            presentJewel = (ScoreJewel*) temp;
            destroyArray.push_back(presentJewel);
            break;
        }
            
        case TypeSpecialJewel:
        {
            return false;
        }
    }
    return true;
}

void GameController::onTouchMoved(Touch* touch, Event* event)
{
    Point location = touch->getLocation();
    CCLOG("%f %f", location.x, location.y);
    location = this->convertToGameMap(location);
    CCLOG("%f %f", location.x, location.y);
    if (!this->isInTheGameMap(location)) return;
    
    int x = location.x / SPACEX;
    int y = location.y / SPACEY;
    
    CCLOG("%d %d", x, y);
    
    if (this->combo((ScoreJewel*)mapLayer->map[x][y])) destroyArray.push_back(mapLayer->map[x][y]);
}

void GameController::onTouchEnded(Touch* touch, Event* event)
{
    Point location = touch->getLocation();
    CCLOG("%f %f", location.x, location.y);
    location = this->convertToGameMap(location);
    CCLOG("%f %f", location.x, location.y);
    if (!this->isInTheGameMap(location)) return;
    
    int x = location.x / SPACEX;
    int y = location.y / SPACEY;
    
    CCLOG("%d %d", x, y);
    
    if (this->combo((ScoreJewel*)mapLayer->map[x][y])) destroyArray.push_back(mapLayer->map[x][y]);
    
    this->crashJewel();
}

void GameController::setGameMapLayer(GameMapLayer* tempMapLayer)
{
    mapLayer = tempMapLayer;
}

Point GameController::convertToGameMap(Point location)
{
    location.x -= BLANKX;
    location.y -= BLANKY;
    
    return location;
}

bool GameController::isInTheGameMap(Point location)
{
    if (location.x < 0) return false;
    if (location.y < 0) return false;
    if (location.x > mapLayer->width * SPACEX) return false;
    if (location.y > mapLayer->height * SPACEY) return false;
    return true;
}

void GameController::crossBoom(SpecialJewel* jewel)
{
    
}

void GameController::diagonalBoom(SpecialJewel* jewel)
{
    
}

void GameController::lightingTheSame(SpecialJewel* jewel)
{
    
}

bool GameController::combo(ScoreJewel* jewel)
{
    int length = abs(jewel->x - presentJewel->x) + abs(jewel->y - presentJewel->y);
    if (length != 1) return false;
    if (jewel->color != presentJewel->color) return false;
    presentJewel = jewel;
    return true;
}

void GameController::crashJewel()
{
    if (destroyArray.size() < 3) return;
    for (int i = 0; i < destroyArray.size() ; ++i)
    {
        Jewel* temp = destroyArray[i];
        temp->destroyAnimation();
        mapLayer->map[temp->x][temp->y] = NULL;
    }
    refreshing = true;
    
    auto action1 = DelayTime::create(0.5);
    auto action2 = CallFunc::create(CC_CALLBACK_0(GameController::crashFinish, this));
    auto action3 = Sequence::createWithTwoActions(action1, action2);
    this->runAction(action3);
}

void GameController::crashFinish()
{
    float time = 0;
    for (int i = 0; i < mapLayer->width; ++i)
    {
        int k = 0;
        for (int j = 0; j < mapLayer->height; ++j)
        {
            if (mapLayer->map[i][j] != NULL)
            {
                if (mapLayer->map[i][j]->fall(i, k))
                {
                    mapLayer->map[i][k] = mapLayer->map[i][j];
                    mapLayer->map[i][j] = NULL;
                }
                ++k;
            }
        }
        if (k != mapLayer->height)
        {
            float delta = mapLayer->height - k;
            for (int j = k; j < mapLayer->height; ++j)
            {
                ScoreJewel* tempJewel = this->randomCreateScoreJewel();
                mapLayer->map[i][j] = tempJewel;
                
                float falltime = delta * SPACEX / FALL_SPEED_PER_SECOND;
                
                tempJewel->x = i;
                tempJewel->y = j;
                tempJewel->setPosition(i * SPACEX + SPACEX / 2, j * SPACEY + SPACEY / 2 + delta * SPACEY);
                tempJewel->runAction(MoveBy::create(falltime, Point(0, -delta * SPACEY)));
                time = time < falltime ? time : falltime;
            }
        }
    }
    auto action1 = DelayTime::create(time);
    auto action2 = CallFunc::create(CC_CALLBACK_0(GameController::refreshFinish, this));
    auto action3 = Sequence::createWithTwoActions(action1, action2);
    this->runAction(action3);
}

void GameController::refreshFinish()
{
    refreshing = false;
}

ScoreJewel* GameController::randomCreateScoreJewel()
{
    ScoreJewel* tempJewel;
    switch ((int)(CCRANDOM_0_1() * 5))
    {
        case 0:
        {
            tempJewel = BlueJewel::create();
            break;
        }
        case 1:
        {
            tempJewel = GreenJewel::create();
            break;
        }
            
        case 2:
        {
            tempJewel = PinkJewel::create();
            break;
        }
            
        case 3:
        {
            tempJewel = PurpleJewel::create();
            break;
        }
            
        case 4:
        {
            tempJewel = YellowJewel::create();
            break;
        }
    }
    
    mapLayer->addChild(tempJewel);
    
    return tempJewel;
}
