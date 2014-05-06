// Roll one six sided die 60000 times

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, const char *argv[])
{
    const int arraySize = 7;
    int face, frequency[arraySize] = {0};

    srand(time(0));

    for(int roll = 1; roll <= 60000; roll++)
        ++frequency[ 1 + rand() % 6];

    cout << "Face" << setw(13) << "Frequency" << endl;

    for(face = 1; face < arraySize; face++)
        cout << setw(4) << face
            << setw(13) << frequency[face] << endl;

    return 0;
}
