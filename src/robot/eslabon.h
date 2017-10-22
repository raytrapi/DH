/*
 * Eslabon.h
 *
 *  Created on: 20 oct. 2017
 *      Author: ray
 */

#ifndef SRC_ROBOT_ESLABON_H_
#define SRC_ROBOT_ESLABON_H_
#include "../vendor/tinyxml/tinyxml.h"
#include "union.h"

namespace DH {
	namespace robot {
		class Union;
		class Eslabon {
			private:
				TiXmlNode * eslabon; //Contiene la información del eslabon
				Union * hijo; //Unión con el eslabón hijo
				Union * padre; //Unión con el eslabón Padre
			public:
				Eslabon(TiXmlNode *);
				virtual ~Eslabon();
				//Observadores
				Union * getPadre();
				Union * getHijo();
				TiXmlNode* getEslabon() ;
				//Modificadores
				void setPadre(Union *&);
				void setHijo(Union *&);

		};

	} /* namespace robot */
} /* namespace DH */

#endif /* SRC_ROBOT_ESLABON_H_ */
