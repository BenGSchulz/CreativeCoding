//
//  MonthState.hpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#ifndef MonthState_hpp
#define MonthState_hpp

#include <stdio.h>
#include "ofMain.h"
#include "State.hpp"
#include "ofxCsv.h"
#include "Circle.hpp"

class MonthState : public State {
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
	
	std::vector<string> months;
	
	std::string year;
	std::string month;
	
	vector<Circle *> circles;
	
	bool target, firstLoad;
	
};
#endif /* MonthState_hpp */
