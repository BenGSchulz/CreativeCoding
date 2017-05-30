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

class State : public ofBaseApp {

	public:
	
	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void exit() = 0;

	virtual void keyPressed(int key) = 0;
	virtual void keyReleased(int key) = 0;
	virtual void mouseMoved(int x, int y ) = 0;
	virtual void mouseReleased(int x, int y, int button) = 0;
	
};

#endif /* State_hpp */
