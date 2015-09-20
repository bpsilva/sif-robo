#ifndef FIS_H
#define FIS_H
#include "geom.hpp"
#include "environm.h"

namespace fis{
using namespace geom;
using namespace environm;
using namespace soccer;

class fis {

	private:
		float ballSet[3];
		float targetSet[3];

	public:
		fis();
		~fis();

		void fuzzify(float ballAngle, robotBox rb);

	private:
		float getBallSetLeft(float ballAngle);
		float getBallSetFront(float ballAngle);
		float getBallSetRight(float ballAngle);


	};

};//end namespace fis

#endif
