#pragma once

#include <map>
#include <list>

using namespace std;

namespace s_engine {
namespace app {
/**
 * Entity represents something that could influence
 * the world(aka scene) in any way. 
 * 
 * Entities could contain other entities(in other frameworks often such class
 * seperated into a derived class. But for the sake of simplicity we will have
 * only one class)
 * 
 * An Entity belongs only to one object. So if you want to share entities 
 * between other entities you need to create a copy of it. 
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
    void OnUpdate(long deltaTime);
    
};

}
}