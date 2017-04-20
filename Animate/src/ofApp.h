#pragma once

#include "ofMain.h"
#include "Mountains.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		void mousePressed(int x, int y, int button);
		void mouseMoved(int x, int y);
	
private:
	Mountains m;
	bool drawBackground = false;
	float noiseChange = 0.002;
	float noiseHeight = ofGetHeight();
	float noiseOffset = 0;
	ofColor color = ofColor::white;
	
};
