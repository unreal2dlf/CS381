
#ifndef INC_ENTITYMGR_H_
#define INC_ENTITYMGR_H_

#include <Entity381.h>
#include <vector>

class EntityMgr{
public:
  EntityMgr(Ogre::SceneManager*);
  ~EntityMgr();

  std::vector<Entity381*> entities;
  Entity381* selectedEntity;
  int selectedEntityIndex;
  Ogre::SceneManager *sceneMgr;

  void CreateEntityOfTypeAtPosition(std::string, Ogre::Vector3);
  void selectNextEntity();

  void Tick(float dt);

private:
  void createEntity(std::string, Ogre::Vector3);
  void createDestroyer(Ogre::Vector3);
  void createCarrier(Ogre::Vector3);
  void createSpeedboat(Ogre::Vector3);
  void createFrigate(Ogre::Vector3);
  int numEnts;

};

#endif /* INC_ENTITYMGR_H_ */
