#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
using namespace sf;

class Entity : public Drawable
{
	sf::Texture texture;
	sf::Sprite sprite;
	std::string textureSource;
	
	const int Width{ 64};
	const int Height{ 64 };
	

	//void draw(RenderTarget& target, RenderStates state) const override; // to use window.draw(Entity)
public:
	Entity();
	~Entity();

	void loadTexture();
	void setPosition();

	Vector2f getPosition();


	void update();

	float left();
	float right();
	float top();
	float bottom();

};

