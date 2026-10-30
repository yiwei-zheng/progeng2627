#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 10000;

int gcd(int a, int b){
    int remainder = 325799;
    while(1){
        remainder = a % b;
        a = b;
        if(remainder == 0){
            break;
        }
        b = remainder;
    }
    return b;
}

int euler_totient(int n){
    int cnt = 0;
    for (int i = 1; i <= n;i++){
        if (gcd(i, n) == 1){
            cnt++;
        }
    }
    return cnt;
}
int totient_sum(int n, int &depth){
    int sum = 0;
    depth = 0;
    while(n!=1){
        n = euler_totient(n);
        sum += n;
        depth++;
    }
    return sum;
}

int depth(int n){
    int d;
    totient_sum(n, d);
    return d;
}


bool is_peak(int n){
    int depth_n = depth(n);
    int depth_a = depth(n - 1);
    int depth_b = depth(n + 1);
    return (depth_a < n && depth_b < n);
}

bool s(int x){
    return (depth(x) - depth(x - 1) + depth(x) - depth(x + 1)) / 2;
}


struct point{
    int val, dpth, is_pk, st;
    point() = default;
    point(int pval){
        val = pval;
        dpth = depth(val);
        is_pk = is_peak(val);
        st = s(val);
    }

    bool operator<(const point& other) const{
        if (dpth != other.dpth){
            return dpth < other.dpth;
        }
        else{
            return st < other.st;
        }
    }
};

int strongest_local_peak(int a, int b){
    point pt[MAXN];
    for (int i = a; i <= b;i++){
        pt[i] = point(i);
    }
    sort(pt + a, pt + b + 1);
    return pt[b].val;
}


int main(){
    cout << strongest_local_peak(14, 20);
    return 0;
}