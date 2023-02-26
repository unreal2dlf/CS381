/*
 * Entity381.h
 *
 *  Created on: Feb 11, 2021
 *      Author: sushil
 */

#ifndef INC_ENTITY381_H_
#define INC_ENTITY381_H_

#include <OgreVector3.h>
#include <OgreSceneNode.h>
#include <OgreSceneManager.h>


enum EntityType {
	CG47Entity = 0,
	PolyPlaneEntity
};

class Entity381 {

public:
	Entity381(EntityType entType, Ogre::Vector3 pos); //might want to pass a unique id down from entityMgr
	virtual ~Entity381(){};
	//-----------------
	void Tick(float dt);
	//-----------------
	unsigned long long id;
	EntityType entityType;
	std::string name;

	Ogre::Vector3 velocity = Ogre::Vector3::ZERO;
	Ogre::Vector3 position = Ogre::Vector3::ZERO;
	bool isSelected = false;

	std::string meshName;
	Ogre::SceneNode* node = nullptr;
	Ogre::Entity* ogreEntityPtr = nullptr;
};

class CG47: public Entity381 {
public:
	CG47(Ogre::Vector3 pos);
	~CG47(){};
};


class PolyPlane: public Entity381 {
public:
	PolyPlane(Ogre::Vector3 pos);
	~PolyPlane(){};
};




#endif /* INC_ENTITY381_H_ */
