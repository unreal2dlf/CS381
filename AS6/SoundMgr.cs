using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Audio;

public class SoundMgr : MonoBehaviour
{
    public static SoundMgr inst;

    private void Awake()
    {
        inst = this;
    }

    private float thresholdVolume = -80f;

    public AudioMixer audioMixer;

    [Range(0f,1f)]
    public float masterVolume;
    [Range(0f, 1f)]
    public float ambientVolume;
    [Range(0f, 1f)]
    public float idleVolume;
    [Range(0f, 1f)]                             
    public float musicVolume;
    [Range(0f, 1f)]
    public float effectVolume;


    // Update is called once per frame
    void Update()
    {
        SetVolume("masterVol",masterVolume);
    }

    public void SetVolume(string exposedParam, float value)
    {
        audioMixer.SetFloat(exposedParam, thresholdVolume * (1f-value));
    }
}
