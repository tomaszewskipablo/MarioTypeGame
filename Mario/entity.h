#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512
using namespace sf;
class Entity : public Drawable // Drawable makes possible to use window.draw(Ball)
{
protected:

	Texture texture;
	Sprite sprite;
	float Width;
	float Height;
	float Velocity;

	Vector2f startingPosition;
	Vector2f velocity{ Velocity, Velocity };

	void draw(RenderTarget& target, RenderStates state) const override; // to use window.draw(Ball)

	bool distroyMode = 0;
public:
	Entity() {};

	~Entity() = default;

	Vector2f getPosition();


	void update();

	float left();
	float right();
	float top();
	float bottom();

	void moveLeft();
	void moveRight();
	void moveTop();
	void moveBottom();

	bool isAlive = true;

	void MovingDirectiongLeft() { velocity.x = -Velocity; }
	void MovingDirectiongRight() { velocity.x = Velocity; }

	Sprite getSprite() { return sprite; }

	void dead() { isAlive = false; }
	bool getIsAlive() { return isAlive; }
	bool getDestroyMode() { return distroyMode; }
	void reset();
};


