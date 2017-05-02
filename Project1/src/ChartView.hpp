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

#include <stdio.h>

class ChartView : public State{
	
public:
	
	//ChartView();
	
	void setup();
	void update();
	void draw();
	void exit();
	
	

	
	int numTracks = 5;
	
	ofxJSONElement jsonChart;
	ofxJSONElement jsonLyrics;
	
	vector<Tracks *> tracks;
	
};



#endif /* ChartView_hpp */
