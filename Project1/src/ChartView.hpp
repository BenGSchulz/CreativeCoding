//
//  ChartView.hpp
//  Project1
//
//  Created by Ben Schulz on 5/2/17.
//
//

#ifndef ChartView_hpp
#define ChartView_hpp

#include "ofMain.h"
#include "State.hpp"

#include "ofxJSON.h"
#include "Tracks.hpp"
#include "ofxGui.h"

#include <stdio.h>

class ChartView : public State {
	
public:
	
	//ChartView();
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	
	void checkMouse();
	
	//void checkLyrics();
	

	
	int numTracks = 5;
	
	ofxJSONElement jsonChart;
	
	ofTrueTypeFont backFont;
	
	vector<Tracks *> tracks;
	
	ofColor buttonColor;
	
	ofxPanel gui;
	ofxButton back;
	
	//bool lyrics = false;
	
	//bool mouseClicked = false;
	
};



#endif /* ChartView_hpp */
