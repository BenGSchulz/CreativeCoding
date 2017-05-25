#pragma once

#include "ofMain.h"
#include "Circle.hpp"
#include "StartState.hpp"
#include "YearState.hpp"
#include "MonthState.hpp"
#include "AttackState.hpp"
#include "ofxBox2d.h"
#include "MovingAverage.hpp"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
	
	ofVideoGrabber grabber;
	ofxMovingAverage pixelX, pixelY;
	
//	ofxBox2d world;
	
	ofRectangle screenRect;
	
	StartState startState;
	YearState yearState;
	MonthState monthState;
	AttackState attackState;
	
	State *state;
	
};
