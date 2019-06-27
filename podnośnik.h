#pragma once

#include <SFML/Graphics.hpp>


using namespace std;
using namespace sf;

class Podnośnik : public sf :: Drawable 
{
public:
	Podnośnik(float t_X, float t_Y);
	Podnośnik() = delete;
	~Podnośnik() = default;

	void update();

	float lewo();
	float prawo();
	float góra();
	float dół();

private:

	void draw(RenderTarget& target, RenderStates state) const override;
	RectangleShape paleta;
	const float szerokość_palety { 10.0f }; 
	const float długość_palety { 20.0f };
	const float szybkość_palety { 4.0f };
	Vector2f velocity { szybkość_palety, 0.f };
	

};

