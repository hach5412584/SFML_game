#include "eat_potins.h"
#include <iostream>
void eat_potins::initPotinsTexture() //讀取角色圖片
{
	if (!this->PotinsTexture.loadFromFile("Textures/potins.png"))
	{
		std::cout << "錯誤：角色圖片讀取失敗(Textures/potins.png)" << std::endl;
	}
}

void eat_potins::initPotinssprite() //設定角色圖片
{
	this->Potinssprite.setTexture(this->PotinsTexture); 
	this->Potinssprite.scale(0.3f, 0.3f); //設定角色圖片比例
}

void eat_potins::initVariables() //參數初始化
{
	this->type = 2;
	this->speed = 2.0f*((rand() % 2) + 1);
	this->points = this->speed;
}

eat_potins::eat_potins(float pos_x, float pos_y) //初始化建構
{
	this->initPotinsTexture();
	this->initPotinssprite();
	this->initVariables();
	this->Potinssprite.setPosition(pos_x, pos_y);
}

eat_potins::~eat_potins() //解構
{
}

const sf::FloatRect eat_potins::eat_potinsBounds() const //取得eat_potins的全域位置
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
