using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PhysicsAndInput : MonoBehaviour
{
    public Vector3 position;
    public Vector3 velocity;
    public bool isSelected= false;
    public GameObject selectionCircle;
    // Start is called before the first frame update
    void Start()
    {
        velocity = Vector3.zero;
      
    }

    // Update is called once per frame
    void Update()
    {

        position = position + velocity * Time.deltaTime;
        transform.localPosition = position;

        selectionCircle.SetActive(isSelected);
    }

}
