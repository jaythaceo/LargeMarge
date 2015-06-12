
#include <iostream>

using namespace std;

void bubbleSort(int *a, int size) {
    int i, j, k, temp;
    for (i = 0; i < size-1; i++) {
        for(j = 0; j < size -1; j++) {
            if (*(a+j) > *(a+j+1)) {
                temp = *(a+j+1);
                *(a+j+1) = *(a+j);
                *(a+j) = temp;
            }
        }
        for (k = 0; k < size; k++)
            cout << *(a+k) << " ";
        cout << endl;

    }
}
int main()
{
    int k;
    int a[] = {5,7,1,4,4,9,2,6,8,0};
    const size_t sz = sizeof(a)/sizeof(a[0]);
    for (k = 0; k < sz; k++)
        cout << *(a+k) << " ";
    cout << endl;
    cout << "=================" << endl;
    bubbleSort(a, sz);

    return 0;
}
