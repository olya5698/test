#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int str_to_int(string str){
    stringstream sstr;
    int int_val;
    if (str.empty())
        return 0;
    sstr << str;
    sstr >> int_val;
    return int_val;
}

int main(int argc, char* argv[]) {
    int i = 2, pos = 0, flag, n, ind, fnum;
    string s, command, N, field;
    ifstream fin(argv[1]);
    while (getline(fin, s)) {
        while (i < argc) {
            command = argv[i];
            if (command[command.size() - 2] == ':') {
                int num = command.find(':', 0);
                N = command.substr(0, num);
                pos = str_to_int(N);
                if (command[command.size() - 1] == 'u') {
                    flag = 0;
                } else if (command[command.size() - 1] == 'U') {
                    flag = 1;
                }
            }
            stringstream ss(s);
            n = 0;
            while (getline(ss, field, '\t')) {
                if (n == pos) break;
                n++;
            }
            string::iterator it = s.begin();
            string::iterator it1 = s.begin();
            it++;
            fnum = 0;
            ind = 1;
            while (it != s.end()){
                if (((*it) != '\t') && (((*it1) == '\t') /*|| (it1 == s.begin())*/)) {
                    fnum++;
                }
                if (fnum == pos) {
                    if (flag == 1)
                        transform(field.begin(), field.end(), field.begin(), ::toupper);
                    else if (flag == 0)
                        transform(field.begin(), field.end(), field.begin(), ::tolower);
                    //cout << field << endl;
                    s.replace(ind, field.size(), field);
                    break;
                }
                it++;
                it1++;
                ind++;
            }
            i++;
        }
        cout << s << endl;
        i = 2;
    }
    fin.close();
    return 0;
}
