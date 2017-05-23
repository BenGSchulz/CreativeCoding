//
//  Circles.cpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#include "Circles.hpp"
#include "ofApp.h"

//--------------------------------------------------------------
Circles::Circles(string title, float radius) {
	this->title = title;
	this->radius = radius;
}

//--------------------------------------------------------------
void Circles::setup(){
	ofApp *app = (ofApp*)ofGetAppPtr();
	world = app->world;
	circle.setup(world.getWorld(), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), radius);
}

//--------------------------------------------------------------
void Circles::update(){
	
}

//--------------------------------------------------------------
void Circles::draw(){
	
}

//--------------------------------------------------------------
void Circles::keyPressed(int key){
	
}

//--------------------------------------------------------------
void Circles::keyReleased(int key){
	
}

//--------------------------------------------------------------
void Circles::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void Circles::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void Circles::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void Circles::mouseReleased(int x, int y, int button){
	
}