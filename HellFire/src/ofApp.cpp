#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	world.init();
	world.setGravity(0, 0);
	world.createGround();
	world.setFPS(60.0);
	world.registerGrabbing();
	
	grabber.setup(720, 540);
	
	pixelX.setSize(20);
	pixelY.setSize(20);
	
	startState.setup();
	yearState.setup();
	monthState.setup();
	attackState.setup();
	
	state = &startState;
	
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	state->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	grabber.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	float maxBrightness = 0; // max brightness found when comparing
	ofPoint brightest; // position of the current brightest pixel found
	
	// check each pixel and look for the brightest
	ofPixels &pixels = grabber.getPixels(); // pixel data ref
	for(int y = 0; y < pixels.getHeight(); y = y + 1) {
		for(int x = 0; x < pixels.getWidth(); x = x + 1) {
			ofColor c = pixels.getColor(x, y);
			
			// compare this pixel's color to see if it's the
			// current brightest pixel that is green, if so update the brightest pos
			if(c.g > 200 && c.r < 100 && c.b < 100 && c.getBrightness() > maxBrightness) {
				maxBrightness = c.getBrightness();
				brightest.set(x, y);
			}
		}
	}
	
	// scale brightest pixel position from range within grabber image
	// to range on the screen
	pixelX = ofMap(brightest.x, 0, grabber.getWidth(), 0, ofGetWidth());
	pixelY = ofMap(brightest.y, 0, grabber.getHeight(), 0, ofGetHeight());

	state->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}
