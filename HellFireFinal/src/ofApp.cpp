#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	grabber.setup(ofGetWidth(), ofGetHeight());
	
	overlay.load("overlay.png");
	predator.load("predator.jpg");
	bg1.load("background1.jpg");
	bg2.load("background2.jpg");
	bg3.load("background3.jpg");
	overlay2.load("overlay2.png");

	
//	if (overlay.load("overlay.png")) {
//		return;
//	} else {
//		ofLog() << "Image not loaded!";
//	}
	
	pixelX.setSize(20);
	pixelY.setSize(20);
	
	startState.setup();
	yearState.setup();
//	monthState.setup();
	
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
	ofSetColor(255);
	if (state == &startState) {
		predator.draw(ofGetWidth()/2, ofGetHeight()/2);
	} else if (state == &yearState) {
		bg1.draw(ofGetWidth()/2, ofGetHeight()/2);
	} else if (state == &monthState) {
		bg2.draw(ofGetWidth()/2, ofGetHeight()/2);
	} else if (state == &attackState) {
		bg3.draw(ofGetWidth()/2, ofGetHeight()/2);
	}
	
	overlay.draw(ofGetMouseX(), ofGetMouseY());
	
	if (state != &startState) {
//		grabber.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
		
		float maxBrightness = 0; // max brightness found when comparing
		ofPoint brightest; // position of the current brightest pixel found
		
		// check each pixel and look for the brightest
		ofPixels &pixels = grabber.getPixels(); // pixel data ref
		for(int y = 0; y < pixels.getHeight(); y ++) {
			for(int x = 0; x < pixels.getWidth(); x ++) {
				ofColor c = pixels.getColor(x, y);
				
				// compare this pixel's color to see if it's the
				// current brightest pixel that is red, if so update the brightest pos
				//c.r > 200 && c.g < 50 && c.b < 50 &&
				if(c.getBrightness() > maxBrightness) {
					maxBrightness = c.getBrightness();
					brightest.set(x, y);
				}
			}
		}
		
		pixelX = brightest.x;
		pixelY = brightest.y;
		// scale brightest pixel position from range within grabber image
		// to range on the screen
//		pixelX = ofMap(brightest.x, 0, grabber.getWidth(), 0, ofGetWidth());
//		pixelY = ofMap(brightest.y, 0, grabber.getHeight(), 0, ofGetHeight());
		
		ofSetColor(255, 0, 0);
		ofDrawCircle(pixelX, pixelY, 5);

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
