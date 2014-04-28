
#include <iostream>
#include <iomanip>

using namespace std;

void print(int ar[], int sz, int step){
    for (int i = 0; i < sz; i++) {
        if(((i+1) % step) != 0)
            cout << setw(3) << ar[1];
        else
            cout << setw(3) << ar[i] << endl;
    }
    cout << endl;
}

void shellSort(int a[], int sz){
    int i, j;
    int step, temp;
    step = sz / 2;
    while(step) {
        print(a, sz, step);
        cout << "==>" << endl;
        for(i = step; i < sz; i++) {
            temp = a[i];
            j = i;
            while(j >= step && a[j - step] > temp) {
                a[j] = a[j - step];
                j = j - step;
            }
            a[j] = temp;
        }
        print(a, sz, step);
        cout << "Current array" << endl;
        print(a, sz, sz);
        cout << "-----------------" << endl;

        step = step / 2.2;
    }
}


int main(int argc, const char *argv[])
{
    int a[] = { 13, 14, 94, 33, 82, 25, 59, 94, 65, 23, 45, 27, 73, 25, 39, 10};
    const size_t sz = sizeof(a)/sizeof(a[0]);

    cout << "Initial array" << endl;
    print(a, sz, sz);
    cout << "---------------"<<  endl;
    shellSort(a,sz);

    cout << "Sorted array" << endl;
    print(a, sz, sz);

    return 0;
}
