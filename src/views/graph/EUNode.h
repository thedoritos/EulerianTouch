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
#include "EUColor.h"

class EUNode {
    
public:
    
    static const float TOUCH_THRESHOLD;
    
    EUNode();
    ~EUNode();
    
    void update(const EUNodeEntity &nodeEntity, const ofRectangle &viewBounds);
    
    void update(float dt);
    void draw();
    
    void setColor(const EUColor &color);
    
    const ofPoint & getPosition() const;
    
    bool contains(const ofPoint &pos) const;
    
private:
    
    ofPoint _pos;
    float _size;
    
    EUColor _color;
    
};

#endif /* defined(__EulerianTouch__EUNode__) */
