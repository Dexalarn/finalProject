#include <stdio.h>
#include <stdlib.h>
#include "MinMax.h"
#include <time.h>

struct min_max maxmin(void) {
	struct min_max r;
	srand(time(NULL));
	r.min = (rand() % 16) - 10;
	r.max = (rand() % 31) + 15;
	return r;
}