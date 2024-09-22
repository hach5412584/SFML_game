#include "Enemy_dead.h"
#include <iostream>
void Enemy_dead::initenemydeadTexture()
{
	if (!this->enemydeadTexture.loadFromFile("Textures/dead.png")) //���J�Ϥ�
	{
		std::cout << "���~�G����Ϥ�Ū������(Textures/dead.png)" << std::endl;
	}
}

void Enemy_dead::initenemydeadsprite()
{
	this->enemydeadsprite.setTexture(this->enemydeadTexture); //�]�wsprite�Ϥ�

	this->enemydeadsprite.scale(0.3f, 0.3f); //�]�w�Ϥ����
}

void Enemy_dead::initVariables() //�Ѽƪ�l��
{
	this->type = 1;
	this->speed = 1.5f*((rand() % 2) + 1);
}

Enemy_dead::Enemy_dead(float pos_x, float pos_y) //�ѼƤƫغc
{
	this->initenemydeadTexture();
	this->initenemydeadsprite();
	this->initVariables();

	this->enemydeadsprite.setPosition(pos_x, pos_y);
}

Enemy_dead::~Enemy_dead() //�Ѻc
{
}

const sf::FloatRect Enemy_dead::Enemy_deadBounds() const  //���o�p�ߦa�ƪ�������n��m
{
	return this->enemydeadsprite.getGlobalBounds();
}

void Enemy_dead::update() //�]�w���ʳt��
{
	this->enemydeadsprite.move(0.0f, this->speed);
}

void Enemy_dead::render(sf::RenderTarget * target) //�b����ø��
{
	target->draw(this->enemydeadsprite);
}
