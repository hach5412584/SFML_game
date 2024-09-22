#include "Enemy.h"
#include <iostream>
void Enemy::initEnemyTexture() //Ū���ĤH�Ϥ�
{
	if (!this->EnemyTexture.loadFromFile("Textures/enemy.png"))
	{
		std::cout << "���~�G����Ϥ�Ū������(Textures/enemy.png)" << std::endl;
	}
}

void Enemy::initEnemysprite() //�]�w�ĤH�Ϥ�
{
	this->Enemysprite.setTexture(this->EnemyTexture);

	this->Enemysprite.scale(1.0f, 1.0f); //�]�w�ĤH�Ϥ����
}

void Enemy::initVariables() //�Ѽƪ�l��
{
	this->type = 0;
	this->speed = 2.0f*((rand()%2)+1);
}

Enemy::Enemy(float pos_x, float pos_y) //�ѼƤƫغc
{	
	this->initEnemyTexture();
	this->initEnemysprite();
	this->initVariables();

	this->Enemysprite.setPosition(pos_x, pos_y);
}

Enemy::~Enemy() //�Ѻc
{

}

const sf::FloatRect Enemy::EnemygetBounds() const //���oEnemy�������m
{
	return this->Enemysprite.getGlobalBounds();
}

void Enemy::update() //���ĤH����
{
	this->Enemysprite.move(0.0f, this->speed);
}

void Enemy::render(sf::RenderTarget * target) //Enemyø��
{
	target->draw(this->Enemysprite);
}
