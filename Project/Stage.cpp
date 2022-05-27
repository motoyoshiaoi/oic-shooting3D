#include "Stage.h"

/**
 * �R���X�g���N�^
 *
 */
CStage::CStage() :
	m_BG(),
	m_Scroll(0.0f),
	m_pEnemyStart(NULL),
	m_EnemyMesh(),
	m_EnemyNo(0){
}

/**
 * �f�X�g���N�^
 *
 */
CStage::~CStage() {
}

/**
 * �ǂݍ���
 * 
 */
bool CStage::Load() {
	//�w�i�e�N�X�`���̓ǂݍ���
	if (!m_BG.CreateSprite("road.png"))
	{
		return false;
	}
	//�X�e�[�W���œo�ꂷ��G�̃��b�V����ǂݍ���
	if (!m_EnemyMesh.Load("enemy.mom"))
	{
		return false;
	}
	return true;
}

/**
 * ������
 *
 * ����
 * [in]					pSt					�G�̊J�n���z��
 */
void CStage::Initialize(ENEMYSTART *pSt) {
	m_BG.m_Angle.x = MOF_MATH_HALFPI;
	m_BG.m_Angle.y = MOF_MATH_HALFPI;
	m_BG.m_Scale = Vector3(200, 200, 200);
	m_BG.m_Position.y = -15;
	m_BG.SetImageRect(0, 0, m_BG.GetTexture()->GetWidth() * 4, m_BG.GetTexture()->GetHeight() * 4);
	m_Scroll = 0;
	m_EnemyNo = 0;
	m_pEnemyStart = pSt;
}

/**
 * �X�V
 *
 * ����
 * [in]					ene						�G�̔z��
 * [in]					ecnt					�G�̔z��̐�
 */
void CStage::Update(CEnemy* ene,int ecnt) {
	m_Scroll += SCROLL_SPEED;

	if (m_EnemyNo < m_pEnemyStart->Count && m_Scroll >= m_pEnemyStart->Scroll[m_EnemyNo])
	{
		for (int i = 0; i < ecnt; i++)
		{
			if (ene[i].GetShow())
			{
				continue;
			}
			ene[i].SetMesh(&m_EnemyMesh);
			ene[i].Start(Vector3(m_pEnemyStart->PosX[m_EnemyNo], 0, 0));
			break;
		}
		m_EnemyNo++;
	}
	if (m_Scroll > 1100)
	{
		m_Scroll = 0;
		m_EnemyNo = 0;
	}
}

/**
 * �`��
 *
 */
void CStage::Render() {
	for (int i = 0; i < 2; i++)
	{
		m_BG.m_Position.z = 50.0f + fmodf(-m_Scroll, m_BG.m_Scale.z) + i * m_BG.m_Scale.z;
		m_BG.Update();
		m_BG.Render();
	}
}

/**
 * �f�o�b�O�����`��
 *
 */
void CStage::RenderDebugText() {
	//�X�N���[���l�̕`��
	CGraphicsUtilities::RenderString(10, 10, MOF_XRGB(0, 0, 0), "�X�N���[��:%.0f", m_Scroll);
}

/**
 * ���
 *
 */
void CStage::Release() {
	m_BG.Release();
	m_EnemyMesh.Release();
}
