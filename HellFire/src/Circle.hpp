//
//  Circle.hpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "ofMain.h"
#include "ofxBox2d.h"

class Circle : public ofBaseApp {
	
public:
	Circle(string title, float radius);
	
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
	ofxBox2dCircle circ;
	
	ofColor color;
	
	ofTrueTypeFont font;
	
	string title;
	float radius;
	
	int xVel, yVel;
	float pixelX, pixelY;
	
};

#endif /* Circle_hpp */
