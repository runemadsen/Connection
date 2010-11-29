#include "CountDown.h"

CountDown::CountDown()
{
	_finished = false;
	
	_font.loadFont("GothamRounded-Book.ttf", 150, true, true);
	
	int duration = 50;
	
	_letter3.setup(duration, 0, 255, Easing::CubicEaseOut);
	_letter2.setup(duration, 0, 255, Easing::CubicEaseOut, 100);
	_letter1.setup(duration, 0, 255, Easing::CubicEaseOut, 200);
	_letter1Down.setup(duration, 0, 255, Easing::CubicEaseOut, 300);
}

void CountDown::update()
{
	_letter1.update();
	_letter1Down.update();
	_letter2.update();
	_letter3.update();
	
	if(_letter1.finished())
	{
		_finished = true;
	}
}

void CountDown::draw()
{
	ofSetColor(255, 255, 255, _letter3.num - _letter2.num);
	_font.drawString("3", (ofGetWidth() / 2) - (_font.stringWidth("3") / 2), (ofGetHeight() / 2)  + (_font.stringHeight("3") / 2));
	
	ofSetColor(255, 255, 255, _letter2.num - _letter1.num);
	_font.drawString("2", (ofGetWidth() / 2) - (_font.stringWidth("2") / 2), (ofGetHeight() / 2)  + (_font.stringHeight("2") / 2));
	
	ofSetColor(255, 255, 255, _letter1.num - _letter1Down.num);
	_font.drawString("1", (ofGetWidth() / 2) - (_font.stringWidth("1") / 2), (ofGetHeight() / 2)  + (_font.stringHeight("1") / 2));
}

void CountDown::play()
{
	_letter1.play();
	_letter1Down.play();
	_letter2.play();
	_letter3.play();
}