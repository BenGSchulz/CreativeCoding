//
//  Tracks.hpp
//  Project1
//
//  Created by Ben Schulz on 4/27/17.
//
//

#ifndef Tracks_hpp
#define Tracks_hpp

#include "ofMain.h"
//#include "ofxBox2d.h"

#include <stdio.h>

class Tracks {

public:
	
	void setup();
	void update();
	void draw();
	
	Tracks(string track, string artist, float radius, string trackID);
	
	string track;
	string artist;
	float x, y, xVel, yVel, radius;
	string trackID;
	
	static ofTrueTypeFont trackFont;
	static ofTrueTypeFont artistFont;
	
	ofColor color;
	
	//ofxBox2d box2d;
	//ofxBox2dCircle circle;
	
};

#endif /* Tracks_hpp */
