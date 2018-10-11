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

    std::map<char,double> action_reward;



public:
    std::vector<double> policies;
    state(double _optimal_policy):optimal_policy(_optimal_policy){  }

    double getOptimal_policy() const {
        return optimal_policy;
    }

    const std::vector<double> &getPolicies() const {
        return policies;
    }

    double do_action(std::vector<std::vector<state>> grid,int i,int j,char action,int numIteration ){
        bool donothing = false;
        double val =0;
        std::vector<double> vals;

        switch(action){
            case 'R':
                if(j==2){
                    j=j;
                    donothing = true;
                }
                else{
                    j=j+1;
                }
                break;
            case 'L':
               if(j==0){
                   j=j;
                   donothing = true;
               }
               else{
                   j=j-1;
               }
                break;
            case 'D':
                if(i==0){
                    i=i;
                    donothing=true;
                } else{
                    i=i-1;
                }

                break;

            case 'U':
                if(i==1){
                    i=i;
                    donothing=true;
                } else{
                    i=i+1;

                }



        }

        //std::cout<<"action= "<<action<<" i= "<<i<<" j= "<<j<<std::endl;
        if(numIteration==0 || donothing){
            val=0;
        } else {
            val=grid[i][j].getPolicies()[numIteration - 1];
        }

   return val; }

};


#endif //REINFORCEMENTLEARNING_STATE_H
