//
//  AttackState.cpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#include "AttackState.hpp"
#include "Circle.hpp"

//--------------------------------------------------------------
void AttackState::setup(){
	year = Circle::yearSelected;
	month = Circle::monthSelected;
	csv.load("DroneStrikes.csv");
	
	
	if (year.compare("2004") == 0) {
		yearIndex = 0;
	} else if (year.compare("2005") == 0) {
		yearIndex = 12;
	} else if (year.compare("2006") == 0) {
		yearIndex = 24;
	} else if (year.compare("2007") == 0) {
		yearIndex = 36;
	} else if (year.compare("2008") == 0) {
		yearIndex = 48;
	} else if (year.compare("2009") == 0) {
		yearIndex = 60;
	} else if (year.compare("2010") == 0) {
		yearIndex = 72;
	} else if (year.compare("2011") == 0) {
		yearIndex = 84;
	} else if (year.compare("2012") == 0) {
		yearIndex = 96;
	} else if (year.compare("2013") == 0) {
		yearIndex = 108;
	} else if (year.compare("2014") == 0) {
		yearIndex = 120;
	} else if (year.compare("2015") == 0) {
		yearIndex = 132;
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
	
}

//--------------------------------------------------------------
void AttackState::update(){

}

//--------------------------------------------------------------
void AttackState::draw(){
	ofSetColor(ofColor::green);
	ofDrawBitmapString("Number of attacks in " + month + "of " + year + ": " + numAttacks, ofGetWidth()/2, ofGetHeight()/4);
	ofDrawBitmapString("Number of deaths in " + month + "of " + year + ": " + numDeaths, ofGetWidth()/2, ofGetHeight()/2);
	ofDrawBitmapString("Number of child deaths in " + month + "of " + year + ": " + numChildren, ofGetWidth()/2, 3*ofGetHeight()/4);
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

}
//--------------------------------------------------------------
void AttackState::mouseReleased(int x, int y, int button){

}