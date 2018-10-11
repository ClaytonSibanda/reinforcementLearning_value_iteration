#include <iostream>
#include "state.h"
#include <vector>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    int discount_factor=0.8;



    vector<vector<state> > grid;

    for(int i=0;i<2;i++){

        for(int j=0;j<3;j++){
            state s(0);
            vector<state> v;
            v.push_back(s);
            grid.push_back(v);
        }

    }


    return 0;
}