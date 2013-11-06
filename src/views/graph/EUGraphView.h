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
    
    ofColor _bgColor;
    ofRectangle _bounds;
    
    vector<EUGraph *> _graphArray;
    
    EUGraphViewDelegate *_delegate;
};

class EUGraphViewDelegate {
public:
    virtual void onScreenTouch(const EUGraphView &view, const ofTouchEventArgs &touch) = 0;
    virtual void onGraphTouch(const EUGraphView &view, int graphIdx) = 0;
    virtual void onNodeTouch(const EUGraphView &view, int graphIdx, int nodeIdx) = 0;
};

#endif /* defined(__EulerianTouch__EUGraphView__) */
