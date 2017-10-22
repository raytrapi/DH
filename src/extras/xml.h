/*
 * XML.h
 *
 *  Created on: 20 oct. 2017
 *      Author: ray
 */

#ifndef SRC_EXTRAS_XML_H_
#define SRC_EXTRAS_XML_H_
#include <vector>
#include "../vendor/tinyxml/tinyxml.h"
namespace DH {
	namespace xml {

		class XML {
		public:
			XML();
			virtual ~XML();
			static TiXmlNode * getElementByName(TiXmlNode * base, const char * nombre);
			static TiXmlNode * getFirstElementByTagName(TiXmlNode * base, const char * nombre);
			static std::vector <TiXmlNode *> getElementsByTagName(TiXmlNode * base, const char * nombre);
		};

	} /* namespace xml */
} /* namespace DH */

#endif /* SRC_EXTRAS_XML_H_ */
