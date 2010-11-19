#include "Scene2.h"
#include "Quad.h"


Scene2::Scene2()
{
	ofBackground(0, 0, 0);
	
	_test.loadImage("step3.jpg");
	_hand.loadImage("hand.png");
	_hand.resize(_hand.width * 0.7, _hand.height * 0.7);
	_title.loadImage("placeyourhand.png");
	
	_font.loadFont("GothamRounded-Book.ttf", 26, true, true);
	
	_countDown.duration = 500;
	_titleFade.duration = 100;
	_handFade.duration = 100;
}

void Scene2::update()
{
	_countDown.tick();
	
	cout << _countDown.time << endl;
	
	if(_countDown.time == _countDown.duration)
	{
		_handFade.tick();
		
		if(_handFade.time > _handFade.duration / 2)
		{
			_titleFade.tick();
		}
	}
	
	if(_titleFade.time == _titleFade.duration)
	{
		_finished = true;
	}
}

void Scene2::display()
{
	ofEnableAlphaBlending();
	
	float a = Quad::easeOut(_handFade.time, 255, -255, _handFade.duration);
	ofSetColor(255, 255, 255, a);
	
	ofPoint loc;
	loc.set((ofGetWidth() / 2) - (_hand.width / 2), (ofGetHeight() / 2) - (_hand.height / 2) - 35);
	_hand.draw(loc.x, loc.y);
	
	a = Quad::easeOut(_titleFade.time, 255, -255, _titleFade.duration);
	ofSetColor(255, 255, 255, a);

	
	_title.draw((ofGetWidth() / 2) - (_title.width / 2), loc.y + _hand.height + 30);
	ofDisableAlphaBlending();
}

void Scene2::keyPressed(int key)
{
}
