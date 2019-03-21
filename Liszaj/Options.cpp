#include "Options.h"

/**
 * Przestrzeń  nazw biblioteki ImGui, do której zostały dodane nowe funkcje.
 */
namespace ImGui
{
	/**
	 * Funkcja anonimowa utworzona na wzór funkcji anonimowej z prototypu funkcji. 
	 * Prototyp tej funkcji: 
	 * IMGUI_API bool          Combo(const char* label, int* current_item, bool(* items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int popup_max_height_in_items = -1);
	 * \param vec Przekazuje wskaźnik (służy jako wskażnik do dowolnego typu).
	 * \param idx Indeks elementu w wektorze.
	 * \param out_text Wskaźnik przez który przekazwyany jest wyjściowy tekst.
	 *	
	 *	Do zmiennej vector przypisywany jest wskaźnik rzutowany do wektora stringów
	 *	Jeżeli index jest ujemny lub większy niż rozmiar wektora to zwracane jest false. 
	 *	W przeciwnym razie wartość ta przypisywana out_text i zwracane jest true.
	 *
	 */
	static auto vector_getter = [](void* vec, int idx, const char** out_text)
	{
		auto& vector = *static_cast<std::vector<std::string>*>(vec);
		if (idx < 0 || idx >= static_cast<int>(vector.size())) { return false; }
		*out_text = vector.at(idx).c_str();
		return true;
	};

	/**
	 * Własna funkcja Combo do tworzenia combo boxa.
	 * \param label Wyświetlana nazwa elementu
	 * \param currIndex wskaźnik do aktualnie wybranego elementu.
	 * \param values wektor stringów przechowujący dzielniki liczb
	 * 
	 * Wewnątrz funkcji badane jest czy wektor jest pusty i zwarcane jest false kiedy tak jest. W przeciwnym wypadku wywoływana jest funkcja o prototypie:
	 *  IMGUI_API bool          Combo(const char* label, int* current_item, bool(* items_getter)(void* data, int idx, const char** out_text), void* data, int items_count, int popup_max_height_in_items = -1);
	 *  
	 */
	bool Combo(const char* label, int* currIndex, std::vector<std::string>& values)
	{
		if (values.empty()) { return false; }
		return Combo(label, currIndex, vector_getter,
			static_cast<void*>(&values), values.size());
	}
}



Options::Options()
{

	infectionGapTime = SimulationSettings::getInstance()->lengthOfInfectionGap.asSeconds();
	infectionTime = SimulationSettings::getInstance()->lengthOfInfection.asSeconds();
	resistanceTime = SimulationSettings::getInstance()->lengthOfResistance.asSeconds();
	//Przesłanie przez referencje
	Utility().allDivisors(&factors);
	infectedColor = ImColor(QuadSettings::getInstance()->infectedColor.r, QuadSettings::getInstance()->infectedColor.g, QuadSettings::getInstance()->infectedColor.b, QuadSettings::getInstance()->infectedColor.a);
	resistanceColor = ImColor(QuadSettings::getInstance()->resistanceColor.r, QuadSettings::getInstance()->resistanceColor.g, QuadSettings::getInstance()->resistanceColor.b, QuadSettings::getInstance()->resistanceColor.a);
	healthyColor = ImColor(QuadSettings::getInstance()->healthyColor.r, QuadSettings::getInstance()->healthyColor.g, QuadSettings::getInstance()->healthyColor.b, QuadSettings::getInstance()->healthyColor.a);



}


Options::~Options()
{
}

