#ifndef FIS_H
#define FIS_H
#include "geom.hpp"
#include "environm.h"
#define LEFT 0
#define FRONT 1
#define RIGHT 2

namespace fis{


using namespace geom;
using namespace environm;
using namespace soccer;





class fis {

	private:
		float ballSet[3]; // Left, Front, Right, in that order
		float targetSet[3]; // Left, Front, Right, in that order

	public:
		fis();
		~fis();

		void fuzzify(float ballAngle, float targetAngle);

	private:
		float getBallSetLeft(float ballAngle);
		float getBallSetFront(float ballAngle);
		float getBallSetRight(float ballAngle);

		float getTargetSetLeft(float targetAngle);
		float getTargetSetFront(float targetAngle);
		float getTargetSetRight(float targetAngle);

	};
};//end namespace fis

#endif