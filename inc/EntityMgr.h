
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
  void createDDG51_V2(Ogre::Vector3);
  void createCVN75(Ogre::Vector3);
  void createCG47(Ogre::Vector3);
  void createCIGARETTE_V2(Ogre::Vector3);
  void createTUG(Ogre::Vector3);
  void createPolyPlane(Ogre::Vector3);
  void createIsland(Ogre::Vector3);
  int numEnts;

};

#endif /* INC_ENTITYMGR_H_ */
