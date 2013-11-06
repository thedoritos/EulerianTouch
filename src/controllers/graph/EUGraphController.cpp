//
//  EUGraphController.cpp
//  EulerianTouch
//
//  Created by thedoritos on 2013/11/05.
//
//

#include "EUGraphController.h"

EUGraphController::EUGraphController(EUGraphModel *model, EUGraphView *view)
{
    _model = model;
    _view = view;
    _view->setDelegate(this);
}

EUGraphController::~EUGraphController()
{
    
}

void EUGraphController::update(float dt)
{
    _view->update(dt);
}

void EUGraphController::draw()
{
    _view->draw();
}

bool EUGraphController::onTouch(const ofTouchEventArgs &touch)
{
    bool handled = false;
    handled = _view->handleTouch(touch);
    
    return handled;
}

void EUGraphController::onScreenTouch(const EUGraphView &view, const ofTouchEventArgs &touch)
{
    switch (touch.type) {
        case ofTouchEventArgs::down:
        {
            // Create graph if needed.
            if (! _model->isEditingGraph()) {
                _model->beginGraph();
            }
            
            // Add node.
            float x = (touch.x - view.getBounds().x) / view.getBounds().width;
            float y = (touch.y - view.getBounds().y) / view.getBounds().height;
            _model->addNode(ofPoint(x, y));
            
            // Update view.
            _view->update(*_model);
            
            break;
        }
        case ofTouchEventArgs::move:
            break;
        case ofTouchEventArgs::up:
            break;
        default:
            break;
    }
}

void EUGraphController::onGraphTouch(const EUGraphView &view, const ofTouchEventArgs &touch, int graphIdx)
{
    
}

void EUGraphController::onNodeTouch(const EUGraphView &view, const ofTouchEventArgs &touch, int graphIdx, int nodeIdx)
{
    switch (touch.type) {
        case ofTouchEventArgs::down:
        {
            // Add node or complete graph.
            bool completed = _model->addNodeOn(graphIdx, nodeIdx);
            if (completed) {
                _model->endGraph();
            }
            
            // Update view.
            _view->update(*_model);
            
            break;
        }
        default:
            break;
    }
}
