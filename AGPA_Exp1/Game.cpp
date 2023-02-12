#include <iostream>
#include <fstream>
#include "Game.h"

using namespace std;

void Game::startGameStateLevel(GameState GS, Level Lvl)
{
	//Level
	level = Lvl;
	//Game State
	gamestate = GS;

	switch (gamestate)
	{
		case Game::MainMenu:
		{
			UI_Button btn_temp(900, 500, 25, 100, "btn_Play");
			btn_temp.setColor(0, 0, 1);
			ButtonVec.push_back(btn_temp);
			UI_Button btn_temp2(900, 400, 25, 100, "btn_Exit");
			btn_temp2.setColor(1, 0, 0);
			ButtonVec.push_back(btn_temp2);
			break;
		}
		case Game::Gameplay:
		{
			//Spawn Bricks
			spawnBricks();

			//Spawn Projectile
			Projectile P(947.5, 50);
			ProjectileVec.push_back(P);

			//Spawn Platform
			Platform Pl(960, 25);
			Pl.setDimentions(25, 200);
			Pl.setOrigin(960 - Pl.getWidth() / 2, 26);
			Pl.setColor(1, 0, 0);
			PlatformVec.push_back(Pl);
			break;
		}
		case Game::Win:
		{

			break;
		}
		case Game::Lose:
		{

			break;
		}
		default:
			break;
	}
	


}

void Game::Update()
{
	Collision();
	switch (gamestate)
	{
		case Gameplay: 
		{
			ProjectileVec[0].Move(Location(ProjectileVec[0].getVelocity().x, ProjectileVec[0].getVelocity().y));
			PlatformVec[0].Move(Location(PlatformVec[0].getVelocity().x, PlatformVec[0].getVelocity().y));
			break;
		}
		default:
			break;
	}
}



void Game::spawnBricks()
{
	
	switch (level)
	{
		case one:
		{
			levelStr = "Level_One.txt";
			break;
		}
		case two:
		{
			levelStr = "Level_Two.txt";
			break;
		}
		case three:
		{
			levelStr = "Level_Three.txt";
			break;
		}
		default:
		{
			ifstream MyReadFile("file.txt");
			break;
		}
	}
	ifstream MyReadFile(levelStr);

    // Use a while loop together with the getline() function to read the file line by line
	
	string str;
	int hCounter = 1, wMargin = 5, hMargin = 5;
	Brick B(0, 1080, '1');
	B.setColor(0, 1, 1);
	BrickVec.push_back(B);
    while (getline(MyReadFile, str))
    {
        // Output the text from the file
		
        for (int i = 0; i < str.size(); i++)
        {
            switch (str[i])
            {
				case '1':
				{
					Brick B(0, 1080, '1');
					B.setColor(0, 1, 1);
					B.setOrigin(0 + (B.getWidth() + wMargin) * i, 1080 - (B.getHeight() + hMargin) * (hCounter));
					BrickVec.push_back(B);
					break;
				}
				case '2':
				{
					Brick B(0, 1080, '2');
					B.setColor(0, 0.7, 1);
					B.setOrigin(0 + (B.getWidth() + wMargin) * i, 1080 - (B.getHeight() + hMargin) * (hCounter));
					BrickVec.push_back(B);
					break;
				}
				case '3':
				{
					Brick B(0, 1080, '3');
					B.setColor(0.5, 0.7, 1);
					B.setOrigin(0 + (B.getWidth() + wMargin) * i, 1080 - (B.getHeight() + hMargin) * (hCounter));
					BrickVec.push_back(B);
					break;
				}
				case '4':
				{
					Brick B(0, 1080, '4');
					B.setColor(0, 1, 0);
					B.setOrigin(0 + (B.getWidth() + wMargin) * i, 1080 - (B.getHeight() + hMargin) * (hCounter));
					BrickVec.push_back(B);
					break;
				}
				case '5':
				{
					Brick B(0, 1080, '5');
					B.setColor(1, 0, 0);
					B.setOrigin(0 + (B.getWidth() + wMargin) * i, 1080 - (B.getHeight() + hMargin) * (hCounter));
					BrickVec.push_back(B);
					break;
				}
				default:
					break;
            }
        }
		hCounter++;

    }

    // Close the file
    MyReadFile.close();
}

int Game::getWindowWidth()
{
	return windowWidth;
}

