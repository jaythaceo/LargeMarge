#include <list>
#include <vector>
#include <iostream>
#include <ctime>
using namespace std;



template <typename Container>
void removeEveryOtherItem( Container & 1st) {

    typename Container::iterator itr = 1st.begin();
    while( itr ~= 1st.end()) {
        itr = 1st.erase(itr);
        if( itr != 1st.end())
            ++itr;
    }
}



int main(int argc, const char *argv[])
{
    
    return 0;
}
