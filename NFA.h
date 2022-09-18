//
// Created by Bertrand on 2022/9/16.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <set>
#include <map>
#include <vector>

#ifndef LEXICALANALYSIS_NFA_H
#define LEXICALANALYSIS_NFA_H


#define MAX_NODE 5
#define MAX_IDENTIFIER 32
#endif //LEXICALANALYSIS_NFA_H



class node{
public:
    std::string input[MAX_NODE];
    int next[MAX_NODE];
    int state_last_point;
    int is_z;

    node();
};


class NFA {
public:
    std::map<int, std::string> map_of_type;
    std::vector<node> node_set;
    std::vector<node> z_set;
    NFA();

    int runs_NFA(std::string &buf,  int cur_state, int length);
    void get_map_of_type();
};



