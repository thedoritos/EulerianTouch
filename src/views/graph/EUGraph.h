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
#include "EUSegment.h"
#include "EUDirector.h"
#include "EUColor.h"

class EUGraph {
    
public:
    
    EUGraph(const EUGraphEntity &graphModel);
    ~EUGraph();
    
    void update(const EUGraphEntity &graphEntity, const ofRectangle &viewBounds);
    
    void update(float dt);
    void draw();
    
    const int indexOfNodeContains(const ofPoint &pos) const;
    const int indexOfSegmentContains(const ofPoint &pos) const;
    
private:
    
    EUColor _color;
    vector<EUNode *> _nodeArray;
    vector<EUSegment *> _segmArray;
    
};

#endif /* defined(__EulerianTouch__EUGraph__) */
