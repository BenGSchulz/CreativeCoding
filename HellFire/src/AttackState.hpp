//
//  AttackState.hpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#ifndef AttackState_hpp
#define AttackState_hpp

#include <stdio.h>
#include "ofMain.h"
#include "State.hpp"
#include "ofxCsv.h"
#include "Circle.hpp"

class AttackState : public State {
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseReleased(int x, int y, int button);
	
	ofxCsv csv;
	
	std::string year;
	std::string month;
	
	int yearIndex, monthIndex;
	std::string numAttacks, numDeaths, numChildren;

};
#endif /* AttackState_hpp */
