/*
 * Robot.h
 *
 *  Created on: 20 oct. 2017
 *      Author: ray
 */

#ifndef SRC_ROBOT_ROBOT_H_
#define SRC_ROBOT_ROBOT_H_


#include "../mensajes.h"
#include "../extras/xml.h"
#include "../vendor/tinyxml/tinyxml.h"
#include "eslabon.h"
#include "union.h"
#include <vector>
#include <map>


namespace DH{
	namespace robot {
		struct cmpStr{
		   bool operator()(const char * a, const char * b) const{
			   return strcmp(a,b)<0;
		   }
		};
		typedef std::map<const char*,Eslabon *,cmpStr> mapElementos;
		class Robot {
			private:
				Eslabon * raiz;
			public:
				Robot(char * fichero, char * modeloRobot, char * mano);
				virtual ~Robot();
			private:
				void load(char *, char *, char *);
				TiXmlNode* buscarEslabonSDF(const std::vector<TiXmlNode *> &, const char *);
				Eslabon* buscarEslabon(mapElementos &, const char *);
		};

	} /* namespace robot */
} /* namespace DH*/
#endif /* SRC_ROBOT_ROBOT_H_ */
