#include "DxLib.h"
#include "SceneMain.h"

SceneMain::SceneMain() :
	m_hPlayerGraphic(-1),
	m_hShotGraphic(-1),
	m_player(),
	m_enemy(),
	m_shot()
{
	m_shot.resize(kShotMax);
}
SceneMain::~SceneMain()
{

}

// ������
void SceneMain::init()
{
	m_hPlayerGraphic = LoadGraph("data/player.bmp");
	m_hShotGraphic = LoadGraph("data/shot.bmp");

	m_player.setMain(this);
	m_player.setHandle(m_hPlayerGraphic);
	m_player.init();

	m_enemy.setMain(this);
	m_enemy.setHandle(m_hPlayerGraphic);
	m_enemy.init();

	for (auto& shot : m_shot)
	{
		shot.setHandle(m_hShotGraphic);
	}
}

// �I������
void SceneMain::end()
{
	DeleteGraph(m_hPlayerGraphic);
	DeleteGraph(m_hShotGraphic);
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
	m_enemy.update();
	
	for (auto& shot : m_shot)
	{
		shot.update();
		if (shot.isCol(m_enemy))
		{
			// �������Ă���ꍇ�̏���
			m_enemy.setExist(false);
		}
	}
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
	m_enemy.draw();

	for (auto& shot : m_shot)
	{
		shot.draw();
	}
}

bool SceneMain::createShot(Vec2 pos, bool isPlayer)
{
	for (auto& shot : m_shot)
	{
		if (!shot.isExist())
		{
			shot.start(pos);
			Vec2 vec{ 8.0f,0.0f };

			if (!isPlayer) vec.x *= -1.0f;
			shot.setVec(vec);
			shot.setPlayerShot(isPlayer);

			return true;
		}
	}
	return false;
}