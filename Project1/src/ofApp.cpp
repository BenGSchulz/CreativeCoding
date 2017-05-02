#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	startView.setup();
	chartView.setup();
	lyricView.setup();
	
	//state = 1;
	
	state = &startView;

}

//--------------------------------------------------------------
void ofApp::update(){
	
//	switch (state) {
//		case 1:
//			startView.update();
//			break;
//			
//		case 2:
//			chartView.update();
//			break;
//		
//		case 3:
//			lyricView.update();
//			break;
//		
//		default:
//			break;
//	}
	
	state->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//	switch (state) {
//		case 1:
//			startView.draw();
//			break;
//			
//		case 2:
//			chartView.draw();
//			break;
//			
//		case 3:
//			lyricView.draw();
//			break;
//			
//		default:
//			break;
//	}
	
	state->draw();
}

//--------------------------------------------------------------
void ofApp::exit(){
	state->exit();
}

void ofApp::mouseMoved(int x, int y) {
	
}


