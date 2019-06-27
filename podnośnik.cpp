#include "Podnośnik.h"

using namespace std;
using namespace sf;

Podnośnik::Podnośnik(float t_X, float t_Y)
{
	paleta.setPosition(t_X, t_Y);
	paleta.setSize ({ this->szerokość_palety,this->długość_palety });
	paleta.setFillColor(Color::Yellow);
	paleta.setOrigin(t_X / 2.f, t_Y / 2.f);

}

void Podnośnik::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->paleta, state);
}

void Podnośnik::update()
{
    this->paleta.move(this->velocity);
	

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->lewo() > 570)
	{
		velocity.x = -szybkość_palety;
	}

	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->prawo() < 950)

	{
		velocity.x = szybkość_palety;
	}

	else { velocity.x = 0; }

	if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->dół() < 460)
	{
		długość_palety += 2.f;
		if (długość_palety > 440.f) { długość_palety = 440.f; }

		paleta.setSize({ this->szerokość_palety,this->długość_palety });
	}

    if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->góra() > 50)
	{
		długość_palety -= 2.f;
		if (długość_palety < 20.f) { długość_palety = 20.f; }
		paleta.setSize({ this->szerokość_palety,this->długość_palety });
	}
}

float Podnośnik::lewo()

{
	return this->paleta.getPosition().x - paleta.getSize().x / 2.f;
}

float Podnośnik::prawo()
{
	return this->paleta.getPosition().x + paleta.getSize().x / 2.f;
}

float Podnośnik::góra()
{
	return this->paleta.getPosition().y ;
}

float Podnośnik::dół()
{
	return this->paleta.getPosition().y ;
}

