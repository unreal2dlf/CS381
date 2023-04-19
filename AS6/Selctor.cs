using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Selctor : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        entity = GetComponentInParent<Entity381>();
    }
    public Entity381 entity;
    public GameObject selectionCircle;


    // Update is called once per frame
    void Update()
    {
      if(entity != null)
            selectionCircle.SetActive(entity.isSelected);
    }
    private void OnMouseDown()
    {
        Debug.Log("Click");
        SelectionMgr.inst.SelectEntity(entity);
        //SelectionMgr.inst.Click();
    }
}
