#include "ofApp.h"


void bubbleSort(vector<int>& circles, int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (circles[j] > circles[j + 1]) std::swap(circles[j], circles[j + 1]);
}

void insertionSort(vector<int>& circles, int n) {
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

void merge(vector<int>& circles, int left, int mid, int right)
{
	int l1 = mid   - left + 1;
	int l2 = right - mid;

	vector<int> leftVector(l1), rightVector(l2);

	for (int i = 0; i < l1; i++)
		leftVector[i] = circles[left + i];
	for (int j = 0; j < l2; j++)
		rightVector[j] = circles[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < l1 && j < l2) {
		if (leftVector[i] <= rightVector[j]) {
			circles[k] = leftVector[i];
			i++;
		}
		else {
			circles[k] = rightVector[j];
			j++;
		}
		k++;
	}

	while (i < l1) {
		circles[k] = leftVector[i];
		i++;
		k++;
	}

	while (j < l2) {
		circles[k] = rightVector[j];
		j++;
		k++;
	}
}

void mergeSort(vector<int>& circles, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(circles, left, mid);
		mergeSort(circles, mid + 1, right);
		merge(circles, left, mid, right);
	}
}

int partition(vector<int>& circles, int start, int end) {
	int pivot = circles[end];
	int i = (start - 1);

	for (int j = start; j < end; j++) {
		if (circles[j] > pivot) continue;
		i++;
		std::swap(circles[i], circles[j]);
	}

	i++;
	std::swap(circles[i], circles[end]);
	return i;
}

void quickSort(vector<int>& circles, int start, int end) {
	if (start < end) {
		int pi = partition(circles, start, end);
		quickSort(circles, start, pi - 1);
		quickSort(circles, pi + 1, end);
	}
}

void fisherYatesSort(vector<int>& circles, int numberOfElements){
	std::srand(time(NULL));

	vector<int> duplicates = vector<int>(numberOfElements), results = vector<int>(numberOfElements);

	for (int i = 0; i < numberOfElements; i++) {
		int j = rand() % numberOfElements;
		while (duplicates[j]) { 
			j = rand() % numberOfElements;
		}
		results[i] = circles[j];
		duplicates[j] = 1; 
	}

	for (int i = 0; i < numberOfElements; i++) {
		circles[i] = results[i];
	}
}

void displayCircles(vector<int> circles, int positionY) {
	ofColor black = ofColor(  0,   0,   0);
	ofColor white = ofColor(255, 255, 255);

	int previousSize = 0;

	for (int i = 0; i < circles.size(); i++) {
		int       currentSize     = circles[i];
		glm::vec2 currentPosition = glm::vec2((i + 1) * 220, positionY);

		previousSize = currentSize;

		ofDrawCircle(currentPosition, currentSize);
		ofDrawBitmapStringHighlight(ofToString(currentSize), currentPosition, white, black);
	}
}

void generateCircles(vector<int>& circles, int minSize, int maxSize) {

	if (minSize > maxSize) minSize = maxSize - 1;
	if (maxSize < minSize) maxSize = minSize + 1;

	std::srand(time(0));

	for (int i = 0; i < circles.size(); i++)
		circles[i] = minSize + (rand() % (maxSize - minSize));
}

//--------------------------------------------------------------
void ofApp::setup(){
	circles = vector<int>(5);
	generateCircles(circles, 10, 100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	displayCircles(circles, 500);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch(key)
	{
	    case 'r':
			generateCircles(circles, 10, 100);
		break;

		case 'b':
			bubbleSort(circles, circles.size());
			break;

		case 'i':
			insertionSort(circles, circles.size());
			break;

		case 'm':
			mergeSort(circles, 0, circles.size() - 1);
			break;

		case 'q':
			quickSort(circles, 0, circles.size() - 1);
			break;

		case 's':
			fisherYatesSort(circles, circles.size());
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
