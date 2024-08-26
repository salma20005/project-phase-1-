#include <iostream>
#include <fstream>
#include <algorithm>
#include<cmath>
#include<numeric>
using namespace std;
int main() {
    int a[4];
    for(int i = 0 ; i < 4 ; i++){
        cin >> a[i];
    }
    int sum =0;
    string m;
    cin >> m;
    for(int i = 0 ; i < m.length( ) ; i++) {
        sum += a[(m[i] - '0') - 1];
    }
    cout << sum;
    return 0;
}