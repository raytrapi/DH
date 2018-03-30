/**
 *
 */
#ifndef DH_MENSAJE_
#define DH_MENSAJE_
#include <iostream>
#include <string>
#include <sstream>
namespace DH{
	class Mensajes{
		public:
			static void log(const std::string mensaje){
				std::cout << mensaje<<"\r\n";
			}
			
			static void error(const std::string mensaje){
				std::cerr << "\033[1;31m"<<mensaje<<"\033[0m\r\n";
			}
			static std::string str(const char * cadena){
				std::stringstream mensaje;
				mensaje.str(cadena);
				return mensaje.str();
			}
	};

}
#endif
