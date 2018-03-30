/*
 * dh.cpp
 *
 *  Created on: 19 mar. 2018
 *      Author: ray
 */

#include "DenavitHartenberg.h"

namespace DH {
	namespace robot {
		
		DenavitHartenberg::DenavitHartenberg() {
			// TODO Auto-generated constructor stub
			
		}
		
		DenavitHartenberg::~DenavitHartenberg() {
			// TODO Auto-generated destructor stub
		}
		std::vector<std::array<std::string,4>> DenavitHartenberg::procesarCadena(std::vector<Eslabon *> cadena){
			std::vector<std::array<std::string,4>> matriz;
			Mensajes::log("Empezamos la generación de matriz de parámetros");
			int ejesNormales[3]={2,0,1}; //z=0,x=1,y=7
			bool ejesNormalesPositivo[3]={true,true,true};
			bool xDireccion;
			bool zDireccion;
			bool xDireccionGiro;
			bool zDireccionGiro;
			bool thetaGiro;
			bool alphaGiro;
			for(int i=0;i<cadena.size()-1 ; i++){
				Union * laUnion=cadena[i]->getHijo();
				std::string articulacion=std::to_string(i+1);
				std::array<std::string,4> parametros;
				std::string theta="0";
				std::string d="0";
				std::string a="0";
				std::string alpha="0";
				zDireccion=laUnion->direccionPositiva;
				zDireccionGiro=!laUnion->giroAntihoraria;
				if(laUnion->getTipo()==robot::REVOLUCION){
					theta="q"+articulacion;
					d="l"+articulacion;
				}else{
					theta="0";
					d="d"+articulacion;
				}
				// Controlamos alguno de los posibles tipos.
				if(laUnion->eje!=ejesNormales[0]){
					//Tenemos que calcular cual es el giro que hace mi ejeNormal
					switch(laUnion->eje){
						case 0:
							//Rota sobre el eje x
							switch(ejesNormales[0]){
								case 2:
									switch(ejesNormales[1]){
										case 0:
											xDireccion=(ejesNormalesPositivo[0]^zDireccion);
											thetaGiro=ejesNormalesPositivo[1]^xDireccion;
											thetaGiro=ejesNormalesPositivo[0]?!thetaGiro:thetaGiro; //(ejesNormalesPositivo[0] & !thetaGiro) | !(ejesNormalesPositivo[0] & thetaGiro);
											alphaGiro=!xDireccion;
											theta+=thetaGiro?" + 90":" - 90";
											alpha=alphaGiro?" + 90":" - 90";
											ejesNormales[1]=1;
											break;
										case 1:
											xDireccion=(ejesNormalesPositivo[0]^zDireccion);
											if(xDireccion!=ejesNormalesPositivo[1]){
												theta+=" + 180";
											}
											alphaGiro=!xDireccion;
											alpha=alphaGiro?" + 90":" - 90";
											break;
									}
									break;
								case 1:
									switch(ejesNormales[1]){
										case 0:
											break;
										case 2:
											break;
									}
									break;
								
							}
							
							break;
						case 1:
							//Rotamos sobre la y
							
							break;
						case 2:
							//Rotamos sobre la z
							break;
						
					}
					ejesNormales[0]=laUnion->eje;
				}
				parametros[0]=theta;
				parametros[1]=d;
				parametros[2]=a;
				parametros[3]=alpha;
				matriz.push_back(parametros);

			}

			return matriz;
		}
		bool * DenavitHartenberg::giroCompleto(const bool e1, const bool e2, const bool f1, const bool f2){
			bool resultado[3];
			/*xDireccion=(e2^e3);
			thetaGiro=ejesNormalesPositivo[1]^xDireccion;
											thetaGiro=ejesNormalesPositivo[0]?!thetaGiro:thetaGiro; //ejesNormalesPositivo[0] & !thetaGiro | !(ejesNormalesPositivo[0] & thetaGiro);
											alphaGiro=!xDireccion;/**/
			return resultado;
		}
	} /* namespace robot */
} /* namespace DG */
