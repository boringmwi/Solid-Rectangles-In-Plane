#include <iostream>
#include <vector>

using namespace std;

class Rectangle
{
    public:
        vector<int> size;
        vector<vector<int>> location;

        void rec_size(const int length, const int width) {
            size.resize(2);
            size[0] = length;
            size[1] = width;
        }

        void set_location(const int x1, const int y1) {
            location.resize(2, vector<int>(2));
            //where the rectangle begins on the x axis
            location[0][0] = x1; 
            //where the rectangle begins on the y axis
            location[0][1] = y1;
            //where the rectangle ends on the x axis
            location[1][0] = x1 + size[0];
            //where the rectangle ends on the y axis
            location[1][1] = y1 + size[1];
        }

        void check_intersection(const Rectangle& rec1, const Rectangle& rec2) {
            if (rec1.location[0][0] < rec2.location[1][0] && rec1.location[1][0] > rec2.location[0][0] &&
                rec1.location[0][1] < rec2.location[1][1] && rec1.location[1][1] > rec2.location[0][1]) {
                cout << "The rectangles intersect." << endl;

                vector<int> intersection_location(2);
                intersection_location[0] = max(rec1.location[0][0], rec2.location[0][0]);
                intersection_location[1] = max(rec1.location[0][1], rec2.location[0][1]);

                vector<int> intersection_size(2);
                intersection_size[0] = min(rec1.location[1][0], rec2.location[1][0]) - intersection_location[0];
                intersection_size[1] = min(rec1.location[1][1], rec2.location[1][1]) - intersection_location[1];
                
                cout << "Intersection location: (" << intersection_location[0] << ", " << intersection_location[1] << ")" << endl;
                cout << "Intersection size: (" << intersection_size[0] << ", " << intersection_size[1] << ")" << endl;
            } else {
                cout << "The rectangles do not intersect." << endl;
            }
        }

        void check_point(const int x, const int y) {
            if (location[0][0] < x && x < location[1][0] && location[0][1] < y && y < location[1][1]) {
                cout << "The point is inside the rectangle." << endl;
            } else {
                cout << "The point is outside the rectangle." << endl;
            }
        }
};

int main() {
    //testing the rectangle class and its functions
    Rectangle rec1, rec2;

    rec1.rec_size(5, 9);
    rec1.set_location(0, 0);

    rec2.rec_size(10, 4);
    rec2.set_location(-6, 1);

    rec1.check_intersection(rec1, rec2);
    rec1.check_point(5, 10);
    
}