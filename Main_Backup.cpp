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
int WindowWidth = 1920, WindowHeight = 1080;

GLfloat xOffset=0, yOffset;
Game game;


void keypress(unsigned char key, int x, int y)
{
	if (key == 'a')
	{

		xOffset -= 10;
	}

	if (key == 'd')
	{
		xOffset += 10;
	}

	if (key == 'w')
	{
		yOffset += 10;
	}

	if (key == 's')
	{
		yOffset -= 10;
	}

	if (key == 'k')
	{
		glutDestroyWindow(1);
	}
}

void init(void)
{
	gluOrtho2D(0, 1920, 0, 1080);
}

void DrawLine(GLfloat xStart, GLfloat yStart, GLfloat xEnd, GLfloat yEnd)
{
	glBegin(GL_LINES);
	glColor3f(1, 1, 1);
	glVertex2f(xStart, yStart);
	glVertex2f(xEnd, yEnd);
	glEnd();
}


class RectangleClass
{
public:
	struct Vertex
	{
		GLfloat x, y;
	};
	Vertex TL, BR;

	GLfloat top = 0, bottom = WindowHeight, left = WindowWidth, right = 0;
	

	void SetVertex(GLfloat TLx, GLfloat TLy, GLfloat BRx, GLfloat BRy)
	{

		TL.x = TLx;
		TL.y = TLy;
		BR.x = BRx;
		BR.y = BRy;
	}


	void Render()
	{
		DrawLine(TL.x, TL.y, TL.x, BR.y);
		DrawLine(TL.x, BR.y,BR.x,BR.y);
		DrawLine(BR.x, BR.y, BR.x,TL.y);
		DrawLine(BR.x, TL.y, TL.x, TL.y);
	}
};


RectangleClass R1, R2;

bool IsOverlapping()
{
	if (R1.TL.x == R1.BR.x || R1.TL.y == R1.BR.y || R2.BR.x == R2.TL.x || R2.TL.y == R2.BR.y)
		return false;
	if (R1.TL.x > R2.BR.x || R2.TL.x > R1.BR.x)
		return false;
	if (R1.BR.y > R2.TL.y || R2.BR.y > R1.TL.y)
		return false;

	return true;

}

void Start()
{
	game.start();	
}

void Update(int id)
{
	game.Update();
	glutPostRedisplay();
	glutTimerFunc(16.67, Update, 1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	R1.SetVertex(10, 80, 50, 60);
	R2.SetVertex(50+xOffset, 30+yOffset, 60+xOffset, 20+yOffset);
	R1.Render();
	R2.Render();

	game.ProjectileVec[0].Move(Location(xOffset, yOffset));

	if (IsOverlapping())
	{
		//Text
		glColor3f(1.0, 0, 0.0);
		glRasterPos2f(80, 80); //define position on the screen
		char* strName = (char*)"OVERLAPPING!!";
		for (int i = 0; i < (int)strlen(strName); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, strName[i]);
		}
	}

	game.display();
	
	glutTimerFunc(16.67, Update, 1);
	glutSwapBuffers();
}









int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);

	glutInitWindowSize(WindowWidth, WindowHeight);
	glutCreateWindow("Aryan Saxena: 500082431");
	init();

	Start();

	glutDisplayFunc(display);
	glutFullScreen();
	glutKeyboardFunc(&keypress);
	glutMainLoop();
	
	return 0;
}