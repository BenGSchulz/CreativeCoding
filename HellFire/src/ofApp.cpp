#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	grabber.setup(960, 720);
	
	pixelX.setSize(20);
	pixelY.setSize(20);
	
	startState.setup();
	yearState.setup();
	monthState.setup();
	
	state = &startState;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (state != &startState) {
		grabber.update();
	}

	state->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (state != &startState) {
		ofSetColor(255);
		grabber.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
		
		float maxBrightness = 0; // max brightness found when comparing
		ofPoint brightest; // position of the current brightest pixel found
		
		// check each pixel and look for the brightest
		ofPixels &pixels = grabber.getPixels(); // pixel data ref
		for(int y = 0; y < pixels.getHeight(); y = y + 1) {
			for(int x = 0; x < pixels.getWidth(); x = x + 1) {
				ofColor c = pixels.getColor(x, y);
				
				// compare this pixel's color to see if it's the
				// current brightest pixel that is green, if so update the brightest pos
				if(c.r > 200 && c.g < 50 && c.b < 50 && c.getBrightness() > maxBrightness) {
					maxBrightness = c.getBrightness();
					brightest.set(x, y);
				}
			}
		}
		
		// scale brightest pixel position from range within grabber image
		// to range on the screen
		pixelX = ofMap(brightest.x, 0, grabber.getWidth(), 0, ofGetWidth());
		pixelY = ofMap(brightest.y, 0, grabber.getHeight(), 0, ofGetHeight());
	}
	


	state->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	state->keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	state->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	state->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	state->mouseReleased(x, y, button);
}
