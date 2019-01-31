#pragma once
#include "ofxTextSuite.h"
#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		
		ofImage btnImg; //image object for button appearance
		ofRectangle btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn10, btn11, btn12; //rectangle object to hold buttons
		ofxTextBlock myPara; //text block to hold text
		int paraY; //variable for paragraph y position
		stringstream tweetStream;
};
