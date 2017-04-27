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

#include <stdio.h>

class Tracks {

public:
	
	void setup();
	void update();
	void draw();
	
	Tracks(string track, string artist, float radius);
	
	string track;
	string artist;
	float x, y, xVel, yVel, radius;
	
	static ofTrueTypeFont trackFont;
	static ofTrueTypeFont artistFont;
	
	ofColor color;
	
	
	
};

#endif /* Tracks_hpp */
