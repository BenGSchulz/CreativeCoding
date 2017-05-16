//
//  LyricView.cpp
//  Project1
//
//  Created by Ben Schulz on 5/2/17.
//
//

#include "LyricView.hpp"
#include "ofApp.h"

//LyricView::LyricView() {
//	
//}

string LyricView::trackID = "";
string LyricView::track = "";
string LyricView::artist = "";

void LyricView::setup() {
	ofFile lyrics(ofToDataPath("lyrics.json"), ofFile::ReadWrite);
	
//	string URL = "https://api.musixmatch.com/ws/1.1/track.lyrics.get?format=jsonp&callback=callback&track_id=" + trackID + "&apikey=926f6fc42dc0a0822fef9ca8491ac332";
	
	//ofHttpResponse lyricResponse = ofLoadURL(URL);
	
	if (lyrics.exists()) {
//		string data = lyricResponse.data;
//		if (data.find("callback") != string::npos) {
//			data = data.substr(9, data.length()-11);
//		}
//		lyrics << data;
//		ofLogNotice() << data;
		jsonLyrics.open("lyrics.json");
	} else {
		lyrics.create();
//		string data = lyricResponse.data;
//		if (data.find("callback") != string::npos) {
//			data = data.substr(9, data.length()-11);
//		}
//		lyrics << data;
//		ofLogNotice() << data;
//		jsonLyrics.open("lyrics.json");
	}
	
	
	lyricBody = jsonLyrics["message"]["body"]["lyrics"]["lyrics_body"].asString();
	
	lyricFont.load(OF_TTF_SANS, 20);
	titleFont.load(OF_TTF_SANS, 40);
	artistFont.load(OF_TTF_SANS, 30);
	
	if (artistFont.stringWidth(artist)> 2*ofGetWidth()/3) {
		artist.insert(artist.size()/2, "\n");
		oversize = true;
	}
	
	if (oversize) {
		artistOffset = 200;
	} else {
		artistOffset = 100;
	}
	
	x = ofGetWidth()/2 - lyricFont.stringWidth(lyricBody)/2;
	y = ofGetHeight();
	scrollSpeed = 1;
	
	buttonColor.set(179,0,0);
	
	gui.setup();
	gui.add(back.setup("Back"));

	back = false;
	
}

void LyricView::update() {
	y -= scrollSpeed;
//	if (ofGetMousePressed()) {
//		mouseClicked = true;
//	}
	checkMouse();
	back = false;
}

void LyricView::draw() {
	gui.draw();
	
	ofSetColor(150);
	titleFont.drawString(track, x, y);
	artistFont.drawString(artist, x, y+50);
	lyricFont.drawString(lyricBody, x, y+artistOffset);
	
	ofSetRectMode(OF_RECTMODE_CORNER);
	
//	ofSetColor(150);
//	ofDrawRectRounded(10, 10, 35, 25, 5);
//	ofSetColor(buttonColor);
//	ofDrawRectRounded(12, 12, 30, 20, 5);
	

}

void LyricView::exit() {
	
}

void LyricView::checkMouse() {
	float x = ofGetMouseX();
	float y = ofGetMouseY();
	
	//if (!(x < 10 || x > 45 || y < 15 || y > 40)) {
		
		buttonColor.set(127, 0, 0);
		
		if (back) {
			//mouseClicked = false;
			ofApp *app = (ofApp *)ofGetAppPtr();
			app->state = &app->chartView;
		}
//	} else {
//		buttonColor.set(179, 0, 0);
//	}

}