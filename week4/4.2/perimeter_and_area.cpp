
using namespace std;

void output_perimeter_area(double length, double width, double &perimter, double &area){
    perimter = 2 * (length + width);
    area = length * width;
}