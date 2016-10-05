#pragma once
class OpenGLApp
{
private:
	int m_windowWidth;
	int m_windowHeight;
	float m_angle;

	//use theses as members to translate with
	float xPos;
	float yPos;
	float zPos;

	//these members can be used to rotate with
	float xAxisAngle;
	float yAxisAngle;
	float zAxisAngle;

	//where should we set these up?


public:
	OpenGLApp();
	~OpenGLApp();

	bool Initialize();	//initialize your opengl scene
	bool Shutdown();	//shut down your scene

	//used to setup your opengl camera and drawing area
	void SetupProjection(int width, int height);
	void Prepare(float dt);
	void Render();

	//some functions to help us out
	void DrawCube();
	void PositionAndRotate(float xPos, float yPos, float zPos, float xAngle, float yAngle, float zAngle);
	void RotateX();
	void RotateY();
	void RotateZ();

	//draw a grid
	void DrawGrid();

};

