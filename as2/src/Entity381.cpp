/*
 * Entity381.cpp
 *
 *  Created on: Feb 11, 2020
 *      Author: sushil
 */

#include<Entity381.h>

Entity381::Entity381(EntityType entType, Ogre::Vector3 pos){
	position = pos;
	entityType = entType;
}

void Entity381::Tick(float dt){
	position += velocity * dt;
	node->setPosition(position);
	node->showBoundingBox(isSelected);
}

//--------------------------------------------------------------
CG47::CG47(Ogre::Vector3 pos): Entity381(CG47Entity, pos){
	meshName = "cg47.mesh";
	name = "CG47: ";
}

//--------------------------------------------------------------
PolyPlane::PolyPlane(Ogre::Vector3 pos): Entity381(PolyPlaneEntity, pos){
	meshName = "PolyPlane.mesh";
	name = "PolyPlane: ";
}
