//
//  YearState.hpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#ifndef YearState_hpp
#define YearState_hpp

#include <stdio.h>
#include "ofMain.h"
#include "State.hpp"
#include "ofxCsv.h"
#include "Circle.hpp"

class YearState : public State {
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	ofxCsv csv;
	
	std::vector<string> years;
	
	vector <shared_ptr<Circle> > circles;
	
};
#endif /* YearState_hpp */
