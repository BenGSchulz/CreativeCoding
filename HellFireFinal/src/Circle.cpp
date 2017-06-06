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
	
	x = ofRandom(radius, ofGetWidth()-radius);
	y = ofRandom(radius, ofGetHeight()-radius);
	
//	xVel = ofRandom(1, 2);
//	yVel = ofRandom(1, 2);
	
	color.set(240, 100);
	
//	font.load(OF_TTF_SANS, 16);
}

//--------------------------------------------------------------
void Circle::update(){
	ofApp *app = (ofApp*)ofGetAppPtr();
	pixelX = app->pixelX;
	pixelY = app->pixelY;
	
	
	if (inside) {
		if (app->state == &app->yearState) {
			app->yearState.year = title;
//			app->lock.setVolume(1);
			
		} else if (app->state == &app->monthState) {
			app->monthState.month = title;
//			app->lock.setVolume(1);
		}

	} else {
//		app->lock.setVolume(0);
//		if (app->state == &app->yearState) {
//			app->yearState.year = "Specify Target";
//		} else if (app->state == &app->monthState) {
//			app->monthState.month = "Specify Target";
//		}
	}
	
//	x += xVel;
//	y += yVel;
	
//	Check laser location against the circle position
	if (app->laser) {
		if (ofDist(pixelX, pixelY, x, y) < radius) {
			color.set(240, 200);
			inside = true;
		} else {
			color.set(240, 100);
			inside = false;
		}
	}
	
	
//	if (x-radius < 0) {
//		x = 0+radius;
//		xVel = -xVel;
//	}
//	
//	if (x+radius > ofGetWidth()) {
//		x = ofGetWidth()-radius;
//		xVel = -xVel;
//	}
//	
//	if (y-radius < 0) {
//		y = 0+radius;
//		yVel = -yVel;
//	}
//	
//	if (y+radius > ofGetHeight()) {
//		y = ofGetHeight()-radius;
//		yVel = -yVel;
//	}
	
}

//--------------------------------------------------------------
void Circle::draw(){
	ofApp *app = (ofApp *)ofGetAppPtr();
	ofSetColor(color);
	ofDrawCircle(x, y, radius);
	
	if (inside) {
		if (app->laser) {
			app->overlay2.draw(pixelX, pixelY);
		} else {
			app->overlay2.draw(ofGetMouseX(), ofGetMouseY());
		}
	}
	
//	ofSetColor(100);
//	font.drawString(title, x-(font.stringWidth(title)/2), y);
}

//--------------------------------------------------------------
void Circle::keyPressed(int key){
	ofApp *app = (ofApp *)ofGetAppPtr();
	if (key == ' ') {
		if (inside) {
			if (app->state == &app->startState) {
				app->state = &app->yearState;
			} else if (app->state == &app->yearState) {
				yearSelected = title;
				app->fire.play();
				app->monthState.setup();
				app->state = &app->monthState;
			} else if (app->state == &app->monthState) {
				monthSelected = title;
				app->fire.play();
				app->attackState.setup();
				app->state = &app->attackState;
			}
		}
	}
}

//--------------------------------------------------------------
void Circle::keyReleased(int key){
	
}

//--------------------------------------------------------------
void Circle::mouseMoved(int x, int y ){
	ofApp *app = (ofApp *)ofGetAppPtr();
	if (ofDist(x, y, this->x, this->y) < radius) {
		color.set(240, 200);
		inside = true;
	} else {
		color.set(240, 100);
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
			app->fire.play();
			app->monthState.setup();
			app->state = &app->monthState;
		} else if (app->state == &app->monthState) {
			monthSelected = title;
			app->fire.play();
			app->attackState.setup();
			app->state = &app->attackState;
		}
	}
}