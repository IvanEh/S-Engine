#pragma once

#include <map>
#include <list>
#include <GL/gl.h>

#include "app/Resources.hpp"

using namespace std;

namespace s_engine {
namespace app {
/**
 * Entity represents something that could influence
 * the world(aka scene) in any way. 
 * 
 * Entities could contain other entities(in other frameworks often such class
 * seperated into a derived class. But for the sake of simplicity we will have
 * only one class). Because of simplicity matter we add some additional 
 * functionality to this class(e.g. position)
 * 
 * An Entity belongs only to one object. So if you want to share entities 
 * between other entities you need to create a copy of it. 
 * 
 */
class Entity {
public: /* fields */
    /**
     * Each Entity class have it's unique purpose so to distinguish 
     * different entities we use some unique tag.
     * 
     * Main tag extracted into a seperate variable @ref name 
     * 
     * In general set to the class name
     */
    static constexpr string NAME_TAG { "Entity" };
private: /* fields */
    const string name;
    
    /**
     * Tags describing the 'class' of entities to which this entity belongs to.
     * The first tag in the list is the so called 'main' tag. It's not ensured
     * that the user wouldn't modify it
     * 
     * @deprecated not implemented yet, could be excluded
     */
    list<string> tags;
    
    /**
     * Entities could consist of another entities. Moreover every such 
     * component entity could do very different tasks compared to each other(
     * rendering, physics, recycling)
     */
    list<Entity> components;
    
    /**
     * Inactive entities do not perform updates. Methods that
     * iterates through components often skip through them
     */
    bool active { true };
    
    
    
private: /* methods */
    virtual void OnUpdate(long deltaTime);
};

class DrawableEntity: public Entity {
private: /* fields */
     /**
     * Used to associate the entity with a model given by the resource
     * id. 
     */
    GLuint modelResId { Resources::NONE };
    
    /**
     * Defines the need to draw the entity. If set to false still interacting with
     * the world
     */
    bool visible { false };
private: /* methods */
    virtual void OnDraw();

public: /* methods */
    void SetModel(GLuint id);
    GLuint GetModelResId();
    
};

/**
 * Let's logically seperate entities that normally served as a part of other entities
 */
class Component: public Entity {
};

}
}