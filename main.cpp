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

vector<char> actions={'R','L','U','D'};

    int iteration =0;
while(true){
    double policy=0;
    double max = -100;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();){
            for(char action:actions){
                policy= 0+discount_factor*(grid[i][j].do_action(grid,i,j,action,iteration)[1]);
                if(policy>max){
                    max=policy;

                }
            }
            vector<double> temp = grid[i][j].getPolicies();
           temp.push_back(max);
        }

    }

iteration++;

}

    return 0;
}