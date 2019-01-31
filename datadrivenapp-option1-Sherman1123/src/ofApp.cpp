#include "ofApp.h"
#include <fstream>
#include "ofxGui.h"
#pragma once
#include <vector>
#include "ofxTextSuite.h"
#include <iostream>
using namespace std;
//--------------------------------------------------------------
stringstream tweetStream;
string CurrentTweet;
int NumberOf = 0;
int NumberOfT = 0;
string MyDataArray[64000];
//--------------------------------------------------------------
void OpenFile(string search);
void ofApp::setup() {
	//btnImg.load("button.png");//load in button image

	//set position and size for 2 button rectangles
	btn1.set(20, 20, 250, 50);
	btn2.set(20, 80, 250, 50);
	btn3.set(20, 140, 250, 50);
	btn4.set(20, 200, 250, 50);
	btn5.set(20, 260, 250, 50);
	btn6.set(20, 320, 250, 50);
	btn7.set(20, 380, 250, 50);
	btn8.set(20, 440, 250, 50);
	btn9.set(20, 500, 250, 50);
	btn10.set(20, 560, 250, 50);

	//myText.init("AbhayaLibre-Regular.ttf", 12);//init text block font and text size
	//myText.setText(tweetStream.str());
	paraY = 30; //set paragraph y position
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255);
	ofDrawRectangle(0, 0, 2000, 750);
	//set color to black
	ofSetColor(0, 0, 0); //draw button rectangle
	//btnImg.draw(btn1);
	ofDrawRectangle(btn1);//creates button
	ofDrawRectangle(btn2);
	ofDrawRectangle(btn3);
	ofDrawRectangle(btn4);
	ofDrawRectangle(btn5);
	ofDrawRectangle(btn6);
	ofDrawRectangle(btn7);
	ofDrawRectangle(btn8);
	ofDrawRectangle(btn9);
	ofDrawRectangle(btn10);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("number of tweets", 30, 42);//creates button text
	ofDrawBitmapString("number of tweets on money", 30, 102);
	ofDrawBitmapString("number of tweets on politics", 30, 162);
	ofDrawBitmapString("print Paris Tweets", 30, 222);
	ofDrawBitmapString("Print Dreamworks Tweets", 30, 282);
	ofDrawBitmapString("Print Uber Tweets", 30, 342);
	ofDrawBitmapString("Print dogs Tweets", 30, 402);
	ofDrawBitmapString("Print cats Tweets", 30, 462);
	ofDrawBitmapString("Print celebs Tweets", 30, 522);
	ofDrawBitmapString("Print dead Tweets", 30, 582);

	//myText.setText(tweetStream.str());
	//myText.wrapTextX(800); //set paragraph width
	//draw paragraph
	//myText.draw(200, paraY);
	//ofDrawBitmapString("shit", 200, 200);
	if (NumberOf > 0)//displays output for number of tweets
	{
		ofSetColor(0, 0, 0);
		ofDrawBitmapString(MyDataArray[0], 280, paraY);
		cout << MyDataArray[0] << endl;// displays output in console for testing
	}
	else// displays output of twets
	{
		for (size_t i = 0; i < NumberOfT; i++)
		{
			ofSetColor(0, 0, 0);
			ofDrawBitmapString(MyDataArray[i], 280, paraY + i * 15);
			cout << MyDataArray[i] << endl; // displays output in console for testing
		}
	}
	ofSetColor(255, 255, 255);
	ofDrawRectangle(0, 0, 2000, 10);//covers the top and bottom to create scrolling effect
	ofDrawRectangle(0, 610, 2000, 140);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	//move text up and down on key press to mimic scrolling
	switch (key) {
	case OF_KEY_UP:
		paraY -= 30;
		break;
	case OF_KEY_DOWN:
		paraY += 30;
		break;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//check whether mouse press is inside buttons
	string type;
	if (btn1.inside(x, y)) {
		type = "DoNothing";
		OpenFile(type);// opens file and checks whick tweets have the type
		draw();
	}
	if (btn2.inside(x, y)) {
		type = "money";
		OpenFile(type);
		draw();
	}
	if (btn3.inside(x, y)) {
		type = "Politics";
		OpenFile(type);
		draw();
	}
	if (btn4.inside(x, y)) {
		type = "Paris";
		OpenFile(type);
		draw();
	}
	if (btn5.inside(x, y)) {
		type = "DreamWorks";
		OpenFile(type);
		draw();
	}
	if (btn6.inside(x, y)) {
		type = "Uber";
		OpenFile(type);
		draw();
	}
	if (btn7.inside(x, y)) {
		type = "dogs";
		OpenFile(type);
		draw();
	}
	if (btn8.inside(x, y)) {
		type = "cats";
		OpenFile(type);
		draw();
	}
	if (btn9.inside(x, y)) {
		type = "celebs";
		OpenFile(type);
		draw();
	}
	if (btn10.inside(x, y)) {
		type = "dead";
		OpenFile(type);
		draw();
	}
}
void OpenFile(string search) {// search is used to check for words in tweets
	//tweetStreams.str("");
	NumberOf = 0;// counts the number of tweets for displaying number of a type of tweet
	NumberOfT = 0;// counts the number of tweets of a type so it can be used in a for to display them
	string TEMP;// these strings hold data about the tweet befor it enters array
	string TEMPcontent;
	string TEMPcreated;
	// open a file in read mode.
	ifstream inFile;
	inFile.open("sampleTweets.csv");
	if (inFile.good())
	{ // check file has opened
		while (!inFile.eof()) { // keep looping through the file until at end
			//cout << "Reading from file" << endl; //checked file was reading
			getline(inFile, TEMPcreated, ','); // seperates the date created and content of tweets originaly for use in table not implamented
			getline(inFile, TEMPcontent, '\n');
			if (search != "DoNothing")// these ifs check to see if the search word is in the content of the tweet
			{
				if (search == "money")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						NumberOf++;
					}
				}
				if (search == "Politics")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						NumberOf++;
					}
				}
				if (search == "Paris")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						//tweetStream << TEMPcreated << TEMPcontent << "/n";
						MyDataArray[NumberOfT] = TEMPcreated + "  " + TEMPcontent;
						NumberOfT++;
					}
				}
				if (search == "DreamWorks")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						MyDataArray[NumberOfT] = TEMPcreated + "  " + TEMPcontent;
						NumberOfT++;
					}
				}
				if (search == "Uber")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						MyDataArray[NumberOfT] = TEMPcreated + "  " + TEMPcontent;
						NumberOfT++;
						cout << search << MyDataArray[NumberOfT] << endl;
					}
				}
				if (search == "dogs")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						MyDataArray[NumberOfT] = TEMPcreated + "  " + TEMPcontent;
						NumberOfT++;
					}
				}
				if (search == "cats")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						MyDataArray[NumberOfT] = TEMPcreated + "  " + TEMPcontent;
						NumberOfT++;
					}
				}
				if (search == "celebs")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						MyDataArray[NumberOfT] = TEMPcreated + "  " + TEMPcontent;
						NumberOfT++;
					}
				}
				if (search == "dead")
				{
					if (TEMPcontent.find(search) <= TEMPcontent.length())
					{
						//tweetStream << TEMPcreated << TEMPcontent << "/n";
						MyDataArray[NumberOfT] = TEMPcreated + "  " + TEMPcontent;
						NumberOfT++;
					}
				}
			}
			else
			{
				NumberOfT++;
			}

		}
		inFile.close(); // close file
		if (search == "DoNothing")
		{
			tweetStream << NumberOfT << endl;
			TEMP = tweetStream.str();
			//tweetStream << "there are " << NumberOfT << "tweets in this data set";
			MyDataArray[0] = "there are " + TEMP + "tweets in this data set";
			NumberOfT = 1;
			tweetStream.str(""); //clears TweetStream
		}
		else if (NumberOf > 0)
		{
			tweetStream << NumberOf << endl; // checks for cirten inputs to set array to display only number of tweets
			TEMP = tweetStream.str();
			MyDataArray[0] = "there are " + TEMP + "tweets about " + search + " in this data set";
			tweetStream.str("");
		}
	}
}





