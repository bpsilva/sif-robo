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





















}
