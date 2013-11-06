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
    _bgColor.setHex(0xFF000000);
}

EUGraphView::~EUGraphView()
{
    
}

void EUGraphView::update(const EUGraphModel &model)
{
    // Adjust the number of the graphs.
    // Create if we need more, or delete if we have too many.
    int numGraphsNeeded = model.getNumGraphs() - _graphArray.size();
    
    if (numGraphsNeeded > 0) {
        int numGraphs = _graphArray.size();
        for (int i = 0; i < numGraphsNeeded; i++) {
            EUGraph *graph = new EUGraph(model.getGraph(numGraphs + i));
            _graphArray.push_back(graph);
        }
        
    } else if (numGraphsNeeded < 0) {
        for (int i = 0; i < (-numGraphsNeeded); i++) {
            EUGraph *graph = *(_graphArray.end() - 1);
            _graphArray.erase(_graphArray.end() - 1);
            if (graph != 0) {
                delete graph;
                graph = 0;
            }
        }
    }
    
    // Update graphs.
    for (int i = 0; i < model.getNumGraphs(); i++) {
        _graphArray[i]->update(model.getGraph(i), _bounds);
    }
}

void EUGraphView::update(float dt)
{
    
}

void EUGraphView::draw()
{
    ofBackground(_bgColor);
    
    for (vector<EUGraph *>::iterator itr = _graphArray.begin(); itr != _graphArray.end(); ++itr) {
        (*itr)->draw();
    }
}

bool EUGraphView::handleTouch(const ofTouchEventArgs &touch)
{
    if (_delegate) {
        _delegate->onScreenTouch(*this, touch);
    }
    
    return true;
}

void EUGraphView::setDelegate(EUGraphViewDelegate *delegate)
{
    _delegate = delegate;
}

const ofRectangle & EUGraphView::getBounds() const
{
    return _bounds;
}
