//
//  EUGraphEntity.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/06.
//
//

#include "EUGraphEntity.h"

EUGraphEntity::EUGraphEntity()
{
    
}

EUGraphEntity::EUGraphEntity(const EUGraphEntity &base)
{
    for (int i = 0; i < base.getNumNodes(); i++) {
        EUNodeEntity *node = new EUNodeEntity(base.getNode(i));
        _nodeArray.push_back(node);
    }
}

EUGraphEntity::~EUGraphEntity()
{
    while (_nodeArray.size() > 0) {
        EUNodeEntity *node = _nodeArray[0];
        _nodeArray.erase(_nodeArray.begin());
        if (node != 0) {
            delete node;
            node = 0;
        }
    }
}

void EUGraphEntity::add(const ofPoint &pos, int idx)
{
    EUNodeEntity *node = new EUNodeEntity(pos);
    _nodeArray.insert(_nodeArray.begin() + idx, node);
}

void EUGraphEntity::add(const ofPoint &pos)
{
    this->add(pos, _nodeArray.size());
}

void EUGraphEntity::remove(int idx)
{
    EUNodeEntity *toDel = _nodeArray[idx];
    _nodeArray.erase(_nodeArray.begin() + idx);
    
    if (toDel != 0) {
        delete toDel;
        toDel = 0;
    }
}

void EUGraphEntity::move(const ofPoint &dif)
{
    for (vector<EUNodeEntity *>::iterator itr = _nodeArray.begin(); itr != _nodeArray.end(); ++itr) {
        (*itr)->move(dif);
    }
}

void EUGraphEntity::move(const ofPoint &dif, int idx)
{
    _nodeArray[idx]->move(dif);
}

const int EUGraphEntity::getNumNodes() const
{
    return _nodeArray.size();
}

const EUNodeEntity & EUGraphEntity::getNode(int idx) const
{
    return *_nodeArray[idx];
}

const bool EUGraphEntity::isCompleted() const
{
    return _isCompleted;
}

void EUGraphEntity::setCompleted(bool completed)
{
    _isCompleted = completed;
}
