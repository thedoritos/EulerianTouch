//
//  EUNodeEntity.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#include "EUNodeEntity.h"

EUNodeEntity::EUNodeEntity(const ofPoint &pos)
: _pos(pos)
{
    
}

EUNodeEntity::EUNodeEntity(const EUNodeEntity &base)
: _pos(base.getPosition())
{
    
}

EUNodeEntity::~EUNodeEntity()
{
    
}

void EUNodeEntity::set(const ofPoint &pos)
{
    _pos.set(pos);
}

void EUNodeEntity::move(const ofPoint &dif)
{
    _pos += dif;
}

const ofPoint& EUNodeEntity::getPosition() const
{
    return _pos;
}
