#include "ScenePlayback.h"

ScenePlayback::ScenePlayback()
{
	ofBackground(0, 0, 0);
	
	_name = SCENE_PLAYBACK;
	
	_curVideo = 0;
	
	_mask.loadImage("mask.png");
	
	_videoFadeUp.setup(100, 0, 255, Easing::QuadEaseOut);
	_videoFadeDown.setup(100, 255, -255, Easing::QuadEaseOut);
}

void ScenePlayback::init()
{
	_video.loadMovie("uservideo/" + App::getInstance()->user.videos[_curVideo]->name);
	_video.play();
	_video.setLoopState(OF_LOOP_NONE);
	_videoFadeUp.play();
}

void ScenePlayback::update()
{
	_videoFadeUp.update();
	_videoFadeDown.update();
	
	if(_videoFadeUp.finished())
	{
		_videoFadeUp.stop();
	}
	
	_video.update();
	
	if(_video.getIsMovieDone() && !_videoFadeDown.isPlaying())
	{
		_videoFadeDown.play();
	}
	
	if (_videoFadeDown.finished()) 
	{
		if(_curVideo < App::getInstance()->user.videos.size() - 1)
		{
			_videoFadeDown.stop();
			
			_curVideo++;
			
			init();
		}
		else 
		{
			_finished = true;
		}
	}
}

void ScenePlayback::display()
{
	ofEnableAlphaBlending();
	
	float a = 255;
	
	if(_videoFadeUp.isPlaying())
	{
		a = _videoFadeUp.num;
	}
	else if(_videoFadeDown.isPlaying())
	{
		a = _videoFadeDown.num;
	}
	
	float scale = 1;
	
	if(scale == 1)
	{
		ofSetColor(255, 255, 255, a);
		_video.draw((ofGetWidth() / 2) - (_video.width / 2), ofGetHeight() - _video.height);
		ofSetColor(255, 255, 255, 255);
		_mask.draw((ofGetWidth() / 2) - (_video.width / 2), ofGetHeight() - _video.height);
	}
	else 
	{
		ofSetColor(255, 255, 255, a);
		_video.draw((ofGetWidth() / 2) - ((_video.width * scale) / 2), ofGetHeight() - (_video.height * scale), _video.width * scale, _video.height * scale);
		ofSetColor(255, 255, 255, 255);
		_mask.draw((ofGetWidth() / 2) - ((_video.width * scale) / 2), ofGetHeight() - (_video.height * scale), _video.width * scale, _video.height * scale);
	}
	
	ofDisableAlphaBlending();
}

/* Reset
 _______________________________________________________________ */

void ScenePlayback::reset()
{
	_finished = false;
	_video.close();
	_videoFadeDown.stop();
	_videoFadeUp.stop();
	_curVideo = 0;
}

void ScenePlayback::keyPressed(int key)
{
	
}
