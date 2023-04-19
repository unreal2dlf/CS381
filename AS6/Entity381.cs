using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Entity381 : MonoBehaviour
{
    //--------------------------------------
    //values below change
    //--------------------------------------
    public bool isSelected = false;
    public int index;
    public bool isFlyingEntity = false;
    //public GameObject selectionCircle;
    public Vector3 position = Vector3.zero;
    public Vector3 velocity = Vector3.zero;

    public float speed;
    public float desiredSpeed;
    public float heading;
    public float desiredHeading;
    public float climbingHeight;
    public float desiredAltitude;
    public float altitude;
    //--------------------------------------
    //values below do not change
    //--------------------------------------


    public float acceleration;
    public float turnRate;
    public float maxSpeed;
    public float minSpeed;

    public AudioSource selectionSound;

    public GameObject cameraRig;
    //public GameObject selectionCircle;

    // Start is called before the first frame update
    void Start()
    {
       // selectionCircle.SetActive(false);
    }

    // Update is called once per frame
    void Update()
    {
      //  selectionCircle.SetActive(isSelected);
    }
}
