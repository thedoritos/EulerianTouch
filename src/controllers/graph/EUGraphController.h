//
//  EUGraphController.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#ifndef __EulerianTouch__EUGraphController__
#define __EulerianTouch__EUGraphController__

#include "ofMain.h"

#include "EUGraphModel.h"
#include "EUGraphView.h"

class EUGraphController : public EUGraphViewDelegate {
    
public:
    
    EUGraphController(EUGraphModel *model, EUGraphView *view);
    ~EUGraphController();
    
    void update(float dt);
    void draw();
    
    bool onTouch(const ofTouchEventArgs &touch);
    
    // EUGraphViewDelegate
    virtual void onScreenTouch(const EUGraphView &view, const ofTouchEventArgs &touch);
    virtual void onGraphTouch(const EUGraphView &view, int graphIdx);
    virtual void onNodeTouch(const EUGraphView &view, int graphIdx, int nodeIdx);

private:
    
    EUGraphModel *_model;
    EUGraphView *_view;
    
};

#endif /* defined(__EulerianTouch__EUGraphController__) */
