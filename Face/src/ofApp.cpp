#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	ofSetCircleResolution(30);
	
	randRad = ofRandom(200, 300);
	
	headColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	eyesColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	mouthColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	hatColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
}

//--------------------------------------------------------------
void ofApp::update(){
	
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(20);
	ofNoFill();
	ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, randRad);
	ofFill();
	ofSetColor(headColor);
	ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, randRad);
	ofSetColor(mouthColor);
	ofDrawRectRounded(ofGetWidth()/2 - (7*randRad/6)/2, ofGetHeight()/2 + 3*randRad/10, 7*randRad/6, randRad/6, 20);
	ofDrawRectRounded(ofGetWidth()/2 - (7*randRad/6)/2, ofGetHeight()/2 + 3*randRad/10 + randRad/6, 7*randRad/6, randRad/6, 20);
	ofSetColor(noseColor);
	ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2 + randRad/10, randRad/5);
	ofSetColor(eyesColor);
	ofDrawEllipse(ofGetWidth()/2 - randRad/3, ofGetHeight()/2 - randRad/2, 4*randRad/7, randRad/3);
	ofDrawEllipse(ofGetWidth()/2 + randRad/3, ofGetHeight()/2 - randRad/2, 4*randRad/7, randRad/3);
	ofSetColor(244);
	ofDrawCircle(ofGetWidth()/2 - randRad/3, ofGetHeight()/2 - randRad/2, randRad/6);
	ofDrawCircle(ofGetWidth()/2 + randRad/3, ofGetHeight()/2 - randRad/2, randRad/6);
	ofSetColor(hatColor);
	ofDrawRectRounded(ofGetWidth()/2-(7*randRad/6)/2, ofGetHeight()/2 - (randRad + 3*randRad/4), 7*randRad/6, 3*randRad/4, 10);
	ofDrawRectRounded(ofGetWidth()/2-(10*randRad/6)/2, ofGetHeight()/2 - randRad, 10*randRad/6, randRad/9, 10);
	ofSetColor(25);
	ofDrawCircle(ofGetWidth()/2 - randRad/3, ofGetHeight()/2 - randRad/2, randRad/10);
	ofDrawCircle(ofGetWidth()/2 + randRad/3, ofGetHeight()/2 - randRad/2, randRad/10);


	ofSetColor(20);
	ofNoFill();
	
	ofDrawEllipse(ofGetWidth()/2 - randRad/3, ofGetHeight()/2 - randRad/2, 4*randRad/7, randRad/3);
	ofDrawEllipse(ofGetWidth()/2 + randRad/3, ofGetHeight()/2 - randRad/2, 4*randRad/7, randRad/3);
	
	ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2 + randRad/10, randRad/5);
	
	ofDrawRectRounded(ofGetWidth()/2 - (7*randRad/6)/2, ofGetHeight()/2 + 3*randRad/10, 7*randRad/6, randRad/6, 20);
	ofDrawRectRounded(ofGetWidth()/2 - (7*randRad/6)/2, ofGetHeight()/2 + 3*randRad/10 + randRad/6, 7*randRad/6, randRad/6, 20);
	
	ofDrawRectRounded(ofGetWidth()/2-(7*randRad/6)/2, ofGetHeight()/2 - (randRad + 3*randRad/4), 7*randRad/6, 3*randRad/4, 10);
	ofDrawRectRounded(ofGetWidth()/2-(10*randRad/6)/2, ofGetHeight()/2 - randRad, 10*randRad/6, randRad/9, 10);
	
	ofDrawCircle(ofGetWidth()/2 - randRad/3, ofGetHeight()/2 - randRad/2, randRad/6);
	ofDrawCircle(ofGetWidth()/2 + randRad/3, ofGetHeight()/2 - randRad/2, randRad/6);
	
	
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
	bool inHead = (ofDist(x, y, ofGetWidth()/2, ofGetHeight()/2) < randRad);
	bool inEyes = (ofDist(x, y, ofGetWidth()/2 - randRad/3, ofGetHeight()/2 - randRad/2) < randRad/6 || ofDist(x, y, ofGetWidth()/2 + randRad/3, ofGetHeight()/2 - randRad/2) < randRad/6);
	bool inMouth = !(x > ofGetWidth()/2 + (7*randRad/6)/2 || x < ofGetWidth()/2 - (7*randRad/6)/2 || y > ofGetHeight()/2 + 3*randRad/10 + randRad/3 || y < ofGetHeight()/2 + 3*randRad/10);
	bool inHat = (ofDist(x, y, ofGetWidth()/2, ofGetHeight()/2 - (randRad + 3*randRad/4)) < 7*randRad/6 || ofDist(x, y, ofGetWidth()/2, ofGetHeight()/2 - (randRad + 3*randRad/4)) < 7*randRad/6);
	bool inNose = (ofDist(x, y, ofGetWidth()/2, ofGetHeight()/2 + randRad/10) < randRad/5);
	
	
	if (inHead && !inEyes && !inMouth && !inNose) {
		headColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	} else if (inEyes) {
		eyesColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	} else if (inMouth) {
		mouthColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	} else if (inHat) {
		hatColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	} else if (inNose) {
		noseColor.set((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	} else if (!inHead && !inHat) {
		ofSetBackgroundColor((int)ofRandom(100, 255), (int)ofRandom(100, 255), (int)ofRandom(100, 255));
	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
