//
//  EUNodeEntity.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#ifndef __EulerianTouch__EUNodeEntity__
#define __EulerianTouch__EUNodeEntity__

#include "ofMain.h"

class EUNodeEntity {
    
public:
    
    EUNodeEntity(const ofPoint &pos);
    EUNodeEntity(const EUNodeEntity &base);
    ~EUNodeEntity();
    
    void set(const ofPoint &pos);
    void move(const ofPoint &dif);
    
    const ofPoint& getPosition() const;
    
private:
    
    ofPoint _pos;
    
};
#endif /* defined(__EulerianTouch__EUNodeEntity__) */
