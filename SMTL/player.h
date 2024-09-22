#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/window.hpp"
#include "SFML/system.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class player
{
private:
	sf::Sprite playersprite;
	sf::Texture playerTexture;

	float movespeed;
	void initplayerTexture();
	void initplayersprite();
public:
	player();
	virtual ~player()	;

	const sf::FloatRect playergetBounds() const;

	void setposition(const sf::Vector2f pos);
	void setposition(const float x , const float y);

	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);
};

