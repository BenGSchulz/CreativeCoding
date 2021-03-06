//
//  YearState.cpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#include "YearState.hpp"
#include "ofApp.h"

//--------------------------------------------------------------
void YearState::setup(){
	csv.load("DroneStrikes.csv");
	for (int i = 0; i < csv.getNumRows(); i++) {
		years.push_back(csv.getRow(i).getString(0));
	}
	
	std::vector<string>::iterator it;
	it = std::unique(years.begin(), years.end());
	
	years.resize(std::distance(years.begin(), it));
	
	for (string year : years) {
		ofLog() << year;
		Circle *circ = new Circle(year, 5);
		circ->setup();
		circles.push_back(circ);
	}
	
	for (int i = 0; i < circles.size(); i++) {
		circles[i]->setup();
	}
	target = false;
}

//--------------------------------------------------------------
void YearState::update(){
//	ofApp *app = (ofApp*)ofGetAppPtr();
	for (int i = 0; i < circles.size(); i++) {
		circles[i]->update();
		if (circles[i]->inside) {
			target = true;
//			app->lock.setVolume(1);
		} else {
			target = false;
//			app->lock.setVolume(0);
		}
	}
	
//	for (int i = 0; i < circles.size(); i++) {
//		for (int j = 0; j < circles.size(); j++) {
//			if (i != j) {
//				if (circles[i]->x + circles[i]->radius + circles[j]->radius > circles[j]->x &&
//					circles[i]->x < circles[j]->x + circles[i]->radius + circles[j]->radius &&
//					circles[i]->y + circles[i]->radius + circles[j]->radius > circles[j]->y &&
//					circles[i]->y < circles[j]->y + circles[i]->radius + circles[j]->radius)
//				{
//					if (ofDist(circles[i]->x, circles[i]->y, circles[j]->x, circles[j]->y) < circles[i]->radius+circles[j]->radius) {
//						int newXVel1 = ((circles[i]->xVel*(circles[i]->radius-circles[j]->radius)) + (2*circles[j]->radius*circles[j]->xVel))/(circles[i]->radius+circles[j]->radius);
//						int newXVel2 = ((circles[j]->xVel*(circles[j]->radius-circles[i]->radius)) + (2*circles[i]->radius*circles[i]->xVel))/(circles[i]->radius+circles[j]->radius);
//						int newYVel1 = ((circles[i]->yVel*(circles[i]->radius-circles[j]->radius)) + (2*circles[j]->radius*circles[j]->yVel))/(circles[i]->radius+circles[j]->radius);
//						int newYVel2 = ((circles[j]->yVel*(circles[j]->radius-circles[i]->radius)) + (2*circles[i]->radius*circles[i]->yVel))/(circles[i]->radius+circles[j]->radius);
//						
//						circles[i]->x += newXVel1;
//						circles[i]->y += newYVel1;
//						circles[j]->x += newXVel2;
//						circles[j]->y += newYVel2;
//						
//						circles[i]->xVel = newXVel1;
//						circles[i]->yVel = newYVel1;
//						circles[j]->xVel = newXVel2;
//						circles[j]->yVel = newYVel2;
//
//					}
//				}
//			}
//		}
//	}
	
}

//--------------------------------------------------------------
void YearState::draw(){
	ofApp *app = (ofApp*)ofGetAppPtr();
	for (int i = 0; i < circles.size(); i++) {
		circles[i]->draw();
		
	}
	
	ofPushMatrix();
	ofSetColor(255);
	//	ofScale(3, 3);
	ofDrawBitmapString("Year: " + year, ofGetWidth()/4, 30);
	ofDrawBitmapString("Month: Specify Target", ofGetWidth()/2, 30);
	ofDrawBitmapString("Laser: " + std::to_string(app->laser), 3*ofGetWidth()/4, 30);
	ofPopMatrix();
}

//--------------------------------------------------------------
void YearState::keyPressed(int key){
	for (int i = 0; i < circles.size(); i++) {
		circles[i]->keyPressed(key);
	}
}

//--------------------------------------------------------------
void YearState::keyReleased(int key){
	
}

//--------------------------------------------------------------
void YearState::mouseMoved(int x, int y ){
	for (int i = 0; i < circles.size(); i++) {
		circles[i]->mouseMoved(x, y);
	}
}
//--------------------------------------------------------------
void YearState::mouseReleased(int x, int y, int button){
	for (int i = 0; i < circles.size(); i++) {
		circles[i]->mouseReleased(x, y, button);
	}
}

//--------------------------------------------------------------
void YearState::exit(){
	
}