#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableAlphaBlending();
	ofSetCircleResolution(100);
	
	gui.setup();
	gui.add(gravity.setup("Gravity", ofVec2f(0.0, 0.0), ofVec2f(-.5, -.5), ofVec2f(1.5, 1.5)));
	gui.add(velocity.setup("Velocity", 0.99, 0.9, 1.1));
	gui.add(dissipation.setup("Dissipation", .99, .9, 1.1));
	gui.add(obstacleT.setup(false));
	gui.add(pos.setup("Position", ofVec2f(ofGetWidth()/2, ofGetHeight()/2), ofVec2f(0, 0), ofVec2f(ofGetWidth(), ofGetHeight())));
	
	width = 800;
	height = 700;
	
	// Initial Allocation
	//
	fluid.allocate(width, height, 0.5);
	
	
	fluid.begin();
	ofSetColor(0,0);
	ofSetColor(255);
	ofDrawCircle(width*0.5, height*0.35, 40);
	fluid.end();
	
	// Adding constant forces
	//
	fluid.addConstantForce(ofPoint(30, 400), ofPoint(0,-10), ofFloatColor(0.6,0.3,0.0), 10.f);
	
	ofSetWindowShape(width, height);
	
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// Adding temporal Force
	//
//	ofPoint m = ofPoint(mouseX,mouseY);
//	ofPoint d = (m - oldM)*15.0;
//	oldM = m;
//	ofPoint c = ofPoint(640*0.5, 480*0.5) - m;
//	c.normalize();
//	fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5)*sin(ofGetElapsedTimef()),3.0f);
	
	//  Update
	//

	
	fluid.dissipation = dissipation;
	fluid.velocityDissipation = velocity;
	
	fluid.setGravity(gravity);
	
	fluid.setUseObstacles(obstacleT);
	
	fluid.update();
	
	
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
	
	fluid.draw();
	
	gui.draw();
}

//--------------------------------------------------------------
//void ofApp::keyPressed(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::keyReleased(int key){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseMoved(int x, int y ){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseDragged(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mousePressed(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseReleased(int x, int y, int button){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseEntered(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::mouseExited(int x, int y){
//
//}
//
////--------------------------------------------------------------
//void ofApp::windowResized(int w, int h){
//
//}
//
////--------------------------------------------------------------
//void ofApp::gotMessage(ofMessage msg){
//
//}
//
////--------------------------------------------------------------
//void ofApp::dragEvent(ofDragInfo dragInfo){ 
//
//}
