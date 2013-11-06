//
//  EUGraph.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#ifndef __EulerianTouch__EUGraph__
#define __EulerianTouch__EUGraph__

#include "ofMain.h"
#include "EUGraphEntity.h"
#include "EUNode.h"

class EUGraph {
    
public:
    
    EUGraph(const EUGraphEntity &graphModel);
    ~EUGraph();
    
    void update(const EUGraphEntity &graphModel, const ofRectangle &viewBounds);
    
    void update(float dt);
    void draw();
    
private:
    
    vector<EUNode *> _nodeArray;
    
};

#endif /* defined(__EulerianTouch__EUGraph__) */
