#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mousePressed(int x, int y, int button);
		
		ofImage btnImg; //image object for button appearance
		ofRectangle btn1, btn2; //rectangle object to hold buttons
};
