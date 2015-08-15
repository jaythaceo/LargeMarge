//
//  main.cpp
//  GhostWriter
//
//  Created by Jason  Brooks on 8/15/15.
//  Copyright (c) 2015 Jason  Brooks. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int hour, minute;
    hour = 13;
    minute = 15;
    
    cout << "Number of minutes since midnight: ";
    cout << hour*60 + minute << endl;
    cout << "Fraction of the hour that has passed: ";
    cout << minute/60 << endl;
    cout << "Percentage of hour that has passed: ";
    cout << minute*100/60 << endl;
    
    
    return 0;
}
