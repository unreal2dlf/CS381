/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 12, 2020
 *      Author: sushil
 */

#include <EntityMgr.h>
#include "OgreSceneManager.h"
#include "OgreSceneNode.h"
#include "OgreEntity.h"



EntityMgr::EntityMgr(Ogre::SceneManager* sm){
	entities.clear();
	gfxSceneManager = sm;
}

void EntityMgr::Tick(float dt){
	for(Entity381* entPtr: entities)
		entPtr->Tick(dt);
}

Entity381* EntityMgr::CreateEntityOfTypeAtPosition(EntityType eType, Ogre::Vector3 pos){
	// Create a varaible which persists between calls to the function
	// that is responsible for assigning unique IDs to each entity.
	static long int nextId = 0;

	// Create the correct type of entity
	Entity381* entPtr;
	switch(eType){
	case CG47Entity:
		entPtr = new CG47(pos);
		break;
	case PolyPlaneEntity:
		entPtr = new PolyPlane(pos);
		break;
	default:
		throw std::runtime_error("Tried to create invalid entity type");
		break;
	}

	// Create the Ogre entity and scene node
	Ogre::Entity* ogreEnt = gfxSceneManager->createEntity(entPtr->meshName);
	entPtr->ogreEntityPtr = ogreEnt;
	entPtr->node = gfxSceneManager->getRootSceneNode()->createChildSceneNode(entPtr->position, Ogre::Quaternion::IDENTITY);
	entPtr->node->attachObject(ogreEnt);

	// Calculate an ID and a name for this entity.
	entPtr->id = nextId++;
	entPtr->name += entPtr->id;
	// Add the entity to the list of entities
	entities.push_back(entPtr);

	// If the selected entity is null, select an entity.
	// This prevents a crash which occurs when we try to move an entity when nothing is selected.
	if(selectedEntity == nullptr)
		SelectNextEntity();

	return entPtr;
}

void EntityMgr::SelectNextEntity(){
	int nEnts = entities.size();
	if(nEnts > 0){
		if(selectedEntity == nullptr)
			selectedEntityIndex = 0;
		else {
			selectedEntity->isSelected = false; //current selection is unselected
			selectedEntityIndex = (selectedEntityIndex + 1) % nEnts;
		}
		selectedEntity = entities[selectedEntityIndex];
		selectedEntity->isSelected = true; //new selection is selected
		//std::cout << "Selected: " << selectedEntity->id << std::endl;
	} else
		throw std::runtime_error("Create a game entity before selecting an entity.");
}
