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

class YearState : public State {
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
};
#endif /* YearState_hpp */
