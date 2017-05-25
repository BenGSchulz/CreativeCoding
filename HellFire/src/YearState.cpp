//
//  YearState.cpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#include "YearState.hpp"

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
		circles.push_back(shared_ptr<Circle>(new Circle(year, 40)));
		Circle * p = circles.back().get();
		p->setup();
	}
}

//--------------------------------------------------------------
void YearState::update(){
	for (int i = 0; i < circles.size(); i++) {
		circles[i].get()->update();
	}
}

//--------------------------------------------------------------
void YearState::draw(){
	for (int i = 0; i < circles.size(); i++) {
		circles[i].get()->draw();
	}
}

//--------------------------------------------------------------
void YearState::exit(){
}