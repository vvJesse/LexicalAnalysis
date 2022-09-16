//
// Created by Bertrand on 2022/9/16.
//
//

#include "NFA.h"


node::node(){
    next = nullptr;
    state_last_point = 0;
    for (int i = 0; i < MAX_NODE; ++i)
        state[i] = 0;
}

void void_set_NFA(std::vector<node> node_set){
    node void_2_46;
    void_2_46.state[void_2_46.state_last_point++] = 2;
    void_2_46.state[void_2_46.state_last_point++] = 46;

    node void_3_46;
    void_3_46.state[void_3_46.state_last_point++] = 3;
    void_3_46.state[void_3_46.state_last_point++] = 46;

    node void_4_46;
    void_4_46.state[void_4_46.state_last_point++] = 4;
    void_4_46.state[void_4_46.state_last_point++] = 46;

    node void_5_46;
    void_5_46.state[void_5_46.state_last_point++] = 5;
    void_5_46.state[void_5_46.state_last_point++] = 46;

    void_2_46.next = &void_3_46;
    void_3_46.next = &void_4_46;
    void_4_46.next = &void_5_46;

    node_set.push_back({void_2_46});
    node_set.push_back({void_3_46});
    node_set.push_back({void_3_46});
    node_set.push_back({void_4_46});
}

NFA::NFA(){

    void_set_NFA();


}




