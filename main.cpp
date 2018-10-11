    #include <iostream>
    #include "state.h"
    #include <vector>
    using namespace std;
    bool isStop(vector<vector<state> > &grid);
    int main() {
        double discount_factor=0.8;



        vector<vector<state> > grid;

        for(int i=0;i<2;i++){
            vector<state> v;
            for(int j=0;j<3;j++){
                state s(0);

                v.push_back(s);

            }
            grid.push_back(v);
        }

    vector<char> actions={'R','L','U','D'};
        int iteration =0;
    while(true){
        double policy=0;
        double max = -100;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
               // cout<<"Max is: "<<max<<endl;

                for(char action:actions){
                    double reward=0;


                    if(action=='D' && i==1 && j==2)
                        reward=50;
                    if(action =='R' && i==0 && j==1) {
                        reward =   100.0;
                    }
                  //specify for the policy state
                  if(i==0 && j==2)
                      policy=0;
                  else
                      policy= reward+discount_factor*(grid[i][j].do_action(grid,i,j,action,iteration));



                    if(policy>max){
                        max=policy;

                    }
                }
                 grid[i][j].policies.push_back(max);


            }

        }
   // cout<<"The max is: "<<max<<endl;
    iteration++;
if(iteration==101){

    break;
}

    }


    for(auto &v:grid){
        for(auto &state:v){
            cout<<state.policies[state.policies.size()-1]<<endl;
        }
    }

        return 0;
    }


    bool isStop(vector<vector<state> > &grid){
        cout<<"istop top"<<endl;
        for (auto &row : grid) {

            for(int j=0;j< row.size();j++){
                if(row[j].getPolicies()[row[j].getPolicies().size()-1]== row[j].getPolicies()[row[j].getPolicies().size()-2]){
                    cout<<"istop inside1"<<endl;

                    return true;
                }
                cout<<"istop inside2"<<endl;
            }
        }
        cout<<"istop bottom"<<endl;

        return false;

    }