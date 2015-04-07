#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

#define mod(x) ((x) > 0 ? (x) : (-(x)))
#define sqr(x) ((x)*(x))
#define eps (1e-6)

struct Point {
  int x;
  int y;

  Point(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }

  double distTo(const Point& p) const {
    return sqrt(sqr(x - p.x) + sqr(y - p.y));
  }
};

inline bool compare(const double a, const double b) {
  return mod(a - b) <= eps;
}


inline bool isPythagorasOk(double c, double b, double a) {
  return compare(sqr(a), sqr(b) + sqr(c));
}

inline bool isRightTriangle(const Point& p1, const Point& p2, const Point& p3) {
  double d1 = p1.distTo(p2);
  double d2 = p1.distTo(p3);
  double d3 = p2.distTo(p3);

  std::vector<double> v(3, 0.0);
  v[0] = d1;
  v[1] = d2;
  v[2] = d3;
  std::sort(v.begin(), v.end());

  return isPythagorasOk(v[0], v[1], v[2]);
}

long long int solve(long long int n) {
  unsigned xa, xb, ya, yb;
  long long int answer = 0;

  Point p1(0, 0);
  Point p2, p3;

  for(xa = 0; xa <= n; ++xa) {
    for(xb = 0; xb <= n; ++xb) {
      for(ya = 0; ya <= n; ++ya) {
	for(yb = 0; yb <= n; ++yb) {
  	  if((!xb && !yb) || (!xa && !ya))
  	    continue;

  	  p2 = Point(xa, ya);
  	  p3 = Point(xb, yb);
  	  answer += isRightTriangle(p1, p2, p3);
  	}
      }
    }
  }  

  return answer;
}

int main(int argc, char* argv[]) {
  assert(mod(-1) == 1);
  assert(mod(1) == 1);

  assert(sqr(3) == 9);
  assert(sqr(-3) == 9);

  assert(isPythagorasOk(3,4,5));
  assert(!isPythagorasOk(5,5,3));
  assert(!isPythagorasOk(3,5,8));

  assert(isRightTriangle(Point(0,0), Point(0,4), Point(5,0)));

  long long int a = atoll(argv[1]);
  std::cout << solve(a) << std::endl;
  return 0;
}
