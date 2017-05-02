//
//  LyricView.hpp
//  Project1
//
//  Created by Ben Schulz on 5/2/17.
//
//

#ifndef LyricView_hpp
#define LyricView_hpp

#include "ofMain.h"
#include "State.hpp"

#include <stdio.h>

class LyricView : public State {

public:
	
	//LyricView();
	
	void setup();
	void update();
	void draw();
	void exit();
	
	ofTrueTypeFont lyricFont;
	
};





#endif /* LyricView_hpp */
