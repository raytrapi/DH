/*
 * Robot.cpp
 *
 *  Created on: 20 oct. 2017
 *      Author: ray
 */

#include "robot.h"
namespace DH{
	namespace robot {
		/**
		 * Constructor
		 * @param fichero Fichero XML en formato sdf
		 * @param modeloRobot Nombre del modelo que contendrá la extructura del robot
		 * @param mano Link que representa la pinza o extremo del robot
		 *
		 */
		Robot::Robot(char * fichero, char * modeloRobot, char * mano) {
			// TODO Auto-generated constructor stub
			load(fichero, modeloRobot, mano);
		}

		Robot::~Robot() {
			// TODO Auto-generated destructor stub
		}
		/**
		 * Carga un fichero en formato sdf para componer el robot
		 * @param fichero Fichero XML en formato sdf
		 * @param modeloRobot Nombre del modelo que contendrá la extructura del robot
		 * @param mano Link que representa la pinza o extremo del robot
		 *
		 */
		void Robot::load(char * fichero, char * modeloRobot, char * mano){
			TiXmlDocument d;
			if(d.LoadFile(fichero)){
				DH::Mensajes::log("Buscamos el modelo ["+  DH::Mensajes::str(modeloRobot) +"]");
				//Tenemos el fichero SDF
				//Obtenemos el modelo a analizar
				TiXmlElement* modelo= NULL;//d.FirstChildElement(argv[2]);
				TiXmlNode * sdf=d.RootElement();
				TiXmlNode * actual=sdf->FirstChild()->FirstChild();
				while (!modelo && actual!=0){
					TiXmlElement *elemento=actual->ToElement();
					//DH::Mensajes::log("actual "+DH::Mensajes::str(elemento->GetText()));
					const char *nombre=elemento->Attribute("name");
					if( nombre && strcmp(nombre,modeloRobot)==0){
						modelo=elemento;
					}
					actual=actual->NextSibling();
				}
				if(modelo){
					DH::Mensajes::log("Procesando robot ["+  DH::Mensajes::str(modeloRobot)+"]");
					//busco los link
					std::vector<TiXmlNode *> links=xml::XML::getElementsByTagName(modelo, "link");
					std::vector<TiXmlNode *> uniones=xml::XML::getElementsByTagName(modelo, "joint");

					mapElementos eslabones;
					//Procesamos las uniones
					for(int i=0;i<uniones.size();i++){
						//La unión tendrá varios valores a obtener entre los que destacan:
						// - El tipo de unión.
						// - El padre y el hijo.
						// - El eje sobre el que se aplica.
						//TODO: ¿Que ocurre si es más de un eje?
						TiXmlNode * nodo=uniones[i];
						const char * tipo=nodo->ToElement()->Attribute("type"); //Tipo
						TiXmlNode * nodoPadre=xml::XML::getFirstElementByTagName(nodo,"parent");
						TiXmlNode * nodoHijo=xml::XML::getFirstElementByTagName(nodo,"child");
						//Lo mejor, en cuanto a eficiencia, sería tener un diccionario que permitiese la búsqueda por el nombre del nodo.
						//Aún así, y debido a que es un proceso que no tiene que ser rápido, lo podemos hacer comprobando cada uno de los eslabones
						const char * nombrePadre=nodoPadre->ToElement()->GetText();
						const char * nombreHijo=nodoHijo->ToElement()->GetText();
						if(strcmp(nombrePadre,mano)!=0 ){ //No aseguramos que la unión no tiene como padre la mano
							//Es un candidato.
							Union * nodoUnion=new Union(nodo, tipo);
							//Buscamos el eslabon padre;
							Eslabon * eslabonPadre=buscarEslabon(eslabones,nombrePadre);
							if(eslabonPadre==NULL){
								//Como es nulo lo creamos
								// Pero antes buscamos el link
								eslabonPadre=new Eslabon(buscarEslabonSDF(links,nombrePadre));
								eslabones[nombrePadre]=eslabonPadre;
							}
							eslabonPadre->setHijo(nodoUnion);
							nodoUnion->setPadre(eslabonPadre);

							Eslabon * eslabonHijo=buscarEslabon(eslabones,nombreHijo);
							if(eslabonHijo==NULL){
								//Como es nulo lo creamos
								eslabonHijo=new Eslabon(buscarEslabonSDF(links,nombreHijo));
								eslabones[nombreHijo]=eslabonHijo;
							}
							eslabonHijo->setPadre(nodoUnion);
							nodoUnion->setHijo(eslabonHijo);/**/
							//Mensajes::log("Tipo: "+Mensajes::str(nodoPadre->ToElement()->GetText()));
						}
					}
					//Ahora recorremos los elementos en busca de la raíz.
					int i=0;
					for(mapElementos::iterator itr=eslabones.begin();itr!=eslabones.end();itr++){
						if(itr->second->getPadre()==NULL){
							raiz=itr->second;
						}else{
							if(raiz==NULL){
								raiz=itr->second;
							}
						}
					}
					Mensajes::log("La cadena cinemática es:\r\n");
					Eslabon* elementoActual=raiz;
					int nivel=0;
					while(elementoActual!=NULL && nivel<100){
						for(int i=0;i<nivel;i++){
							std::cout<<"\t";
						}
						Mensajes::log(Mensajes::str(elementoActual->getEslabon()->ToElement()->Attribute("name")));
						nivel++;
						if(elementoActual->getHijo()!=NULL){
							elementoActual=elementoActual->getHijo()->getHijo();
						}else{
							elementoActual=NULL;
						}
					}


					DH::Mensajes::log("\r\nHay  "+std::to_string(eslabones.size())+" eslabones y "+std::to_string(eslabones.size()-1)+" grados de libertad");

				}else{
					std::stringstream mensaje;
					mensaje.str(modeloRobot);
					DH::Mensajes::error("No se ha encontrado el modelo : "+DH::Mensajes::str(modeloRobot));
				}
			}else{
				DH::Mensajes::error("El fichero no es correcto.\r\n\t"+DH::Mensajes::str(d.ErrorDesc()));
			}
		}
		/**
		 * Busca un nodo dentro de un vector de nodos
		 *
		 * @param nodos Es el vector de nodos en el que se buscará por el atributo name
		 * @param nombre El nombre del nodo a buscar
		 *
		 * @return El nodo encontrado o null si no se ha encontrado el nodo
		 */
		TiXmlNode* Robot::buscarEslabonSDF(const std::vector<TiXmlNode*> & nodos, const char * nombre) {
			for(int i=0;i<nodos.size();i++){
				if(strcmp(nodos[i]->ToElement()->Attribute("name"),nombre)==0){
					return nodos[i];
				}
			}
			return NULL;
		}
		/**
		 * Busca un nodo dentro de un vector de nodos
		 *
		 * @param nodos Es el vector de nodos en el que se buscará por el atributo name
		 * @param nombre El nombre del nodo a buscar
		 *
		 * @return El nodo encontrado o null si no se ha encontrado el nodo
		 */
		Eslabon* Robot::buscarEslabon(mapElementos & nodos, const char * nombre) {
			mapElementos::iterator elemento;
			elemento= nodos.find(nombre);
			if(elemento!=nodos.end()){
				return elemento->second;
			}
			return NULL;
		}

	} /* namespace robot */
} /* namespace DH */
