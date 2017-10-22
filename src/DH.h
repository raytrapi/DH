/*
 * DH.h
 *
 *  Created on: 14 oct. 2017
 *      Author: ray
 */

#ifndef SRC_DH_H_
#define SRC_DH_H_

#include "mensajes.h"
#include <vector>
#include "robot/robot.h"

TiXmlNode * getElementByName(TiXmlNode * base, const char * nombre);
std::vector<TiXmlNode *> getElementsByTagName(TiXmlNode * base, const char * nombre);
#endif /* SRC_DH_H_ */
