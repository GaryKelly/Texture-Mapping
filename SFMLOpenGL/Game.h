#ifndef GAME_H
#define GAME_H

#include <Debug.h>

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <Vector3.h>
#include <Matrix3.h>
#include "MyMatrix3.h"
#include "MyVector3.h"
 

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <fstream>
using namespace std;
using namespace sf;
using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void render();
	void unload();
	void rotate(int t_axis);
	void translate(int t_val, char t_axis);
	void scale(int t_val);
	Clock clock;
	Time elapsed;
	float m_rotationAngleY = 0.0f;			
	float m_rotationAngleX = 0.0f;			
	float m_rotationAngleZ = 0.0f;

	float rotationAngle = 0.0f;
};

#endif