using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EndTrigger : MonoBehaviour
{
    public GameManager gameManger;

    void OnTriggerEnter2D()
    {
        gameManger.CompleteLevel();
    }
}
