#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofEnableSmoothing();
    ofEnableAlphaBlending();
    ofSetCircleResolution(32);
    
    ofRectangle winBounds = ofGetWindowRect();
    
    _graphModel = new EUGraphModel();
    _graphView = new EUGraphView(winBounds);
    _graphController = new EUGraphController(_graphModel, _graphView);
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // Using const dt to make is simple.
    float dt = 1.0f / 45.0f;
    
    _graphController->update(dt);
}

//--------------------------------------------------------------
void testApp::draw(){
    _graphController->draw();
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){
    touch.type = ofTouchEventArgs::down;
    _graphController->onTouch(touch);
}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){
    touch.type = ofTouchEventArgs::move;
    _graphController->onTouch(touch);
}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){
    touch.type = ofTouchEventArgs::up;
    _graphController->onTouch(touch);
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

