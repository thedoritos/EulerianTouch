//
//  EUNode.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#include "EUNode.h"

const float EUNode::TOUCH_THRESHOLD = 12.0f;

EUNode::EUNode()
{
    _size = 24.0f;
}

EUNode::~EUNode()
{
    
}

void EUNode::update(const EUNodeEntity &nodeEntity, const ofRectangle &viewBounds)
{
    float x = viewBounds.x + nodeEntity.getPosition().x * viewBounds.width;
    float y = viewBounds.y + nodeEntity.getPosition().y * viewBounds.height;
    
    _pos.set(x, y);
}

void EUNode::update(float dt)
{
    
}

void EUNode::draw()
{
    ofFill();
    ofSetColor(_color.fill);
    ofEllipse(_pos, _size, _size);
    
    ofNoFill();
    ofSetColor(_color.frame);
    ofEllipse(_pos, _size, _size);
}

void EUNode::setColor(const EUColor &color)
{
    _color.fill = color.fill;
    _color.frame = color.frame;
}

const ofPoint & EUNode::getPosition() const
{
    return _pos;
}

bool EUNode::contains(const ofPoint &pos) const
{
    return _pos.distance(pos) < _size * 0.5f + TOUCH_THRESHOLD;
}
