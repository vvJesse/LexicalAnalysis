//
// Created by Bertrand on 2022/9/16.
//
//

#include "NFA.h"


node::node(){
    state_last_point = 0;
    for(auto & i : next)
        i = nullptr;

}


NFA::NFA(){

    node single_46;

    node void_2_46, void_3_46, void_4_46, void_5_46;

    void_2_46.input[void_2_46.state_last_point] = "o";
    void_2_46.next[void_2_46.state_last_point++] = &void_3_46;
    void_2_46.input[void_2_46.state_last_point] = "letter/digit";
    void_2_46.next[void_2_46.state_last_point++] = &single_46;

    void_3_46.input[void_3_46.state_last_point] = "i";
    void_3_46.next[void_3_46.state_last_point++] = &void_4_46;
    void_3_46.input[void_3_46.state_last_point] = "letter/digit";
    void_3_46.next[void_3_46.state_last_point++] = &single_46;

    void_4_46.input[void_4_46.state_last_point] = "d";
    void_4_46.next[void_4_46.state_last_point++] = &void_5_46;
    void_4_46.input[void_4_46.state_last_point] = "letter/digit";
    void_4_46.next[void_4_46.state_last_point++] = &single_46;

    void_5_46.input[void_5_46.state_last_point] = "letter/digit";
    void_5_46.next[void_5_46.state_last_point++] = &single_46;

    single_46.input[single_46.state_last_point] = "letter/digit";
    single_46.next[single_46.state_last_point++] = &single_46;

    node_set.push_back(single_46);
    node_set.push_back(void_2_46);
    node_set.push_back(void_3_46);
    node_set.push_back(void_4_46);
    node_set.push_back(void_5_46);


}

bool match_the_input(std::string &require_input, std::string actual_input){
    if(actual_input == require_input)
        return true;
    else if(require_input == "letter")
        return isalpha(actual_input[0]);
    else if(require_input == "digit")
        return isalnum(actual_input[0]);
    else if(require_input == "letter/digit")
        return isalnum(actual_input[0]) || isalpha(actual_input[0]);
    else
        return false;
}

//bool is_blank(std::string actual_input){
//    if (actual_input[0])
//}


int NFA::runs_NFA(std::string &buf) {
    for(int i = 0; i < MAX_IDENTIFIER && i < buf.length(); i++){

    }
}



