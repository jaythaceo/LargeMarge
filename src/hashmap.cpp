/*
 * Hashmap
 */

#include <map>
#include <iostream>
#include <cassert>

int main(int argc, const char *argv[])
{
    std::map<std::string, int> m;
    m["Hello"] = 23;

    // check is key present
    if(m.find("world") != m.end())
        std::cout << "Map contains key world!\n";

    // retrive
    std::cout << m["Hello"] << '\n';
    std::map<std::string, int>::iterator i = m.find("Hello");
    assert(i != m.end());
    std::cout << "Key: " << i->first << " Value: " << i->second << '\n';

    return 0;
}
