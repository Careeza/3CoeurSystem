using UnityEngine;
using UnityEngine.Events;

public class CharacterController2D : MonoBehaviour
{
	[SerializeField] private float m_DashForce = 7.5f;
    [SerializeField] private float m_DashCDValue = 1f;
	[SerializeField] private float m_JumpForce = 7.5f;							// Amount of force added when the player jumps.
	[Range(0, .3f)] [SerializeField] private float m_MovementSmoothing = .05f;	// How much to smooth out the movement
	[SerializeField] private bool m_AirControl = true;							// Whether or not a player can steer while jumping;
	[SerializeField] private LayerMask m_WhatIsGround;							// A mask determining what is ground to the character
	[SerializeField] private Transform m_GroundCheck;							// A position marking where to check if the player is grounded.

	const float k_GroundedRadius = .02f; // Radius of the overlap circle to determine if grounded
	private bool m_Grounded;            // Whether or not the player is grounded.
	private Rigidbody2D m_Rigidbody2D;
	private bool m_FacingRight = true;  // For determining which way the player is currently facing.
	private Vector3 velocity = Vector3.zero;

    private int maxJump;
	public int maxJumpValue = 2;
    private float m_LastDash;

	[Header("Events")]
	[Space]

	public UnityEvent OnLandEvent;
	public UnityEvent OnJumpEvent;
	public UnityEvent OnDashEvent;

	private void Awake()
	{
		m_Rigidbody2D = GetComponent<Rigidbody2D>();

		if (OnLandEvent == null)
			OnLandEvent = new UnityEvent();

		if (OnJumpEvent == null)
			OnJumpEvent = new UnityEvent();

		if (OnDashEvent == null)
			OnDashEvent = new UnityEvent();
	}

	private void Start()
	{
		maxJump = maxJumpValue;
		m_LastDash = 0f;
	}

	private void FixedUpdate()
	{
		bool wasGrounded = m_Grounded;
		m_Grounded = false;

		// The player is grounded if a circlecast to the groundcheck position hits anything designated as ground
		// This can be done using layers instead but Sample Assets will not overwrite your project settings.
		Collider2D[] colliders = Physics2D.OverlapCircleAll(m_GroundCheck.position, k_GroundedRadius, m_WhatIsGround);
		for (int i = 0; i < colliders.Length; i++)
		{
			if (colliders[i].gameObject != gameObject)
			{
				m_Grounded = true;
				if (!wasGrounded)
				{
					OnLandEvent.Invoke();
				}
			}
		}

        if (!m_Grounded && wasGrounded)
		{
			OnJumpEvent.Invoke();
		}
	}


	public void Move(float move, bool jump, bool dash)
	{
		//only control the player if grounded or airControl is turned on
		if (m_Grounded || m_AirControl)
		{
			Vector3 targetVelocity = new Vector2(move * 10f, m_Rigidbody2D.velocity.y);
			m_Rigidbody2D.velocity = Vector3.SmoothDamp(m_Rigidbody2D.velocity, targetVelocity, ref velocity, m_MovementSmoothing);

			if (move > 0 && !m_FacingRight)
			{
				Flip();
			}
			else if (move < 0 && m_FacingRight)
			{
				Flip();
			}
		}

		if (m_Grounded && m_Rigidbody2D.velocity.y < 0.01)
		{
			maxJump = maxJumpValue;
		}

        if (dash && Time.time - m_LastDash > m_DashCDValue)
		{
			m_LastDash = Time.time;
			float dashSpeed = m_DashForce;
			if (!m_FacingRight)
				dashSpeed = -dashSpeed;
			m_Rigidbody2D.velocity = new Vector2(dashSpeed, m_Rigidbody2D.velocity.y);
			OnDashEvent.Invoke();
		}

		if (jump && maxJump > 0)
        {
			m_Grounded = false;
			maxJump--;
            m_Rigidbody2D.velocity = new Vector2(m_Rigidbody2D.velocity.x, m_JumpForce);
		}
	}


	private void Flip()
	{
		// Switch the way the player is labelled as facing.
		m_FacingRight = !m_FacingRight;

		// Multiply the player's x local scale by -1.
		Vector3 theScale = transform.localScale;
		theScale.x *= -1;
		transform.localScale = theScale;
	}
}
