#include "ofApp.h"

bool withinRadius(shared_ptr<CustomParticle> p);

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	ofBackground(0);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	bForce = false;
	centerRadius = 20;
	
	box2d.init();
	box2d.setGravity(0, 0);
	box2d.createGround();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();
	
	
	gui.setup();
	gui.add(strengthS.setup("Mass of Black Hole", 900, 500, 1300));
	gui.add(densityS.setup("Particle Density", -0.5, -1, 1));
	gui.add(bounceS.setup("Particle Bounce", 0, -1, 1));
	gui.add(frictionS.setup("Particle Friction", .1, -1, 1));
	gui.add(grid.setup("Grid Particles", false));
	gui.add(random.setup("Random Particles", false));
	gui.add(sizeS.setup("Particle Size(mass)", 1, 1, 20));

}

//--------------------------------------------------------------
void ofApp::update(){
	box2d.update();
	
	if (random) {
		if ((int)ofRandom(0,5) == 0) {
			customParticles.push_back(shared_ptr<CustomParticle>(new CustomParticle));
			CustomParticle * p = customParticles.back().get();
			p->setPhysics(densityS, bounceS, frictionS);
			p->setup(box2d.getWorld(), ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 1);
		}
		//random = false;
	}
	
	if (grid) {
		for (int i = 1; i <= ofGetHeight(); i += 10) {
			for (int j = 1; j < ofGetWidth(); j += 10) {
				customParticles.push_back(shared_ptr<CustomParticle>(new CustomParticle));
				CustomParticle * p = customParticles.back().get();
				p->setPhysics(densityS, bounceS, frictionS);
				p->setup(box2d.getWorld(), j, i, 1);
			}
		}
		grid = false;
	}
	
	if(bForce) {
		for(int i=0; i<customParticles.size(); i++) {
			float strength = (strengthS*customParticles[i].get()->getRadius())/pow((ofDist(customParticles[i].get()->getPosition().x, customParticles[i].get()->getPosition().y, center.x, center.y)), 2);
			
			ofClamp(strength, 0.001, 500);
			
			customParticles[i].get()->addAttractionPoint(center.x+18, center.y+16, strength);
			//customParticles[i].get()->setDamping(damping, damping);
		}
		
	}
	
	
	ofRemove(customParticles, withinRadius);
	ofRemove(customParticles, ofxBox2dBaseShape::shouldRemoveOffScreen);
}

//--------------------------------------------------------------
void ofApp::draw(){
	for(int i=0; i<customParticles.size(); i++) {
		customParticles[i].get()->draw();
		//customParticles[i].get()->addForce(ofVec2f(1, 0), .1);
	}
	
	
	ofSetColor(255, 255, 220);
	ofDrawCircle(center.x, center.y, centerRadius+1);
	ofSetColor(0);
	ofDrawCircle(center.x, center.y, centerRadius);
	
	if (guiDraw) gui.draw();
	ofSetColor(255);
	ofDrawBitmapString("Force on: " + std::to_string(bForce), 10, ofGetHeight()-10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'f') bForce = !bForce;
	
	if (key == 'd') {
		guiDraw = !guiDraw;
	}
	
	if(key == 'z') {
		customParticles.push_back(shared_ptr<CustomParticle>(new CustomParticle));
		CustomParticle * p = customParticles.back().get();
		p->setPhysics(densityS, bounceS, frictionS);
		p->setup(box2d.getWorld(), ofGetMouseX(), ofGetMouseY(), sizeS);
			
	}
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

bool withinRadius(shared_ptr<CustomParticle> p){
	ofApp *app = (ofApp*)ofGetAppPtr();
	return (ofDist(p->getPosition().x, p->getPosition().y, app->center.x, app->center.y) < app->centerRadius);
}
