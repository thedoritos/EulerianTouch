#include "ofMain.h"
#include "testApp.h"

int main(){
//	ofSetupOpenGL(1024,768, OF_FULLSCREEN);			// <-------- setup the GL context
    
    ofAppiOSWindow *window = new ofAppiOSWindow();
    window->enableAntiAliasing(4);
    ofSetupOpenGL(window, 1024, 768, OF_FULLSCREEN);
    
	ofRunApp(new testApp);
    
}
