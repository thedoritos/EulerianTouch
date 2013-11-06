//
//  EUNode.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#ifndef __EulerianTouch__EUNode__
#define __EulerianTouch__EUNode__

#include "ofMain.h"
#include "EUNodeEntity.h"

class EUNode {
    
public:
    
    EUNode();
    ~EUNode();
    
    void update(const EUNodeEntity &nodeModel, const ofRectangle &viewBounds);
    
    void update(float dt);
    void draw();
    
private:
    
    ofPoint _pos;
    float _size;
    
};

#endif /* defined(__EulerianTouch__EUNode__) */
