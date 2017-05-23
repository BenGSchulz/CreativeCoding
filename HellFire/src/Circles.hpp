//
//  Circles.hpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#ifndef Circles_hpp
#define Circles_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxBox2d.h"

class Circles : public ofBaseApp {
	
public:
	Circles(string title, float radius);
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	
	ofxBox2d world;
	ofxBox2dCircle circle;
	
	string title;
	float radius;
	
};

#endif /* Circles_hpp */
