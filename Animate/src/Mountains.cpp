//
//  Mountains.cpp
//  Animate
//
//  Created by Ben Schulz on 4/10/17.
//
//

#include "Mountains.hpp"

Mountains :: Mountains() {
	
}

void Mountains::draw(float noiseChange, float noiseHeight, float noiseOffset, ofColor color) {
	for (int i = 0; i < ofGetWidth(); i += 6){
		ofSetColor(ofColor::black, 25);
		ofDrawCircle(i, noiseOffset + (ofNoise(i*noiseChange, ofGetFrameNum()*noiseChange)*noiseHeight), 11);

		ofSetColor(color);
		ofDrawCircle(i, noiseOffset + (ofNoise(i*noiseChange, ofGetFrameNum()*noiseChange)*noiseHeight), 10);
	}
}
