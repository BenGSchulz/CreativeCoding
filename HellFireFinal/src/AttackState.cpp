//
//  AttackState.cpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#include "AttackState.hpp"
#include "Circle.hpp"
#include "ofApp.h"

//--------------------------------------------------------------
void AttackState::setup(){

	year = Circle::yearSelected;
	month = Circle::monthSelected;
	csv.load("DroneStrikes.csv");
	
	launch.load("launch.wav");
	impact.load("impact.wav");
	launch.play();
	
	children.load("children.jpg");
	aftermath.load("aftermath.jpg");
	backfire.load("backfire.jpg");
	
	font.load(OF_TTF_SANS, 20);
	
	start = true;
	childrenB = false;
	aftermathB = false;
	backfireB = false;
	inButton = false;
	
	rand = ofRandom(1);
	
	buttonColor.set(240, 200);
	
	if (year.compare("2004") == 0) {
		yearIndex = 0;
	} else if (year.compare("2005") == 0) {
		yearIndex = 12;
	} else if (year.compare("2006") == 0) {
		yearIndex = 12*2;
	} else if (year.compare("2007") == 0) {
		yearIndex = 12*3;
	} else if (year.compare("2008") == 0) {
		yearIndex = 12*4;
	} else if (year.compare("2009") == 0) {
		yearIndex = 12*5;
	} else if (year.compare("2010") == 0) {
		yearIndex = 12*6;
	} else if (year.compare("2011") == 0) {
		yearIndex = 12*7;
	} else if (year.compare("2012") == 0) {
		yearIndex = 12*8;
	} else if (year.compare("2013") == 0) {
		yearIndex = 12*9;
	} else if (year.compare("2014") == 0) {
		yearIndex = 12*10;
	} else if (year.compare("2015") == 0) {
		yearIndex = 12*11;
	}
	
	if (month.compare("Jan.") == 0) {
		monthIndex = yearIndex;
	} else if (month.compare("Feb.") == 0) {
		monthIndex = yearIndex+1;
	} else if (month.compare("Mar.") == 0) {
		monthIndex = yearIndex+2;
	} else if (month.compare("Apr.") == 0) {
		monthIndex = yearIndex+3;
	} else if (month.compare("May") == 0) {
		monthIndex = yearIndex+4;
	} else if (month.compare("Jun.") == 0) {
		monthIndex = yearIndex+5;
	} else if (month.compare("Jul.") == 0) {
		monthIndex = yearIndex+6;
	} else if (month.compare("Aug.") == 0) {
		monthIndex = yearIndex+7;
	} else if (month.compare("Sep.") == 0) {
		monthIndex = yearIndex+8;
	} else if (month.compare("Oct.") == 0) {
		monthIndex = yearIndex+9;
	} else if (month.compare("Nov.") == 0) {
		monthIndex = yearIndex+10;
	} else if (month.compare("Dec.") == 0) {
		monthIndex = yearIndex+11;
	}
	
	numAttacks = csv.getRow(monthIndex).getString(2);
	numDeaths = csv.getRow(monthIndex).getString(3);
	numChildren = csv.getRow(monthIndex).getString(4);
	
	childrenI = std::stoi(numChildren);
	deaths = std::stoi(numDeaths);
	attacks = std::stoi(numAttacks);
}

//--------------------------------------------------------------
void AttackState::update(){
	
	if (!launch.isPlaying()&&start) {
		impact.play();
		start=false;
	}
	
	if (!impact.isPlaying()&&!start) {
		if (childrenI > 0) {
			childrenB = true;
		} else {
			if (rand > .5) {
				aftermathB = true;
			} else {
				backfireB = true;
			}
		}
	}
}

//--------------------------------------------------------------
void AttackState::draw(){
	if (start ) {
		ofBackground(0);
	}
	
	ofSetColor(255);
	if (childrenB) {
		children.draw(ofGetWidth()/2, ofGetHeight()/2);
	} else if (aftermathB) {
		aftermath.draw(ofGetWidth()/2, ofGetHeight()/2);
	} else if (backfireB) {
		backfire.draw(ofGetWidth()/2, ofGetHeight()/2);
	}
	if (childrenB||aftermathB||backfireB) {
		ofShowCursor();
		ofSetColor(0);
		ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/4-(font.stringHeight("Number of deaths in " + month + " of " + year + ": " + numDeaths)/2), font.stringWidth("Number of attacks in " + month + " of " + year + ": " + numAttacks)+5, font.stringHeight("Number of attacks in " + month + " of " + year + ": " + numAttacks)+5);
		ofDrawRectangle(ofGetWidth()/2, ofGetHeight()/2-(font.stringHeight("Number of deaths in " + month + " of " + year + ": " + numDeaths)/2), font.stringWidth("Number of deaths in " + month + " of " + year + ": " + numDeaths)+5, font.stringHeight("Number of deaths in " + month + " of " + year + ": " + numDeaths)+5);
		ofDrawRectangle(ofGetWidth()/2, 3*ofGetHeight()/4-(font.stringHeight("Number of deaths in " + month + " of " + year + ": " + numDeaths)/2), font.stringWidth("Number of child deaths in " + month + " of " + year + ": " + numChildren)+5, font.stringHeight("Number of child deaths in " + month + " of " + year + ": " + numChildren)+5);
		
		
		ofSetColor(ofColor::red);
		font.drawString("Number of attacks in " + month + " of " + year + ": " + numAttacks, ofGetWidth()/2-(font.stringWidth("Number of attacks in " + month + " of " + year + ": " + numAttacks)/2), ofGetHeight()/4);
		font.drawString("Number of deaths in " + month + " of " + year + ": " + numDeaths, ofGetWidth()/2-(font.stringWidth("Number of deaths in " + month + " of " + year + ": " + numDeaths)/2), ofGetHeight()/2);
		font.drawString("Number of child deaths in " + month + " of " + year + ": " + numChildren, ofGetWidth()/2-(font.stringWidth("Number of child deaths in " + month + " of " + year + ": " + numChildren)/2), 3*ofGetHeight()/4);
		
		
		ofSetColor(buttonColor);
		ofDrawRectRounded(57, 32, 70, 15, 5);
		
		ofSetColor(100);
		ofDrawBitmapString("Redeploy", 25, 30);
	}

	
//	ofDrawBitmapString("Number of attacks in " + month + "of " + year + ": " + numAttacks, ofGetWidth()/2, ofGetHeight()/4);
//	ofDrawBitmapString("Number of deaths in " + month + "of " + year + ": " + numDeaths, ofGetWidth()/2, ofGetHeight()/2);
//	ofDrawBitmapString("Number of child deaths in " + month + "of " + year + ": " + numChildren, ofGetWidth()/2, 3*ofGetHeight()/4);

}

//--------------------------------------------------------------
void AttackState::exit(){
}

//--------------------------------------------------------------
void AttackState::keyPressed(int key){
	
}

//--------------------------------------------------------------
void AttackState::keyReleased(int key){
	
}

//--------------------------------------------------------------
void AttackState::mouseMoved(int x, int y ){
	if (ofDist(x, y, 57, 52) < 25) {
		buttonColor.set(240, 250);
		inButton = true;
	} else {
		buttonColor.set(240, 200);
		inButton = false;
	}
}
//--------------------------------------------------------------
void AttackState::mouseReleased(int x, int y, int button){
	ofApp *app = (ofApp *)ofGetAppPtr();
	if (inButton) {
		app->state = &app->yearState;
	}
}