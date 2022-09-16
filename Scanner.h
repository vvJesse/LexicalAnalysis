//
// Created by Bertrand on 2022/9/16.
//

#ifndef LEXICALANALYSIS_SCANNER_H
#define LEXICALANALYSIS_SCANNER_H

#include <iostream>
#define ID_MAXLENGTH 32
#define BUFSIZE 64
using namespace std;

class Scanner {
    string buffer;
    string checked_part;
    int state;
};


#endif //LEXICALANALYSIS_SCANNER_H
