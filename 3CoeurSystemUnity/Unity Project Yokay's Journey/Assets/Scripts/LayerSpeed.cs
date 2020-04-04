using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LayerSpeed : MonoBehaviour
{
    public float speedX;
    public float speedY;
    public Vector3 offset;
    public Transform Camera;

    private void Start()
    {
     //   Camera.position = Camera.position;
    }

    private void LateUpdate()
    {
        Vector3 desiredPosition;
        desiredPosition = new Vector3(Camera.position.x * speedX, Camera.position.y * speedY, transform.position.z);
        transform.position = desiredPosition + offset;
    }
}
