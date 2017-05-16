//
//  Balls.cpp
//  Vision
//
//  Created by Ben Schulz on 5/16/17.
//
//

#include "Balls.hpp"

void Balls::setup(float _x, float _y) {
	x = _x;
	y = _y;
	xStart = _x;
	yStart = _y;
	color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
	xVel = ofRandom(-3, 3);
	yVel = ofRandom(-3, 3);
}

void Balls::update() {
	x += xVel;
	y += yVel;
}

void Balls::draw() {
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
}