
#include <iostream>

using namespace std;

class Point
{
    public:
        double x, y;
};

class Vector
{
    public:
        Point start, end;
};

int main()
{
    Vector vec1;
    vec1.start.x = 1.0;
    vec1.start.y = 2.0;
    vec1.end.x = 3.0;
    vec1.end.y = 4.0;

    Vector vec2;
    vec1.end.x = 5.0;
    vec1.end.y = 6.0;
    vec2.end.x = 7.0;
    vec2.end.y = 8.0;
}
