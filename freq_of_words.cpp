// Tokenizing a string using stringstream 
#include <string>
#include <cctype>
#include <map>
#include <iostream>

using namespace std;

string to_lower(string s) {
    string ret_val;
    string::iterator iter = s.begin(),
        iter_end = s.end();
    for (; iter_end != iter; ++iter) {
        ret_val += tolower(*iter);
    }
    return ret_val;
}
int main(int argc, char** argv){
    string line = "The cat in the hat.";

    string sline = line;
    string lower_case_str = to_lower(sline);

    char separators[] = " ,\t\n;.";
    char* token, * next_token;
    
    // Table that keeps track of words vs. count of occurence
    map<string, int> m;
    token = strtok_s((char*)(lower_case_str.c_str()), separators, &next_token); 

    // Step 1: Break it up into tokens.
    while (token != NULL){
        if (token != NULL) {
            // If the word is already in the map..
            if (m.find(token) != m.end()) { 
                m[token] += 1;
            }
            else { // This word has not been seen before.
                m[token] = 1;
            }
            token = strtok_s(NULL, separators, &next_token);
        }

    }
    // Display the results by iterating through the map entries.
    map<string, int>::iterator iter = m.begin(),
        iter_end = m.end();
    for (; iter_end != iter; ++iter) {
        cout << "<" << (*iter).first << "," << (*iter).second << ">";
    }
    cout << endl;

    return 0;
}