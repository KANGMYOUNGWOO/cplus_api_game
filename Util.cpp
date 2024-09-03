#include "Util.h"


void Util::Clamp(float min, float max, float & current) {
	if (current < min || current > max)
		current = (current < min) ? min : max;
}
