/*
 * dh.h
 *
 *  Created on: 19 mar. 2018
 *      Author: ray
 */

#ifndef SRC_ROBOT_DH_H_
#define SRC_ROBOT_DH_H_
#include <vector>
#include <array>
#include "eslabon.h"
#include "union.h"
#include "../mensajes.h"
namespace DH  {
	namespace robot {
		
		class DenavitHartenberg {
			private:
				bool * giroCompleto(const bool e1, const bool e2, const bool f1, const bool f2);
			public:
				DenavitHartenberg();
				virtual ~DenavitHartenberg();
				static std::vector<std::array<std::string,4>> procesarCadena(std::vector<Eslabon *>);
		};
	
	} /* namespace robot */
} /* namespace DG */

#endif /* SRC_ROBOT_DH_H_ */
