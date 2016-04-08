#include "bitonic.h"
#include <cmath>
using namespace std;

double d(point p, point q) {double x=p.x-q.x, y=p.y-q.y; return sqrt(x*x+y*y);}
