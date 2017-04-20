#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255);
	ofSetBackgroundAuto(false);
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (drawBackground) {
		ofBackground(255);
	}
	
	m.draw(noiseChange, noiseHeight, noiseOffset, color);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' ') {
		drawBackground = !drawBackground;
	} else if (key == 'b') {
		color = ofColor::skyBlue;
	} else if (key == 'r') {
		color = ofColor::darkSalmon;
	} else if (key == 'w') {
		color = ofColor::white;
	} else if (key == '1') {
		noiseHeight = ofGetHeight();
		noiseOffset = 0;
	} else if (key == '2') {
		noiseHeight = ofGetHeight()/2;
		noiseOffset = ofGetHeight()/4;
	} else if (key == '3') {
		noiseHeight = ofGetHeight()/4;
		noiseOffset = 3*ofGetHeight()/8;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	noiseChange = ofMap(x, 0, ofGetWidth(), -0.005, 0.005);
}

void ofApp::mouseMoved(int x, int y) {
	//noiseHeight = ofMap(y, 0, ofGetHeight(), 100, ofGetHeight());
}

