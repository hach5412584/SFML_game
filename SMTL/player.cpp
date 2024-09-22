#include "player.h"

void player::initplayerTexture() //Ū������Ϥ�
{
	if (!this->playerTexture.loadFromFile("Textures/player.gif")) 
	{ 
		std::cout << "���~�G����Ϥ�Ū������(Textures/player.gif)" << std::endl;
	}
}

void player::initplayersprite() //�]�w����Ϥ�
{
	this->playersprite.setTexture(this->playerTexture); 

	this->playersprite.scale(0.25f, 0.25f); //�]�w����Ϥ����
	
	this->playersprite.setPosition(150.0f, 550.0f); //�]�w����Ϥ���}
}

player::player() //��l�ƫغc
{
	this->movespeed = 2.0f;
	this->initplayerTexture();
	this->initplayersprite();
}

player::~player() //�Ѻc
{
}

const sf::FloatRect player::playergetBounds() const //���oplayer�������m
{
	return this->playersprite.getGlobalBounds();
}

void player::setposition(const sf::Vector2f pos) //�]�wplayer��pos��m
{
	this->playersprite.setPosition(pos);
}

void player::setposition(const float x, const float y) //�]�wplayer��x,y��m
{
	this->playersprite.setPosition(x, y);
}

void player::move(const float dirX, const float dirY) //player����
{
	this->playersprite.move(this->movespeed * dirX, this->movespeed * dirY);
}

void player::update()
{

}

void player::render(sf::RenderTarget& target) //playerø��
{
	target.draw(this->playersprite);
}
