//
//  EUGraphModel.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#ifndef __EulerianTouch__EUGraphModel__
#define __EulerianTouch__EUGraphModel__

#include "ofMain.h"
#include "EUGraphEntity.h"

class EUGraphModel {
    
public:
    
    static const int IDX_UNDEFINED;
    
    const int getNumGraphs() const;
    const EUGraphEntity & getGraph(int idx) const;
    
    const bool isEditingGraph() const;
    const bool isEditingNode() const;
    
    // Creating graph.
    bool beginGraph();
    bool endGraph();
    
    // Editing graph.
    bool beginEditGraph(int graphIdx);
    bool endEditGraph();
    
    // Editing node.
    bool beginEditNode(int graphIdx, int nodeIdx);
    bool endEditNode();
    
    void addNode(const ofPoint &pos);
    void addNode(const ofPoint &pos, int idx);
    void moveNode(const ofPoint &dif);
    void moveGraph(const ofPoint &dif);
    void copyNode();
    void copyGraph();
    void removeNode();
    void removeGraph();
    
    
private:
    
    int _editGraphIdx = IDX_UNDEFINED;
    int _editNodeIdx  = IDX_UNDEFINED;
    
    
    
    vector<EUGraphEntity *> _graphArray;
    
};

#endif /* defined(__EulerianTouch__EUGraphModel__) */