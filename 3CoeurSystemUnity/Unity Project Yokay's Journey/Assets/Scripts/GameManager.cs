using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    bool gameHasEnded = false;
    public float restartDelay = 1;

    public GameObject completLevelUI;


    public void CompleteLevel()
    {
        completLevelUI.SetActive(true);
        Debug.Log("level01");
    }

    public void EndGame()
    {
        if (!gameHasEnded)
        {
            Debug.Log("Game Over");
            gameHasEnded = true;
        }
        Invoke("Restart", restartDelay);
    }

    void Restart()
    {
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }
}