void Options::draw()
{

	// Pausing logic of program
	if (ImGui::Button("Play/Pause")) SimulationSettings::getInstance()->stopLogic = !SimulationSettings::getInstance()->stopLogic;
	if (SimulationSettings::getInstance()->stopLogic && SimulationSettings::getInstance()->globalClock.isRunning()) SimulationSettings::getInstance()->globalClock.stop();
	if (!SimulationSettings::getInstance()->stopLogic && !SimulationSettings::getInstance()->globalClock.isRunning()) SimulationSettings::getInstance()->globalClock.start();

	//Restarting simulation
	if (ImGui::Button("Restart"))
	{
		if (isinf(QuadSettings::getInstance()->quadDimensions.x) || isinf(QuadSettings::getInstance()->quadDimensions.y)) QuadSettings::getInstance()->quadDimensions = sf::Vector2f(10,10);
		m_tile->init();
	}

	ImGui::Separator();

	if (ImGui::Combo("Rozmiary komorek", &selected, factors))
	{
		QuadSettings::getInstance()->quadDimensions = sf::Vector2f(std::stoi(factors[selected]), std::stoi(factors[selected]));
		m_tile->init();
	}

	if (ImGui::Button("+")) m_tile->add(); ImGui::SameLine(); if (ImGui::Button("-")) m_tile->remove(); ImGui::SameLine(); ImGui::Text("Dodawanie i usuwanie komorek");

	ImGui::Separator();

	ImGui::Checkbox("Punkt zarazenia", &SimulationSettings::getInstance()->pointOfInfection);

	ImGui::Separator();

	ImGui::Checkbox("Gradacja kolorow", &SimulationSettings::getInstance()->colorGradation);

	ImGui::Separator();

	ImGui::Text("Kolory komorek");



	if (ImGui::ColorButton("Kolor zainfekowanej komorki", infectedColor)) ImGui::OpenPopup("InfectedColorPicker");
	if(ImGui::BeginPopup("InfectedColorPicker"))
	{
		if (ImGui::ColorPicker3("Zarazone", (float*)&infectedColor))
		{
			QuadSettings::getInstance()->updateInfectedTextureColor(infectedColor);
			QuadSettings::getInstance()->updateResistanceTextureColor(resistanceColor);
		}
			

		ImGui::EndPopup();
	}
	ImGui::SameLine();
	ImGui::Text("Zarazona");
	ImGui::SameLine();
	if (ImGui::ColorButton("Kolor odpornej komorki", resistanceColor)) ImGui::OpenPopup("ResistedColorPicker");
	if (ImGui::BeginPopup("ResistedColorPicker"))
	{
		if (ImGui::ColorPicker3("Odporna", (float*)&resistanceColor))
		{
			QuadSettings::getInstance()->updateResistanceTextureColor(resistanceColor);
			QuadSettings::getInstance()->updateInfectedTextureColor(infectedColor);
		}
			

		ImGui::EndPopup();
	}
	ImGui::SameLine();
	ImGui::Text("Odporna");
	ImGui::SameLine();
	if (ImGui::ColorButton("Kolor zdrowej komorki", healthyColor)) ImGui::OpenPopup("HealthyColorPicker");
	if (ImGui::BeginPopup("HealthyColorPicker"))
	{
		if (ImGui::ColorPicker3("Zdrowa", (float*)&healthyColor))
		{
			QuadSettings::getInstance()->updateHealthyTextureColor(healthyColor);
		}
			

		ImGui::EndPopup();
	}
	ImGui::SameLine();
	ImGui::Text("Zdrowa");

	ImGui::Separator();
	
	ImGui::Checkbox("Pojedyncze zarazenie", &SimulationSettings::getInstance()->multiInfectionsOfQuad);
	ImGui::SliderFloat("Prawdopodobienstwo", &SimulationSettings::getInstance()->probabilityOfInfection, 0, 1, "%.1f");

	ImGui::Separator();

	ImGui::DragFloat("Czas infekcji", &infectionTime, 0.1, 0, 60);
	ImGui::DragFloat("Czas odpornosci", &resistanceTime, 0.1, 0, 60);
	ImGui::DragFloat("Czas pomiedzy infekcjami", &infectionGapTime, 0.1, 0, 60);

	if(ImGui::Button("Zastosuj czasy"))
	{
		SimulationSettings::getInstance()->lengthOfResistance = sf::seconds(resistanceTime);
		SimulationSettings::getInstance()->lengthOfInfection = sf::seconds(infectionTime);
		SimulationSettings::getInstance()->lengthOfInfectionGap = sf::seconds(infectionGapTime);
	}
}

void Options::setTile(Tile* tile)
{
	m_tile = tile;
}
