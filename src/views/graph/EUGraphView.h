//
//  EUGraphView.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#ifndef __EulerianTouch__EUGraphView__
#define __EulerianTouch__EUGraphView__

#include "ofMain.h"

class EUGraphView {
    
public:
    
    EUGraphView(const ofRectangle &bounds);
    ~EUGraphView();
    
    void update(float dt);
    void draw();
    
private:
    
    ofColor _bgColor;
    ofRectangle _bounds;
    
};

#endif /* defined(__EulerianTouch__EUGraphView__) */
