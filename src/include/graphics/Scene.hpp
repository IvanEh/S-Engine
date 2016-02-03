#pragma once

#include <list>

#include "app/Entity.hpp"

using namespace std;


class Scene {
private: /* fields */
    /**
     * For better performance drawable entities stored seperately 
     * from other entities
     */
    list<DrawableEntities> drawables;
    
    /**
     * Non-drawable entities manage the logics of the scene.
     */
    list<Entity> managers;
    
    /**
     * Scene camera
     */
    Camera camera;
public: /* methods */
    /**
     * Called when a particular scene prepared to execute
     */
    virtual void OnStart();
    
    /**
     * Called every frame
     */
    virtual void OnUpdate(long deltaTime);
    
    /**
     * Draw the scene
     */
    virtual void OnDraw();
};
