#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofFile input(ofToDataPath("input.json"), ofFile::ReadWrite);
	//ofHttpResponse response = ofLoadURL("https://api.musixmatch.com/ws/1.1/chart.tracks.get?format=jsonp&callback=callback&page=1&page_size=3&country=us&apikey=926f6fc42dc0a0822fef9ca8491ac332");
	
	if (input.exists()) {
		//input << response.data;
		//ofLogNotice() << response.data;
		json.open("input.json");
	} else {
		input.create();
	}
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);
	ofSetColor(200, 50, 50);
	
	std::stringstream stream;
	
	stream << "Track Name 1: " << json["message"]["body"]["track_list"][0]["track"]["track_name"].asString() << std::endl;
	stream << "	Artist: " << json["message"]["body"]["track_list"][0]["track"]["artist_name"].asString() << std::endl;
	
	stream << "Track Name 2: " << json["message"]["body"]["track_list"][1]["track"]["track_name"].asString() << std::endl;
	stream << "	Artist: " << json["message"]["body"]["track_list"][1]["track"]["artist_name"].asString() << std::endl;
	
	stream << "Track Name 3: " << json["message"]["body"]["track_list"][2]["track"]["track_name"].asString() << std::endl;
	stream << "	Artist: " << json["message"]["body"]["track_list"][2]["track"]["artist_name"].asString() << std::endl;
	
	ofDrawBitmapString(stream.str(), 10, 14);
	
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
