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
	lock.load("lock.wav");
	lock.setLoop(true);
	lock.setVolume(0);
	lock.play();
	fire.load("fire.wav");
	
	drone.load("drone.wav");
	drone.setLoop(true);
	drone.setVolume(0);
	drone.play();
	
	pixelX.setSize(15);
	pixelY.setSize(15);
	
	startState.setup();
	yearState.setup();
	monthState.firstLoad = true;
//	monthState.setup();
	
	laser = false;
	
	state = &startState;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (state != &startState) {
		grabber.update();
	}
	
	if (state == &yearState || state == &monthState) {
//		if (yearState.target||monthState.target) {
//			lock.setVolume(1);
//		} else {
//			lock.setVolume(0);
//		}
		drone.setVolume(1);
	} else {
		drone.setVolume(0);
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
	}
//	  else if (state == &attackState) {
//		bg3.draw(ofGetWidth()/2, ofGetHeight()/2);
//	}
	
	
	if (state != &startState && state != &attackState) {
//		grabber.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
		
		ofHideCursor();
		
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
					brightest.set(ofGetWidth()-x, y);
				}
			}
		}
		
		pixelX = brightest.x;
		pixelY = brightest.y;
		
		if (laser) {
			overlay.draw(pixelX, pixelY);
		} else {
			overlay.draw(ofGetMouseX(), ofGetMouseY());
		}

		// scale brightest pixel position from range within grabber image
		// to range on the screen
//		pixelX = ofMap(brightest.x, 0, grabber.getWidth(), 0, ofGetWidth());
//		pixelY = ofMap(brightest.y, 0, grabber.getHeight(), 0, ofGetHeight());
		
//		ofSetColor(255, 0, 0);
//		ofDrawCircle(pixelX, pixelY, 5);

	}
	


	state->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'l') {
		laser = !laser;
	}
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
