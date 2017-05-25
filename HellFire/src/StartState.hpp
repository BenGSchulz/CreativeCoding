//
//  StartState.hpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#ifndef StartState_hpp
#define StartState_hpp

#include <stdio.h>
#include "ofMain.h"
#include "State.hpp"


class StartState : public State {
	public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void mouseMoved();
	
	ofTrueTypeFont titleFont;
	ofTrueTypeFont textFont;
	
	ofColor buttonColor;
	
};

#endif /* StartState_hpp */
