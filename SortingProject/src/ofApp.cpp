#include "ofApp.h"


void BubbleSort(vector<int>& circles, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (circles[j] > circles[j + 1]) std::swap(circles[j], circles[j + 1]);
}

void InsertionSort(vector<int>& circles, int n) {
	for (int i = 1; i < n; ++i) {
		int value = circles[i];
		int j = i - 1;

		while (j >= 0 && circles[j] > value) {
			circles[j + 1] = circles[j];
			j = j - 1;
		}
		circles[j + 1] = value;
	}
}

void FusionSort(vector<int>& circles, int n) {

}

void QuickSort(vector<int>& circles, int n) {

}

void FisherYatesSort(vector<int>& circles, int n){

}

void DisplayCircles(vector<int> circles, int positionY) {
	ofColor black = ofColor(  0,   0,   0);
	ofColor white = ofColor(255, 255, 255);

	int previousSize = 0;

	for (int i = 0; i < circles.size(); i++) {
		int       currentSize     = circles[i];
		glm::vec2 currentPosition = glm::vec2((i + 1) * 200, positionY);

		previousSize = currentSize;

		ofDrawCircle(currentPosition, currentSize);
		ofDrawBitmapStringHighlight(ofToString(currentSize), currentPosition, white, black);
	}
}

void GenerateCircles(vector<int>& circles, int minSize, int maxSize) {

	if (minSize > maxSize) minSize = maxSize - 1;
	if (maxSize < minSize) maxSize = minSize + 1;

	for (int i = 0; i < circles.size(); i++) {
		circles[i] = minSize + rand() % (maxSize + 1);
	}
}

//--------------------------------------------------------------
void ofApp::setup(){
	circles = vector<int>(5);
	GenerateCircles(circles, 10, 100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	DisplayCircles(circles, 50);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key)
	{
	    case 'r':
			GenerateCircles(circles, 10, 100);
		break;

		case 'b':
			BubbleSort(circles, circles.size());
			break;

		case 'i':
			InsertionSort(circles, circles.size());
			break;

		case 'm':
			FusionSort(circles, circles.size());
			break;

		case 'q':
			QuickSort(circles, circles.size());
			break;

		case 's':
			FisherYatesSort(circles, circles.size());
			break;
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
