//
// Created by Lenovo-User on 2018/10/11.
//

#ifndef REINFORCEMENTLEARNING_STATE_H
#define REINFORCEMENTLEARNING_STATE_H

#include <vector>
#include <string>
#include <map>

class state {

    double optimal_policy;
    std::vector<double> policies;
    std::map<char,double> action_reward;



public:
    state(double _optimal_policy):optimal_policy(_optimal_policy){  }

    double getOptimal_policy() const {
        return optimal_policy;
    }

    const std::vector<double> &getPolicies() const {
        return policies;
    }

    std::vector<double>& do_action(std::vector<std::vector<state>> grid,int i,int j,char action,int numIteration ){
        std::vector<double> vals;
        switch(action){
            case 'R':
                i=i+1>=grid.size()?i:i+1;
                break;
            case 'L':
                i=0<i-1?i:i-1;
            case 'D':
                if(j)
                j=0<j-1?j:j-1;

            case 'U':
                j=j+1>=grid[0].size()?j:j+1;


        }
vals.push_back(0);
vals.push_back(grid[i][j].getPolicies()[numIteration-1]);

   return vals; }

};


#endif //REINFORCEMENTLEARNING_STATE_H
