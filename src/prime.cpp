// Prime numbers
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    // Start here
    std::vector<int> primes;
    primes.push_back(2);
    for (int i = 2; i < 1000; i++) {

        bool prime = true;
        for(int j = 0; j < primes.size() && primes[j] * primes[j] <= i; j++){

            if (i % primes[j] == 0) {
                prime = false;
                break;
            }
        }
        if(prime)
        {
            primes.push_back(i);
            cout << i << " ";
            
        }
    }

   cout << "End." << endl; 
    
   return 0;
}
