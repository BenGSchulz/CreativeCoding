//
//  Tracks.cpp
//  Project1
//
//  Created by Ben Schulz on 4/27/17.
//
//

#include "Tracks.hpp"

ofTrueTypeFont Tracks::trackFont;
ofTrueTypeFont Tracks::artistFont;

Tracks::Tracks(string track, string artist, float radius, string trackID) {
	this->track = track;
	this->artist = artist;
	this->radius = radius;
	this->trackID = trackID;
}

void Tracks::setup() {
	
	ofSetCircleResolution(30);
	ofSetVerticalSync(true);
	
//	box2d.init();
//	box2d.setGravity(0, 0);
//	box2d.createBounds();
//	box2d.setFPS(60);
//	box2d.registerGrabbing();
	
	
	x = ofRandom(radius, ofGetWidth()-radius);
	y = ofRandom(radius, ofGetHeight()-radius);
	
	xVel = ofRandom(-1, 1);
	yVel = ofRandom(-1, 1);
	
	//circle.setup(box2d, x, y, radius);
	
	//color.set(ofRandom(150, 256), ofRandom(0, 50), ofRandom(0, 50));
	
	if (!trackFont.isLoaded()) {
		trackFont.load(OF_TTF_SANS, 18);
		artistFont.load(OF_TTF_SANS, 14);
	}

}

void Tracks::update() {
	
	//box2d.update();
	
	if (x < radius) {
		x = radius;
		xVel = -xVel;
	}
	if (x > ofGetWidth()-radius) {
		x = ofGetWidth()-radius;
		xVel = -xVel;
	}
	
	if (y < radius) {
		y = radius;
		yVel = -yVel;
	}
	if (y > ofGetHeight()-radius) {
		y = ofGetHeight()-radius;
		yVel = -yVel;
	}
	
	x += xVel;
	y += yVel;
	
}

void Tracks::draw() {
	ofSetColor(color);

	ofDrawCircle(x, y, radius);
	
	ofSetColor(150);
	trackFont.drawString(track, x-(trackFont.stringWidth(track)/2), y);
	artistFont.drawString(artist, x-(artistFont.stringWidth(artist)/2), y+14);
	
}