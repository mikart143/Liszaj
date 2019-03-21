#pragma once

#include <Thor/Config.hpp>

#include <Thor/Graphics/ColorGradient.hpp>

#include <Thor/Graphics/UniformAccess.hpp>


/**
 * Przestrzeń nazw thor. Jest to przestrzeń nazw wykorzystywana przez bibliotekę thor.
 */
namespace  thor
{
	/**
	 * Zmodyfikowana klasa ColorAnimation z biblioteki thor.
	 */
	class ColorAnimationModified
	{
	public:
		/**
		 * Konstruktor przyjmujący jako parametr wskaźnik to ColorGradient. Przy oznaczeniu konstruktora jako explicit, nie będzie przeprowadzana automatyczna konwersja przy pomocy tego konstruktora.
		 */
		explicit ColorAnimationModified( ColorGradient* gradient);

		/**
		 * Szablon z parametrem klasy
		 */
		template <class Animated>
		/**
		*
 		*	Przeciążenei operatora (). Służy zmianie koloru danemu elementowi.
 		*	\param animated Parametr przekazujący adres do elementu, w którym ma być zmieniony kolor.
 		*	\param progress Parametr który przyjmuje postęp w zakresie 0f do 100f.
		*/
		void operator() (Animated& animated, float progress) const;
	private:

		/**
		 * Zmienna prywatna, wskaźnik do ColorGradient.
		 */
		thor::ColorGradient *m_gradient;

	};

	template <class Animated>

	void ColorAnimationModified::operator()(Animated& animated, float progress) const
	{
		thor::setColor(animated, m_gradient->sampleColor(progress));
	}
}


