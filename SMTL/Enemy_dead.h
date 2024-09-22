#ifndef _ENEMY_HD
#define _ENEMY_HD

#include "SFML/Graphics.hpp"

class Enemy_dead
{
private:
	sf::Sprite enemydeadsprite;
	sf::Texture enemydeadTexture;

	float speed;
	int type;

	void initenemydeadTexture();
	void initenemydeadsprite();
	void initVariables();
public:
	Enemy_dead(float pos_x, float pos_y);
	virtual ~Enemy_dead();

	const sf::FloatRect Enemy_deadBounds() const;

	void update();
	void render(sf::RenderTarget* target);
};

#endif