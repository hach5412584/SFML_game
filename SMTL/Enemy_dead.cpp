#include "Enemy_dead.h"
#include <iostream>
void Enemy_dead::initenemydeadTexture()
{
	if (!this->enemydeadTexture.loadFromFile("Textures/dead.png")) //載入圖片
	{
		std::cout << "錯誤：角色圖片讀取失敗(Textures/dead.png)" << std::endl;
	}
}

void Enemy_dead::initenemydeadsprite()
{
	this->enemydeadsprite.setTexture(this->enemydeadTexture); //設定sprite圖片

	this->enemydeadsprite.scale(0.3f, 0.3f); //設定圖片比例
}

void Enemy_dead::initVariables() //參數初始化
{
	this->type = 1;
	this->speed = 1.5f*((rand() % 2) + 1);
}

Enemy_dead::Enemy_dead(float pos_x, float pos_y) //參數化建構
{
	this->initenemydeadTexture();
	this->initenemydeadsprite();
	this->initVariables();

	this->enemydeadsprite.setPosition(pos_x, pos_y);
}

Enemy_dead::~Enemy_dead() //解構
{
}

const sf::FloatRect Enemy_dead::Enemy_deadBounds() const  //取得小心地滑的全域體積位置
{
	return this->enemydeadsprite.getGlobalBounds();
}

void Enemy_dead::update() //設定移動速度
{
	this->enemydeadsprite.move(0.0f, this->speed);
}

void Enemy_dead::render(sf::RenderTarget * target) //在視窗繪圖
{
	target->draw(this->enemydeadsprite);
}
