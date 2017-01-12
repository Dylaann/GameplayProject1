#include "Game.h"

bool flip = false;
int current = 1;

Vector3new v1(0.25f, 0.25f, -5.0f);
Vector3new v2(-0.25f, 0.25f, -5.0f);
Vector3new v3(-0.25f, -0.25f, -5.0f);
Vector3new v4(0.25f, -0.25f, -5.0f);
Vector3new v5(0.25f, 0.25f, -6.0f);
Vector3new v6(-0.25f, 0.25f, -6.0f);
Vector3new v7(-0.25f, -0.25f, -6.0f);
Vector3new v8(0.25f, -0.25f, -6.0f);


Game::Game() : window(VideoMode(800, 600), "OpenGL Cube"), primitives(1), m1(1, 0, 0, 0, cos(rotationAngle), sin(rotationAngle), 0, -sin(rotationAngle), cos(rotationAngle))
{
	index = glGenLists(primitives);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	glNewList(index, GL_COMPILE);
	
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 0.01f)
	{
		clock.restart();

		cout << "Update up" << endl;
	}
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << current << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 1, 0); // Rotates the camera on Y Axis
	glBegin(GL_QUADS);
	{
		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(v1.x, v1.y, v1.z);
		glVertex3f(v2.x, v2.y, v2.z);
		glVertex3f(v3.x, v3.y, v3.z);
		glVertex3f(v4.x, v4.y, v4.z);

		//Back Face
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(v5.x, v5.y, v5.z);
		glVertex3f(v6.x, v6.y, v6.z);
		glVertex3f(v7.x, v7.y, v7.z);
		glVertex3f(v8.x, v8.y, v8.z);

		//topside
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(v1.x , v1.y, v1.z);
		glVertex3f(v2.x, v2.y, v2.z);
		glVertex3f(v6.x, v6.y, v6.z);
		glVertex3f(v5.x, v5.y, v5.z);

		//bottom
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex3f(v8.x, v8.y, v8.z);
		glVertex3f(v7.x, v7.y, v7.z);
		glVertex3f(v3.x, v3.y, v3.z);
		glVertex3f(v4.x, v4.y, v4.z);

		//left
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(v2.x, v2.y, v2.z);
		glVertex3f(v3.x, v3.y, v3.z);
		glVertex3f(v7.x, v7.y, v7.z);
		glVertex3f(v6.x, v6.y, v6.z);

		//right
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(v1.x, v1.y, v1.z);
		glVertex3f(v4.x, v4.y, v4.z);
		glVertex3f(v8.x, v8.y, v8.z);
		glVertex3f(v5.x, v5.y, v5.z);
	}
	glCallList(current);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

