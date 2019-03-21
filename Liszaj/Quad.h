#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <Thor/Time.hpp>
#include <Thor/Animations/ColorAnimation.hpp>
#include <vector>
#include "Utility.h"
#include "SimulationSettings.h"
#include "TileSettings.h"
#include "QuadSettings.h"
#include "ColorAnimationModified.h"

/**
 * Klasa która reprezentuje komórkę i zarządza jej stanami.
 */
class Quad
{
public:
	/**
	 * Domyślny konstruktor.
	 */
	Quad();
	/**
	 * Destruktor
	 */
	~Quad();
	/**
	 * Zmienna typu bool odpowiadająca za poinformowanie czy komórka jest zdrowa.
	 */
	bool healthy;
	/**
	* Zmienna typu bool odpowiadająca za poinformowanie czy komórka jest zainfekowana.
	*/
	bool infected;
	/**
	 * Zmienna typu bool odpowiadająca za poinformowanie czy komórka jest odporna.
	 */
	bool resistant;
	/**
	* Zmienna typu bool odpowiadająca za poinformowanie czy komórka jest stałym punktem infekcji.
	 */
	bool pointOfInfection;
	/**
	 * Metoda która ustawia komórkę w stan zarażenia.
	 */
	void setInfected();
	/**
	 * Metoda aktualizująca stan komórki. Sprawdza czasy poszczególnych etapów i ustawia odpowiedni stan komórki.
	 */
	void updateState();
	/**
	 * Metoda odpowiadająca za ustawienie komórki na planszy.
	 * \param x Wartość typu int opisująca położenie na osi x.
	 * \param y Wartość typu int opisująca położenie na osi y.
	 */
	void setPosition(int x, int y);
	/**
	 * Metoda odpowiadająca za aktualizację wektora pobliskich elementów.
	 * Wektor jest czyszczony z elementów. Następnie jest wywoływana funkcja z klasy Utility o prototypie: \ref  void Utility::generateNearbyElements(std::vector<Quad> *tileQuads, std::vector<Quad*> *nearbyQuads, sf::Vector2u tileSize,  sf::Vector2u position);
	 */
	void updateNearbyElements();
	/**
	 * Zmienna przechowująca czas w którym została zainfekowana.
	 */
	sf::Time hitTime;
	/**
	 * Zmienna opisująca położenie komórki na planszy.
	 */
	sf::Vector2u position;
	/**
	 * Metoda zwracająca wskaźnik do sprite'a komórki.
	 * \return sf::Sprite*
	 */
	sf::Sprite* getSprite();
	/**
	 * Zmienna służąca animacji koloru komórki.
	 */
	thor::ColorAnimationModified p_animation;
private:
	/**
	 * Zmienna przechwoująca sprite komórki.
	 */
	sf::Sprite sprite;
	/**
	 * Metoda która ustawia komórkę w zdrowy stan. 
	 */
	void setHealthy();
	/**
	 * Metoda która ustawia komórkę w stan odporności.
	 */
	void setResistance();
	/**
	 * Zmienna typu bool mająca na celu informowania czy sąsiednie komórki zostały zarażone.
	 */
	bool m_nearbyInfected;
	/**
	 * Wektor psoiadający wskaźniki do sąsiednich elementów.
	 */
	std::vector<Quad*> m_nearbyQuads;
	/**
	* Zmienna typu sf::Sprite posiadająca Sprite komórki.
	*/
	sf::Sprite m_sprite;
};

