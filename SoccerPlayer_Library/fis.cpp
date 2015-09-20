#include "fis.h"

namespace fis
{
	fis::fis()
	{
		//do nothing for now
	}

	fis::~fis()
	{
		//do nothing for now
	}

	void fis::fuzzify(float ballAngle, float targetAngle)
	{

		// cout << "BallAngle: " << ballAngle << " BallSet: L " << getBallSetLeft(ballAngle) << " F " << getBallSetFront(ballAngle) << " R " << getBallSetRight(ballAngle) << "\n";
			ballSet[LEFT] = getBallSetLeft(ballAngle);
			ballSet[FRONT] = getBallSetFront(ballAngle);
			ballSet[RIGHT] = getBallSetRight(ballAngle);

			targetSet[LEFT] = getTargetSetLeft(targetAngle);
			targetSet[FRONT] = getTargetSetFront(targetAngle);
			targetSet[RIGHT] = getTargetSetRight(targetAngle);

	}

	float fis::getBallSetLeft(float ballAngle)
	{
		return getTriangleValue(ballAngle, -190.0f, -180.0f, 0.0f);
	}

	float fis::getBallSetFront(float ballAngle)
	{
		return getTriangleValue(ballAngle, -90.0f, 0.0f, 90.0f);
	}

	float fis::getBallSetRight(float ballAngle)
	{
		return getTriangleValue(ballAngle, 0.0f, 180.0f, 190.0f);
	}

	float fis::getTargetSetLeft(float targetAngle)
	{
		return getTriangleValue(targetAngle, -190.0f, -180.0f, 0.0f);
	}

	float fis::getTargetSetFront(float targetAngle)
	{
		return getTriangleValue(targetAngle, -90.0f, 0.0f, 90.0f);
	}

	float fis::getTargetSetRight(float targetAngle)
	{
		return getTriangleValue(targetAngle, 0.0f, 180.0f, 190.0f);
	}

	float fis::getTriangleValue(float angle, float alpha, float beta, float gamma)
	{
		if (angle <= alpha || angle >= gamma)
			return 0;

		if (angle >= alpha || angle <= beta)
			return ((angle - alpha)/(beta - alpha));

		if (angle > beta || angle < gamma)
			return ((gamma - angle)/(gamma - beta));
	}


	float fis::min(float a, float b)
	{
		return (a<b?a:b);
	}

	float fis::max(float a, float b, float c)
	{
		int max_ab = (a>b?a:b);
		return (c > max_ab? c :max_ab);
	}


//	       alvo
//       E 	 F   D
//b      0   1   2
//o  E 0 F   E   E
//l  F 1 D   F   E
//a  D 2 D   D   F
	
	void fis::infer()
	{
		for(int i = 0 ; i < 3 ; i ++)
		{
			for(int j = 0 ; j < 3 ; j++)
			{
				rules[i][j] = min(ballSet[i] , targetSet[j]);
			}
		}

		action[0] = max(rules[0][1], rules[0][2], rules[1][2]);
		action[1] = max(rules[0][0], rules[1][1], rules[2][2]);
		action[2] = max(rules[1][0], rules[2][0], rules[2][1]);

	}
}
