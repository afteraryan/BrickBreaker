#include<iostream>
#include<fstream>
#include <vector>
#include "Brick.h"
#include "Projectile.h"
#include "Platform.h"
#include "UI_Button.h"

#pragma once
class Game
{
	//Window
	int windowWidth = 1920, windowHeight = 1080;

	//Platform
	GLfloat PlatformUnit;
	float HitMultiplier = 1;

	


public:
	//Level
	enum Level { one, two, three };
	Level level;
	std::string levelStr;
	//Game State
	enum GameState { MainMenu, Gameplay, Win, Lose };
	GameState gamestate;
	std::vector <Brick> BrickVec;
	std::vector <Projectile> ProjectileVec;
	std::vector <Platform> PlatformVec;
	std::vector <UI_Button> ButtonVec;
	

	void startGameStateLevel(GameState GS, Level Lvl);
	void Update();
	void spawnBricks();
	
	int getWindowWidth();
	int getWindowHeight();

	//Collision Functions
	void Collision();
	void GameplayCollision();
	void MainMenuCollision();
	void WinCollision();
	void LoseCollision();

	//Display Functions
	void display();
	void GameplayDisplay();
	void MainMenuDisplay();
	void WinDisplay();
	void LoseDisplay();

	//Callback Functions
	void mouse_callback(int button, int state, int x, int y);

};

