//
//  EUGraphModel.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#include "EUGraphModel.h"

const int EUGraphModel::IDX_UNDEFINED = -1;

const int EUGraphModel::getNumGraphs() const
{
    return _graphArray.size();
}

const EUGraphEntity & EUGraphModel::getGraph(int idx) const
{
    return *_graphArray[idx];
}

const bool EUGraphModel::isEditingGraph() const
{
    return _editGraphIdx != IDX_UNDEFINED;
}

const bool EUGraphModel::isEditingNode() const
{
    return _editNodeIdx != IDX_UNDEFINED;
}

bool EUGraphModel::beginGraph()
{
    if (isEditingGraph()) return false;
    
    _editGraphIdx = _graphArray.size();
    _editNodeIdx  = IDX_UNDEFINED;
    
    EUGraphEntity *newGraph = new EUGraphEntity();
    _graphArray.push_back(newGraph);
    
    return true;
}

bool EUGraphModel::endGraph()
{
    if (!isEditingGraph()) return false;
    
    _editGraphIdx = IDX_UNDEFINED;
    _editNodeIdx  = IDX_UNDEFINED;
    
    return true;
}

bool EUGraphModel::beginEditGraph(int graphIdx)
{
    if (isEditingGraph()) return false;
    
    _editGraphIdx = graphIdx;
    _editNodeIdx  = IDX_UNDEFINED;
    
    return true;
} 

bool EUGraphModel::endEditGraph()
{
    if (!isEditingGraph()) return false;
    
    _editGraphIdx = IDX_UNDEFINED;
    _editNodeIdx  = IDX_UNDEFINED;
    
    return true;
}

bool EUGraphModel::beginEditNode(int graphIdx, int nodeIdx)
{
    if (isEditingGraph()) return false;
    
    _editGraphIdx = graphIdx;
    _editNodeIdx  = nodeIdx;
    
    return true;
}

bool EUGraphModel::endEditNode()
{
    if (!isEditingGraph()) return false;
    
    _editGraphIdx = IDX_UNDEFINED;
    _editNodeIdx  = IDX_UNDEFINED;
    
    return true;
}

void EUGraphModel::addNode(const ofPoint &pos)
{
    _graphArray[_editGraphIdx]->add(pos);
}

void EUGraphModel::addNode(const ofPoint &pos, int idx)
{
    _graphArray[_editGraphIdx]->add(pos, idx);
}

bool EUGraphModel::addNodeOn(int graphIdx, int nodeIdx)
{
    // Check if this action will complete graph.
    if (graphIdx == _editGraphIdx
        && nodeIdx == 0
        && _graphArray[_editGraphIdx]->getNumNodes() >= 3) {
        
        // Complete graph.
        _graphArray[_editGraphIdx]->setCompleted(true);
        return true;
        
    } else {
        
        // Add node.
        addNode(_graphArray[graphIdx]->getNode(nodeIdx).getPosition());
        return false;
    }
}

void EUGraphModel::moveNode(const ofPoint &dif)
{
    _graphArray[_editGraphIdx]->move(dif, _editNodeIdx);
}

void EUGraphModel::moveGraph(const ofPoint &dif)
{
    _graphArray[_editGraphIdx]->move(dif);
}

void EUGraphModel::copyNode()
{
    EUGraphEntity *graph = _graphArray[_editGraphIdx];
    graph->add(graph->getNode(_editNodeIdx).getPosition(), _editNodeIdx + 1);
    
    _editNodeIdx += 1;
}

void EUGraphModel::copyGraph()
{
    EUGraphEntity *graph = new EUGraphEntity(*_graphArray[_editGraphIdx]);
    _graphArray.insert(_graphArray.begin() + _editGraphIdx + 1, graph);
    
    _editGraphIdx += 1;
}

void EUGraphModel::removeNode()
{
    EUGraphEntity *graph = _graphArray[_editGraphIdx];
    graph->remove(_editNodeIdx);
}

void EUGraphModel::removeGraph()
{
    EUGraphEntity *graph = _graphArray[_editGraphIdx];
    _graphArray.erase(_graphArray.begin() + _editGraphIdx);
    if (graph != 0) {
        delete graph;
        graph = 0;
    }
}
