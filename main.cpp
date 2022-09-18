#include <iostream>

#include "NFA.h"
#define MAX_IDENTIFIER 32
using namespace std;



int main() {

    //open file

    //Scanner, and buff

    NFA nfa;
    string test = "oi>df";
    string test2 = "oid2";
    string buf = "oid";
    node* o_begin = &nfa.node_set.at(1);
    nfa.get_map_of_type();
//    for(const auto & i : nfa.map_of_type){
//        cout << i.first << "  " << i.second << endl;
//    }
    cout << nfa.runs_NFA(test, 1, 0);

    return 0;
}