//
//  EUGraphEntity.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#ifndef __EulerianTouch__EUGraphEntity__
#define __EulerianTouch__EUGraphEntity__

#include "ofMain.h"
#include "EUNodeEntity.h"

class EUGraphEntity {
    
public:
    
    EUGraphEntity();
    EUGraphEntity(const EUGraphEntity &base);
    ~EUGraphEntity();
    
    void add(const ofPoint &pos, int idx);
    void add(const ofPoint &pos);
    void remove(int idx);
    
    void move(const ofPoint &dif);
    void move(const ofPoint &dif, int idx);
    
    const int getNumNodes() const;
    const EUNodeEntity & getNode(int idx) const;
    
    const bool isCompleted() const;
    void setCompleted(bool completed);
    
private:
    
    vector<EUNodeEntity *> _nodeArray;
    bool _isCompleted;
    
};

#endif /* defined(__EulerianTouch__EUGraphEntity__) */
