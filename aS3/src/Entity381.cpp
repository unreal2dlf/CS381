
#include <Entity381.h>

std::string myStrConverter(int thatID){
	// Convert int to string, couldn't figure
	// out how to use C++11
	char buffer[100];
	sprintf(buffer, "%i", thatID);
	return std::string(buffer);
}

Entity381::Entity381(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName){

	meshfilename = whichMesh;
	position = pos;
	velocity = Ogre::Vector3(0, 0, 0);
	entityID = whatID;
	isSelected = false;

	// Easy naming convention to help when debugging
	entityName = whichMesh + "_" + myStrConverter(entityID);

	ogreEntity = sceneMgr->createEntity(meshfilename);
	sceneNode = sceneMgr->getRootSceneNode()->createChildSceneNode(pos);
	sceneNode->attachObject(ogreEntity);
	ogreEntity->setMaterialName(materialName);

	Physics* physics = new Physics(this);
	aspects.push_back((Aspect*) physics);
	Renderable* renderable = new Renderable(this);
	aspects.push_back((Aspect*)renderable);
	Rotator* rotator = new Rotator(this);
	aspects.push_back((Aspect*)rotator);

	minSpeed = 0, maxSpeed = 0, speed = 0;
	heading = 0, desiredSpeed = 0, desiredHeading = 0;
	acceleration = 0, turningRate = 0;
}

Entity381::~Entity381(){
}

void Entity381::Tick(float dt){
	for(unsigned int i = 0; i < aspects.size(); i++){
		aspects[i]->Tick(dt);
	}
}

Destroyer::Destroyer(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0; // Ships can't go backwards
	maxSpeed = 150; // Decently fast I guess
	acceleration = 15;
	turningRate = 10;
}

Destroyer::~Destroyer(){
}

Carrier::Carrier(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0;
	maxSpeed = 200; // Fastest of all the ships
	acceleration = 20; // Should be able to get up to speed pretty fast
	turningRate = 5; // Slowest at turning
}

Carrier::~Carrier(){
}

Speedboat::Speedboat(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0;
	maxSpeed = 125;
	acceleration = 15;
	turningRate = 15;
}

Speedboat::~Speedboat(){
}

Frigate::Frigate(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0;
	maxSpeed = 75;
	acceleration = 10;
	turningRate = 12;
}

Frigate::~Frigate(){
}

/*Alien::Alien(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0;
	maxSpeed = 50; // Very slow because weak engine
	acceleration = 10; // Very agile, should be able to reach max speed fast
	turningRate = 45; // Turning abilities that defy physics
}*/

/*Alien::~Alien(){
}*/
