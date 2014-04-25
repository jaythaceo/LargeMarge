/*
 * Printing an unsigned interger
 * in bits.
 *
 */

#include <iostream>
#include <iomanip>
using namespace std;


void displayBits( unsigned );

int main(int argc, const char *argv[])
{
    unsigned x;

    cout << "Enter a integer: ";
    cin >> x;
    displayBits(x);

    return 0;
}

void displayBits( unsigned value )
{
    const int SHIFT = 8 * sizeof( unsigned ) - 1;
    const unsigned MASK = 1 << SHIFT;

    cout << setw( 7 ) << value << " = ";

    for (unsigned c =1; c <= SHIFT + 1; c++) {
        cout << (value & MASK ? '1' : '0');
        value <<= 1;

        if (c % 8 == 0)
            cout << ' ';
    }

    cout << endl;
}



