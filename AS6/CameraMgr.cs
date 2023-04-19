using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMgr : MonoBehaviour
{
    public static CameraMgr inst;
    private void Awake()
    {
        inst = this;
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }
    public GameObject RTSCameraRig;
    public GameObject YawNode;// child of RTSRig
    public GameObject PitchNode;//child of Yawnode
    public GameObject RollNode;//child of Pitchnode
    // Update is called once per frame
    public float cameraMoveSpeed= 100;
    public float cameraTurnRate= 10;
    public Vector3 currentYawEulerAngles = Vector3.zero;
    public Vector3 currentPitchEulerAngles = Vector3.zero;

    void Update()
    {
        if (Input.GetKey(KeyCode.W))
            YawNode.transform.Translate(Vector3.forward * Time.deltaTime * cameraMoveSpeed);
        if (Input.GetKey(KeyCode.S))
            YawNode.transform.Translate(Vector3.back * Time.deltaTime * cameraMoveSpeed);
        if (Input.GetKey(KeyCode.A))
            YawNode.transform.Translate(Vector3.left * Time.deltaTime * cameraMoveSpeed);
        if (Input.GetKey(KeyCode.D))
            YawNode.transform.Translate(Vector3.right * Time.deltaTime * cameraMoveSpeed);
        if (Input.GetKey(KeyCode.R))
            YawNode.transform.Translate(Vector3.up * Time.deltaTime * cameraMoveSpeed);
        if (Input.GetKey(KeyCode.F))
            YawNode.transform.Translate(Vector3.down * Time.deltaTime * cameraMoveSpeed);

        currentYawEulerAngles = YawNode.transform.localEulerAngles;
        if (Input.GetKey(KeyCode.Q))
           currentYawEulerAngles.y -= cameraTurnRate * Time.deltaTime;
        if (Input.GetKey(KeyCode.E))
            currentYawEulerAngles.y += cameraTurnRate * Time.deltaTime;
        YawNode.transform.localEulerAngles = currentYawEulerAngles;

        currentPitchEulerAngles = PitchNode.transform.localEulerAngles;
        if (Input.GetKey(KeyCode.Z))
            currentPitchEulerAngles.x -= cameraTurnRate * Time.deltaTime;
        if (Input.GetKey(KeyCode.X))
            currentPitchEulerAngles.x += cameraTurnRate * Time.deltaTime;
        PitchNode.transform.localEulerAngles = currentPitchEulerAngles;

        if (Input.GetKeyUp(KeyCode.C))
        {
            if (isRTSMode)
            {
                YawNode.transform.SetParent(SelectionMgr.inst.selectedEntity.cameraRig.transform);
                YawNode.transform.localPosition = Vector3.zero;
                YawNode.transform.localEulerAngles = Vector3.zero;
            }else {
                YawNode.transform.SetParent(RTSCameraRig.transform);
                YawNode.transform.localPosition = Vector3.zero;
                YawNode.transform.localEulerAngles = Vector3.zero;
            }
            isRTSMode = !isRTSMode;
        }
    }
    public bool isRTSMode = true;
}
