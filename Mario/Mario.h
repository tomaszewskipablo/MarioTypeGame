#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#define WINDOW_WIDTH 1024
#define WINDOW_HIGHT 512

using namespace sf;
class Mario : public Drawable // Drawable makes possible to use window.draw(Ball)
{
private:

	Texture texture;
	Sprite sprite;
	const float MarioWidth{ 80.0f };
	const float MarioHeight{ 20.0f };
	const float MarioVelocity{ 2.0f };
	Vector2f velocity{ MarioVelocity, 0.f };
	void draw(RenderTarget& target, RenderStates state) const override; // to use window.draw(Ball)
public:
	Mario(float t_X, float t_Y);
	Mario() = delete;;
	~Mario() = default;

	Vector2f getPosition();


	void update();

	float left();
	float right();
	float top();
	float bottom();
};

