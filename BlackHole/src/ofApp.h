#pragma once

#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxGui.h"

class CustomParticle : public ofxBox2dCircle {
	
public:
	CustomParticle() {
	}
	ofColor color;
	void draw() {
		//float radius;
		
		glPushMatrix();
		glTranslatef(getPosition().x, getPosition().y, 0);
		
		ofSetColor(255, 246, 222);
		ofFill();
		ofDrawCircle(0, 0, getRadius());
		
		glPopMatrix();
		
	}
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
	
		//bool withinRadius(CustomParticle p);
	
	
	bool bForce = true;
	bool guiDraw = true;
	float centerRadius;
	
	ofxBox2d box2d;
	vector<shared_ptr<CustomParticle>> customParticles;
	
	ofVec2f center = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
	
	ofxPanel gui;
	ofxFloatSlider strengthS;
	ofxFloatSlider sizeS;
	ofxFloatSlider densityS;
	ofxFloatSlider bounceS;
	ofxFloatSlider frictionS;
	ofxToggle grid;
	ofxToggle random;
		
};
