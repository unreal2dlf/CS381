
#include <Entity381.h>



Entity381::Entity381(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName){

	meshfilename = whichMesh;
	position = pos;
	velocity = Ogre::Vector3(0, 0, 0);
	entityID = whatID;
	isSelected = false;


	entityName = whichMesh;

	ogreEntity = sceneMgr->createEntity(meshfilename);
	sceneNode = sceneMgr->getRootSceneNode()->createChildSceneNode(pos);
	sceneNode->attachObject(ogreEntity);
	ogreEntity->setMaterialName(materialName);

	Physics* physics = new Physics(this);


	aspects.push_back((Aspect*) physics);
	//aspects.push_back((Aspect*) physics3d);
	Renderable* renderable = new Renderable(this);
	aspects.push_back((Aspect*)renderable);
	Rotator* rotator = new Rotator(this);
	aspects.push_back((Aspect*)rotator);

	minSpeed = 0, maxSpeed = 0, speed = 0;
	heading = 0, desiredSpeed = 0, desiredHeading = 0;
	acceleration = 0, turningRate = 0;
	altitude= 0, desiredAltitude= 0, climbingRate= 0;
}

Entity381::~Entity381(){
}


void Entity381::Tick(float dt){
	for(unsigned int i = 0; i < aspects.size(); i++){
		aspects[i]->Tick(dt);
	}
}

DDG51_V2::DDG51_V2(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0; // Ships can't go backwards
	maxSpeed = 150; // Decently fast I guess
	acceleration = 15;
	turningRate = 10;


}

DDG51_V2::~DDG51_V2(){
}

CVN75::CVN75(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0;
	maxSpeed = 200; // Fastest of all the ships
	acceleration = 20; // Should be able to get up to speed pretty fast
	turningRate = 5; // Slowest at turning
}

CVN75::~CVN75(){
}

CIGARETTE_V2::CIGARETTE_V2(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0;
	maxSpeed = 125;
	acceleration = 15;
	turningRate = 15;
}

CIGARETTE_V2::~CIGARETTE_V2(){
}

TUG::TUG(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0;
	maxSpeed = 75;
	acceleration = 10;
	turningRate = 12;
}

TUG::~TUG(){
}


CG47::CG47(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = 0;
	maxSpeed = 150; // Fastest of all the ships
	acceleration = 20; // Should be able to get up to speed pretty fast
	turningRate = 5; // Slowest at turning
}

CG47::~CG47(){
}

PolyPlane::PolyPlane(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	aspects.erase(aspects.begin());
	Physics3D* physics3d= new Physics3D(this);
	minSpeed = 0;
	maxSpeed = 150; // Fastest of all the ships
	acceleration = 20; // Should be able to get up to speed pretty fast
	turningRate = 10; // Slowest at turning
	climbingRate = 20;// should rise in altitude quickly
	altitude=10;
	desiredAltitude=10;
	aspects.push_back((Aspect*) physics3d);

}

PolyPlane::~PolyPlane(){
}

Island::Island(Ogre::SceneManager* sceneMgr, std::string whichMesh, Ogre::Vector3 pos, int whatID, std::string materialName):Entity381(sceneMgr, whichMesh, pos, whatID, materialName){
	minSpeed = .01;
	maxSpeed = 1;
	acceleration = 01;
	turningRate = 1;
}

Island::~Island(){
}

