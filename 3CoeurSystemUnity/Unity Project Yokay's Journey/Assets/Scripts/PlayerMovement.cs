using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerMovement : MonoBehaviour {

	private Rigidbody2D m_Rigidbody2D;
	public CharacterController2D controller;
	public Animator animator;

	public float runSpeed = 40f;

	float horizontalMove = 0f;
	bool jump = false;
	bool dash = false;


	private void Awake()
	{
		m_Rigidbody2D = GetComponent<Rigidbody2D>();
	}

	// Update is called once per frame
	void Update () {

		horizontalMove = Input.GetAxisRaw("Horizontal") * runSpeed;

		animator.SetFloat("Speed", Mathf.Abs(horizontalMove));
		animator.SetFloat("JumpSpeed", m_Rigidbody2D.velocity.y);

		if (Input.GetButtonDown("Jump"))
		{
			jump = true;
		}

        if (Input.GetButtonDown("Dash"))
		{
			dash = true;
		}
	}

	public void OnLanding()
	{
		animator.SetBool("IsJumping", false);
	}

    public void OnJumping()
	{
		animator.SetBool("IsJumping", true);
	}

    public void OnDashing()
	{
		animator.SetBool("IsDashing", true);
	}

    public void EndDash()
	{
		dash = false;
		animator.SetBool("IsDashing", false);
	}

	void FixedUpdate ()
	{
		// Move our character
		controller.Move(horizontalMove, jump, dash);

//		if (transform.position.y < -10f)
//			FindObjectOfType<GameManager>().EndGame();

		jump = false;
	}
}
