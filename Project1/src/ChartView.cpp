//
//  ChartView.cpp
//  Project1
//
//  Created by Ben Schulz on 5/2/17.
//
//

#include "ChartView.hpp"
#include "ofApp.h"
#include "LyricView.hpp"

void ChartView::setup(){
	
	ofSetVerticalSync(true);
	ofEnableAntiAliasing();
	
	ofFile chart(ofToDataPath("chart.json"), ofFile::ReadWrite);
	
	ofHttpResponse chartResponse = ofLoadURL("https://api.musixmatch.com/ws/1.1/chart.tracks.get?format=jsonp&callback=callback&page=1&page_size=5&country=us&f_has_lyrics=true&apikey=926f6fc42dc0a0822fef9ca8491ac332");
	
	if (chart.exists()) {
		string data = chartResponse.data;
		if (data.find("callback") != string::npos) {
			data = data.substr(9, data.length()-11);
		}
		chart << data;
		ofLogNotice() << data;
		jsonChart.open("chart.json");
	} else {
		chart.create();
	}
	
	
	for (int i = numTracks-1; i >= 0; i--) {
		string track = jsonChart["message"]["body"]["track_list"][i]["track"]["track_name"].asString();
		string artist = jsonChart["message"]["body"]["track_list"][i]["track"]["artist_name"].asString();
		float radius = 150-(i*10);
		string trackID = jsonChart["message"]["body"]["track_list"][i]["track"]["track_id"].asString();
		Tracks *t = new Tracks(track, artist, radius, trackID);
		t->setup();
		t->color.set(179, 0, 0);
		tracks.push_back(t);
		
	}
	
	backFont.load(OF_TTF_SANS, 12);
	
	buttonColor.set(179, 0, 0);
}

//--------------------------------------------------------------
void ChartView::update(){
	
	for (int i = 0; i < tracks.size(); i++) {
		tracks[i]->update();
	}
	
	checkMouse();
	checkLyrics();
	
	
//	for (int i = 0; i < tracks.size(); i++) {
//		for (int j = i+1; j < tracks.size(); j++) {
//			if (tracks[i] != tracks[j]) {
//				if (ofDist(tracks[i]->x, tracks[i]->y, tracks[j]->x, tracks[j]->y) < (tracks[i]->radius+tracks[j]->radius)) {
//					tracks[i]->xVel = -tracks[i]->xVel;
//					tracks[i]->xVel = -tracks[i]->xVel;
//					tracks[j]->xVel = -tracks[j]->xVel;
//				}
//			}
//		}
//	}
}

//--------------------------------------------------------------
void ChartView::draw(){
	
	ofBackground(0);
	//ofSetColor(200, 50, 50);
	
	for (int i = 0; i < tracks.size(); i++) {
		tracks[i]->draw();
	}
	
	backFont.drawString("BACK", 10, 40);
	
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofSetColor(150);
	ofDrawRectRounded(10, 10, 35, 25, 5);
	ofSetColor(buttonColor);
	ofDrawRectRounded(12, 12, 30, 20, 5);
	
	
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
void ChartView::exit(){
	for (int i = 0; i < tracks.size(); i++) {
		delete tracks[i];
	}
	tracks.clear();
}

void ChartView::checkMouse() {
	int x = ofGetMouseX();
	int y = ofGetMouseY();
	
	for (int i = numTracks-1; i >= 0; i--) {
		if (ofDist(x, y, tracks[i]->x, tracks[i]->y) < tracks[i]->radius) {
			tracks[i]->color.set(127, 0, 0);
			if (ofGetMousePressed()) {
				LyricView::trackID = tracks[i]->trackID;
				LyricView::track = tracks[i]->track;
				LyricView::artist = tracks[i]->artist;
				lyrics = true;
			}
		} else {
			tracks[i]->color.set(179, 0, 0);
		}
	}
	
	if (!(x < 10 || x > 45 || y < 15 || y > 40)) {
		
		buttonColor.set(127, 0, 0);
		
		if (ofGetMousePressed()) {
			ofApp *app = (ofApp *)ofGetAppPtr();
			app->state = &app->startView;
		}
	} else {
		buttonColor.set(179, 0, 0);
	}
}

void ChartView::keyPressed(int key) {
	if (key == 49) {
		ofApp *app = (ofApp *)ofGetAppPtr();
		app->state = &app->startView;
	}
}

void ChartView::checkLyrics() {
	if (lyrics) {
		lyrics = false;
		ofApp *app = (ofApp *)ofGetAppPtr();
		app->lyricView.setup();
		app->state = &app->lyricView;
	}
}


