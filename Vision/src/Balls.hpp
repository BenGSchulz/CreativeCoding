//
//  Balls.hpp
//  Vision
//
//  Created by Ben Schulz on 5/16/17.
//
//

#ifndef Balls_hpp
#define Balls_hpp

#include <stdio.h>
#include "ofMain.h"

class Balls : public ofBaseApp {
public:
	void setup(float x, float y);
	void update();
	void draw();
	
	float x, y, xStart, yStart, xVel, yVel, radius = 20;
	
	ofColor color;
};

#endif /* Balls_hpp */
