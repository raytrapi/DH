/*
 * Union.cpp
 *
 *  Created on: 20 oct. 2017
 *      Author: ray
 */

#include "union.h"

namespace DH {
	namespace robot {

		Union::Union(TiXmlNode * nodo,const char* tipo) {
			this->nodo=nodo;
			if(strcmp(tipo,"revolute")==0){
				this->tipo=REVOLUCION;
			}else if(strcmp(tipo, "prismatic")==0){
				this->tipo=PRISMATICO;
			}else{
				throw 100;
			}
			padre=NULL;
			hijo=NULL;
		}

		Union::~Union() {
			// TODO Auto-generated destructor stub
		}
		Eslabon* Union::getHijo(){
			return hijo;
		}

		void Union::setHijo(Eslabon* &hijo){
			this->hijo = hijo;
		}

		TiXmlNode* Union::getNodo(){
			return nodo;
		}

		 Eslabon* Union::getPadre(){
			return padre;
		}

		void Union::setPadre(Eslabon* &padre){
			this->padre = padre;
		}

		TipoUnion Union::getTipo(){
			return tipo;
		}
		void Union::desenlazarHijo() {
			hijo->desenlazarHijo();
			delete hijo;
			hijo=NULL;
		}


	} /* namespace robot */
} /* namespace DH */

