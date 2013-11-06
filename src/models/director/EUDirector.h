//
//  EUDirector.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#ifndef __EulerianTouch__EUDirector__
#define __EulerianTouch__EUDirector__

#include "EUColorDirector.h"

class EUDirector {
    
public:
    
    static EUDirector* GetInstance();
    
    EUColorDirector* getColorDirector();
    
private:
    
    EUDirector();
    EUDirector(const EUDirector* rhs);
    EUDirector& operator=(const EUDirector& rhs);
    
    EUColorDirector *_colorDirector;
    
};

#endif /* defined(__EulerianTouch__EUDirector__) */
