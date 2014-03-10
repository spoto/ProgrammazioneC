struct point {
  double x;
  double y;
};

void print_point(struct point this);
double distance(struct point p1, struct point p2);
struct point closest
  (struct point this, struct point points[], int length);
