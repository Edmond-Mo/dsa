#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define ROWS 4
#define COLS 5

// use double stars
void fun(int **a)
{
    cout << a[ROWS-1][COLS-1] << "\n";
}

// use constant width
//void fun2(int a[][COLS])   // both works fine
void fun2(int (*a)[COLS])
{
    cout << a[ROWS-1][COLS-1] << "\n";
}

int main() {
    // a is an array of ROWS int pointers
    int *a[ROWS];
    for (int i = 0; i < ROWS; i++) {
        a[i] = new int[COLS]; // works fine
        //a[i] = (int*)malloc(sizeof(int) * COLS); // works fine too
    }

    a[ROWS-1][COLS-1] = 5;
    fun(a);
    // fun2(a); // DOESN't COMPILE!!
    int c[ROWS][COLS] = {0};
    c[ROWS-1][COLS-1] = 7;
    fun2(c);    // works fine

    int **b;
    //b = (int **)malloc(sizeof(int*) * ROWS); // works fine
    b = new int* [ROWS]; // works fine
    for (int i = 0; i < ROWS; i++) {
        b[i] = (int*)malloc(sizeof(int) * COLS);
    }
    b[ROWS-1][COLS-1] = 6;
    fun(b);
    // fun2(b); // DOESN't COMPILE!!
    return 0;
}

