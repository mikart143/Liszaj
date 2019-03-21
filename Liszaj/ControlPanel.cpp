#include "ControlPanel.h"



ControlPanel::ControlPanel()
{
	windowPosition = sf::Vector2f(0, 0);
	windowSize = sf::Vector2f(0, 0);
	m_options.setTile(m_tile);
}


ControlPanel::~ControlPanel()
{
}

void ControlPanel::draw()
{
	ImGui::Begin("Panel Sterowania");

	if(!ImGui::CollapsingHeader("Ustawienia"))
	{
		m_options.draw();
	}
	if(ImGui::CollapsingHeader("Statystyki"))
	{
		m_statistics.draw();
	}


	windowPosition = sf::Vector2f(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y);
	windowSize = sf::Vector2f(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y);

	ImGui::End();

}

void ControlPanel::setTile(Tile* tile)
{
	m_tile = tile;
}
