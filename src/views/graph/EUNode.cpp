//
//  EUNode.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#include "EUNode.h"

EUNode::EUNode()
{
    _size = 36.0f;
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
    // Drawing configurations are set on EUGraph
    ofEllipse(_pos, _size, _size);
}
