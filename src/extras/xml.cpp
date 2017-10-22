/*
 * XML.cpp
 *
 *  Created on: 20 oct. 2017
 *      Author: ray
 */

#include "xml.h"

namespace DH {
	namespace xml {

		XML::XML() {
			// TODO Auto-generated constructor stub

		}

		XML::~XML() {
			// TODO Auto-generated destructor stub
		}
		/**
		 * Devuelve el primer elemento que tenga en el atributo "name" el nombre indicado. La búsqueda es en profuncidad
		 *
		 * @param base es el nodo desde el que se buscará. Este nodo también se evaluará y puede pertenecer al resultado.
		 * @param nombre indica el nombre que deberá tener el atributo name
		 *
		 */
		TiXmlNode * XML::getElementByName(TiXmlNode * base, const char * nombre){
			const char * name=base->ToElement()->Attribute("name");
			if(name && strcmp(name,nombre)==0){
				return base;
			}
			TiXmlNode * hijo = base->FirstChild();
			if(hijo->Type()==4){ //Nodo de tipo texto
				return NULL;
			}
			TiXmlNode * elemento=NULL;
			while (hijo && !elemento){
				elemento=getElementByName(hijo, nombre);
				hijo=hijo->NextSibling();
			}
			return elemento;
		}
		/**
		 * Devuelve el primer elemento que corresponda con el nombre indicado a partir de la base. La búsqueda es en profuncidad
		 *
		 * @param base es el nodo desde el que se buscará. Este nodo también se evaluará y puede pertenecer al resultado.
		 * @param nombre indica el nombre del tag
		 *
		 */
		TiXmlNode * XML::getFirstElementByTagName(TiXmlNode * base, const char * nombre){
			const char * name=base->Value();
			if(name && strcmp(name,nombre)==0){
				return base;
			}
			TiXmlNode * hijo = base->FirstChild();
			while (hijo ){
				if(hijo->Type()!=4){ //Nodo de tipo texto
					TiXmlNode * salida=getFirstElementByTagName(hijo,nombre);
					if(salida!=NULL){
						return salida;
					}
				}
				hijo=hijo->NextSibling();
			}
			return NULL;
		}
		/**
		 * Devuelve una lista de nodos en base al tipo de nodo indicado. La búsqueda es en profuncidad
		 *
		 * @param base es el nodo desde el que se buscará. Este nodo también se evaluará y puede pertenecer al resultado.
		 * @param nombre indica el nombre del tag
		 *
		 */
		std::vector <TiXmlNode *> XML::getElementsByTagName(TiXmlNode * base, const char * nombre){
			std::vector <TiXmlNode *> nodos;
			const char * name=base->Value();
			if(name && strcmp(name,nombre)==0){
				nodos.push_back(base);
			}
			TiXmlNode * hijo = base->FirstChild();
			while (hijo ){
				if(hijo->Type()!=4){ //Nodo de tipo texto
					std::vector <TiXmlNode *> salida=getElementsByTagName(hijo,nombre);
					for (int i=0;i<salida.size();i++){
						nodos.push_back(salida[i]);
					}

				}
				hijo=hijo->NextSibling();

			}
			return nodos;
		}
	} /* namespace xml */
} /* namespace DH */