int Game::getWindowHeight()
{
	return windowHeight;
}




//Display Functions
void Game::display()
{
	switch (gamestate)
	{
		case Gameplay:
		{
			GameplayDisplay();
			break;
		}
		case MainMenu:
		{
			MainMenuDisplay();
			break;
		}
		case Win:
		{
			WinDisplay();
			break;
		}
		case Lose:
		{
			LoseDisplay();
			break;
		}
		default:
			break;
	}
}
void Game::GameplayDisplay()
{
	for (int i = 0; i < BrickVec.size(); i++)
	{
		BrickVec[i].drawPolygon(BrickVec[i].getLocation());
	}

	ProjectileVec[0].drawPolygon(ProjectileVec[0].getLocation());
	PlatformVec[0].drawPolygon(PlatformVec[0].getLocation());
}

void Game::MainMenuDisplay()
{
	for (int i = 0; i < ButtonVec.size(); i++)
	{
		ButtonVec[i].drawPolygon(ButtonVec[i].getLocation());
	}
}

void Game::WinDisplay()
{
	//Text Frame Counter
	glColor3f(1.0, 0, 0.0);
	glRasterPos2f(900, 540); //define position on the screen
	string t = "You Win!";
	char* strName = (char*)(t.c_str());
	for (int i = 0; i < (int)strlen(strName); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, strName[i]);
	}
}

void Game::LoseDisplay()
{
	//Text Frame Counter
	glColor3f(1.0, 0, 0.0);
	glRasterPos2f(900, 540); //define position on the screen
	string t = "Game Over";
	char* strName = (char*)(t.c_str());
	for (int i = 0; i < (int)strlen(strName); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, strName[i]);
	}
}

void Game::mouse_callback(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		
		switch (gamestate)
		{
			case Game::MainMenu:
			{
				
				for (int i = 0; i < ButtonVec.size()-1; i++)
				{
					
					if (ButtonVec[i].isClicked(x,y, ButtonVec[i].getLocation()))
					{
						std::cout << "Click\n";
						if (ButtonVec[i].getName() == "btn_Play")
							startGameStateLevel(Gameplay, one);
						else if (ButtonVec[i].getName() == "btn_Exit")
							glutDestroyWindow(1);
					}
				}
				break;
			}
			case Game::Gameplay:
			{

				break;
			}
			case Game::Win:
			{

				break;
			}
			case Game::Lose:
			{

				break;
			}
			default:
				break;
		}
	}
}















