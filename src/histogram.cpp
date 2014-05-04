// Printing Histogram

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char *argv[])
{
    const int arraySize = 10;
    int n[arraySize] = { 19, 3, 12, 8, 21, 3, 32, 11, 20, 12};

    cout << "Element" << setw(13) << "Value"
        << setw(17) << "Histogram" << endl;

    for (int i = 0; i < arraySize; i++) {
        cout << setw(7) << i << setw(13)
            << n[i] << setw(9);

        for (int j = 0; j < n[i]; j++)
            cout << "*";

        cout << endl;
    }

    return 0;
}
