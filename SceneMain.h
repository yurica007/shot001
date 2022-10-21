#pragma once

#include "player.h"
#include "enemy.h"
#include "shot.h"
#include <vector>

class SceneMain
{
public:
	SceneMain();
	virtual ~SceneMain();

	// ������
	void init();
	// �I������
	void end();

	// ���t���[���̏���
	void update();
	// ���t���[���̕`��
	void draw();
	
	// �V���b�g������
	bool createShot(Vec2 pos, bool isPlayer);
//	bool createPlayerShot(Vec2 pos);
//	bool createEnemyShot(Vec2 pos);

private:
	// �V���b�g�̍ő吔
	static constexpr int kShotMax = 64;

private:

	// �v���C���[�̃O���t�B�b�N�n���h��
	int m_hPlayerGraphic;
	int m_hShotGraphic;
	// �v���C���[
	Player m_player;
	// �G
	Enemy m_enemy;
	// �V���b�g
	std::vector<Shot> m_shot;
};