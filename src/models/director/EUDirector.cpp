//
//  EUDirector.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#include "EUDirector.h"

EUDirector* EUDirector::GetInstance()
{
    static EUDirector instance;
    return &instance;
}

EUDirector::EUDirector()
{
    _colorDirector = new EUColorDirector();
}

EUColorDirector* EUDirector::getColorDirector()
{
    return _colorDirector;
}
