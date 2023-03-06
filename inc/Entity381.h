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
  float altitude, desiredAltitude, climbingRate;

  std::string meshfilename;
  Ogre::SceneNode* sceneNode;
  Ogre::Entity* ogreEntity;

  std::vector<Aspect*> aspects;
  bool isSelected;
  void Tick(float dt);
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

class DDG51_V2:Entity381{
public:
	DDG51_V2(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~DDG51_V2();
};

class CVN75:Entity381{
public:
	CVN75(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~CVN75();
};

class CIGARETTE_V2:Entity381{
public:
	CIGARETTE_V2(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~CIGARETTE_V2();
};

class TUG:Entity381{
public:
	TUG(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~TUG();
};

class Island:Entity381{
public:
	Island(Ogre::SceneManager*, std::string, Ogre::Vector3, int, std::string);
	~Island();
};






#endif /* INC_ENTITY381_H_ */
