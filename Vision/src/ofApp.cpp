#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetWindowTitle("Vision");
	ofBackground(255);
	
	grabber.setup(640, 480);
	haarFinderEyes.setup("haarcascade_eye.xml");
//	haarFinderSmile.setup("haarcascade_smile.xml");
//	haarFinderLeftEye.setup("haarcascade_lefteye_2splits.xml");
//	haarFinderRightEye.setup("haarcascade_righteye_2splits.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	ofPixels &pixels = grabber.getPixels();
	haarFinderEyes.findHaarObjects(pixels);
	
	
	for (int i = 0; i < haarFinderEyes.blobs.size(); i++) {
		Balls tempBall;
		tempBall.setup(haarFinderEyes.blobs[i].centroid.x, haarFinderEyes.blobs[i].centroid.y);
		balls.push_back(tempBall);
	}
	
	if (drawB) {
		for (int i = 0; i < balls.size(); i++) {
			if (balls[i].x > balls[i].xStart+30 || balls[i].y > balls[i].yStart+30  || balls[i].x < balls[i].xStart-30  || balls[i].y < balls[i].yStart-30 ) {
				balls.erase(balls.begin()+i);
			}
			
			balls[i].update();
		}
	}
	
	
//	haarFinderSmile.findHaarObjects(pixels);
//	haarFinderLeftEye.findHaarObjects(pixels);
//	haarFinderRightEye.findHaarObjects(pixels);
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	grabber.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	if (drawB) {
		for (int i = 0; i < balls.size(); i++) {
			balls[i].draw();
		}
	}
	
	ofDrawBitmapString("Draw: " + std::to_string(drawB), 10, 20);

//	haarFinderLeftEye.draw(0, 0);
//	haarFinderRightEye.draw(0, 0);

//	for (int i = 0; i < haarFinderEyes.blobs.size(); i++) {
//		Balls tempBall;
//		tempBall.setup(haarFinderEyes.blobs[i].centroid.x, haarFinderEyes.blobs[i].centroid.y);
	
//		ofDrawRectangle(haarFinderEyes.blobs[i].boundingRect);
//		ofDrawCircle(haarFinderEyes.blobs[i].centroid, 10);
//		haarFinderEyes.blobs[i].draw();
		
//		for (int j = 0; j < 20; j++) {
//			ofDrawLine(haarFinderEyes.blobs[i].centroid.x, haarFinderEyes.blobs[i].centroid.y,		ofRandom(haarFinderEyes.blobs[i].centroid.x+25, haarFinderEyes.blobs[i].centroid.x+70), ofRandom(haarFinderEyes.blobs[i].centroid.y+10, haarFinderEyes.blobs[i].centroid.y+20));
//		}

//	}
	
//	for (int i = 0; i < haarFinderSmile.blobs.size(); i++) {
//		//ofDrawRectangle(haarFinderSmile.blobs[i].boundingRect);
//		ofDrawCircle(haarFinderSmile.blobs[i].centroid, 10);
//		//haarFinderSmile.blobs[i].draw();
//	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == ' '); {
		drawB = !drawB;
	}
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
