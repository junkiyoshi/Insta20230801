#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(0);
	ofEnableDepthTest();
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int x = -300; x <= 300; x += 20) {

		for (int y = -300; y <= 300; y += 20) {

			ofPushMatrix();
			ofTranslate(x, y);

			auto deg_x = ofMap(ofNoise(x * 0.003, ofGetFrameNum() * 0.01), 0, 1, -220, 220);
			auto deg_y = ofMap(ofNoise(y * 0.003, ofGetFrameNum() * 0.01), 0, 1, -220, 220);

			ofRotateY(deg_y);
			ofRotateX(deg_x);

			ofNoFill();
			ofDrawRectangle(0, 0, 20, 20);

			ofFill();
			ofDrawRectangle(0, 0, 13, 13);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}