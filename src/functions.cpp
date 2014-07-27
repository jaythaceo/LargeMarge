/*
 * Functions
 */

#include <iostream>
using namespace std;

int add(int ,int);

int main(int argc, const char *argv[])
{
    int x = 248;
    int y = 20;

    cout << add(x,y) << endl;


    return 0;
}


int add(int a, int b){

    return a + b;

}

