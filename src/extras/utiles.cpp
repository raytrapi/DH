/*
 * utiles.cpp
 *
 *  Created on: 19 mar. 2018
 *      Author: ray
 */

#include "utiles.h"

namespace DH {
	namespace extras {
		
		Utiles::Utiles() {
			// TODO Auto-generated constructor stub
			
		}
		
		Utiles::~Utiles() {
			// TODO Auto-generated destructor stub
		}
		
		//Este método no es lo suficientemente eficiente.
		//TODO: Mejeror método
		/**
		 * Divide la cadena en partes
		 * @param cadena const char * con la cadena a dividir
		 * @param divisor const char * cadena con el divisor
		 * 
		 * @return std::vector<std::string> con el resultado de la división. En este caso devolvemos std::strings y no char * para simplificar el problema
		 */
		std::vector<std::string> Utiles::dividir(const char* cadena, const char* divisor) {
			if(cadena == NULL){
				std::cout<<"nulo \r\n";
			} 
			//int coindicencias=0;
			int longitud=strlen(cadena);
			int longitudDivisor=strlen(divisor);
			//int posInicial=0;
			int posDivisor=0;
			std::string cadenaActual="";
			std::string cadenaTemp="";
			std::vector<std::string> resultado;
			for(int i=0; i<longitud; i++){
				if(cadena[i]==divisor[posDivisor++]){
					cadenaTemp+=cadena[i];
				}else{
					posDivisor=0;
					cadenaActual+=cadenaTemp+cadena[i];
					cadenaTemp="";
				}
				if(posDivisor>=longitudDivisor){
					//Tenemos una nueva cadena
					resultado.push_back(cadenaActual);
					cadenaActual="";
					posDivisor=0;
					cadenaTemp="";
				}
			};
			resultado.push_back(cadenaActual);
			return resultado;
		}
	} /* namespace extras */
} /* namespace DH */
