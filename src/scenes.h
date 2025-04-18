#ifndef scenes_h
#define scenes_h
#include "worldMap.h"
#include "task.h"
#include "tile.h"
#include "person.h"
#include "resource.h"
#include "gui.h"
#include "battle.h"

#include <ctime>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <inttypes.h>

class Scene
{
	public:
		Scene();
		virtual void handleEvent(sf::Event event)=0;
		virtual void renderFrame()=0;
	
};

class worldMapScene : virtual public Scene
{
	public:
		std::string selectedPersonString;
		std::string selectedTileString;
		std::string infoString;
		std::string inventoryString;
		sf::Font *font;
		sf::Text *infoOverlay;
		sf::Text *selectedPersonOverlay;
		sf::Text *selectedTileOverlay;
		sf::Text *inventoryOverlay;
		tile * hoveredTile;
		tile * selectedTile;

		person* selectedPerson;


		moveTask * taskToAdd;
		gui::ButtonPanel * buttonPanel;
		bool endingTurn;
		worldMap * map;
		sf::RenderWindow * window;
		sf::Vector2f size;

		worldMapScene(sf::RenderWindow * window, int mapWidth, int mapHeight, int numPersons);

		void handleEvent(sf::Event event);
		void renderFrame();

		tile * getTileAtMousePosition(worldMap map, sf::Vector2f size);		
		std::string getTileString(worldMap map, tile * currentTile);
		std::string getInfoString(worldMap map, tile * currentTile);
		std::string getSelectedTileString(worldMap map, tile * currentTile);
		std::string getSelectedPersonString(person * selectedPerson);
		std::string getInventoryString(person* selectedPerson);

		void endTurn(worldMap *map);
};

class BattleScene : Scene
{

private:

	sf::RenderWindow* m_window;

	std::shared_ptr<BattleCore> m_BattleCore;

public:

	BattleScene(sf::RenderWindow* window, person*, person*);

	void handleEvent(sf::Event);

	void renderFrame();
	void updateScene();
};

class menuScene : public Scene
{

private:
	gui::ButtonPanel * buttonPanel;
public:
	menuScene(sf::RenderWindow * window);
	void handleEvent(sf::Event);
	void renderFrame();

	sf::RenderWindow * window;
};


#endif