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
		
			ballSet[LEFT] = getBallSetLeft(ballAngle);
			ballSet[FRONT] = getBallSetFront(ballAngle);
			ballSet[RIGHT] = getBallSetRight(ballAngle);
		
			targetSet[LEFT] = getBallSetLeft(ballAngle);
			targetSet[FRONT] = getBallSetFront(ballAngle);
			targetSet[RIGHT] = getBallSetRight(ballAngle);
	}

	float fis::getBallSetLeft(float ballAngle)
	{
		//do nothing for now
	}

	float fis::getBallSetFront(float ballAngle)
	{
		//do nothing for now
	}

	float fis::getBallSetRight(float ballAngle)
	{
		//do nothing for now
	}

	float fis::getTargetSetLeft(float targetAngle)
	{
		//do nothing for now
	}

	float fis::getTargetSetFront(float targetAngle)
	{
		//do nothing for now
	}
	float fis::getTargetSetRight(float targetAngle)
	{
		//do nothing for now
	}
}