#include<gl/glut.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<time.h>
#include "Brick.h"
#include "Game.h"

using namespace std;
Game game;
Game* gamePtr = &game;

int FrameCounter = 0;


void init(void)
{
	gluOrtho2D(0,game.getWindowWidth(), 0, game.getWindowHeight());
}

void mouse_callback(int button, int state, int x, int y) 
{
	cout << x << "," << game.getWindowHeight() - y << "\n";
	game.mouse_callback(button, state, x, game.getWindowHeight()-y);
}

void keyUp(unsigned char key, int x, int y)
{
	if (key == 'a')
		game.PlatformVec[0].setVelocity(0, 0);

	if (key == 'd')
		game.PlatformVec[0].setVelocity(0, 0);
}

void keypress(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		game.PlatformVec[0].setVelocity(-15, 0);
	}

	if (key == 'd')
	{
		game.PlatformVec[0].setVelocity(15, 0);
	}

	if (key == 'k')
	{
		glutDestroyWindow(1);
	}
}

void Start()
{
	game.startGameStateLevel(Game::Gameplay, Game::one);
}

void Update(int id)
{
	game.Update();
	glutPostRedisplay();
	glutTimerFunc(16.67, Update, 1);
	FrameCounter++;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	glColor3f(1,1,1);
	glVertex2f(0,0);
	glVertex2f(0,10);
	glVertex2f(10,10);
	glVertex2f(10,0);
	glEnd();

	game.display();
	
	//glutTimerFunc(1000, Update, 1);
	glutSwapBuffers();
}









int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);

	glutInitWindowSize(game.getWindowWidth(), game.getWindowHeight());
	glutCreateWindow("Aryan Saxena: 500082431");
	init();

	Start();

	glutDisplayFunc(display);
	glutFullScreen();
	glutKeyboardFunc(keypress);
	glutKeyboardUpFunc(keyUp);
	glutMouseFunc(mouse_callback);
	Update(1);
	glutMainLoop();
	
	return 0;
}