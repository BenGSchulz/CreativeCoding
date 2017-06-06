#pragma once

#include "ofMain.h"
#include "Circle.hpp"
#include "StartState.hpp"
#include "YearState.hpp"
#include "MonthState.hpp"
#include "AttackState.hpp"
#include "MovingAverage.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseReleased(int x, int y, int button);
	
	ofVideoGrabber grabber;
	ofxMovingAverage pixelX, pixelY;
	
	//	ofImage video;
	ofImage overlay;
	ofImage predator;
	ofImage bg1;
	ofImage bg2;
	ofImage bg3;
	ofImage overlay2;
	
	ofSoundPlayer drone;
	ofSoundPlayer lock;
	ofSoundPlayer fire;
	
	StartState startState;
	YearState yearState;
	MonthState monthState;
	AttackState attackState;
	
	bool laser;
	
	State *state;
	
};
