//
//  StartView.hpp
//  Project1
//
//  Created by Ben Schulz on 5/2/17.
//
//

#ifndef StartView_hpp
#define StartView_hpp

#include "ofMain.h"
#include "State.hpp"

#include <stdio.h>

class StartView : public State {

public:
	
	//StartView();
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void mouseMoved();
	void goToChart();
	
	ofTrueTypeFont titleFont;
	ofTrueTypeFont textFont;
	
	ofColor buttonColor;
	
	bool goChart = false;
	
};







#endif /* StartView_hpp */
