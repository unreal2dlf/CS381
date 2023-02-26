/*
 * Name:
 * Email:
 * Date:
 */

#include <as2.h>

// ---------------------------------------------- Scene Setup -------------------------------------------- //

void as2::createScene(void) {
	setupCamera();
	createGround();
	createSkyAndShadows();

	entityMgr = new EntityMgr(mSceneMgr);

	createEntities();
}

void as2::setupCamera(){
	mCamera->setPosition(0, 0, 0);
	mCamera->setOrientation(Ogre::Quaternion::IDENTITY);

	cameraSceneNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	cameraSceneNode->attachObject(mCamera);
	cameraSceneNode->setPosition(0, 200, 800);
	mCamera->lookAt(0, 0, 0);
}

void as2::createGround(){
	// Create surface plane
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	Ogre::MeshManager::getSingleton().createPlane(
			"ocean",
			Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			plane, 10000, 10000, 20, 20, true, 1, 5, 5, Ogre::Vector3::UNIT_Z);

	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ocean");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

	groundEntity->setMaterialName("Ocean2_Cg");
	groundEntity->setCastShadows(false);
}

void as2::createSkyAndShadows(){
	mSceneMgr->setSkyBox(true, "Examples/MorningSkyBox");

	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
}

void as2::createEntities(){
	float x = 0;
	float y = 0;
	int entitiesPerRow = 5;
	int spacing = 200; // units in-between entities

	// Loop through the entity types
	for(int i = 0; i < 2; i++){
		x = -(entitiesPerRow/2) * spacing; // this centers positions of entities along the x-axis
		// Create row of entity type specified by i
		for(int j = 0; j < entitiesPerRow; j++){
			entityMgr->CreateEntityOfTypeAtPosition((EntityType) i, Ogre::Vector3(x, y, 0));
			x += 200;
		}
		y += 100;
	}
}

// ---------------------------------------------- Frame Updates -------------------------------------------- //

bool as2::frameRenderingQueued(const Ogre::FrameEvent& fe) {
	// Process all of the frame rendering from base application (saving if we should keep the application running)
	if (!BaseApplication::frameRenderingQueued(fe)) return false;

	// Process our unbuffered input
	if(!processUnbufferedInput(fe)) return false;

	// Update everything that is part of the infinite loop
	updateCamera(fe.timeSinceLastFrame);
	entityMgr->Tick(fe.timeSinceLastFrame);

	// Return true if we should keep the application running
	return true;
}

void as2::updateCamera(float dt) {
	// Move camera by size of vector
	cameraSceneNode->translate(cameraMoveVec * dt, Ogre::Node::TS_LOCAL);

	// Reset camera direction vector to zero for linear movement
	cameraMoveVec = Ogre::Vector3::ZERO;
}

// ---------------------------------------------- Input Handling -------------------------------------------- //

// Unbuffered input handling
bool as2::processUnbufferedInput(const Ogre::FrameEvent& fe) {
	// Keys that are captured without rappid toggle prevention
	if (mKeyboard->isKeyDown(OIS::KC_W))
		cameraMoveVec.z -= cameraStep;
	if (mKeyboard->isKeyDown(OIS::KC_S))
		cameraMoveVec.z += cameraStep;
	if (mKeyboard->isKeyDown(OIS::KC_E))
		cameraMoveVec.y += cameraStep;
	if (mKeyboard->isKeyDown(OIS::KC_F))
		cameraMoveVec.y -= cameraStep;
	if (mKeyboard->isKeyDown(OIS::KC_A)) {
		if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
			cameraSceneNode->yaw(Ogre::Degree(15 * fe.timeSinceLastFrame));
		else
			cameraMoveVec.x -= cameraStep;
	}

	if (mKeyboard->isKeyDown(OIS::KC_D)) {
		if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
			cameraSceneNode->yaw(Ogre::Degree(-15 * fe.timeSinceLastFrame));
		else
			cameraMoveVec.x += cameraStep;
	}

	return true;
}

// Buffered input handling
bool as2::keyPressed(const OIS::KeyEvent& ke) {
	// Call the baseapp key press function since it still has purpose
	if (!BaseApplication::keyPressed(ke)) return false;

	switch (ke.key) {
		case OIS::KC_TAB:
			entityMgr->SelectNextEntity();
			break;
		case OIS::KC_SPACE:
			entityMgr->selectedEntity->velocity = Ogre::Vector3::ZERO;
			break;
		case OIS::KC_Q:
			mShutDown = true;
			break;

		// Selected entity control
		case OIS::KC_UP:
			entityMgr->selectedEntity->velocity.z -= velocityStep;
			break;
		case OIS::KC_DOWN:
			entityMgr->selectedEntity->velocity.z += velocityStep;
			break;
		case OIS::KC_LEFT:
			entityMgr->selectedEntity->velocity.x -= velocityStep;
			break;
		case OIS::KC_RIGHT:
			entityMgr->selectedEntity->velocity.x += velocityStep;
			break;
		case OIS::KC_PGUP:
			entityMgr->selectedEntity->velocity.y += velocityStep;
			break;
		case OIS::KC_PGDOWN:
			entityMgr->selectedEntity->velocity.y -= velocityStep;
			break;

		default:
			break;
	}

	return true;
}

// Buffered input handling
bool as2::keyReleased(const OIS::KeyEvent& ke) {
	// Call the baseapp key press function since it still has purpose
	if (!BaseApplication::keyReleased(ke)) return false;

	return true;
}


//---------------------------------------------------------------------------

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
    INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT)
#else
    int main(int argc, char *argv[])
#endif
    {
        // Create application object
        as2 app;

        try {
            app.go();
        } catch(Ogre::Exception& e)  {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
            MessageBox(NULL, e.getFullDescription().c_str(), "An exception has occurred!", MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
            std::cerr << "An exception has occurred: " <<
                e.getFullDescription().c_str() << std::endl;
#endif
        }

        return 0;
    }

#ifdef __cplusplus
}
#endif

//---------------------------------------------------------------------------
