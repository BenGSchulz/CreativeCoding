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

class Circle : public ofBaseApp, ofxBox2dCircle {
	
public:
	Circle(string title, float radius);
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	
	ofColor color;
	
	vector<Circle> circles;
	
	ofTrueTypeFont font;
	
	string title;
	float radius;
	
	int x, y, xVel, yVel;
	float pixelX, pixelY;
	
	static std::string yearSelected;
	static std::string monthSelected;
	
	bool inside = false;
	
};

#endif /* Circle_hpp */
