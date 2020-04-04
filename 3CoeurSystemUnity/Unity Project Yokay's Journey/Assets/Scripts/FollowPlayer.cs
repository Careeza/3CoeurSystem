using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowPlayer : MonoBehaviour
{
    [SerializeField] private Transform target;

    public bool lockY = true;
    public bool lockX = false;
    public bool zoom = true;

    public float zoomValue = 1f;

    [Range(0, 1)] public float smoothSpeed = 0.125f;
    [Range(0, 1)] public float smoothZoom = 0.125f;
    public Vector3 offset;

    private void Start()
    {
        transform.position = target.position + offset;
    }

    void FixedUpdate()
    {
        Vector3 desiredPosition;
        if (!lockX && !lockY)
        {
            desiredPosition = new Vector3(target.position.x + offset.x, target.position.y + offset.y, target.position.z + offset.z);
        }
        else if (!lockX && lockY)
        {
            desiredPosition = new Vector3(target.position.x + offset.x, transform.position.y, target.position.z + offset.z);
        }
        else if (lockX && !lockY)
        {
            desiredPosition = new Vector3(transform.position.x, target.position.y + offset.y, target.position.z + offset.z);
        }
        else
		{
            desiredPosition = new Vector3(transform.position.x, transform.position.y, target.position.z + offset.z);
		}

        Vector3 smoothedPosition = Vector3.Lerp(transform.position, desiredPosition, smoothSpeed);
        transform.position = smoothedPosition;

        if (zoom)
        {
            Vector3 vDistance = desiredPosition - smoothedPosition;

            float distance = Mathf.Abs(vDistance.x);
            float desiredOrthographicSize = 1.25f + (distance / zoomValue);

            float newOrthographicSize = desiredOrthographicSize * smoothZoom + Camera.main.orthographicSize * (1 - smoothZoom);
            newOrthographicSize = Mathf.Clamp(newOrthographicSize, 0f, 2.2f);

            Camera.main.orthographicSize = newOrthographicSize;
        }
        else
            Camera.main.orthographicSize = 1.25f;
    }
}