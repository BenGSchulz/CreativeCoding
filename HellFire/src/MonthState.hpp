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

class MonthState : public State {
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
};
#endif /* MonthState_hpp */
