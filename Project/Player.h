#pragma once

#include "GameDefine.h"
#include "PlayerShot.h"

// �ړ����x
#define PLAYER_SPEED		(0.1f)

//���̔��ˌ��E��
#define PLAYERSHOT_COUNT	(40)

//�e�̔��ˊԊu
#define PLAYERSHOT_WAIT		(5)



class CPlayer{
private:
	CMeshContainer	m_Mesh;
	CVector3		m_Pos;
	float			m_RotZ;
	CMeshContainer	m_ShotMesh;
	CPlayerShot		m_ShotArray[PLAYERSHOT_COUNT];
	int				m_ShotWait;

	PlayerShotMode m_ShotMode;
public:
	CPlayer();
	~CPlayer();
	bool Load();
	void Initialize();
	void Update();
	void Render();
	void RenderDebugText();
	const CVector3 GetPosition(){ return m_Pos; }
	void Release();

	void UpdateMode();
	void UpdateSingleShot();
	void UpdateDoubleShot();
	void UpdateTrippleShot();
};