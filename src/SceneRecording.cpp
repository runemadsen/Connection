#include "SceneRecording.h"

SceneRecording::SceneRecording()
{
	ofBackground(0, 0, 0);
	
	_name = SCENE_RECORDING;
	
	_captureFade.setup(100, 0, 255, Easing::QuadEaseOut);
	
	_rectSize = 30;
	
	int duration = 200;
	int delay = duration / 10;
	
	_line1.setup(duration, 0, ofGetWidth(), Easing::CubicEaseOut);
	_line2.setup(duration, 0, ofGetHeight(), Easing::CubicEaseOut, delay);
	_line3.setup(duration, ofGetWidth(), -(ofGetWidth()), Easing::CubicEaseOut, delay * 2);
	_line4.setup(duration, ofGetHeight(), -(ofGetHeight()), Easing::CubicEaseOut, delay * 3);
	_lineColor.setup(50, 255, -255, Easing::SineEaseIn, 100, 2);
	
	_line1.play();
	_line2.play();
	_line3.play();
	_line4.play();
	
	_captureStarted = false;
	_recordStarted = false;
}

void SceneRecording::init()
{
	_vidGrabber.setVerbose(true);
	//_vidGrabber.listDevices();
	//_vidGrabber.setDeviceID(6);
	_vidGrabber.initGrabber(320, 240);
}

void SceneRecording::update()
{
	_count.update();
	
	_line1.update();
	_line2.update();
	_line3.update();
	_line4.update();
	_lineColor.update();
	
	if(!_captureStarted && _vidGrabber.isFrameNew())
	{
		_captureFade.play();
		
		_count.play();
		
		_captureStarted = true;
	}
	
	if(_count.finished() && !_recordStarted)
	{		
		_lineColor.play();
		
		// record
		
		_recordStarted = true;
	}
	
	_captureFade.update();
	_vidGrabber.grabFrame();
}

void SceneRecording::display()
{
	ofEnableAlphaBlending();
	
	ofSetColor(255, 255, 255, _captureFade.num);
	_vidGrabber.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	ofSetColor(255, 255, 255, 255);
	
	_count.draw();
	
	ofDisableAlphaBlending();
	
	// draw rects
	ofSetColor(255, _lineColor.num, _lineColor.num, 255);
	ofRect(0, 0, _line1.num, _rectSize);
	ofRect(ofGetWidth() - _rectSize, 0, _rectSize, _line2.num);
	ofRect(_line3.num, ofGetHeight() - _rectSize, ofGetWidth() - _line3.num, _rectSize);
	ofRect(0, _line4.num, _rectSize, ofGetHeight() - _line4.num);
}

void SceneRecording::keyPressed(int key)
{
	
}
