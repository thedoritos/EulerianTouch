//
//  EUGraph.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#include "EUGraph.h"

EUGraph::EUGraph(const EUGraphEntity &graphModel)
{
    EUColorDirector *colorDirector = EUDirector::GetInstance()->getColorDirector();
    _color = colorDirector->getGraphColor(0);
}

EUGraph::~EUGraph()
{
    
}

void EUGraph::update(const EUGraphEntity &graphEntity, const ofRectangle &viewBounds)
{
    // Adjust the number of the nodes.
    // Create if we need more, or delete if we have too many.
    int numNodesNeeded = graphEntity.getNumNodes() - _nodeArray.size();
    
    if (numNodesNeeded > 0) {
        // Create nodes. (and segments)
        for (int i = 0; i < numNodesNeeded; i++) {
            EUNode *node = new EUNode();
            _nodeArray.push_back(node);
            
            EUSegment *seg = new EUSegment();
            _segmArray.push_back(seg);
        }
        
    } else if (numNodesNeeded < 0) {
        // Delete nodes. (and segments)
        for (int i = 0; i < (-numNodesNeeded); i++) {
            EUNode *node = *(_nodeArray.end() - 1);
            _nodeArray.erase(_nodeArray.end() - 1);
            if (node != 0) {
                delete node;
                node = 0;
            }
            
            EUSegment *seg = *(_segmArray.end() - 1);
            _segmArray.erase(_segmArray.end() - 1);
            if (seg != 0) {
                delete seg;
                seg = 0;
            }
        }
    }
    
    // Update nodes.
    for (int i = 0; i < _nodeArray.size(); i++) {
        _nodeArray[i]->update(graphEntity.getNode(i), viewBounds);
        _nodeArray[i]->setColor(_color);
    }
    
    // Update segments.
    for (int i = 0; i < _segmArray.size() - 1; i++) {
        _segmArray[i]->setNodes(_nodeArray[i], _nodeArray[i + 1]);
    }
    if (graphEntity.isCompleted()) {
        int i = _segmArray.size() - 1;
        _segmArray[i]->setNodes(_nodeArray[i], _nodeArray[0]);
    }
}

void EUGraph::update(float dt)
{
    for (vector<EUNode *>::iterator itr = _nodeArray.begin(); itr != _nodeArray.end(); ++itr) {
        (*itr)->update(dt);
    }
}

void EUGraph::draw()
{
    for (vector<EUNode *>::iterator itr = _nodeArray.begin(); itr != _nodeArray.end(); ++itr) {
        (*itr)->draw();
    }
    for (vector<EUSegment *>::iterator itr = _segmArray.begin(); itr != _segmArray.end(); ++itr) {
        (*itr)->draw();
    }
}

const int EUGraph::indexOfNodeContains(const ofPoint &pos) const
{
    for (int i = _nodeArray.size() - 1; i >= 0; i--) {
        if (_nodeArray[i]->contains(pos)) {
            return i;
        }
    }
    return -1;
}

const int EUGraph::indexOfSegmentContains(const ofPoint &pos) const
{
    for (int i = _segmArray.size() - 1; i >= 0; i--) {
        if (_segmArray[i]->contains(pos)) {
            return i;
        }
    }
    return -1;
}
