#ifndef ENEMY_H
#define ENEMY_H

#include "SFML/Graphics.hpp"

class Enemy
{
private:
	sf::Sprite Enemysprite;
	sf::Texture EnemyTexture;
	float speed;
	int type;

	void initEnemyTexture();
	void initEnemysprite();
	void initVariables();
public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	const sf::FloatRect EnemygetBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

#endif

