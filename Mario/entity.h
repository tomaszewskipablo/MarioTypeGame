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
	const float Width{ 32.0f };
	const float Height{ 64.0f };
	const float Velocity{ 0.7f };

	Vector2f startingPosition;
	Vector2f velocity{ Velocity, Velocity };

	bool canJump = false;

	void draw(RenderTarget& target, RenderStates state) const override; // to use window.draw(Ball)
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

	void setCanJump(bool canJump) { this->canJump = canJump; }
};

