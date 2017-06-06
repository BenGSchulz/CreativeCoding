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
}

//--------------------------------------------------------------
void StartState::draw(){
//	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	ofSetColor(255);
	//gui.draw();
	
	ofSetColor(150);
	titleFont.drawString("HellFIRE", ofGetWidth()/2-(titleFont.stringWidth("HellFIRE")/2), ofGetHeight()/3-50);
	ofDrawRectRounded(ofGetWidth()/2, 2*ofGetHeight()/3, textFont.stringWidth("Deploy Drone")+25, 80, 20);
	
	ofSetColor(buttonColor);
	ofDrawRectRounded(ofGetWidth()/2, 2*ofGetHeight()/3, textFont.stringWidth("Deploy Drone")+20, 75, 20);
	
	ofSetColor(150);
	textFont.drawString("Deploy Drone", ofGetWidth()/2-(textFont.stringWidth("Deploy Drone")/2), 2*ofGetHeight()/3+15);
//	ofSetRectMode(OF_RECTMODE_CORNER);
}

//--------------------------------------------------------------
void StartState::exit(){
}


//--------------------------------------------------------------
void StartState::keyPressed(int key){
	
}

//--------------------------------------------------------------
void StartState::keyReleased(int key){
	
}

//--------------------------------------------------------------
void StartState::mouseMoved(int x, int y ){
	if (!(x < (ofGetWidth()/2 - (textFont.stringWidth("Deploy Drone")+20)/2) || x > (ofGetWidth()/2 + (textFont.stringWidth("Deploy Drone")+20)/2) || y < 2*ofGetHeight()/3-48 || y > 2*ofGetHeight()/3+48)) {
		buttonColor.set(127, 0, 0);
		insideButton = true;
	}
	else {
		buttonColor.set(179, 0, 0);
		insideButton = false;
	}
}
//--------------------------------------------------------------
void StartState::mouseReleased(int x, int y, int button){
	if (insideButton) {
		ofApp *app = (ofApp *)ofGetAppPtr();
		app->state = &app->yearState;
	}
}
