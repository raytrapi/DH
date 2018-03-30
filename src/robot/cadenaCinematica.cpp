#include "cadenaCinematica.h"

namespace DH{
    namespace robot{
        std::vector<Eslabon *> CadenaCinematica::obtenerCadena(Eslabon* raiz){
            std::vector<Eslabon *> cadenaCinematica;
            Eslabon* elementoActual=raiz;
            int nivel=0;
            while(elementoActual!=NULL && nivel<100){
                Union * unionActual=elementoActual->getHijo();
                cadenaCinematica.push_back(elementoActual);
                for(int i=0;i<nivel;i++){
                    std::cout<<"\t";
                }
                if(unionActual!=NULL){
                    std::string tipo=Mensajes::str(unionActual->getNodo()->ToElement()->Attribute("type"));
                    std::string eje="no";
                    if(tipo=="revolute"){
                        TiXmlNode * xyz=xml::XML::getFirstElementByTagName(unionActual->getNodo(),"xyz");
                        if(xyz!=NULL){
                            const char * tipoTemp=xyz->ToElement()->GetText();
                            std::vector<std::string> partes= extras::Utiles::dividir(tipoTemp, " ");
                            //Tenemos los angulos, así que buscamos el giro.
                            //TODO: OJO, aquí solo definimo un único eje de giro y será negativo o positivo. No miraremos los angulos. Mejorar en el futuro.

                            for(int i=0;i<partes.size();i++){
                                int posVal=0;
                                if(partes[i][posVal]=='-'){
                                    unionActual->giroAntihoraria=true;
                                    posVal++;
                                }
                                if(partes[i][posVal]=='1'){
                                    unionActual->eje=i;
                                }
                            }
                            
                            /*if(strcmp(tipoTemp,"0 0 1"))
                            eje=std::string();/**/
                        }
                        //Ahora averiguamos si va hacia arriba o hacia abajo
                        Eslabon *hijo=unionActual->getHijo();
                        Eslabon *padre=unionActual->getPadre();
                        double * posicionHijo=posicion(hijo->getEslabon());
                        double * posicionPadre=posicion(padre->getEslabon());


                        Mensajes::log(Mensajes::str(elementoActual->getEslabon()->ToElement()->Attribute("name"))+" de tipo "+tipo+" en eje " + (elementoActual->getHijo()->giroAntihoraria?"-":"+") + std::to_string(elementoActual->getHijo()->eje));
                    }else{
                        Mensajes::log(Mensajes::str(elementoActual->getEslabon()->ToElement()->Attribute("name"))+" de tipo "+tipo);
                    }
                
                    
                }else{
                    Mensajes::log(Mensajes::str(elementoActual->getEslabon()->ToElement()->Attribute("name"))+" final");
                }
                nivel++;
                if(elementoActual->getHijo()!=NULL){
                    elementoActual=elementoActual->getHijo()->getHijo();
                }else{
                    elementoActual=NULL;
                }
            }
            return cadenaCinematica; 
        }
        double * CadenaCinematica::posicion(TiXmlNode * xml){
            double posiciones[6];
            TiXmlNode * pose=xml::XML::getFirstElementByTagName(xml,"pose");
            std::vector<std::string> partes=extras::Utiles::dividir(pose->ToElement()->GetText(), " ");
            for (int i=0; i<partes.size(); i++){
                posiciones[i]=std::stod(partes[i]);
            }
            return posiciones;
        }
    }
}