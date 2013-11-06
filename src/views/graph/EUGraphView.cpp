//
//  EUGraphView.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#include "EUGraphView.h"

#include "EUDirector.h"

EUGraphView::EUGraphView(const ofRectangle &bounds)
: _bounds(bounds)
{
    EUColorDirector *colorDirector = EUDirector::GetInstance()->getColorDirector();
    _color = colorDirector->getGraphBackground();
    
    _idxGraphTouched = -1;
    _idxNodeTouched = -1;
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
    // Background.
    ofFill();
    ofSetColor(_color.fill);
    ofRect(_bounds);
    
    // Graphs.
    for (vector<EUGraph *>::iterator itr = _graphArray.begin(); itr != _graphArray.end(); ++itr) {
        (*itr)->draw();
    }
}

bool EUGraphView::handleTouch(const ofTouchEventArgs &touch)
{
    // Check interaction.
    switch (touch.type) {
        case ofTouchEventArgs::down:
        {
            ofPoint touchPos = ofPoint(touch.x, touch.y);
            
            int graphIdx, nodeIdx, segIdx;
            graphIdx = nodeIdx = segIdx = -1;
            
            // Check if a node or a semgent in graphs is touched.
            for (int i = _graphArray.size() - 1; i >= 0; i--) {
                
                nodeIdx = _graphArray[i]->indexOfNodeContains(touchPos);
                if (nodeIdx != -1) {
                    graphIdx = i;
                    if (_delegate) {
                        _delegate->onNodeTouch(*this, touch, graphIdx, nodeIdx);
                    }
                    
                    _idxGraphTouched = i;
                    _idxNodeTouched = nodeIdx;
                    return true;
                }
                
                segIdx = _graphArray[i]->indexOfSegmentContains(touchPos);
                if (segIdx != -1) {
                    graphIdx = i;
                    if (_delegate) {
                        _delegate->onGraphTouch(*this, touch, graphIdx);
                    }
                    
                    _idxGraphTouched = i;
                    _idxNodeTouched = -1;
                    return true;
                }
            }
            
            // Neither node or segment touched.
            if (_delegate) {
                _delegate->onScreenTouch(*this, touch);
            }
            
            _idxGraphTouched = -1;
            _idxNodeTouched = -1;
            return true;
        }
        
        case ofTouchEventArgs::move:
        {
            if (_idxGraphTouched != -1) {
                if (_idxNodeTouched != -1) {
                    // Touching node.
                    if (_delegate) {
                        _delegate->onNodeTouch(*this, touch, _idxGraphTouched, _idxNodeTouched);
                    }
                } else {
                    // Touching segment.
                    if (_delegate) {
                        _delegate->onGraphTouch(*this, touch, _idxGraphTouched);
                    }
                }
            } else {
                // Touching screen.
                if (_delegate) {
                    _delegate->onScreenTouch(*this, touch);
                }
            }
        }
            
        case ofTouchEventArgs::up:
        {
            if (_idxGraphTouched != -1) {
                if (_idxNodeTouched != -1) {
                    // Touching node.
                    if (_delegate) {
                        _delegate->onNodeTouch(*this, touch, _idxGraphTouched, _idxNodeTouched);
                    }
                } else {
                    // Touching segment.
                    if (_delegate) {
                        _delegate->onGraphTouch(*this, touch, _idxGraphTouched);
                    }
                }
            } else {
                // Touching screen.
                if (_delegate) {
                    _delegate->onScreenTouch(*this, touch);
                }
            }
        }
        default:
            break;
    }
    
    return false;
}

void EUGraphView::setDelegate(EUGraphViewDelegate *delegate)
{
    _delegate = delegate;
}

const ofRectangle & EUGraphView::getBounds() const
{
    return _bounds;
}
