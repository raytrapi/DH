/*
 * utiles.h
 *
 *  Created on: 19 mar. 2018
 *      Author: ray
 */

#ifndef SRC_EXTRAS_UTILES_H_
#define SRC_EXTRAS_UTILES_H_
#include <vector>
#include <string>
#include <iostream>
namespace DH {
	namespace extras {
		
		class Utiles {
			public:
				Utiles();
				virtual ~Utiles();
				static std::vector<std::string> dividir(const char * cadena, const char *divisor);
		};
	
	} /* namespace extras */
} /* namespace DH */

#endif /* SRC_EXTRAS_UTILES_H_ */
