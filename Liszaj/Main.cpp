#include<SFML/Graphics.hpp>
#include <imgui.h>
#include <sfml-imgui/sfml-imgui/imgui-SFML.hpp>
#include <sfml-imgui/sfml-imgui/imconfig-SFML.hpp>
#include "TileSettings.h"
#include "SimulationSettings.h"
#include "QuadSettings.h"
#include "Tile.h"
#include "Options.h"
#include "ControlPanel.h"
/**
 * Funkcj główna main.
 * Zawarte jest w niej główna pętla aplikacji.
 *  
 *  Na początku tworzone jest okno główne.
 *  Ilość klatek blokowana jest na odświeżanie ekranu.
 *  
 *  Następnie deklarowane są najważniejsze zmienne.
 *  Następnie inicjowane jest okno Panelu Sterowania.
 *  Następnie inicjowane jest siatka wraz z Panelem Sterowania.
 *  
 *  Na samym końcu znajduje się główna pętla w której jest pętla odpowiadająca za przechwytywanie zdarzeń (np. kliknięcie myszką). Pod koniec pętli rysowane są wszystkie elementy.
 */
int main()
{
	sf::RenderWindow mainWindow(sf::VideoMode(800,800), "Liszaj", sf::Style::Close);
	mainWindow.setVerticalSyncEnabled(true);
	sf::Event mainWindowEvent;
	sf::Clock deltaClockImGui;
	sf::Clock deltaClockFPS;



	TileSettings::getInstance()->mainWindowSize = mainWindow.getSize();

	ImGui::SFML::Init(mainWindow);

	Tile tile;
	tile.init();

	ControlPanel controlPanel;
	controlPanel.setTile(&tile);



	while(mainWindow.isOpen())
	{

		while(mainWindow.pollEvent(mainWindowEvent))
		{
			ImGui::SFML::ProcessEvent(mainWindowEvent);
			if (mainWindowEvent.type == sf::Event::Closed) mainWindow.close();
			if(mainWindowEvent.type == sf::Event::MouseButtonPressed && mainWindowEvent.mouseButton.button == sf::Mouse::Button::Left &&
				!Utility().clickedInWindow(controlPanel.windowSize, controlPanel.windowPosition, sf::Vector2u(mainWindowEvent.mouseButton.x, mainWindowEvent.mouseButton.y)) )
				tile.infect(sf::Vector2f(mainWindowEvent.mouseButton.x, mainWindowEvent.mouseButton.y));
			
		}
		ImGui::SFML::Update(mainWindow, deltaClockImGui.restart());

		mainWindow.clear(QuadSettings::getInstance()->healthyColor);
		mainWindow.draw(tile);
		controlPanel.draw();

		ImGui::SFML::Render(mainWindow);

		SimulationSettings::getInstance()->currentFPS = 1 / deltaClockFPS.restart().asSeconds();

		mainWindow.display();
	}
	ImGui::SFML::Shutdown();
	return 0;
}
