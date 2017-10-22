/*
 * Union.h
 *
 *  Created on: 20 oct. 2017
 *      Author: ray
 */

#ifndef SRC_ROBOT_UNION_H_
#define SRC_ROBOT_UNION_H_
#include "../vendor/tinyxml/tinyxml.h"
#include "eslabon.h"

namespace DH {
	namespace robot {
		class Eslabon;
		enum Tipo {REVOLUCION, PRISMATICO};
		class Union {
			private:
				TiXmlNode * nodo;
				Eslabon * padre;
				Eslabon * hijo;
				Tipo tipo;
			public:
				Union(TiXmlNode *,const char*);
				virtual ~Union();
				Eslabon* getHijo() ;
				void setHijo( Eslabon* &hijo);
				TiXmlNode* getNodo() ;
				Eslabon* getPadre() ;
				void setPadre( Eslabon* &padre);
				Tipo getTipo() ;
		};

	} /* namespace robot */
} /* namespace DH */

#endif /* SRC_ROBOT_UNION_H_ */
