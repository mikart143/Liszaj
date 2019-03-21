#include "Statistics.h"
#include "TileSettings.h"


Statistics::Statistics()
{
}


Statistics::~Statistics()
{
}

void Statistics::draw()
{

	ImGui::Text("Rozmiar okna symulacji:");
	ImGui::SameLine();
	ImGui::Text(std::to_string(TileSettings::getInstance()->mainWindowSize.x).c_str());
	ImGui::SameLine();
	ImGui::Text("px");
	ImGui::SameLine();
	ImGui::Text("x");
	ImGui::SameLine();
	ImGui::Text(std::to_string(TileSettings::getInstance()->mainWindowSize.y).c_str());
	ImGui::SameLine();
	ImGui::Text("px");

	ImGui::Text("Ilosc kwadratow: ");
	ImGui::SameLine();
	ImGui::Text(std::to_string(TileSettings::getInstance()->tileSize.x * TileSettings::getInstance()->tileSize.y).c_str());

	ImGui::Text("Rozmiar kwadratu: ");
	ImGui::SameLine();
	ImGui::Text(std::to_string(QuadSettings::getInstance()->quadDimensions.x).c_str());
	ImGui::SameLine();
	ImGui::Text("px");


	ImGui::Text("Rozmiar siatki:");
	ImGui::SameLine();
	ImGui::Text(std::to_string(TileSettings::getInstance()->tileSize.x).c_str());
	ImGui::SameLine();
	ImGui::Text("elementow");
	ImGui::SameLine();
	ImGui::Text("na");
	ImGui::SameLine();
	ImGui::Text(std::to_string(TileSettings::getInstance()->tileSize.y).c_str());
	ImGui::SameLine();
	ImGui::Text("elementow");

	ImGui::Text("FPS:");
	ImGui::SameLine();
	ImGui::Text(std::to_string(SimulationSettings::getInstance()->currentFPS).c_str());


}
