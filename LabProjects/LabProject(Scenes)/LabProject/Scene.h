#pragma once

#include "GameObject.h"
#include "Player.h"

class CScene
{
public:
	CScene();
	virtual ~CScene();

	CPlayer						*m_pPlayer = NULL;

	int							m_nObjects = 0;
	CGameObject					**m_ppObjects = NULL;

	virtual void BuildObjects();
	virtual void ReleaseObjects();

	virtual void CheckObjectByObjectCollisions();
		
	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);

	virtual void OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	virtual void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
};

class RolerCosterScene : public CScene
{
public:
	int m_UpDown = DEFAULT;
	int m_LeftRight = DEFAULT;

	int m_KorailCount = 0;
	int m_Target = 0;

	float m_RotateSpeed = 0.5f;
	float m_MovingSpeed = 30.0f;

	float m_PlayerTimer = 0.0f;
	float m_KorailTimer = 0.0f;
	float m_RoateTimer[4]{ 0.0f };

	CGameObject * m_KorailMaker;

	enum {
		UP,
		DOWN,
		LEFT,
		RIGHT,
		DEFAULT
	};
public:
	RolerCosterScene();
	virtual ~RolerCosterScene();

	virtual void BuildObjects();

	void OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
	
	virtual void Animate(float fElapsedTime);
	virtual void Render(HDC hDCFrameBuffer, CCamera *pCamera);
};