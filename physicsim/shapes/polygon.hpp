#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
using namespace std;

typedef struct Point {
    int x;
    int y;

    Point() {}
    Point(int x, int y) : x(x), y(y) {}
} Point;

typedef struct Edge {
    Point* a;
    Point* b;

    Edge() {}
    Edge(Point* a, Point* b) : a(a), b(b) {}
} Edge;

class Polygon {

public:
    vector<Point> points;
    vector<Edge> edges;

};

#endif
