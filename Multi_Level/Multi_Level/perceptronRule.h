#pragma once
#include "Resource.h"

#define IS_EQUAL(x, y) (((x) < (y) + 0.4f && (x) > (y) - 0.4f)? 1 : 0)
// eger y,  - 0.05 y + 0.05 araligindaysa x ve y birbirine esittir.
// burada 0.05 hata payi oluyor

int perceptronRule(Samples, double*, double);
int deltaRule(Samples, double*, double);
