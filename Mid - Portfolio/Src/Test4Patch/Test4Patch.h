
/*
################################################################################

Copyright � 2014-2015 Mid (Midhun Kumar Pallipurath)
Aspiring Game Programmer
Undergraduate Portfolio Project @ the Art Institute of Vancouver
Bachelors of Science in Visual and Game Programming

################################################################################

Copyright Notice:
Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the fact that this copyright 
notice and this permission notice shall be included in all copies or 
portions of the software and/or instructions.

DISCLAIMER:
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

################################################################################
*/

//Header Definition
//################################################################################
#ifndef _Test4Patch_
	#define _Test4Patch_
#pragma once


#include "3DGE.h"
#include "patch.h"
class Test4Patch : public EDGE::application
{
public:
    Test4Patch()
        : program(0),
		programCP(0),
		points(true),
        wireframe(true),
        paused(false)
    {
    }

    void init()
    {
        static const char title[] = "3DGE - Cubic Bezier Patch Test1";
        EDGE::application::init();
        memcpy(info.title, title, sizeof(title));
    }

    void startup();
    void render(double currentTime);

protected:
    GLuint      program;
	GLuint      programCP;
    GLuint      vao;
    GLuint      buffer;

	Camera		mCamera;
	Input		input;
	patch		ocean;
	patch		patchInit;
	wave		waves[3];

    bool        wireframe;
	bool        points;
    bool        paused;

    void load_shaders();
	void onKey(int key, int action);//could be virtuals
    void onMouseButton(int button, int action);
	void onMouseMove(int x, int y);
	void onMouseWheel(int pos);
	void HandleInput(float dt);

    struct
    {
        struct
        {
            int     mv_matrix;
            int     proj_matrix;
            int     mvp;
        } patch;
		struct
        {
            int     draw_color;
            int     mvp;
        } control_point;
    } uniforms;
};

void Test4Patch::onMouseWheel(int pos)
{
	input.mWheelPos = pos;
}
void Test4Patch::onKey(int key, int action)
{
	if(action==GLFW_PRESS)
	{
		input.mKeyStates[key]=true;
	}
	else if(action==GLFW_RELEASE)
	{
		input.mKeyStates[key]=false;
	}
}
void Test4Patch::onMouseButton(int button, int action)
{
	if(action==GLFW_PRESS)
	{
		input.mMouseStates[button]=true;
	}
	else if(action==GLFW_RELEASE)
	{
		input.mMouseStates[button]=false;
	}
}
void Test4Patch::onMouseMove(int x, int y)
{
	
	input.mMouseX=x;
	input.mMouseY=y;
}

void Test4Patch::HandleInput(float dt)
{
	input.updateMouseDeltas();
	if (input.mKeyStates['Y'])
    {
		mCamera.Walk(-10.0f*dt);
	}
	if (input.mKeyStates['H'])
    {
		mCamera.Walk(10.0f*dt);
	}
	if (input.mKeyStates['G'])
    {
		mCamera.Strafe(-10.0f*dt);
	}
	if (input.mKeyStates['J'])
    {
		mCamera.Strafe(10.0f*dt);
	}
	if (input.mKeyStates['T'])
    {
		mCamera.Rise(10.0f*dt);
	}
	if (input.mKeyStates['U'])
    {
		mCamera.Rise(-10.0f*dt);
	}
	if (input.mKeyStates['V'])
    {
		mCamera.Pitch(10.0f*dt);
	}
	if (input.mKeyStates['C'])
    {
		mCamera.Yaw(10.0f*dt);
	}


	if (input.mKeyStates['1'])
	{
		waves[0].toggle=true;
	}
	if (input.mKeyStates['2'])
	{
		waves[1].toggle=true;
	}
	if (input.mKeyStates['3'])
	{
		waves[2].toggle=true;
	}
	if (input.mKeyStates['4'])
	{
		waves[0].toggle=false;
	}
	if (input.mKeyStates['5'])
	{
		waves[1].toggle=false;
	}
	if (input.mKeyStates['6'])
	{
		waves[2].toggle=false;
	}

	if (input.mMouseStates[mouse::BUTTON_1])
	{
		//int deltaX = input.mMousePress[mouse::BUTTON_1].X - input.mMouseX;
		int deltaY = input.mMousePress[mouse::BUTTON_1].Y - input.mMouseY;
		if(deltaY)
		{
		//mCamera.Yaw((dt*-deltaX)*0.1f);// diffin y
		mCamera.Pitch((dt*-deltaY)*0.1f);//diff in x
		}
		
	}
	if (input.mMouseStates[mouse::BUTTON_2])
	{
		int deltaX = input.mMousePress[mouse::BUTTON_2].X - input.mMouseX;
		//int deltaY = input.mMousePress[mouse::BUTTON_1].Y - input.mMouseY;
		if(deltaX)
		{mCamera.Yaw((dt*-deltaX)*0.1f);// diffin y
		//mCamera.Pitch((dt*-deltaY)*0.1f);//diff in x
		}
		
	}
}
//Header Definition
//################################################################################
#endif// Test2Input