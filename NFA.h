//
// Created by Bertrand on 2022/9/16.
//

#include <iostream>
#include <vector>

#ifndef LEXICALANALYSIS_NFA_H
#define LEXICALANALYSIS_NFA_H


#define MAX_NODE 5
#define MAX_IDENTIFIER 32
#endif //LEXICALANALYSIS_NFA_H



class node{
public:
    std::string input[MAX_NODE];
    node* next[MAX_NODE];
    int state_last_point;

    node();
};


class NFA {
public:
    std::vector<node> node_set;
    std::vector<node> z_set;
    NFA();
    int runs_NFA(std::string &buf);

};

void void_set_NFA();