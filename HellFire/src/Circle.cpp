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
	ofApp *app = (ofApp*)ofGetAppPtr();
	world = app->world;

	circ.setup(world.getWorld(), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), radius);
	xVel = ofRandom(-3, 3);
	yVel = ofRandom(-3, 3);
	circ.setVelocity(xVel, yVel);
	
	color.set(127, 12, 0);
	
	font.load(OF_TTF_SANS, 16);
}

//--------------------------------------------------------------
void Circle::update(){
	ofApp *app = (ofApp*)ofGetAppPtr();
	pixelX = app->pixelX;
	pixelY = app->pixelY;
	
	world.update();
	
	//Check laser location against the circle position
//	if (ofDist(pixelX, pixelY, circ.getPosition().x, circ.getPosition().y) < radius) {
//		if (app->state == &app->startState) {
//			app->state == &app->yearState;
//		} else if (app->state == &app->yearState) {
//			app->state == &app->monthState;
//		} else if (app->state == &app->monthState) {
//			app->state == &app->attackState;
//		}
//	}
	
	
	if (circ.getPosition().x-radius < 0) {
		circ.setPosition(0+radius, circ.getPosition().y);
		circ.setVelocity(-xVel, yVel);
	}
	
	if (circ.getPosition().x+radius > ofGetWidth()) {
		circ.setPosition(ofGetWidth()-radius, circ.getPosition().y);
		circ.setVelocity(-xVel, yVel);
	}
	
	if (circ.getPosition().y-radius < 0) {
		circ.setPosition(0+radius, circ.getPosition().y);
		circ.setVelocity(xVel, -yVel);
	}
	
	if (circ.getPosition().y+radius > ofGetHeight()) {
		circ.setPosition(ofGetHeight()-radius, circ.getPosition().y);
		circ.setVelocity(xVel, -yVel);
	}
	
}

//--------------------------------------------------------------
void Circle::draw(){
	ofSetColor(color);
	circ.draw();
	ofSetColor(100);
	font.drawString(title, circ.getPosition().x, circ.getPosition().y);
}

//--------------------------------------------------------------
void Circle::keyPressed(int key){
	
}

//--------------------------------------------------------------
void Circle::keyReleased(int key){
	
}

//--------------------------------------------------------------
void Circle::mouseMoved(int x, int y ){
	if (ofDist(x, y, circ.getPosition().x-(font.stringWidth(title)), circ.getPosition().y) < radius) {
		color.set(178, 17, 0);
	}
}

//--------------------------------------------------------------
void Circle::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void Circle::mousePressed(int x, int y, int button){
	ofApp *app = (ofApp *)ofGetAppPtr();
	if (ofDist(x, y, circ.getPosition().x, circ.getPosition().y) < radius) {
		if (app->state == &app->startState) {
			app->state == &app->yearState;
		} else if (app->state == &app->yearState) {
			app->state == &app->monthState;
		} else if (app->state == &app->monthState) {
			app->state == &app->attackState;
		}
	}
	
}

//--------------------------------------------------------------
void Circle::mouseReleased(int x, int y, int button){
	
}