#include "DxLib.h"
#include "game.h"
#include "enemy.h"

namespace
{
}

Enemy::Enemy()
{
	m_handle = -1;
}

Enemy::~Enemy()
{
	
}

void Enemy::init()
{
	m_pos.x = Game::kScreenWidth - 80.0f;
	m_pos.y = Game::kScreenHeight / 2;
	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

void Enemy::update()
{
	m_pos += m_vec;
}

void Enemy::draw()
{
	DrawTurnGraphF(m_pos.x, m_pos.y, m_handle, true);
}

float Enemy::getColWidth()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempX;
}

float Enemy::getColHieght()
{
	float tempX = 0;
	float tempY = 0;
	GetGraphSizeF(m_handle, &tempX, &tempY);
	return tempY;
}