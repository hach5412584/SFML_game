#include "Enemy.h"
#include <iostream>
void Enemy::initEnemyTexture() //讀取敵人圖片
{
	if (!this->EnemyTexture.loadFromFile("Textures/enemy.png"))
	{
		std::cout << "錯誤：角色圖片讀取失敗(Textures/enemy.png)" << std::endl;
	}
}

void Enemy::initEnemysprite() //設定敵人圖片
{
	this->Enemysprite.setTexture(this->EnemyTexture);

	this->Enemysprite.scale(1.0f, 1.0f); //設定敵人圖片比例
}

void Enemy::initVariables() //參數初始化
{
	this->type = 0;
	this->speed = 2.0f*((rand()%2)+1);
}

Enemy::Enemy(float pos_x, float pos_y) //參數化建構
{	
	this->initEnemyTexture();
	this->initEnemysprite();
	this->initVariables();

	this->Enemysprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy() //解構
{

}

const sf::FloatRect Enemy::EnemygetBounds() const //取得Enemy的全域位置
{
	return this->Enemysprite.getGlobalBounds();
}

void Enemy::update() //讓敵人移動
{
	this->Enemysprite.move(0.0f, this->speed);
}

void Enemy::render(sf::RenderTarget * target) //Enemy繪圖
{
	target->draw(this->Enemysprite);
}
