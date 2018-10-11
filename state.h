//
// Created by Lenovo-User on 2018/10/11.
//

#ifndef REINFORCEMENTLEARNING_STATE_H
#define REINFORCEMENTLEARNING_STATE_H

#include <vector>
#include <string>
class state {

    double optimal_policy;
    std::vector<double> policies;



public:
    state(double _optimal_policy):optimal_policy(_optimal_policy){  }

    double getOptimal_policy() const {
        return optimal_policy;
    }

    const std::vector<double> &getPolicies() const {
        return policies;
    }

    double do_action(std::vector<std::vector<state>> grid,int i,int j,std::string direction ){

    }

};


#endif //REINFORCEMENTLEARNING_STATE_H
