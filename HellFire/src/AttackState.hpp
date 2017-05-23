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

class AttackState : public State {
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
};
#endif /* AttackState_hpp */
