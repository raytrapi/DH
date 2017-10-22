
#include "DH.h"

int main(int argc, char* argv[]) {
	if(argc<4){
		DH::Mensajes::error("DH - Algorítmo Denavit Hartenberg\r\n\t dh \"fichero sdf\" \"modelo\" \"mano\"");
		return 1;
	}
	DH::Mensajes::log("Procesamos \""+  DH::Mensajes::str(argv[1])+"\"\r\n");
	DH::robot::Robot robot(argv[1],argv[2],argv[3]);

	return 0;
}




