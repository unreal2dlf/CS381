/*
 * Name:
 * Email:
 * Date:
 */

#ifndef __as2_h_
#define __as2_h_

#include "BaseApplication.h"
#include "EntityMgr.h"

//---------------------------------------------------------------------------

class as2 : public BaseApplication {
	constexpr static float surfaceHeight = -3.5;

	// Variables used to control various speeds
	constexpr static float cameraStep = 25; // units per second of camera movement
	constexpr static float velocityStep = 10; // units per second of velocity increase

public:
    as2() {}
    virtual ~as2() {}

protected:

    // Scene Setup
    virtual void createScene(void);
    void setupCamera();
    void createGround();
    void createSkyAndShadows();
    void createEntities();

    // Frame Updates
	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
    void updateCamera(float dt);

    // Input Handling
	bool processUnbufferedInput(const Ogre::FrameEvent& fe);
    virtual bool keyPressed(const OIS::KeyEvent& ke);
    virtual bool keyReleased(const OIS::KeyEvent& ke);

private:

    Ogre::SceneNode* cameraSceneNode = nullptr;
    EntityMgr* entityMgr = nullptr;

    Ogre::Vector3 cameraMoveVec = Ogre::Vector3::ZERO;
};

#endif //
