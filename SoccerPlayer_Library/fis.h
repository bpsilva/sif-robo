#ifndef FIS_H
#define FIS_H

#include <iostream>
#include "geom.hpp"
#include "environm.h"

#define LEFT 0
#define FRONT 1
#define RIGHT 2

#define STEPSIZE 10

namespace fis	{

	using namespace std;
	using namespace geom;
	using namespace environm;
	using namespace soccer;

	class Fis {

		private:
			float ballSet[3]; // Left, Front, Right, in that order
			float targetSet[3]; // Left, Front, Right, in that order
			float rules[3][3];
			float cut[3];// Left, Front, Right, in that order
			float leftMotor, rightMotor; //[-1 , +1]

		public:

			void fuzzify(float ballAngle, float targetAngle);
			void infer();
			void defuzzify();
			float getLeftMotor();
			float getRightMotor();
		//private:
			float getBallSetLeft(float ballAngle);
			float getBallSetFront(float ballAngle);
			float getBallSetRight(float ballAngle);


			float getTargetSetLeft(float targetAngle);
			float getTargetSetFront(float targetAngle);
			float getTargetSetRight(float targetAngle);

			float getTriangleValue(float angle, float alfa, float beta, float gama);


			float min(float a, float b);
			float max(float a, float b, float c);
			
			void setMotorValues(float centroid);

	};
};//end namespace fis

#endif
