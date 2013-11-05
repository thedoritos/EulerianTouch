//
//  EUNodeModel.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#ifndef __EulerianTouch__EUNodeModel__
#define __EulerianTouch__EUNodeModel__

#include "ofMain.h"

class EUNodeModel {
    
public:
    
    const ofVec2f& getPosition() const;
    
private:
    
    ofVec2f _pos;
    
};
#endif /* defined(__EulerianTouch__EUNodeModel__) */
