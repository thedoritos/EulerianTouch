//
//  EUGraphView.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#include "EUGraphView.h"

EUGraphView::EUGraphView(const ofRectangle &bounds)
: _bounds(bounds)
{
    _bgColor.setHex(0xFF888888);
}

EUGraphView::~EUGraphView()
{
    
}

void EUGraphView::update(float dt)
{
    
}

void EUGraphView::draw()
{
    ofBackground(_bgColor);
}
