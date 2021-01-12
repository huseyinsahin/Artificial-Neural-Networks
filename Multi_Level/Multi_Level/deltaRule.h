#pragma once
#include "Resource.h"

#define IS_EQUAL(x, y) (((x) < (y) + 0.4f && (x) > (y) - 0.4f)? 1 : 0)
/*
	|x - y| < 0.4 ise 1 değilse 0 döndürür.
	desired_output ile output arasındaki fark 0.4 ten küçükse öğrenme gerçekleşir.
*/

int deltaRule(Samples, double*, double);