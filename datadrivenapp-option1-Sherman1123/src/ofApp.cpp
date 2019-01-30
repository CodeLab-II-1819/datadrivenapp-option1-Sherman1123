#include "ofApp.h"
#include <fstream>
#include "ofxGui.h"
#pragma once
#include <vector>

//--------------------------------------------------------------
void ofApp::setup() {
	btnImg.load("button.png");//load in button image

	//set position and size for 2 button rectangles
	btn1.set(20, 20, 150, 50);
	btn2.set(20, 80, 150, 50);
	btn3.set(20, 140, 150, 50);
	btn4.set(20, 200, 150, 50);
	btn5.set(20, 260, 150, 50);
	btn6.set(20, 320, 150, 50);
	btn7.set(20, 380, 150, 50);
	btn8.set(20, 440, 150, 50);
	btn9.set(20, 500, 150, 50);
	btn10.set(20, 560, 150, 50);
	btn11.set(20, 620, 150, 50);
	btn12.set(20, 680, 150, 50);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw() {
	//set color to black
	ofSetColor(0, 0, 0); //draw button rectangle
	//btnImg.draw(btn1);
	ofDrawRectangle(btn1);
	ofDrawRectangle(btn2);
	ofDrawRectangle(btn3);
	ofDrawRectangle(btn4);
	ofDrawRectangle(btn5);
	ofDrawRectangle(btn6);
	ofDrawRectangle(btn7);
	ofDrawRectangle(btn8);
	ofDrawRectangle(btn9);
	ofDrawRectangle(btn10);
	ofDrawRectangle(btn11);
	ofDrawRectangle(btn12);

}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//check whether mouse press is inside buttons
	if (btn1.inside(x, y)) {
		std::cout << "Clicked button 1" << endl;
	}
	if (btn2.inside(x, y)) {
		std::cout << "Clicked button 2" << endl;
	}
	if (btn3.inside(x, y)) {
		std::cout << "Clicked button 3" << endl;
	}
	if (btn4.inside(x, y)) {
		std::cout << "Clicked button 4" << endl;
	}
	if (btn5.inside(x, y)) {
		std::cout << "Clicked button 5" << endl;
	}
	if (btn6.inside(x, y)) {
		std::cout << "Clicked button 6" << endl;
	}
	if (btn7.inside(x, y)) {
		std::cout << "Clicked button 7" << endl;
	}
	if (btn8.inside(x, y)) {
		std::cout << "Clicked button 8" << endl;
	}
	if (btn9.inside(x, y)) {
		std::cout << "Clicked button 9" << endl;
	}
	if (btn10.inside(x, y)) {
		std::cout << "Clicked button 10" << endl;
	}
	if (btn11.inside(x, y)) {
		std::cout << "Clicked button 11" << endl;
	}
	if (btn12.inside(x, y)) {
		std::cout << "Clicked button 12" << endl;
	}
}
void OpenFile(string search){
	int Places = 0;
	vector<string> Created = {};
	vector<string> Content = {};
	// open a file in read mode.
	ifstream inFile;
	inFile.open("sampleTweets.csv");
	if (inFile.good())
	{ // check file has opened
		while (!inFile.eof()) { // keep looping through the file until at end
			cout << "Reading from file" << endl;
			Created.resize(Created.size() +1);
			Content.resize(Content.size() + 1);
			getline(inFile, Created[Places], ','); // getline from file till comma
			getline(inFile, Content[Places], '\n'); // getline from file till comma
			Places++;
		}
		inFile.close(); // close file
	}
}





