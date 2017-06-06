//
//  Circle.cpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#include "Circle.hpp"
#include "ofApp.h"

std::string Circle::yearSelected;
std::string Circle::monthSelected;

//--------------------------------------------------------------
Circle::Circle(string title, float radius) {
	this->title = title;
	this->radius = radius;
}

//--------------------------------------------------------------
void Circle::setup(){
	
	x = ofRandom(ofGetWidth());
	y = ofRandom(ofGetHeight());
	
	xVel = ofRandom(1, 2);
	yVel = ofRandom(1, 2);
	
	color.set(127, 12, 0);
	
	font.load(OF_TTF_SANS, 16);
}

//--------------------------------------------------------------
void Circle::update(){
	ofApp *app = (ofApp*)ofGetAppPtr();
	pixelX = app->pixelX;
	pixelY = app->pixelY;
	
	x += xVel;
	y += yVel;
	
	//Check laser location against the circle position
//	if (ofDist(pixelX, pixelY, x, y) < radius) {
//		if (app->state == &app->startState) {
//			app->state == &app->yearState;
//		} else if (app->state == &app->yearState) {
//			app->state == &app->monthState;
//		} else if (app->state == &app->monthState) {
//			app->state == &app->attackState;
//		}
//	}
	
	
	if (x-radius < 0) {
		x = 0+radius;
		xVel = -xVel;
	}
	
	if (x+radius > ofGetWidth()) {
		x = ofGetWidth()-radius;
		xVel = -xVel;
	}
	
	if (y-radius < 0) {
		y = 0+radius;
		yVel = -yVel;
	}
	
	if (y+radius > ofGetHeight()) {
		y = ofGetHeight()-radius;
		yVel = -yVel;
	}
	
}

//--------------------------------------------------------------
void Circle::draw(){
	
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
	
	ofSetColor(100);
	font.drawString(title, x-(font.stringWidth(title)/2), y);
}

//--------------------------------------------------------------
void Circle::keyPressed(int key){
	
}

//--------------------------------------------------------------
void Circle::keyReleased(int key){
	
}

//--------------------------------------------------------------
void Circle::mouseMoved(int x, int y ){
	ofApp *app = (ofApp *)ofGetAppPtr();
	if (ofDist(x, y, this->x, this->y) < radius) {
		color.set(178, 17, 0);
		inside = true;
		
		if (app->state == &app->yearState) {
			app->yearState.year = title;
		} else if (app->state == &app->monthState) {
			app->monthState.month = title;
		}
	} else {
		color.set(127, 12, 0);
		inside = false;
	}
	
}

//--------------------------------------------------------------
void Circle::mouseReleased(int x, int y, int button){
	ofApp *app = (ofApp *)ofGetAppPtr();
	if (inside) {
		if (app->state == &app->startState) {
			app->state = &app->yearState;
		} else if (app->state == &app->yearState) {
			yearSelected = title;
			app->state = &app->monthState;
		} else if (app->state == &app->monthState) {
			monthSelected = title;
			app->attackState.setup();
			app->state = &app->attackState;
		}
	}
}