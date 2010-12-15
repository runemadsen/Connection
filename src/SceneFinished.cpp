#include "SceneFinished.h"

SceneFinished::SceneFinished()
{
	ofBackground(0, 0, 0);
	
	_fadeDown.setup(100, 255, -255, Easing::QuadEaseOut, 300);
}

void SceneFinished::init()
{
	_fadeDown.play();
	_font.loadFont("GothamRounded-Book.ttf", 26, true, true);
}

void SceneFinished::update()
{
	_fadeDown.update();
	
	if(_fadeDown.finished())
	{
		_finished = true;
	}
}

void SceneFinished::display()
{
	ofEnableAlphaBlending();
	
	ofSetColor(255, 255, 255, _fadeDown.num);
	
	string message = "Your message was recorded";
	
	_font.drawString(message, (ofGetWidth() / 2) - (_font.stringWidth(message) / 2), ofGetHeight() / 2);
	
	ofDisableAlphaBlending();
}

/* Reset
 _______________________________________________________________ */

void SceneFinished::reset()
{
	_finished = false;
	_fadeDown.stop();
}

void SceneFinished::keyPressed(int key)
{
	
}
