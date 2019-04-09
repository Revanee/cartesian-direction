#ifndef Targeter_h
#define Targeter_h

#include <math.h>

struct Point {
    float x;
    float y;
};

namespace Targeter {
    float getAngleFromVector(Point vector) {
        return atan2(vector.y, vector.x);
    }

    Point getRelativeVector(Point origin, Point destination) {
        Point p;
        p.x = destination.x - origin.x;
        p.y = destination.y - origin.y;
        return p;
    }

    float getAngleBetweenCoordinates(Point origin, Point destination) {
        Point relativeVector = getRelativeVector(origin, destination);
        return getAngleFromVector(relativeVector);
    }

    float getNormalizedAngle(float angle) {
	float normalized;
	if (angle < 0) {
		normalized = angle + 360;
		return getNormalizedAngle(normalized);
	}
	if (angle >= 360) {
		normalized = angle - 360;
		return getNormalizedAngle(normalized);
	}
	return angle;
    }

    float getRelativeAngle(float currentOrientation, float targetOrientation) {
    	float offsetToTarget = -currentOrientation + targetOrientation;
	return getNormalizedAngle(offsetToTarget);
    }
};

#endif
