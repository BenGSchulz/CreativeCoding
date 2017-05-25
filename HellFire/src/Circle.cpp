//
//  Circle.cpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#include "Circle.hpp"
#include "ofApp.h"

//--------------------------------------------------------------
Circle::Circle(string title, float radius) {
	this->title = title;
	this->radius = radius;
}

//--------------------------------------------------------------
void Circle::setup(){
//	ofApp *app = (ofApp*)ofGetAppPtr();
//	world = app->world;
	
	x = ofRandom(ofGetWidth());
	y = ofRandom(ofGetHeight());
	
	xVel = ofRandom(1, 3);
	yVel = ofRandom(1, 3);

//	ofxBox2dCircle::setup(world.getWorld(), x, y, radius);
//	setPhysics(.5, 1, 1);

//	setVelocity(xVel, yVel);
	
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
	
//	world.update();
	
	//circ.setPosition(x, y);
	
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
//	glPushMatrix();
//	glTranslatef(getPosition().x, getPosition().y, 0);
//	
//	ofSetColor(color);
//	ofFill();
//	ofDrawCircle(0, 0, getRadius());
//	
//	glPopMatrix();
	
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
	if (ofDist(x, y, this->x, this->y) < radius) {
		color.set(178, 17, 0);
	}
}

//--------------------------------------------------------------
void Circle::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void Circle::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void Circle::mouseReleased(int x, int y, int button){
	ofApp *app = (ofApp *)ofGetAppPtr();
	if (ofDist(x, y, this->x, this->y) < radius) {
		if (app->state == &app->startState) {
			app->state == &app->yearState;
		} else if (app->state == &app->yearState) {
			app->state == &app->monthState;
		} else if (app->state == &app->monthState) {
			app->state == &app->attackState;
		}
	}
}