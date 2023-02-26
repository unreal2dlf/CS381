/*
 * EntityMgr.h
 *
 *  Created on: Feb 12, 2020
 *      Author: sushil
 */

#ifndef INC_ENTITYMGR_H_
#define INC_ENTITYMGR_H_

#include "Entity381.h"

class EntityMgr {

public:

	EntityMgr(Ogre::SceneManager* sm);
	~EntityMgr(){};

	Entity381* CreateEntityOfTypeAtPosition(EntityType entype, Ogre::Vector3 pos);
	void Tick(float dt);
	void SelectNextEntity();

	Ogre::SceneManager* gfxSceneManager;

	std::vector<Entity381*> entities;
	Entity381* selectedEntity = nullptr;
	long int selectedEntityIndex = 0;

};



#endif /* INC_ENTITYMGR_H_ */
