//
//  EUGraphView.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#ifndef __EulerianTouch__EUGraphView__
#define __EulerianTouch__EUGraphView__

#include "ofMain.h"

#include "EUGraphModel.h"

#include "EUGraph.h"
#include "EUNode.h"
#include "EUColor.h"

class EUGraphViewDelegate;

class EUGraphView {
    
public:
    
    EUGraphView(const ofRectangle &bounds);
    ~EUGraphView();
    
    void update(const EUGraphModel &model);
    void update(float dt);
    void draw();
    
    bool handleTouch(const ofTouchEventArgs &touch);
    
    void setDelegate(EUGraphViewDelegate *delegate);
    
    const ofRectangle & getBounds() const;
    
private:
    
    EUColor _color;
    ofRectangle _bounds;
    
    vector<EUGraph *> _graphArray;
    
    int _idxGraphTouched;
    int _idxNodeTouched;
    
    EUGraphViewDelegate *_delegate;
};

class EUGraphViewDelegate {
public:
    virtual void onScreenTouch(const EUGraphView &view, const ofTouchEventArgs &touch) = 0;
    virtual void onGraphTouch(const EUGraphView &view, const ofTouchEventArgs &touch, int graphIdx) = 0;
    virtual void onNodeTouch(const EUGraphView &view, const ofTouchEventArgs &touch, int graphIdx, int nodeIdx) = 0;
};

#endif /* defined(__EulerianTouch__EUGraphView__) */
