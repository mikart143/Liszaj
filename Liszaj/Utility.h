#pragma once
#include<iostream>
#include "Quad.h"
class Quad;


/**
 * Klasa posiadająca podręczne metody dla symulacji.
 */
class Utility
{
public:
	/**
	 * Domyślny konstruktor.
	 */
	Utility();
	/**
	 * Destruktor.
	 */
	~Utility();
	/**
	 * Funkcja zwracająca bool. Jako parametr jest podawane prawdopodobieństwo wystąpienia prawdy.
	 * \param probability Prawdopodobieństwo wystąpienia prawdy.
	 * \return bool
	 */
	bool yesOrNo(float probability);
	/**
	 * Funkcja służąca generowaniu sąsiednich elementów komórki.
	 * \param *tileQuads wskaźnik do wektora komórek.
	 * \param *nearbyQuads wskaźnik do wektora  wskaźników sąsiednich komórek.
	 * \param tileSize Rozmiar siatki komórek.
	 * \param position Pozycja komórki na siatce.
	 */
	void generateNearbyElements(std::vector<Quad> *tileQuads, std::vector<Quad*> *nearbyQuads, sf::Vector2u tileSize,  sf::Vector2u position);
	/**
	 * Metoda zwracająca bool. Sprawdza czy kliknięcie zostało zarejestrowane np. w oknie Panelu Sterowania.
	 * \param windowSize Rozmiar okna 
	 * \param windowPosition Pozycja okna na ekranie.
	 * \param mousePosition Pozycja kursora na ekranie.
	 * \return bool
	 */
	bool clickedInWindow(sf::Vector2f windowSize, sf::Vector2f windowPosition, sf::Vector2u mousePosition);
	/**
	 * Metoda oblicza wszystkie wspólne dzielniki szerokości i długośći głównego okna.
	 * \param *v_factors wskaźnik do wektora stringów
	 */
	void allDivisors(std::vector<std::string> *v_factors);
private:
	/**
	 * Metoda zwracająca bool, sprawdza czy dana komórka na danej pozycji istnieje.
	 * \param point Miejsce, w którym poszukiwana jest komórka.
	 * \param tileSize Rozmiar siatki komórek.
	 */
	bool existQuad(sf::Vector2u point, sf::Vector2u tileSize);

};

