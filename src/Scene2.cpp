#include "Scene2.h"

Scene2::Scene2()
{
	ofBackground(0, 0, 0);
	
	_name = SCENE_2;
	
	_test.loadImage("step3.jpg");
	_hand.loadImage("hand.png");
	_hand.resize(_hand.width * 0.7, _hand.height * 0.7);
	_title.loadImage("placeyourhand.png");
	
	_font.loadFont("GothamRounded-Book.ttf", 26, true, true);
}

void Scene2::init()
{
	_countDown.duration = 500;
	_countDown.state = 1;
	
	_titleFade.setup(100, 255, -255, Easing::QuadEaseOut, 50);
	_handFade.setup(100, 255, -255, Easing::QuadEaseOut);
}

void Scene2::update()
{
	_countDown.tick();
	
	if(_countDown.time == _countDown.duration && !_fadeMode)
	{
		_fadeMode = true;
		
		_handFade.play();
		_titleFade.play();
		
	}
	
	_handFade.update();
	_titleFade.update();
	
	if(_titleFade.finished())
	{
		_finished = true;
	}
}

void Scene2::display()
{
	ofEnableAlphaBlending();
	
	ofSetColor(255, 255, 255, _handFade.num);
	
	ofPoint loc;
	loc.set((ofGetWidth() / 2) - (_hand.width / 2), (ofGetHeight() / 2) - (_hand.height / 2) - 35);
	_hand.draw(loc.x, loc.y);
	
	ofSetColor(255, 255, 255, _titleFade.num);

	_title.draw((ofGetWidth() / 2) - (_title.width / 2), loc.y + _hand.height + 30);
	ofDisableAlphaBlending();
}
/* Reset
 _______________________________________________________________ */

void Scene2::reset()
{
	_finished = false;
	_titleFade.stop();
	_handFade.stop();
	_fadeMode = false;
	_countDown.time = 0;
}

void Scene2::keyPressed(int key)
{
}
