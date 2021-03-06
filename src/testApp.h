#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "Scene.h"
#include "Scene1.h"
#include "Scene2.h"
#include "ScenePlayback.h"
#include "SceneRecording.h"
#include "SceneBeforeRecording.h"
#include "SceneFinished.h"

class testApp : public ofBaseApp
{	
	public:
		
		void setup();
		void update();
		void draw();
		void resetAll();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		vector <Scene *> scenes;
		int curScene;
};

#endif
	
