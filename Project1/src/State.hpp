//
//  State.hpp
//  Project1
//
//  Created by Ben Schulz on 5/2/17.
//
//

#ifndef State_hpp
#define State_hpp

#include "ofMain.h"

#include <stdio.h>

class State : public ofBaseApp {
	
public:
	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void exit() = 0;
	
	void keyPressed(int key){};
	
	virtual void mousePressed(int x, int y, int button){};

};



#endif /* State_hpp */
