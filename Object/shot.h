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

	// ���݂��邩
	bool isExist() const { return m_isExist; }
	void setExist(bool isExist) { m_isExist = isExist; }

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
};