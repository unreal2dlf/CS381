using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SelectionMgr : MonoBehaviour
{
    public static SelectionMgr inst;
    public LayerMask selectableLayer;
    // public GameObject selectionCircle;

    public Vector3 Intersection_Point = Vector3.zero;
    public float radius = 100;
    public List<int> IDs = new List<int>();
    public int closestEntity = 0;

    private void Awake() 
    {
        inst = this;
    }

    //public EntityMgr entityMgr;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //old code below
        if (Input.GetKeyUp(KeyCode.Tab))
            SelectNextEntity();
        //selectionCircle.SetActive(selectedEntity.isSelected);

        //below is the new code
        if (Input.GetMouseButtonDown(0))
        {
            Click();
        }

    }

    public int selectedEntityIndex= 0;
    public Entity381 selectedEntity;

    public void SelectNextEntity() 
    {
        selectedEntityIndex = (selectedEntityIndex >= EntityMgr.inst.entities.Count -1 ? 0 : selectedEntityIndex + 1);
        selectedEntity = EntityMgr.inst.entities[selectedEntityIndex];
        UnselectAll();
        selectedEntity.isSelected = true;

        selectedEntity.selectionSound.Play();
        if (!CameraMgr.inst.isRTSMode)
        {
            CameraMgr.inst.YawNode.transform.SetParent(SelectionMgr.inst.selectedEntity.cameraRig.transform);
            CameraMgr.inst.YawNode.transform.localPosition = Vector3.zero;
            CameraMgr.inst.YawNode.transform.localEulerAngles = Vector3.zero;
        }

    }
    void UnselectAll() 
    {
        foreach(Entity381 ent in EntityMgr.inst.entities)
            ent.isSelected = false;
      
    }
    // Below is what I had first that allowed clikcing on screen
    public void SelectEntity(Entity381 ent)
    {
        UnselectAll();
        selectedEntity = ent;
        selectedEntity.isSelected = true;
        selectedEntityIndex = EntityMgr.inst.entities.FindIndex(x => (x== ent));
    }

    //mouse select-------------new
    public void  Click()
    {
        RaycastHit raycastInfo;
        IDs.Clear();
        if (Physics.Raycast(Camera.main.ScreenPointToRay(Input.mousePosition), out raycastInfo, Mathf.Infinity, 1 << LayerMask.NameToLayer("Water")))
        {
            Intersection_Point = raycastInfo.point;

            for (int i = 0; i < EntityMgr.inst.entities.Count; i++)
            {
                Entity381 Obj = EntityMgr.inst.entities[i];
              /*if (Vector3.Distance(raycastInfo.point, Obj.position) < radius)
                {
                    //print(Intersection_Point + " " + Obj.position + " " + Vector3.Distance(raycastInfo.point, Obj.position));
                    IDs.Add(Obj.index);
                }*/

                if (Obj.GetComponent<Collider>() is BoxCollider boxCollider)
                {
                    Vector3 halfExtents = boxCollider.size * 0.5f;
                    if (boxCollider.bounds.Contains(raycastInfo.point))
                    {
                        IDs.Add(Obj.index);
                    }
                }
            }

            if (IDs.Count > 0)
            {
                closestEntity = FindClosestEntity(raycastInfo.point);
                SelectClosestEntity(closestEntity);
            }

            
        }

    }

    public int FindClosestEntity(Vector3 Intersection_Point)
    {
        int ID = selectedEntityIndex;
        float _min = 100000000000;
        for (int i = 0; i < IDs.Count; i++)
        {
            if (Vector3.Distance(Intersection_Point, EntityMgr.inst.entities[IDs[i]].position) < _min)
            {
                _min = Vector3.Distance(Intersection_Point, EntityMgr.inst.entities[IDs[i]].position);
                ID = IDs[i];
            }
        }
        return ID;
    }

    public void SelectClosestEntity(int id)
    {
        selectedEntity = EntityMgr.inst.entities[id];
        UnselectAll();
        selectedEntity.isSelected = true;
    }
}
