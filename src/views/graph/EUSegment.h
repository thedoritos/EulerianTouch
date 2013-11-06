//
//  EUSegment.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#ifndef __EulerianTouch__EUSegment__
#define __EulerianTouch__EUSegment__

#include "ofMain.h"

#include "EUNode.h"
#include "EUColor.h"

class EUSegment {
    
public:
    
    static const float TOUCH_THRESHOLD;
    
    EUSegment();
    EUSegment(const EUNode *nodeFrom, const EUNode *nodeTo);
    
    void draw();
    
    void setColor(const EUColor &color);
    void setNodes(const EUNode *nodeFrom, const EUNode *nodeTo);
    
    bool contains(const ofPoint &pos) const;
    
private:
    
    const EUNode *_nodeFrom;
    const EUNode *_nodeTo;
    
    EUColor _color;
    
};
#endif /* defined(__EulerianTouch__EUSegment__) */
