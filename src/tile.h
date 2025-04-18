#ifndef TILE_H
#define TILE_H
#include "item.h"
#include <SFML/Graphics.hpp>
#include <vector>
class worldMap;
class tile;

class locatable
{
public:
    int xPos;
    int yPos;
    worldMap* attachedMap;
    tile* getTile();
};

class person;  // Forward declaration
class structure : public locatable
{
public:
    sf::Color color;
    structure();
    structure(sf::Color color);

    virtual void processTurn()=0;
};

class mainCity : public structure
{
    public:
        void processTurn() override;
        mainCity(sf::Color color);
};

class tile : public locatable{
public:
    float elevation;
    float waterLevel;
    person* personHere;
    structure * structureHere;
    std::vector<float> resourceQuantity;
    std::vector<item *> itemsOnGround;
    tile();
    tile(int x, int y, worldMap * attachedMap);
    tile(int x, int y, worldMap* attachedMap, float elevation, float waterLevel, person* personHere);
    float waterDepth();
};

#endif