#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <set>
#include <map>
#include "NFA.h"
#define MAX_IDENTIFIER 32
using namespace std;

map<int, string> map_of_type;
set<string> set_of_restricted_words({"void", "int", "float", "double", "if", "else", "for", "do", "while"});
set<string> set_of_valid_symbols({"+", "-", "*", ";", ",", "(", ")", "{", "}", ">", "<", "=", "!", "\\"});
// define valid symbol
set<char> set_of_valid_symbols_c({'+', '-', '*', ';', ',', '(', ')', '{', '}', '>', '<', '=', '!', '\\'});
// define type identifier num


void get_map_of_type(){
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

int main() {

    //open file

    //Scanner, and buff

//    get_map_of_type();
//    for(auto & i : map_of_type)
//        cout << i.first << "------------>" << i.second << endl;
    NFA nfa;

    return 0;
}