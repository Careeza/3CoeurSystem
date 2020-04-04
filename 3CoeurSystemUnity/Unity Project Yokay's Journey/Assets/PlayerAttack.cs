using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerAttack : MonoBehaviour
{
    public Animator animator;

    public int noOfClicks = 0;
    float lastClickedTime = 0;
    public float maxComboDelay = 1.2f;

    bool attack1End = false;
    bool attack2End = false;
//    bool attack3End = false;

    // Start is called before the first frame update
    void Start()
    {
        animator = gameObject.GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        if (Time.time - lastClickedTime > maxComboDelay)
        {
            noOfClicks = 0;
            attack1End = false;
            attack2End = false;
//            attack3End = false;

            animator.SetBool("Attack1", false);
            animator.SetBool("Attack2", false);
            animator.SetBool("Attack3", false);
        }

        if (Input.GetMouseButtonDown(0))
        {
            lastClickedTime = Time.time;
            noOfClicks++;
            if (noOfClicks == 1)
            {
                animator.SetBool("Attack1", true);
            }
            if (noOfClicks == 2 && attack1End)
			{
                animator.SetBool("Attack2", true);
            }
            if (noOfClicks == 3 && attack2End)
			{
                animator.SetBool("Attack3", true);
            }
            noOfClicks = Mathf.Clamp(noOfClicks, 0, 3);
        }
    }

    public void return1()
    {
        attack1End = true;
    }

    public void return2()
    {
        attack2End = true;
    }

    public void return3()
    {
        attack1End = false;
        attack2End = false;

        animator.SetBool("Attack1", false);
        animator.SetBool("Attack2", false);
        animator.SetBool("Attack3", false);
        noOfClicks = 0;
    }
}
