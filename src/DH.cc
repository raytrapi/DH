
#include "DH.h"

int main(int argc, char* argv[]) {
	if(argc<3){
		DH::Mensajes::error("DH - Algorítmo Denavit Hartenberg\r\n\t dh fichero modelo");
		return 1;
	}
	DH::Mensajes::log("Procesamos \""+  DH::Mensajes::str(argv[1])+"\"\r\n");
		TiXmlDocument d;
		if(d.LoadFile(argv[1])){
			DH::Mensajes::log("Buscamos el modelo ["+  DH::Mensajes::str(argv[2])+"]");
			//Tenemos el fichero SDF
			//Obtenemos el modelo a analizar
			TiXmlElement* modelo= NULL;//d.FirstChildElement(argv[2]);
			TiXmlNode * sdf=d.RootElement();
			TiXmlNode * actual=sdf->FirstChild()->FirstChild();
			while (!modelo && actual!=0){
				TiXmlElement *elemento=actual->ToElement();
				//DH::Mensajes::log("actual "+DH::Mensajes::str(elemento->GetText()));
				const char *nombre=elemento->Attribute("name");
				if( nombre && strcmp(nombre,argv[2])==0){
					modelo=elemento;
				}
				actual=actual->NextSibling();
			}
			if(modelo){
				DH::Mensajes::log("Procesando robot ["+  DH::Mensajes::str(argv[2])+"]");
				//busco los link
				std::vector<TiXmlNode *> links=getElementsByTagName(modelo, "link");
				std::vector<TiXmlNode *> grados=getElementsByTagName(modelo, "joint");
				DH::Mensajes::log("Hay  "+std::to_string(links.size())+" eslabones y "+std::to_string(grados.size())+" grados de libertad");
				//TiXmlNode * base=getElementByName((TiXmlNode *)modelo, "base");
				//DH::Mensajes::log("base "+DH::Mensajes::str(base->Value()));
			}else{
				std::stringstream mensaje;
				mensaje.str(argv[2]);
				DH::Mensajes::error("No se ha encontrado el modelo : "+DH::Mensajes::str(argv[2]));
			}
		}else{
			DH::Mensajes::error("El fichero no es correcto.\r\n\t"+DH::Mensajes::str(d.ErrorDesc()));
		}

		return 0;
}
TiXmlNode * getElementByName(TiXmlNode * base, const char * nombre){
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
std::vector <TiXmlNode *> getElementsByTagName(TiXmlNode * base, const char * nombre){
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



