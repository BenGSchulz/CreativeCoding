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

#include "ofxJSON.h"
#include "ofxGui.h"

#include <stdio.h>

class LyricView : public State {

public:
	
	//LyricView();
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void checkMouse();
	
	ofTrueTypeFont lyricFont;
	ofTrueTypeFont titleFont;
	ofTrueTypeFont artistFont;
	
	ofxJSONElement jsonLyrics;
	
	static string trackID;
	static string track;
	static string artist;
	
	string lyricBody;
	//string id1, id2, id3, id4, id5;
	
	float x, y, scrollSpeed;
	
	int artistOffset = 100;
	
	bool oversize = false;
	//bool mouseClicked = false;
	
	ofColor buttonColor;
	
	ofxPanel gui;
	ofxButton back;
	
};





#endif /* LyricView_hpp */
