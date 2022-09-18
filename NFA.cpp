#include "NFA.h"
//
// Created by Bertrand on 2022/9/16.
//
//

using namespace std;

node::node(){
    state_last_point = 0;
    for(auto i = 0; i < MAX_NODE; i++) {
        input[i] = "\0";
        next[i] = -1;
    }

}


NFA::NFA(){

    node single_46;

    node void_2_46, void_3_46, void_4_46, void_5_46;

    void_2_46.input[void_2_46.state_last_point] = "o";
    void_2_46.next[void_2_46.state_last_point++] = 2;
    void_2_46.input[void_2_46.state_last_point] = "letter/digit";
    void_2_46.next[void_2_46.state_last_point++] = 0;

    void_3_46.input[void_3_46.state_last_point] = "i";
    void_3_46.next[void_3_46.state_last_point++] = 3;
    void_3_46.input[void_3_46.state_last_point] = "letter/digit";
    void_3_46.next[void_3_46.state_last_point++] = 0;

    void_4_46.input[void_4_46.state_last_point] = "d";
    void_4_46.next[void_4_46.state_last_point++] = 4;
    void_4_46.input[void_4_46.state_last_point] = "letter/digit";
    void_4_46.next[void_4_46.state_last_point++] = 0;

    void_5_46.input[void_5_46.state_last_point] = "letter/digit";
    void_5_46.next[void_5_46.state_last_point++] = 0;

    single_46.input[single_46.state_last_point] = "letter/digit";
    single_46.next[single_46.state_last_point++] = 0;

    node_set.push_back(single_46);
    node_set.push_back(void_2_46);
    node_set.push_back(void_3_46);
    node_set.push_back(void_4_46);
    node_set.push_back(void_5_46);


}


std::set<string> set_of_restricted_words({"void", "int", "float", "double", "if", "else", "for", "do", "while"});
std::set<string> set_of_valid_symbols({"+", "-", "*", ";", ",", "(", ")", "{", "}", ">", "<", "=", "!", "\\"});
// define valid symbol
set<char> set_of_valid_symbols_c({'+', '-', '*', ';', ',', '(', ')', '{', '}', '>', '<', '=', '!', '\\'});
// define type identifier num

//Warning:(12, 13) Clang-Tidy: Initialization of 'set_of_restricted_words' with static storage duration may throw an exception that cannot be caught

void NFA::get_map_of_type(){
    int p = 1;
    map_of_type.insert({p++, "IDENTIFIER"});
    map_of_type.insert({p++, "NON-SIG-INT"});
    map_of_type.insert({p++, "SINGLE-BOUNDARY"});
    map_of_type.insert({p++, "DOUBLE-BOUNDARY"});
    for(auto i = set_of_valid_symbols.begin(); i != set_of_valid_symbols.end() ; i++, p++)
        map_of_type.insert(map_of_type.end(), {p, *i});
    for(auto i = set_of_restricted_words.begin(); i != set_of_restricted_words.end() ; i++, p++)
        map_of_type.insert(map_of_type.end(), {p, *i});
}

bool is_a_valid_char(char c){
    if(isalpha(c) || isalnum(c))
        return true;
    return set_of_valid_symbols_c.find(c) != set_of_valid_symbols_c.end();
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

bool is_blank(std::string actual_input){
    return actual_input[0] == '\t' || actual_input[0] == ' ' || actual_input[0] == '\n';
}

bool is_symbol(const string& str){
    return set_of_valid_symbols.find(str) != set_of_valid_symbols.end();
}

// return the length of valid part
int NFA::runs_NFA(std::string &buf, int cur_state, int length) {

    // prerequisite: buf is full (except the ending part), so there is no space for other words.
    if(length >= buf.length()){
        cout << cur_state << endl;
        return length;
    }

    if(is_blank(string(1, buf[length]))) {
        return length;
    }

    for(int i = 0; i < node_set[cur_state].state_last_point; i++){
        if(match_the_input(node_set[cur_state].input[i], buf.substr(length, 1))){
            return runs_NFA(buf, node_set[cur_state].next[i], length+1);
        }
    }

    if(isalpha(buf[length]) && is_symbol(string(1, buf[length+1]))){
        cout << cur_state << endl;
        return length;
    }

    if(is_symbol(string(1, buf[length])) && isalpha(buf[length+1])){
        cout << cur_state << endl;
        return length;
    }

    return -1;
}



