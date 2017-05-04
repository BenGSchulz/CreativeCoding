//
//  StartView.cpp
//  Project1
//
//  Created by Ben Schulz on 5/2/17.
//
//

#include "StartView.hpp"

#include "ofApp.h"

//StartView::StartView() {
//	
//}

void StartView::setup() {

	titleFont.load(OF_TTF_SANS, 80);
	textFont.load(OF_TTF_SANS, 30);
	
	buttonColor.set(179, 0, 0);
	
	gui.setup();
	gui.add(chart.setup("Go to chart"));

}

void StartView::update() {
//	if (ofGetMousePressed()) {
//		mouseClicked = true;
//	}

	mouseMoved();
}

void StartView::draw() {
	ofBackground(0);
	ofSetRectMode(OF_RECTMODE_CENTER);
	
	gui.draw();
	
	ofSetColor(150);
	titleFont.drawString("LYRICAL", ofGetWidth()/2-(titleFont.stringWidth("LYRICAL")/2), ofGetHeight()/3);
	ofDrawRectRounded(ofGetWidth()/2, ofGetHeight()/2-10, textFont.stringWidth("Get Chart Tracks")+25, 80, 20);
	
	ofSetColor(buttonColor);
	ofDrawRectRounded(ofGetWidth()/2, ofGetHeight()/2-10, textFont.stringWidth("Get Chart Tracks")+20, 75, 20);
	
	ofSetColor(150);
	textFont.drawString("Get Chart Tracks", ofGetWidth()/2-(textFont.stringWidth("Get Chart Tracks")/2), ofGetHeight()/2);
}

void StartView::exit() {
	
}

void StartView::mouseMoved() {
	float x = ofGetMouseX();
	float y = ofGetMouseY();
	
	if (!(x < (ofGetWidth()/2 - (textFont.stringWidth("Get Chart Tracks")+20)/2) || x > (ofGetWidth()/2 + (textFont.stringWidth("Get Chart Tracks")+20)/2) || y < ofGetHeight()/2-48 || y > ofGetHeight()/2+48)) {
		
		buttonColor.set(127, 0, 0);
		
		if (ofGetMousePressed()) {
			//mouseClicked = false;
			ofApp *app = (ofApp *)ofGetAppPtr();
			app->state = &app->chartView;

			//goChart = true;
		}
	} else {
		buttonColor.set(179, 0, 0);
	}
	
	//ofLogNotice() << "x: " + x + " y: " + y;
}



