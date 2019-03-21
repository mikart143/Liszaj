#pragma once
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "TileSettings.h"
#include "QuadSettings.h"
#include <SFML/Graphics/RenderTarget.hpp>


/**
 * 		Klasa służąca zarządzaniu całą siatką kwadratów.
 *
 */
class Tile : public sf::Drawable, public sf::Transformable
{
public:
	/**
	 *	Domyślny konstruktor
	 */
	Tile();
	/**
	 *	Metoda służąca inicjacji zmiennych oraz domyślnej siatki.
	 */
	void init();
	/**
	 *	Metoda służąca infekowaniu komórki
	 *	
	 *	 \param mousePosition Aktualna pozycja kursora na planszy.
	 */
	void infect(sf::Vector2f mousePosition);
	/**
	 *		Metoda służąca usuwaniu komórek z siatki. Usuwana jest ostatnia kolumna i wiersz.
	 */
	void remove();
	/**
	 *	Metoda służąca dodawaniu komórek do siatki. Dodawana jest kolumna i wiersz na samych końcach.
	 */
	void add();
	/**
	 *	Destruktor
	 */
	~Tile();
private:
	/**
	 *	Metoda służąca aktualizacji pozycji komórek na planszy oraz ich rozmiaru.
	 */
	void updatePositions();
	/**
	 *	Metoda, która została nadpisana z sf::Drawable
	 *	
	 *	\param target  RenderTarget do którego będzie rysowane
	 *	\param states Aktualny stan rysowania
	 */
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const 
	{
		states.transform *= getTransform();

		for (auto &element : TileSettings::getInstance()->tileQuads) {
			if(!SimulationSettings::getInstance()->stopLogic && !element.healthy)
			{
				element.updateState();
			}
			target.draw(*element.getSprite(), states);
		}

	}
};

