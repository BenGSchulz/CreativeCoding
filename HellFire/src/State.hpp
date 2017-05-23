//
//  State.hpp
//  HellFire
//
//  Created by Ben Schulz on 5/23/17.
//
//

#ifndef State_hpp
#define State_hpp

#include <stdio.h>
#include "ofMain.h"

class State {

	public:
	
	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void exit() = 0;

	
};

#endif /* State_hpp */
