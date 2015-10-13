#include <stdio.h>

#include <math.h>

//defines the point structure
struct point {
	double x;
	double y;
};


//defines the triangle structure
struct triangle {
	struct point a;
	struct point b;
	struct point c;
};

//all function declarations
double distance (struct point a, struct point b);
double radius (struct triangle t);


//function that computes the distance between two points
double distance (struct point a, struct point b)
{
	double s;
	double d;
	s = (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
	d = sqrt(s);
	return d;
}

//function computes radius of inscribed circle
double radius (struct triangle t)
{
	double a;
	double p;
	double r;
	
	a = 0.5*fabs((t.b.x - t.a.x)*(t.c.y - t.a.y) -
       		 (t.c.x - t.a.x)*(t.b.y - t.a.y));
	
	p = distance(t.a, t.b) + distance(t.b, t.c) + distance(t.c, t.a);

	r = 2*a/p;
	
	return r;	
}

int main(void)
{
	struct triangle t = (struct triangle){{2., 2.}, {-2., 1.}, {0., -3.}};

	double r = radius(t);

	printf("radius = %f\n", r);	

	return 0;
}



