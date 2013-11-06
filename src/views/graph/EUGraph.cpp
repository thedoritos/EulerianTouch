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
        for (int i = 0; i < numNodesNeeded; i++) {
            EUNode *node = new EUNode();
            _nodeArray.push_back(node);
        }
        
    } else if (numNodesNeeded < 0) {
        for (int i = 0; i < (-numNodesNeeded); i++) {
            EUNode *node = *(_nodeArray.end() - 1);
            _nodeArray.erase(_nodeArray.end() - 1);
            if (node != 0) {
                delete node;
                node = 0;
            }
        }
    }
    
    // Update nodes.
    for (int i = 0; i < _nodeArray.size(); i++) {
        _nodeArray[i]->update(graphEntity.getNode(i), viewBounds);
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
}
