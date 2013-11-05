#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofRectangle winBounds = ofGetWindowRect();
    
    _graphView = new EUGraphView(winBounds);
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Using const dt to make is simple.
    float dt = 1.0f / 45.0f;
    
    _graphView->update(dt);
}

//--------------------------------------------------------------
void testApp::draw(){
	_graphView->draw();
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}

