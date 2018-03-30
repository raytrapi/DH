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
		enum TipoUnion {REVOLUCION, PRISMATICO};
		class Union {
			private:
				TiXmlNode * nodo;
				Eslabon * padre;
				Eslabon * hijo;
				TipoUnion tipo;
				
			public:
				Union(TiXmlNode *,const char*);
				virtual ~Union();
				Eslabon* getHijo() ;
				void setHijo( Eslabon* &hijo);
				TiXmlNode* getNodo() ;
				Eslabon* getPadre() ;
				void setPadre( Eslabon* &padre);
				TipoUnion getTipo() ;
				void desenlazarHijo();
				int eje; //0=x, 1=y, 2=z
				bool giroAntihoraria=false; 
				bool direccionPositiva=true;
		};

	} /* namespace robot */
} /* namespace DH */

#endif /* SRC_ROBOT_UNION_H_ */
