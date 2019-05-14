#include "stdafx.h"
#include "Scene.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
CScene::CScene()
{
}

CScene::~CScene()
{
}

void CScene::OnProcessingMouseMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}

void CScene::BuildObjects()
{
}

void CScene::ReleaseObjects()
{
}

void CScene::CheckObjectByObjectCollisions()
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->m_pObjectCollided = NULL;
	for (int i = 0; i < m_nObjects; i++)
	{
		for (int j = (i + 1); j < m_nObjects; j++)
		{
			if (m_ppObjects[i]->m_xmOOBB.Intersects(m_ppObjects[j]->m_xmOOBB))
			{
				m_ppObjects[i]->m_pObjectCollided = m_ppObjects[j];
				m_ppObjects[j]->m_pObjectCollided = m_ppObjects[i];
			}
		}
	}
	for (int i = 0; i < m_nObjects; i++)
	{
		if (m_ppObjects[i]->m_pObjectCollided)
		{
			XMFLOAT3 xmf3MovingDirection = m_ppObjects[i]->m_xmf3MovingDirection;
			float fMovingSpeed = m_ppObjects[i]->m_fMovingSpeed;
			m_ppObjects[i]->m_xmf3MovingDirection = m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection;
			m_ppObjects[i]->m_fMovingSpeed = m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_xmf3MovingDirection = xmf3MovingDirection;
			m_ppObjects[i]->m_pObjectCollided->m_fMovingSpeed = fMovingSpeed;
			m_ppObjects[i]->m_pObjectCollided->m_pObjectCollided = NULL;
			m_ppObjects[i]->m_pObjectCollided = NULL;
		}
	}
}

void CScene::Animate(float fElapsedTime)
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Animate(fElapsedTime);

	CheckObjectByObjectCollisions();
}

void CScene::Render(HDC hDCFrameBuffer, CCamera *pCamera)
{
	for (int i = 0; i < m_nObjects; i++) m_ppObjects[i]->Render(hDCFrameBuffer, pCamera);
}

RolerCosterScene::RolerCosterScene()
{
}

RolerCosterScene::~RolerCosterScene()
{
}

void RolerCosterScene::BuildObjects()
{
	m_nObjects = 100;
	m_ppObjects = new CGameObject*[m_nObjects];

	Korail *pObjectKorailMesh = new Korail(3.0f, 2.0f);

	m_KorailMaker = new CGameObject;
	m_KorailMaker->SetMesh(new CCubeMesh(4.0f, 4.0f, 2.0f));
	m_KorailMaker->SetMovingSpeed(m_MovingSpeed);
	m_KorailMaker->SetPosition(0, 0, 30.0f);
	m_KorailMaker->SetColor(RGB(0, 0, 255));
	
	
	for (int i = 0; i < m_nObjects; i++)
	{
		m_ppObjects[i] = new CGameObject();
		m_ppObjects[i]->SetMesh(pObjectKorailMesh);
		m_ppObjects[i]->SetColor(RGB(0, 0, 0));
		m_ppObjects[i]->SetPosition(0, 0, 30.0f);
	}
}