//Collision Functions
void Game::Collision()
{
	switch (gamestate)
	{
		case Gameplay:
		{
			GameplayCollision();
			break;
		}
		case MainMenu:
		{
			MainMenuCollision();
			break;
		}
		case Win:
		{
			WinCollision();
			break;
		}
		case Lose:
		{
			LoseCollision();
			break;
		}
		default:
			break;
	}
}
void Game::GameplayCollision()
{
	Location Projectile_MidLoc = Location(ProjectileVec[0].getLocation().x + ProjectileVec[0].getWidth() / 2, ProjectileVec[0].getLocation().y + ProjectileVec[0].getHeight() / 2);
	Location Platform_MidLoc = Location(PlatformVec[0].getLocation().x + PlatformVec[0].getWidth() / 2, PlatformVec[0].getLocation().y + PlatformVec[0].getHeight() / 2);
	Location Playform_Origin = Location(PlatformVec[0].getLocation());

	//Collision with Bricks
	for (int i = 0; i < BrickVec.size(); i++)
	{
		if (BrickVec[i].CollisionCheck(&ProjectileVec[0]) == true)
		{

			if ((ProjectileVec[0].getLocation().x + ProjectileVec[0].getWidth() >= BrickVec[i].getLocation().x) && ProjectileVec[0].getLocation().x <= BrickVec[i].getLocation().x + BrickVec[i].getWidth())
			{
				ProjectileVec[0].setVelocity(ProjectileVec[0].getVelocity().x, -1 * ProjectileVec[0].getVelocity().y);
				std::cout << "X Collision\n";
				BrickVec[i].ability(&PlatformVec[0]);
				BrickVec[i].destroy();
				break;
			}
			else if ((ProjectileVec[0].getLocation().y + ProjectileVec[0].getHeight() >= BrickVec[i].getLocation().y) && ProjectileVec[0].getLocation().y <= BrickVec[i].getLocation().y + BrickVec[i].getHeight())
			{
				ProjectileVec[0].setVelocity(-1 * ProjectileVec[0].getVelocity().x, ProjectileVec[0].getVelocity().y);
				std::cout << "Y Collision\n";
				BrickVec[i].ability(&PlatformVec[0]);
				BrickVec[i].destroy();
				break;
			}
			
			ProjectileVec[0].setVelocity(-1 * ProjectileVec[0].getVelocity().x, -1 * ProjectileVec[0].getVelocity().y);
			std::cout << "Vertex Collision\n";
			std::cout << ProjectileVec[0].getLocation().x << " + " << ProjectileVec[0].getWidth() << " > " << BrickVec[i].getLocation().x << " && " << ProjectileVec[0].getLocation().x << " < " << BrickVec[i].getLocation().x << " + " << BrickVec[i].getWidth() << std::endl;
			
			BrickVec[i].ability(&PlatformVec[0]);
			BrickVec[i].destroy();
		}
	}

	//Collision with Platform
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	if (PlatformVec[0].getVelocity().x > 0)
		HitMultiplier = 1.5;
	else if (PlatformVec[0].getVelocity().x == 0)
		HitMultiplier = 1;
	if (PlatformVec[0].CollisionCheck(&ProjectileVec[0]) == true)
	{
		PlatformUnit = PlatformVec[0].getWidth() / 5;

		//Mid
		if (Projectile_MidLoc.x >= Playform_Origin.x + PlatformUnit * 2 && Projectile_MidLoc.x <= Playform_Origin.x + PlatformUnit * 3)
			ProjectileVec[0].setVelocity(6 * HitMultiplier + r*4, 5.5 * HitMultiplier + r * 2);

		//Between Mid and Edges
		if (Projectile_MidLoc.x >= Playform_Origin.x + PlatformUnit * 1 && Projectile_MidLoc.x < Playform_Origin.x + PlatformUnit * 2)
			ProjectileVec[0].setVelocity(-5.5 * HitMultiplier + r, 5.5 * HitMultiplier);

		if (Projectile_MidLoc.x > Playform_Origin.x + PlatformUnit * 3 && Projectile_MidLoc.x <= Playform_Origin.x + PlatformUnit * 4)
			ProjectileVec[0].setVelocity(5.5 * HitMultiplier + r*3, 5.5 * HitMultiplier);

		//Edges
		if (Projectile_MidLoc.x >= Playform_Origin.x + PlatformUnit * 0 && Projectile_MidLoc.x < Playform_Origin.x + PlatformUnit * 1)
			ProjectileVec[0].setVelocity(-6 * HitMultiplier + r, 6 * HitMultiplier + r*2);

		if (Projectile_MidLoc.x > Playform_Origin.x + PlatformUnit * 4 && Projectile_MidLoc.x <= Playform_Origin.x + PlatformUnit * 5)
			ProjectileVec[0].setVelocity(6 * HitMultiplier + r, 6 * HitMultiplier + r * 2);
	}

	//Projectile Collision with Bounds
	if (Projectile_MidLoc.x <= 0 || Projectile_MidLoc.x >= getWindowWidth())
	{
		ProjectileVec[0].setVelocity(ProjectileVec[0].getVelocity().x * -1, ProjectileVec[0].getVelocity().y);
	}
	else if (Projectile_MidLoc.y >= getWindowHeight())
	{
		ProjectileVec[0].setVelocity(ProjectileVec[0].getVelocity().x, ProjectileVec[0].getVelocity().y * -1);
	}
	else if (Projectile_MidLoc.y <= 0)
	{
		gamestate = Lose;
	}

	//Platform Collision with Boundaries
	if (PlatformVec[0].getLocation().x < 0)
	{
		PlatformVec[0].setVelocity(0, 0);
		PlatformVec[0].setLocation(1, PlatformVec[0].getLocation().y);
	}
	else if (PlatformVec[0].getLocation().x + PlatformVec[0].getWidth() > 1920)
	{
		PlatformVec[0].setVelocity(0, 0);
		PlatformVec[0].setLocation(1920 - PlatformVec[0].getWidth(), PlatformVec[0].getLocation().y);
	}
}

void Game::MainMenuCollision()
{

}

void Game::WinCollision()
{

}

void Game::LoseCollision()
{

}

