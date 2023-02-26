#ifndef INC_ENTITY381_H_
#define INC_ENTITY381_H_

#include <Aspect.h>
#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreVector3.h>
#include <vector>

class Entity381{
public:
  Entity381();
  Entity381(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
  virtual ~Entity381();

  int entityID;
  std::string entityName;

  Ogre::Vector3 position;
  Ogre::Vector3 velocity;
  float minSpeed, maxSpeed, speed;
  float heading, desiredSpeed, desiredHeading;
  float acceleration, turningRate;

  std::string meshfilename;
  Ogre::SceneNode* sceneNode;
  Ogre::Entity* ogreEntity;

  std::vector<Aspect*> aspects;
  bool isSelected;
  void Tick(float dt);
};

class Cube:Entity381{
public:
	Cube(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~Cube();
};

class CG47:Entity381{
public:
	CG47(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~CG47();
};

class PolyPlane:Entity381{
public:
	PolyPlane(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~PolyPlane();
};

class Destroyer:Entity381{
public:
	Destroyer(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~Destroyer();
};

class Carrier:Entity381{
public:
	Carrier(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~Carrier();
};

class Speedboat:Entity381{
public:
	Speedboat(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~Speedboat();
};

class Frigate:Entity381{
public:
	Frigate(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~Frigate();
};







#endif /* INC_ENTITY381_H_ */
