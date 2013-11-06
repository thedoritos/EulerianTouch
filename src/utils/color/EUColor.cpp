//
//  EUColor.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#include "EUColor.h"

EUColor::EUColor()
{
    frame.setHex(SUOH, 0xFF);
    fill.setHex(SUOH, 0x88);
    text.setHex(SUOH, 0xFF);
}

EUColor::EUColor(const EUColor &rhs)
{
    frame = rhs.frame;
    fill  = rhs.fill;
    text  = rhs.text;
}
