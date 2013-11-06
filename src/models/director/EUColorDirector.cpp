//
//  EUColorDirector.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#include "EUColorDirector.h"

EUColor EUColorDirector::getGraphColor(int chIdx)
{
    EUColor ret;
    return ret;
}

EUColor EUColorDirector::getGraphBackground()
{
    EUColor ret;
    ret.frame.setHex(EUColor::SUMI, 0xFF);
    ret.fill.setHex(EUColor::SUMI, 0xFF);
    ret.text.setHex(EUColor::WHITESMOKE, 0xFF);
    
    return ret;
}

