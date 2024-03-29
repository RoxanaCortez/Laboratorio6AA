#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int fastWay(int a[][3], int t[][2], int* e, int* x, int n){
    
    int f1[n];
    int f2[n];

    f1[0] = e[0] + a[0][0];
    f2[0] = e[1] + a[0][1];

    string p1 = to_string(e[0]) + ", " + to_string(a[0][0]);
    string p2 = to_string(e[0]) + ", " + to_string(a[0][1]);

    for (int j = 1; j < n; j++ ) {
        
        string tempp1 = p1;
        string tempp2 = p2;

        if (f1[j-1] + a[0][j] <= f2[j-1] + t[1][j-1] + a[0][j]) {
            f1[j] = f1[j-1] + a[0][j];
            p1 = tempp1 + " , " + to_string(a[0][j]);
        } else {
            f1[j] = f2[j-1] + t[j-1][1] + a[0][j];
            p2 = tempp2 + " , " + to_string(a[0][j]);
        }

        if (f2[j-1] + a[1][j] <= f1[j-1] + t[0][j-1] + a[1][j]){
            f2[j] = f2[j-1] + a[1][j];
            p2 = tempp2 + " , " + to_string(a[1][j]);
        } else {
            f2[j] = f1[j-1] + t[0][j-1] + a[1][j];
            p1 = tempp1 + " , " + to_string(a[1][j]);
        }
    }

    if (f1[n-1] + x[0] <= f2[n-1] + x[1]){
        cout << p1 << " , " << x[0];
        printf("\n\ntiempo: ");
        return f1[n-1] + x[0];
    }else{
        cout << p2 << " , " << x[1];
        printf("\n\ntiempo: ");
        return f2[n-1] + x[1];
    }
}

int main(){
    int lines[2][3] = {{3,2,4},{4,2,5}};
    int times[][2] = {{3,3}, {2,4}};

    int e[] = {2, 3};
    int x[] = {1, 2};

    printf("%d",fastWay(lines, times, e, x, 3));
    return 0;
}
