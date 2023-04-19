using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AIMgr : MonoBehaviour
{
    public static AIMgr inst;
    private void Awake()
    {
        inst = this;
    }
    // Start is called before the first frame update
    void Start()
    {
        layerMask = 1 << LayerMask.GetMask("Water");
    }

   // public RaycastHit hit;
    public int layerMask;

    // Update is called once per frame
    void Update()
    {
        //Debug.Log("24");

        if (Input.GetMouseButtonDown(1)) 
        {
            //Debug.Log("28");

            Debug.Log(Input.mousePosition);
            if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out var hit, float.MaxValue, ~layerMask)) 
            {
                Debug.Log("Happening");
                Debug.DrawLine(Camera.main.transform.position, hit.point, Color.yellow, 2); //for debugging
                Vector3 pos = hit.point;
                pos.y = 0;
                Entity381 ent = FindClosestEntInRadius(pos, rClickRadiusSq);
                if (ent == null) 
                {
                    HandleMove(pos);
                } 
                else {
                    if (Input.GetKey(KeyCode.LeftControl))
                        HandleIntercept(ent);
                    else
                        HandleFollow(ent);
                }
            } else 
            {
                Debug.DrawRay(Camera.main.transform.position, Camera.main.transform.TransformDirection(Vector3.forward) * 1000, Color.yellow, 2);
            }
        }
    }

    void HandleMove(Vector3 point) 
    {
        Debug.Log("Trying to move");
        Move m = new Move(SelectionMgr.inst.selectedEntity, point);
        UnitAI uai = SelectionMgr.inst.selectedEntity.GetComponent<UnitAI>();
        if (Input.GetKey(KeyCode.LeftShift))
        {
            m.endPos = point;
            uai.AddCommand(m);
        }
        else
        {
            m.endPos = point;
            uai.SetCommand(m);
        }
    }

    void HandleFollow(Entity381 ent)
    {
        Follow f = new Follow(SelectionMgr.inst.selectedEntity, ent, new Vector3(100, 0, 0));
        UnitAI uai = SelectionMgr.inst.selectedEntity.GetComponent<UnitAI>();
        if (Input.GetKey(KeyCode.LeftShift))
            uai.AddCommand(f);
        else
            uai.SetCommand(f);

    }

    void HandleIntercept(Entity381 ent)
    {
        Intercept intercept = new Intercept(SelectionMgr.inst.selectedEntity, ent);
        UnitAI uai = SelectionMgr.inst.selectedEntity.GetComponent<UnitAI>();
        if (Input.GetKey(KeyCode.LeftShift))
            uai.AddCommand(intercept);
        else
            uai.SetCommand(intercept);

    }

    public float rClickRadiusSq = 10000;
    public Entity381 FindClosestEntInRadius(Vector3 point, float rsq)
    {
        Entity381 minEnt = null;
        float min = float.MaxValue;
        foreach (Entity381 ent in EntityMgr.inst.entities) {
            float distanceSq = (ent.transform.position - point).sqrMagnitude;
            if (distanceSq < rsq) {
                if (distanceSq < min) {
                    minEnt = ent;
                    min = distanceSq;
                }
            }    
        }
        return minEnt;
    }
}
