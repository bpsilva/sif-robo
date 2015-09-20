#include "fis.h"

namespace fis
{
	void Fis::fuzzify(float ballAngle, float targetAngle)
	{
		ballSet[LEFT] = getBallSetLeft(ballAngle);
		ballSet[FRONT] = getBallSetFront(ballAngle);
		ballSet[RIGHT] = getBallSetRight(ballAngle);

		targetSet[LEFT] = getTargetSetLeft(targetAngle);
		targetSet[FRONT] = getTargetSetFront(targetAngle);
		targetSet[RIGHT] = getTargetSetRight(targetAngle);
	}

	float Fis::getBallSetLeft(float ballAngle)
	{
		return getTriangleValue(ballAngle, -190.0f, -180.0f, 0.0f);
	}

	float Fis::getBallSetFront(float ballAngle)
	{
		return getTriangleValue(ballAngle, -90.0f, 0.0f, 90.0f);
	}

	float Fis::getBallSetRight(float ballAngle)
	{
		return getTriangleValue(ballAngle, 0.0f, 180.0f, 190.0f);
	}

	float Fis::getTargetSetLeft(float targetAngle)
	{
		return getTriangleValue(targetAngle, -190.0f, -180.0f, 0.0f);
	}

	float Fis::getTargetSetFront(float targetAngle)
	{
		return getTriangleValue(targetAngle, -90.0f, 0.0f, 90.0f);
	}

	float Fis::getTargetSetRight(float targetAngle)
	{
		return getTriangleValue(targetAngle, 0.0f, 180.0f, 190.0f);
	}

	float Fis::getTriangleValue(float angle, float alpha, float beta, float gamma)
	{
		if (angle <= alpha || angle >= gamma)
			return 0;

		if (angle >= alpha && angle <= beta)
			return ((angle - alpha)/(beta - alpha));

		if (angle > beta && angle < gamma)
			return ((gamma - angle)/(gamma - beta));
	}

	float Fis::min(float a, float b)
	{
		return ((a < b) ? a : b);
	}

	float Fis::max(float a, float b, float c)
	{
		float max_ab = ((a > b) ? a : b);
		return ((c > max_ab) ? c : max_ab);
	}


//	       alvo
//       E 	 F   D
//b      0   1   2
//o  E 0 F   E   E
//l  F 1 D   F   E
//a  D 2 D   D   F

	void Fis::infer()
	{
		for(int i = 0 ; i < 3 ; i ++)
		{
			for(int j = 0 ; j < 3 ; j++)
			{
				rules[i][j] = min(ballSet[i] , targetSet[j]);
			}
		}

		cut[LEFT] = max(rules[0][1], rules[0][2], rules[1][2]);
		cut[FRONT] = max(rules[0][0], rules[1][1], rules[2][2]);
		cut[RIGHT] = max(rules[1][0], rules[2][0], rules[2][1]);
	}

	void Fis::defuzzify()
	{
		int steps = ((180-(-180))/STEPSIZE) + 1;
		float left[steps], front[steps], right[steps];
		float unionSet[steps];
		float angle;

		for(int i = 0 ; i < steps ; i++)
		{
			angle = -180 + (i * STEPSIZE);

			left[i] = getBallSetLeft(angle);
			front[i] = getBallSetFront(angle);
			right[i] = getBallSetRight(angle);

			if(left[i] > cut[LEFT])
			{
				left[i] = cut[LEFT];
			}
			if(front[i] > cut[FRONT])
			{
				front[i] = cut[FRONT];
			}

			if(right[i] > cut[RIGHT])
			{
				right[i] = cut[RIGHT];
			}

			unionSet[i] = max(left[i], front[i], right[i]);
		}

		float ac = 0.0;
		float d = 0.0;
		for(int i = 0 ; i < steps ; i++)
		{
			ac += unionSet[i] * (-180 + (i * STEPSIZE));
			d += unionSet[i];
		}
		float centroid = ac/d;

		setMotorValues(centroid);
	}

	void Fis::setMotorValues(float centroid)
	{
		std::cout << "centroid: " << centroid << std::endl;

		if(centroid <= 0.0)
		{
			rightMotor =  ((1-(-centroid/180))*2)-1;
			leftMotor = 1;
		}
		if(centroid >= 0.0)
		{
			rightMotor = 1;
			leftMotor = 2-((centroid/180)*2)-1;
		}
	}

	float Fis::getRightMotor()
	{
		return rightMotor;
	}
	float Fis::getLeftMotor()
	{
		return leftMotor;
	}
}
