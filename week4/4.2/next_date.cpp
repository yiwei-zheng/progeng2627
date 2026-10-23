#include <iostream>

using namespace std;

bool leap_year(int year){
    return !(year % 4 != 0 || (year % 100 == 0 && year % 400 != 0));
}

bool find(int *a, int length, int obj){
    for (int i = 0; i < length;i++){
        if(a[i] == obj){
            return 1;
        }
    }
    return 0;
}


void next_date(int d1, int m1, int y1, int& d2, int& m2, int& y2){
    // TODO: d1, m1, y1 are inputs 
    // corresponding to the date d1/m1/y1
    // d2, m2, y2 are outputs that the function must compute
    // corresponding to the date d2/m2/y2 
    // which is meant to be the day after d1/m1/y1

    // function leap_year is useful for this task

    // do not begin to write code straightaway
    // sketch some diagrams first like we did
    // for the leap year task

    // (this function should not print anything)
    int leap_month[8] = {1, 3, 5, 7, 8, 10, 11, 12};
    if (find(leap_month, 8, m1)){
        if(m1 == 12){
            if(d1 == 31){
                y2 = y1 + 1;
                m2 = 1;
                d2 = 1;
                return;
            }else{
                y2 = y1;
                m2 = m1;
                d2 = d1 + 1;
                return;
            }
        }

        if(d1 == 31){
            y2 = y1;
            m2 = m1 + 1;
            d2 = 1;
            return;
        }
        y2 = y1;
        m2 = m1;
        d2 = d1 + 1;
        return;
    }
    else{
        if (m1 != 2){
            if(d1 == 30){
                y2 = y1;
                m2 = m1 + 1;
                d2 = 1;
                return;
            }else{
                y2 = y1;
                m2 = m1;
                d2 = d1 + 1;
                return;
            }
        }
        else{
            if(leap_year(y1) && d1 == 29){
                y2 = y1;
                m2 = m1 + 1;
                d2 = 1;
                return;
            }else if(!leap_year(y1) && d1 == 28){
                y2 = y1;
                m2 = m1 + 1;
                d2 = 1;
                return;
            }
            y2 = y1;
            m2 = m1;
            d2 = d1 + 1;
            return;
        }
    }


}

int main(){
    // TODO: write a main to test the function
    int d1, m1, y1, d2, m2, y2;

    cin >> d1 >> m1 >> y1;
    next_date(d1, m1, y1, d2, m2, y2);
    cout << d2 << '/' << m2 << '/' << y2;
    return 0;
}