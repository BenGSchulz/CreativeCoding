#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
#include "StartView.hpp"
#include "ChartView.hpp"
#include "LyricView.hpp"
#include "Tracks.hpp"
#include "State.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void exit();
	
		void mouseMoved(int x, int y);
	
	

	State *state;
	
	//int state;
	
	StartView startView;
	
	ChartView chartView;
	
	LyricView lyricView;
	
};