void RolerCosterScene::OnProcessingKeyboardMessage(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	switch (nMessageID)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'W':
			m_UpDown = UP;
			break;
		case 'A':
			m_LeftRight = LEFT;
			break;
		case 'S':
			m_UpDown = DOWN;
			break;
		case 'D':
			m_LeftRight = RIGHT;
			break;
		case 'R':
			m_UpDown = DEFAULT;
			m_LeftRight = DEFAULT;
			m_RotateSpeed = 0.5f;
			m_MovingSpeed = 30.0f;
			break;
		case 'O':
			m_RotateSpeed = (m_RotateSpeed - 0.1f) > 0.1f ? (m_RotateSpeed - 0.1f) : m_RotateSpeed;
			break;
		case 'P':
			m_RotateSpeed = 5.0f > (m_RotateSpeed + 0.1f) ? (m_RotateSpeed + 0.1f) : m_RotateSpeed;
			break;
		case 'K':
			m_MovingSpeed = (m_MovingSpeed - 1.0f) > 0.1f ? (m_MovingSpeed - 1.0f) : m_MovingSpeed;
			break;
		case 'L':
			m_MovingSpeed = 100.0f > (m_MovingSpeed + 1.0f) ? (m_MovingSpeed + 1.0f) : m_MovingSpeed;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void RolerCosterScene::Animate(float fElapsedTime)
{
	m_KorailTimer += fElapsedTime;
	m_PlayerTimer += fElapsedTime;

	if (m_KorailTimer >= (1.0f / 60.0f))
	{
		m_KorailTimer = 0.0f;
		if (m_KorailCount >= m_nObjects)
			m_KorailCount = 0;
		m_ppObjects[m_KorailCount]->SetColor(RGB(0, 0, 0));
		m_ppObjects[m_KorailCount++]->m_xmf4x4World = m_KorailMaker->m_xmf4x4World;
	}

	
	if (m_PlayerTimer >= (1.0f / 60.0f))
	{
		m_PlayerTimer = 0.0f;
		if (m_Target >= m_nObjects)
			m_Target = 0;
			if (m_KorailCount - 30 >= m_Target)
			{
				m_pPlayer->m_xmf3Up = m_ppObjects[m_Target]->GetUp();
				m_pPlayer->m_xmf3Right = m_ppObjects[m_Target]->GetRight();
				m_pPlayer->m_xmf3Look = m_ppObjects[m_Target]->GetLook();
				
				m_ppObjects[m_Target]->SetColor(RGB(255, 0, 0));

				m_pPlayer->m_xmf3Position = m_ppObjects[m_Target]->GetPosition();
				m_Target++;
			}
			else if (m_Target > m_KorailCount)
			{
				m_ppObjects[m_Target]->SetColor(RGB(255, 0, 0));

				m_pPlayer->m_xmf3Position = m_ppObjects[m_Target++]->GetPosition();
			}
	}
	
	switch (m_UpDown)
	{
	case UP:
		if (1.0f > m_RoateTimer[UP])
		{
			m_RoateTimer[UP] += fElapsedTime;
			m_KorailMaker->Rotate(-m_RotateSpeed, 0, 0);
			m_KorailMaker->SetMovingDirection(m_KorailMaker->GetLook());
		}
		else
		{
			m_RoateTimer[UP] = 0;
			m_UpDown = DEFAULT;
		}
		break;
	case DOWN:
		if (1.0f > m_RoateTimer[DOWN])
		{
			m_RoateTimer[DOWN] += fElapsedTime;
			m_KorailMaker->Rotate(m_RotateSpeed, 0, 0);
			m_KorailMaker->SetMovingDirection(m_KorailMaker->GetLook());
		}
		else
		{
			m_RoateTimer[DOWN] = 0;
			m_UpDown = DEFAULT;
		}
		break;
	}

	switch (m_LeftRight)
	{
	case LEFT:
		if (1.0f > m_RoateTimer[LEFT])
		{
			m_RoateTimer[LEFT] += fElapsedTime;
			m_KorailMaker->Rotate(0, -m_RotateSpeed, 0);
			m_KorailMaker->SetMovingDirection(m_KorailMaker->GetLook());
		}
		else
		{
			m_RoateTimer[LEFT] = 0;
			m_LeftRight = DEFAULT;
		}
		break;
	case RIGHT:
		if (1.0f > m_RoateTimer[RIGHT])
		{
			m_RoateTimer[RIGHT] += fElapsedTime;
			m_KorailMaker->Rotate(0, m_RotateSpeed, 0);
			m_KorailMaker->SetMovingDirection(m_KorailMaker->GetLook());
		}
		else
		{
			m_RoateTimer[RIGHT] = 0;
			m_LeftRight = DEFAULT;
		}
		break;
	}

	m_KorailMaker->SetMovingSpeed(m_MovingSpeed);

	m_KorailMaker->Animate(fElapsedTime);

	CScene::Animate(fElapsedTime);
}

void RolerCosterScene::Render(HDC hDCFrameBuffer, CCamera * pCamera)
{
	m_KorailMaker->Render(hDCFrameBuffer, pCamera);
	
	CScene::Render(hDCFrameBuffer, pCamera);
}
