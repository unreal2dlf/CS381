using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ControlMgr : MonoBehaviour
{

    public static ControlMgr inst;
    // Start is called before the first frame update
    void Start()
    {
        inst = this;
    }

    public float deltaSpeed = 1;
    public float deltaHeading = 2;
    public float deltaAltitude = 10;
    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyUp(KeyCode.UpArrow))
            SelectionMgr.inst.selectedEntity.desiredSpeed += deltaSpeed;
        if (Input.GetKeyUp(KeyCode.DownArrow))
            SelectionMgr.inst.selectedEntity.desiredSpeed -= deltaSpeed;
        SelectionMgr.inst.selectedEntity.desiredSpeed =
            Utils.Clamp(SelectionMgr.inst.selectedEntity.desiredSpeed, SelectionMgr.inst.selectedEntity.minSpeed, SelectionMgr.inst.selectedEntity.maxSpeed);


        if (Input.GetKeyUp(KeyCode.LeftArrow))
            SelectionMgr.inst.selectedEntity.desiredHeading -= deltaHeading;
        if (Input.GetKeyUp(KeyCode.RightArrow))
            SelectionMgr.inst.selectedEntity.desiredHeading += deltaHeading;
        SelectionMgr.inst.selectedEntity.desiredHeading = Utils.Degrees360(SelectionMgr.inst.selectedEntity.desiredHeading);
        //Plane Altitude
        if (Input.GetKeyUp(KeyCode.PageUp))
            SelectionMgr.inst.selectedEntity.desiredAltitude += deltaAltitude;
        if (Input.GetKeyUp(KeyCode.PageDown))
            SelectionMgr.inst.selectedEntity.desiredAltitude -= deltaAltitude;
        if (Input.GetKeyUp(KeyCode.Keypad9))
            SelectionMgr.inst.selectedEntity.desiredAltitude += deltaAltitude;
        if (Input.GetKeyUp(KeyCode.Keypad3))
            SelectionMgr.inst.selectedEntity.desiredAltitude -= deltaAltitude;
        //quit

        if (Input.GetKey("escape"))
        {
            Application.Quit();
        }
    }
}
