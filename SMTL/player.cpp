#include "player.h"

void player::initplayerTexture() //讀取角色圖片
{
	if (!this->playerTexture.loadFromFile("Textures/player.gif")) 
	{ 
		std::cout << "錯誤：角色圖片讀取失敗(Textures/player.gif)" << std::endl;
	}
}

void player::initplayersprite() //設定角色圖片
{
	this->playersprite.setTexture(this->playerTexture); 

	this->playersprite.scale(0.25f, 0.25f); //設定角色圖片比例
	
	this->playersprite.setPosition(150.0f, 550.0f); //設定角色圖片位址
}

player::player() //初始化建構
{
	this->movespeed = 2.0f;
	this->initplayerTexture();
	this->initplayersprite();
}

player::~player() //解構
{
}

const sf::FloatRect player::playergetBounds() const //取得player的全域位置
{
	return this->playersprite.getGlobalBounds();
}

void player::setposition(const sf::Vector2f pos) //設定player的pos位置
{
	this->playersprite.setPosition(pos);
}

void player::setposition(const float x, const float y) //設定player的x,y位置
{
	this->playersprite.setPosition(x, y);
}

void player::move(const float dirX, const float dirY) //player移動
{
	this->playersprite.move(this->movespeed * dirX, this->movespeed * dirY);
}

void player::update()
{

}

void player::render(sf::RenderTarget& target) //player繪圖
{
	target.draw(this->playersprite);
}
