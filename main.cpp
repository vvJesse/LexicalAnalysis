#include <iostream>

#include "DFA.h"
#define MAX_IDENTIFIER 32
using namespace std;



int main() {

    DFA lex;
    lex.set_all_nodes();
    lex.set_map();
    string filename = "hhh.txt";
    lex.run_DFA(filename);
    system("pause");
    return 0;
}