#ifndef FIS_H
#define FIS_H
#include "geom.hpp"
#include "environm.h"

namespace fis{
using namespace geom;
using namespace environm;
using namespace soccer;
class fis{

	fis();
	~fis();

public:
void fuzzify(point<float> ball, robotBox rb);
};

};//end namespace fis





#endif