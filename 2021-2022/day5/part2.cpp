#include <iostream>
#include <vector>
#include <map>

struct Point { int x, y; };
struct Line { Point start, finish; };

std::istream &operator >> (std::istream &is, char const &c) {
    std::istream::sentry sentry (is);

    if (sentry) {
        if (is.peek() == c) 
            is.get(); 
        else
            is.setstate(std::ios_base::failbit);
    }

    return is;
}


std::istream &operator >> (std::istream &is, char const *s) {
    std::istream::sentry sentry (is);

    if (sentry) {
        for (char c; is && (c = *s) != 0; ++s)
            if (c == is.peek())
                is.get(); else is.setstate(std::ios_base::failbit);
    }

    return is;
}


// Point input reader
std::istream &operator >> (std::istream &is, Point &point) {
    return is >> point.x >> ',' >> point.y;
}
// Line input reader
std::istream &operator >> (std::istream &is, Line &line) {
    return is >> line.start >> "->" >> line.finish;
}


// Point comparator
bool operator < (const Point &p1, const Point &p2) {
    return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}


// Ponit toString()
std::ostream &operator << (std::ostream &os, Point const &point) {
    return os << "[" << point.x << ',' << point.y << "]";
}
// Line toString()
std::ostream &operator << (std::ostream &os, Line const &line) {
    return os << "<" << line.start << " -> " << line.finish << ">";
}


int main ()
{
    Line line;
    int overlaps = 0;
    std::vector<Line> lines;
    std::map<Point, int> points;

    // computes the input and stores it in a vector
    while(std::cin >> line)
        lines.push_back(line);

    std::cout << lines.size() << " lines found..." << std::endl;

    for(Line l: lines) {

        Point p1 = l.start;
        Point p2 = l.finish;

        // Vertical line
        if(p1.x == p2.x) {

            // if p1 comes after p2 (in that vertical line)
            // we swap the points, for convenience
            if(p1.y > p2.y)
                std::swap(p1, p2);

            Point temp = p1;

            // we mark all the points in the line
            while(temp.y <= p2.y) {
                
                points[temp]++;

                if(points[temp] == 2)
                    overlaps++;

                temp.y++;
            }
            
        }
        // Horizontal line
        else if(p1.y == p2.y) {

            if(p1.x > p2.x)
                std::swap(p1, p2);
    
            Point temp = p1;

            while(temp.x <= p2.x) {
                
                points[temp]++;

                if(points[temp] == 2)
                    overlaps++;

                temp.x++;
            }
        }
        // Diagonal line (left to right)
        else if(p1.x - p1.y == p2.x - p2.y) {

            if(p2.y < p1.y)
                std::swap(p1, p2);
            
            Point temp = p1;

            while(temp.y <= p2.y) {
                
                points[temp]++;

                if(points[temp] == 2)
                    overlaps++;

                temp.x++;
                temp.y++;
            }
        }
        // Diagonal line (right to left)
        else if(p1.x + p1.y == p2.x + p2.y) {

            if(p2.y < p1.y)
                std::swap(p1, p2);
            
            Point temp = p1;

            while(temp.y <= p2.y) {
                
                points[temp]++;

                if(points[temp] == 2)
                    overlaps++;

                temp.x--;
                temp.y++;
            }
        }
        else
            continue;
    }

    std::cout << overlaps << " overlaps." << std::endl;
}
