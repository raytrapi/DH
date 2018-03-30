#ifndef SRC_CADENA_CINEMATICA_H
#define SRC_CADENA_CINEMATICA_H
#include <vector>
#include "eslabon.h"
#include "../mensajes.h"
#include "../extras/utiles.h"
#include "../extras/xml.h"
#include "../vendor/tinyxml/tinyxml.h"
namespace DH{
    namespace robot{
        class CadenaCinematica{
            private:
                static double * posicion(TiXmlNode * eslabon);
            public:
                static std::vector<Eslabon *> obtenerCadena(Eslabon* raiz);
        };
    }
}
#endif // !SRC_CADENA_CINEMATICA_H
