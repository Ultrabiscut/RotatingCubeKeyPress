#include<Windows.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include <cmath>
#include "OpenGLApp.h"


OpenGLApp::OpenGLApp()
{
}


OpenGLApp::~OpenGLApp()
{
}


bool OpenGLApp::Initialize()	//initialize your opengl scene
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//TO DO: INITIALIZE X, Y, AND Z POSTITIONS
	xPos = 0.0f;
	yPos = 0.0f;
	zPos = 0.0f;
	//		 INITIALIZE X, Y, AND Z ROTATIONS
	xAxisAngle = 0.0f;
	yAxisAngle = 0.0f;
	zAxisAngle = 0.0f;

	return true;
}	
bool OpenGLApp::Shutdown()	//shut down your scene
{
	return true;
}

//used to setup your opengl camera and drawing area
void OpenGLApp::SetupProjection(int width, int height){
	if (height == 0)
	{
		height = 1;
	}

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// you need 3 things to create a frustum
	// 1. Field of view (52.0f here)
	// 2. aspect ratio of screen (width/height of window)
	// 3. near and far plane (1, and 1000)
	gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	m_windowWidth = width;
	m_windowHeight = height;
}

void OpenGLApp::Prepare(float dt)
{
	//TO DO: MANIPULATE THE X,Y, AND Z AXIS ROTATIONS
	//		 MAKE SURE ROTATIONS DON'T EXCEED 360
	/*xAxisAngle += 1.0f;
	yAxisAngle += 1.0f;
	zAxisAngle += 1.0f;*/

	//if (xAxisAngle >= 360) zAxisAngle = 0.0f;
	//if (yAxisAngle >= 360) zAxisAngle = 0.0f;
	//if (zAxisAngle >= 360) zAxisAngle = 0.0f;
}
void OpenGLApp::RotateX()
{
	xAxisAngle += 1.0f;
}

void OpenGLApp::RotateY()
{
	yAxisAngle += 1.0f;
}

void OpenGLApp::RotateZ()
{
	zAxisAngle += 1.0f;
}

void OpenGLApp::PositionAndRotate(float xPos, float yPos, float zPos, float xAngle, float yAngle, float zAngle)
{
	//TO DO:	ROTATE AND TRANSLATE



	//glTranslatef(xPos, yPos, zPos);
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);


}

void OpenGLApp::DrawCube()
{
	//draw a cube!
	//hint:	GL_QUADS
		//glColor3f(1.0f, 0.0f, 0.0f); //red
	glBegin(GL_QUADS); //front face
		glVertex3f(-1.0f, 1.0, 1.0);
		glVertex3f(-1.0f, -1.0, 1.0);
		glVertex3f(1.0f, -1.0, 1.0);
		glVertex3f(1.0f, 1.0, 1.0);
	glEnd();

		//glColor3f(0.0f, 1.0f, 0.0f); //green
	glBegin(GL_QUADS); //right face
		glVertex3f(1.0f, 1.0, 1.0);
		glVertex3f(1.0f, 1.0, -1.0);
		glVertex3f(1.0f, -1.0, -1.0);
		glVertex3f(1.0f, -1.0, 1.0);
	glEnd();

		//glColor3f(0.0f, 0.0f, 1.0f); //blue
	glBegin(GL_QUADS); //back face
		glVertex3f(-1.0f, 1.0, -1.0);
		glVertex3f(-1.0f, -1.0, -1.0);
		glVertex3f(1.0f, -1.0, -1.0);
		glVertex3f(1.0f, 1.0, -1.0);
	glEnd();

		//glColor3f(1.0f, 0.0f, 1.0f); //purple
	glBegin(GL_QUADS); //left face
		glVertex3f(-1.0f, 1.0, 1.0);
		glVertex3f(-1.0f, 1.0, -1.0);
		glVertex3f(-1.0f, -1.0, -1.0);
		glVertex3f(-1.0f, -1.0, 1.0);
	glEnd();

		//glColor3f(0.0f, 1.0f, 1.0f); //teal
	glBegin(GL_QUADS); //top face
		glVertex3f(-1.0f, 1.0, 1.0);
		glVertex3f(-1.0f, 1.0, -1.0);
		glVertex3f(1.0f, 1.0, -1.0);
		glVertex3f(1.0f, 1.0, 1.0);
	glEnd();

		//glColor3f(1.0f, 1.0f, 1.0f); //white
	glBegin(GL_QUADS); //bottom face
		glVertex3f(-1.0f, -1.0, 1.0);
		glVertex3f(-1.0f, -1.0, -1.0);
		glVertex3f(1.0f, -1.0, -1.0);
		glVertex3f(1.0f, -1.0, 1.0);
	glEnd();

	//x axis
		glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex3f(-3.0f, 0.0f, 0.0f);
		glVertex3f(3.0f, 0.0f, 0.0f);
	glEnd();


	//y axis
		glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
		glVertex3f(0.0f, -3.0f, 0.0f);
		glVertex3f(0.0f, 3.0f, 0.0f);
	glEnd();


	//z axis
		glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
		glVertex3f(0.0f, 0.0f, -3.0f);
		glVertex3f(0.0f, 0.0f, 3.0f);
	glEnd();
}

void OpenGLApp::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	glLoadIdentity();

	//keep?
	glTranslatef(0.0f, 0.0f, -10.0f);


	//keep?
	glColor3f(1.0f, 0.0f, 1.0f); //red
	
	//what polygon mode? line? fill? point?
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//call PositionAndRotate
	glPolygonMode(GL_FRONT, GL_LINE);
	glPushMatrix();
		PositionAndRotate(xPos, yPos, zPos, xAxisAngle, yAxisAngle, zAxisAngle);
		//call DrawCube
		DrawCube();
	glPopMatrix();


	//make this funciton call if you want to see the grid
	//DrawGrid();
}

void OpenGLApp::DrawGrid()
{
	//increase the size of drawn points
	glPointSize(3.0f);

	glBegin(GL_LINES);
	//change the color to blue
	glColor3f(0.0f, 0.0, 1.0f);

	//vertical
	for (float x = 8; x >= -8; x--)
	{
		glVertex3f(x, 5.0f, 0.0f);
		glVertex3f(x, -5.0f, 0.0f);
	}
	//horizontal
	for (float y = 5; y >= -5; y--)
	{
		glVertex3f(8.0f, y, 0.0f);
		glVertex3f(-8.0f, y, 0.0f);
	}

	glEnd();
	
	//we are going to draw below
	glBegin(GL_POINTS);

		//change color to white
		glColor3f(1.0f, 1.0f, 1.0f);

		//draw the points on the y-axis
		for (float y = 5; y >= -5; y--)
		{
			glVertex3f(0.0f, y, 0.0f);
		}

		//draw the points on the x-axis
		for (float x = 8; x >= -8; x--)
		{
			glVertex3f(x, 0.0, 0.0f);
		}

		//set the color to red
		glColor3f(1.0f, 0.0f, 0.0f);
		//draw the orgin
		glVertex3f(0.0f, 0.0f, 0.0f);

	glEnd();

}
