//
//  StartState.cpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#include "StartState.hpp"
#include "ofApp.h"

//--------------------------------------------------------------
void StartState::setup(){
	
	titleFont.load(OF_TTF_SANS, 80);
	textFont.load(OF_TTF_SANS, 30);
	
	buttonColor.set(179, 0, 0);

}

//--------------------------------------------------------------
void StartState::update(){
	mouseMoved();
}

//--------------------------------------------------------------
void StartState::draw(){
	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofSetColor(255);
	//gui.draw();
	
	ofSetColor(150);
	titleFont.drawString("HellFIRE", ofGetWidth()/2-(titleFont.stringWidth("HellFIRE")/2), ofGetHeight()/3);
	ofDrawRectRounded(ofGetWidth()/2, ofGetHeight()/2-10, textFont.stringWidth("Show Years")+25, 80, 20);
	
	ofSetColor(buttonColor);
	ofDrawRectRounded(ofGetWidth()/2, ofGetHeight()/2-10, textFont.stringWidth("Show Years")+20, 75, 20);
	
	ofSetColor(150);
	textFont.drawString("Show Years", ofGetWidth()/2-(textFont.stringWidth("Show Years")/2), ofGetHeight()/2);
}

//--------------------------------------------------------------
void StartState::exit(){
}

//--------------------------------------------------------------
void StartState::mouseMoved() {
	float x = ofGetMouseX();
	float y = ofGetMouseY();
	
	if (!(x < (ofGetWidth()/2 - (textFont.stringWidth("Get Chart Tracks")+20)/2) || x > (ofGetWidth()/2 + (textFont.stringWidth("Get Chart Tracks")+20)/2) || y < ofGetHeight()/2-48 || y > ofGetHeight()/2+48)) {
		
		buttonColor.set(127, 0, 0);
		
		if (ofGetMousePressed()) {
			ofApp *app = (ofApp *)ofGetAppPtr();
			app->state = &app->yearState;
		}
		
	} else {
		buttonColor.set(179, 0, 0);
	}

}