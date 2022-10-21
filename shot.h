#pragma once
#include "Vec2.h"

class Shot
{
public:
	Shot();
	virtual ~Shot();

	void setHandle(int handle) { m_handle = handle; }

	// �X�V
	void update();
	// �\��
	void draw();

private:
	// �O���t�B�b�N�n���h��
	int m_handle;
	// �\���ʒu
	Vec2	m_pos;
	// �ړ�
	Vec2	m_vec;
};