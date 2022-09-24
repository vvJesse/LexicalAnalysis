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
    std::string name;
    std::string input[MAX_NODE];
    int next[MAX_NODE];
    int state_last_point;

    node(std::string str, std::vector<std::string> &vec, std::vector<int> &n_vec, std::vector<node> &set_of_node);

};

class DFA {
public:
    std::vector<node> set_of_node;
    std::map<std::string, int> out_type_map;
    std::map<char, int> map_of_char;
    int judge_a_word(std::string buf);
    int find_end(const std::string& buf, int cur_state, int matched_length);
    int out_type(std::string &buf);
    void set_all_nodes();
    void set_map();
    void run_DFA(std::string &filename);

};



