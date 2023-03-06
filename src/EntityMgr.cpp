#include <EntityMgr.h>

EntityMgr::EntityMgr(Ogre::SceneManager* newSceneMgr){
	selectedEntity = 0;
	sceneMgr = newSceneMgr;
	numEnts = 0;
	selectedEntityIndex = -1;
}

EntityMgr::~EntityMgr(){
}

void EntityMgr::createEntity(std::string meshfilename, Ogre::Vector3 pos){
	Entity381 *newEnt = new Entity381(sceneMgr, meshfilename, pos, numEnts, "");
	numEnts++;
	entities.push_back(newEnt);
}

void EntityMgr::createDDG51_V2(Ogre::Vector3 pos){
	DDG51_V2 *newEnt = new DDG51_V2(sceneMgr, "ddg51-v2.mesh", pos, numEnts, "ddg51-v2");
	numEnts++;
	entities.push_back((Entity381 *)newEnt);
}

void EntityMgr::createCG47(Ogre::Vector3 pos){
	CG47 *newEnt = new CG47(sceneMgr, "cg47.mesh", pos, numEnts, "cg47.mesh");
	numEnts++;
	entities.push_back((Entity381 *)newEnt);
}

void EntityMgr::createCVN75(Ogre::Vector3 pos){
	CVN75 *newEnt = new CVN75(sceneMgr, "cvn75.mesh", pos, numEnts, "cvn75");
	numEnts++;
	entities.push_back((Entity381 *)newEnt);
}

void EntityMgr::createCIGARETTE_V2(Ogre::Vector3 pos){
	CIGARETTE_V2 *newEnt = new CIGARETTE_V2(sceneMgr, "cigarette-V2.mesh", pos, numEnts, "cigarette-V2");
	numEnts++;
	entities.push_back((Entity381 *)newEnt);
	//how do I fix the multiple material problem
}

void EntityMgr::createTUG(Ogre::Vector3 pos){
	TUG *newEnt = new TUG(sceneMgr, "tug.mesh", pos, numEnts, "tug");
	numEnts++;
	entities.push_back((Entity381 *)newEnt);
}

void EntityMgr::createPolyPlane(Ogre::Vector3 pos){
	PolyPlane *newEnt = new PolyPlane(sceneMgr, "PolyPlane.mesh", pos, numEnts, "PolyPlane");
	numEnts++;
	entities.push_back((Entity381 *)newEnt);
}

void EntityMgr::createIsland(Ogre::Vector3 pos){
	Island *newEnt = new Island(sceneMgr, "island2.mesh", pos, numEnts, "IslandTerrain");
	numEnts++;
	entities.push_back((Entity381 *)newEnt);
}



void EntityMgr::selectNextEntity(){
	if(selectedEntityIndex >= numEnts - 1) {
		// Wrap around
		selectedEntityIndex = 0;
	}
	else {
		selectedEntityIndex++;
	}
	if(selectedEntity != 0){
		// Update so that other entities don't
		// count as selected
		selectedEntity->isSelected = false;
	}
	selectedEntity = entities[selectedEntityIndex];
	selectedEntity->isSelected = true;
}

void EntityMgr::CreateEntityOfTypeAtPosition(std::string entType, Ogre::Vector3 pos){
	if(entType == "DDG51_V2"){
		createDDG51_V2(pos);
	}
	else if(entType == "CG47"){
		createCG47(pos);
	}
	else if(entType == "CIGARETTE_V2"){
		createCIGARETTE_V2(pos);
	}
	else if(entType == "TUG"){
		createTUG(pos);
	}
	else if (entType == "CVN75"){
		createCVN75(pos);
	}
	else if(entType == "PolyPlane"){
		createPolyPlane(pos);
	}
	else if(entType == "Island"){
		createIsland(pos);
		}
	/*else{
		// If they accidentally forgot to specify
		createEntity("ninja.mesh", pos);
	}*/
}
//Should there be a Void EntityMgr::Tick3D for the plane?
void EntityMgr::Tick(float dt){
	for(int i = 0; i < numEnts; i++){
		entities[i]->Tick(dt);
	}
}
