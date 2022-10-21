#pragma once
#include "Vec2.h"

class Enemy;

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void setHandle(int handle) { m_handle = handle; }

	// ����
	void start(Vec2 pos);

	// �X�V
	void update();
	// �\��
	void draw();

	// �e�̐i�s��������
	void setVec(Vec2 vec) { m_vec = vec; }

	// ���݂��邩
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

	// �v���C���[���������e���ǂ���
	bool isPlayerShot() const { return m_isPlayerShot; }
	void setPlayerShot(bool isPlayerShot) { m_isPlayerShot = isPlayerShot; }


	// �G�Ƃ̓����蔻��
	bool isCol(Enemy& enemy);

private:
	// �O���t�B�b�N�n���h��
	int m_handle;
	// ���݃O���t
	bool m_isExist;

	// �\���ʒu
	Vec2	m_pos;
	// �ړ�
	Vec2	m_vec;
	// �v���C���[���������e���ǂ���
	bool m_isPlayerShot;
};