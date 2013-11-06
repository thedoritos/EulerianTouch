//
//  EUSegment.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#include "EUSegment.h"

const float EUSegment::TOUCH_THRESHOLD = 12.0f;

EUSegment::EUSegment()
{
    _nodeFrom = 0;
    _nodeTo = 0;
}

EUSegment::EUSegment(const EUNode *nodeFrom, const EUNode *nodeTo)
{
    _nodeFrom = nodeFrom;
    _nodeTo = nodeTo;
}

void EUSegment::draw()
{
    ofSetColor(_color.frame);
    if (_nodeFrom != 0 && _nodeTo != 0) {
        ofLine(_nodeFrom->getPosition(), _nodeTo->getPosition());
    }
}

void EUSegment::setColor(const EUColor &color)
{
    _color = color;
}

void EUSegment::setNodes(const EUNode *nodeFrom, const EUNode *nodeTo)
{
    _nodeFrom = nodeFrom;
    _nodeTo = nodeTo;
}

bool EUSegment::contains(const ofPoint &pos) const
{
    // Check if the segment has nodes.
    if (_nodeFrom == 0 || _nodeTo == 0) return false;
    
    ofPoint posFrom = _nodeFrom->getPosition();
    ofPoint posTo = _nodeTo->getPosition();
    
    // Check if the pos is close enough.
    if ((posFrom.x - pos.x) * (posTo.x - pos.x) > TOUCH_THRESHOLD * TOUCH_THRESHOLD ||
        (posFrom.y - pos.y) * (posTo.y - pos.y) > TOUCH_THRESHOLD * TOUCH_THRESHOLD)
        return false;
    
    // Check distance.
    float angleSeg = atan2(posTo.y - posFrom.y, posTo.x - posFrom.x);
    float anglePt  = atan2(  pos.y - posFrom.y,   pos.x - posFrom.x);
    float dist = posFrom.distance(pos) * abs(sin(angleSeg - anglePt));
    
    return dist < TOUCH_THRESHOLD;
}
