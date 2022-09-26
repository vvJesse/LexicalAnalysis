#include <iostream>

#include "DFA.h"

using namespace std;


int main() {
    DFA lex;
    lex.set_all_nodes();
    lex.set_map();

    string filename1 = "test1.txt";
    string fname1 = lex.clear_annotation(filename1);
    lex.run_DFA(fname1);


    string filename2 = "test2.txt";
    string fname2 = lex.clear_annotation(filename2);
    lex.run_DFA(fname2);

    system("pause");
    return 0;
}