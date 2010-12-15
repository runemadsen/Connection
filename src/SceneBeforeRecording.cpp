#include "SceneBeforeRecording.h"

SceneBeforeRecording::SceneBeforeRecording()
{
	ofBackground(0, 0, 0);
	
	_signToShow = 0;
	
	_name = SCENE_BEFORE_RECORDING;
	
	_fadeDown.setup(100, 255, -255, Easing::QuadEaseOut, 300);
	
	_msg1 = "No more messages recorded";
	_msg2 = "No messages recorded";
}

void SceneBeforeRecording::init()
{
	_fadeDown.play();
	_font.loadFont("GothamRounded-Book.ttf", 26, true, true);
}

void SceneBeforeRecording::update()
{
	_fadeDown.update();
	
	if(_fadeDown.finished())
	{
		_finished = true;
	}
}

void SceneBeforeRecording::display()
{
	string message;
	switch (_signToShow) 
	{
		case 1:
			message = _msg2;
			break;
		default:
			message = _msg1;
			break;
	}
	
	ofEnableAlphaBlending();
	
	ofSetColor(255, 255, 255, _fadeDown.num);
	
	_font.drawString(message, (ofGetWidth() / 2) - (_font.stringWidth(message) / 2), ofGetHeight() / 2);
	
	ofDisableAlphaBlending();
}

/* Reset
 _______________________________________________________________ */

void SceneBeforeRecording::reset()
{
	_finished = false;
	_fadeDown.stop();
	_signToShow = 0;
}

void SceneBeforeRecording::keyPressed(int key)
{
	
}

void SceneBeforeRecording::showNoVideosSign()
{
	_signToShow = 1;
}
