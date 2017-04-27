#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	
	ofSetVerticalSync(true);
	ofEnableAntiAliasing();
	
	ofFile chart(ofToDataPath("input.json"), ofFile::ReadWrite);
	ofFile lyrics(ofToDataPath("lyrics.json"), ofFile::ReadWrite);
	
	ofHttpResponse chartResponse = ofLoadURL("https://api.musixmatch.com/ws/1.1/chart.tracks.get?format=jsonp&callback=callback&page=1&page_size=5&country=us&apikey=926f6fc42dc0a0822fef9ca8491ac332");
	
	if (chart.exists()) {
		string data = chartResponse.data;
		if (data.find("callback") != string::npos) {
			data = data.substr(9, data.length()-11);
		}
		chart << data;
		ofLogNotice() << data;
		json.open("input.json");
	} else {
		chart.create();
	}
	
	
	for (int i = 0; i < numTracks; i++) {
		string track = json["message"]["body"]["track_list"][i]["track"]["track_name"].asString();
		string artist = json["message"]["body"]["track_list"][i]["track"]["artist_name"].asString();
		float radius = 150-(i*10);
		Tracks *t = new Tracks(track, artist, radius);
		t->setup();
		tracks.push_back(t);
	}

	
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < tracks.size(); i++) {
		tracks[i]->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackground(0);
	ofSetColor(200, 50, 50);
	
	for (int i = 0; i < tracks.size(); i++) {
		tracks[i]->draw();
	}

	
	//string tracks[20];
	
	
	
//	string track1 = json["message"]["body"]["track_list"][0]["track"]["track_name"].asString();
//	string track2 = json["message"]["body"]["track_list"][1]["track"]["track_name"].asString();
	
//	std::stringstream stream;
//	
//	stream << "Track Name 1: " << json["message"]["body"]["track_list"][0]["track"]["track_name"].asString() << std::endl;
//	stream << "	Artist: " << json["message"]["body"]["track_list"][0]["track"]["artist_name"].asString() << std::endl;
//	
//	stream << "Track Name 2: " << json["message"]["body"]["track_list"][1]["track"]["track_name"].asString() << std::endl;
//	stream << "	Artist: " << json["message"]["body"]["track_list"][1]["track"]["artist_name"].asString() << std::endl;
//	
//	stream << "Track Name 3: " << json["message"]["body"]["track_list"][2]["track"]["track_name"].asString() << std::endl;
//	stream << "	Artist: " << json["message"]["body"]["track_list"][2]["track"]["artist_name"].asString() << std::endl;
//	
//	ofDrawBitmapString(stream.str(), 10, 14);
	
}

//--------------------------------------------------------------
void ofApp::exit(){
	for (int i = 0; i < tracks.size(); i++) {
		delete tracks[i];
	}
	tracks.clear();
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
