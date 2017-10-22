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
		Eslabon* DH::robot::Union::getHijo(){
			return hijo;
		}

		void DH::robot::Union::setHijo(Eslabon* &hijo){
			this->hijo = hijo;
		}

		TiXmlNode* DH::robot::Union::getNodo(){
			return nodo;
		}

		 Eslabon* DH::robot::Union::getPadre(){
			return padre;
		}

		void DH::robot::Union::setPadre(Eslabon* &padre){
			this->padre = padre;
		}

		Tipo DH::robot::Union::getTipo(){
			return tipo;
		}

	} /* namespace robot */
} /* namespace DH */


