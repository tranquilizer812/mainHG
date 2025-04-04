#include <iostream>
using namespace std;

int max_of_three(int a, int b, int c) {
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

double max_of_three(double a, double b, double c) {
    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

double max_of_three(int a, double b, float c) {
    double max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    return max;
}

int main() {
    cout << max_of_three(5, 3.7, 2.9f) << endl;
    cout << max_of_three(10, 20, 30) << endl;
    return 0;
}