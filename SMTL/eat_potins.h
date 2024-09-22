#ifndef _Potins_Eat
#define _Potins_Eat

#include "SFML/Graphics.hpp"

class eat_potins
{
private:
	sf::Sprite Potinssprite;
	sf::Texture PotinsTexture;

	float speed;
	int type;
	float points;

	void initPotinsTexture();
	void initPotinssprite();
	void initVariables();
public:
	eat_potins(float pos_x, float pos_y);
	virtual ~eat_potins();

	const sf::FloatRect eat_potinsBounds() const;
	const int& getpoints() const;

	void update();
	void render(sf::RenderTarget* target);
};
#endif
