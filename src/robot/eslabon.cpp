/*
 * Eslabon.cpp
 *
 *  Created on: 20 oct. 2017
 *      Author: ray
 */

#include "eslabon.h"

namespace DH {
	namespace robot {

		Eslabon::Eslabon(TiXmlNode * nodo) {
			// TODO Auto-generated constructor stub
			eslabon=nodo;
			padre=NULL;
			hijo=NULL;
		}

		Eslabon::~Eslabon() {
			// TODO Auto-generated destructor stub
		}

		Union* Eslabon::getPadre() {
			return padre;
		}

		Union* Eslabon::getHijo() {
			return hijo;
		}

		void Eslabon::setPadre(Union* &padre) {
			this->padre=padre;
		}

		void Eslabon::setHijo(Union*& hijo) {
			this->hijo=hijo;
		}
		TiXmlNode* Eslabon::getEslabon() {
			return eslabon;
		}
		void Eslabon::desenlazarHijo() {
			delete hijo;
			hijo=NULL;
		}

	} /* namespace robot */
} /* namespace DH */


