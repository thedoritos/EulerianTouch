//
//  EUColor.h
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#ifndef __EulerianTouch__EUColor__
#define __EulerianTouch__EUColor__

#include "ofColor.h"

class EUColor {
    
public:
    
    EUColor();
    EUColor(const EUColor &rhs);
    
    ofColor frame;
    ofColor fill;
    ofColor text;
    
    //
    // @see http://iro-color.com/colorchart/arrangement/bird-color.html
    //
    static const int PINK   = 0xF4B3C2;
    static const int ORANGE = 0xEA5532;
    static const int GREEN  = 0x006658;
    static const int NAVY   = 0x004663;
    static const int BLUE   = 0x08607F;
    static const int OCEAN  = 0x00AC97;
    static const int BROWN  = 0x6E5C26;
    static const int YELLOW = 0xFFF462;
    static const int LIME   = 0x6EBA38;
    static const int WHITE  = 0xFEECD2;
    static const int GRAY   = 0x7A7B69;
    static const int BLACK  = 0x00000F;
    
    //
    // @see http://nipponcolors.com
    //
    static const int SUOH       = 0x8E354A;
    static const int KUCHIBA    = 0xE2943B;
    static const int NAE        = 0x86C166;
    static const int VELUDO     = 0x096148;
    static const int SABIONANDO = 0x336774;
    static const int RURI       = 0x005CAF;
    static const int BENIMIDORI = 0x7B90D2;
    static const int BOTAN      = 0xC1328E;
    
    static const int SUMI       = 0x1C1C1C;
    static const int RO         = 0x0C0C0C;
    
    //
    // @see http://www.colordic.org
    //
    static const int WHITESMOKE = 0xF5F5F5;
    
private:
    
};

#endif /* defined(__EulerianTouch__EUColor__) */
