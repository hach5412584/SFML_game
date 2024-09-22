#include "eat_potins.h"
#include <iostream>
void eat_potins::initPotinsTexture() //Ū������Ϥ�
{
	if (!this->PotinsTexture.loadFromFile("Textures/potins.png"))
	{
		std::cout << "���~�G����Ϥ�Ū������(Textures/potins.png)" << std::endl;
	}
}

void eat_potins::initPotinssprite() //�]�w����Ϥ�
{
	this->Potinssprite.setTexture(this->PotinsTexture); 
	this->Potinssprite.scale(0.3f, 0.3f); //�]�w����Ϥ����
}

void eat_potins::initVariables() //�Ѽƪ�l��
{
	this->type = 2;
	this->speed = 2.0f*((rand() % 2) + 1);
	this->points = this->speed;
}

eat_potins::eat_potins(float pos_x, float pos_y) //��l�ƫغc
{
	this->initPotinsTexture();
	this->initPotinssprite();
	this->initVariables();
	this->Potinssprite.setPosition(pos_x, pos_y);
}

eat_potins::~eat_potins() //�Ѻc
{
}

const sf::FloatRect eat_potins::eat_potinsBounds() const //���oeat_potins�������m
{
	return this->Potinssprite.getGlobalBounds();
}

const int & eat_potins::getpoints() const
{
	return this->points;
}

void eat_potins::update()
{
	this->Potinssprite.move(0.0f, this->speed);
}

void eat_potins::render(sf::RenderTarget * target)
{
	target->draw(this->Potinssprite);
}
