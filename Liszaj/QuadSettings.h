#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <Thor/Animations/ColorAnimation.hpp>
#include <imgui.h>
/**
 * Singleton który przechowuje najważniejsze informacje dla komórki, które są współdzielone przez nie wszystkie.
 */
class QuadSettings
{
public:
	/**
	 * Zmienna przechowująca wymiary komórki.
	 */
	sf::Vector2f quadDimensions;
	/**
	 * Zmienna przechowująca przeźroczysty obraz.
	 */
	sf::Image transparentImage;
	/**
	 *Zmienna przechowująca przeżroczystą teksturę.
	 */
	sf::Texture transparentTexture;
	/**
	 * Zmienna przechowująca biały obrazek.
	 */
	sf::Image solidImage;
	/**
	 * Zmienna przechowująca białą teksturę.
	 */
	sf::Texture solidTexture;

	/**
	 * Zmienna przechowująca kolor dla zarażonej komórki.
	 */
	sf::Color infectedColor;
	/**
	 * Zmienna przechowująca kolor dla odpornej komórki.
	 */
	sf::Color resistanceColor;
	/**
	 * Zmienna przechowująca kolor dla zdrowej komórki.
	 */
	sf::Color healthyColor;
	/**
	 * Zmienna przechowująca gradient dla zarażonej komórki.
	 */
	thor::ColorGradient infectionGradient;
	/**
	 * Zmienna przechwoująca gradient dla odpornej komórki.
	 */
	thor::ColorGradient resistanceGradient;
	/**
	 * Metoda mająca na celu uzyskanie instancji singletonu.
	 * \return QuadSettings*
	 */
	static QuadSettings* getInstance();
	/**
	 * Metoda mająca na celu aktualizacje koloru odporności oraz gradientów.
	 */
	void updateResistanceTextureColor(ImVec4 resisted);
	/**
	 * Metoda mająca na celu aktualizacje koloru zarażenia oraz gradientów.
	 */
	void updateInfectedTextureColor(ImVec4 infected);
	/**
	 * Metoda mająca na celu aktualizacje koloru zdrowej komórki oraz gradientów.
	 */
	void updateHealthyTextureColor(ImVec4 healthy);
	/**
	 * Metoda mająca na celu aktualizacje wymiarów tekstur i obrazków, czyli aktualizacji wielkosci komórki na planszy.
	 */
	void updateTextures();
private:
	/**
	 * Domyślny konstruktor.
	 */
	QuadSettings();
	/**
	 * Destruktor
	 */
	~QuadSettings();
	/**
	 * Zmienna statyczna która posiada jedyną instancje klasy QuadSettings. Pozyskiwana jest przez funkcję: \ref static QuadSettings* QuadSettings::getInstance();
	 */
	static QuadSettings *s_quad_settings;
};

