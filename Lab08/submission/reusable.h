/*
* AUTHOR: ASHWIN ABRAHAM
*/

#ifndef REUSABLE_H
#define REUSABLE_H

#include <string>
#include <fstream>
#include <cassert>

#define num_keywords 53
#define num_symbols 21



//if the logic in both C++ files is similiar, then the number of each key word will be similiar
//this logic is used for detecting plagiarism
const std::string keywords[num_keywords] = {"asm", "auto", "break", "case", "catch", "char", "cin", "class", "const", "continue", "cout", "default", "delete",
"do", "double", "else", "enum", "extern", "float", "for", "friend", "goto", "if", "inline", "include", "else", "long", "new", "operator", "private", 
"protected", "public", "register", "return", "short", "signed", "sizeof", "static", "string", "struct", "switch", "template", "this", "throw", "try", 
"typedef", "union", "unsigned", "vector", "virtual", "void", "volatile", "while"};



//If the logic in both C++ files is similiar, then the number of symbols would be similiar
const char symbols[num_symbols] = {'+', '-', '!', '#', '%', '^', '&', '=', '~', '|', '\\', ';', ':', '\'', '\"', '.', ',', '/', '<', '>', '?'};


class File {
    private:
        int keyword_occurrences[num_keywords];
        long long int num_char;
        int num_brackets[3]; //(), [], {}
        int symbol_occurrences[num_symbols];

    public:
        File(const std::string& filename): num_char(0)
        {
            for(int i = 0; i<num_keywords; ++i) keyword_occurrences[i] = 0;
            for(int i = 0; i<3; ++i) num_brackets[i] = 0;
            for(int i = 0; i<num_symbols; ++i) symbol_occurrences[i] = 0;

            std::ifstream file;
            file.open(filename);
            std::string line;
            while(std::getline(file, line))
            {

                for(int i = 0; i<num_keywords; ++i)
                {
                    for(std::size_t found = 0; line.find(keywords[i], found) != std::string::npos; ++found) ++keyword_occurrences[i];
                }

                for(int i = 0; i<line.length(); ++i)
                {
                    switch (line[i])
                    {
                        case '(':
                            ++num_brackets[0];
                            break;
                        
                        case '[':
                            ++num_brackets[1];
                            break;
                        
                        case '{':
                            ++num_brackets[2];
                            break;
                    }

                    for(int j = 0; j<num_symbols; ++j)
                    {
                        if(line[i] == symbols[j])
                        {
                            ++symbol_occurrences[j];
                            break;
                        }
                    }
                }

                num_char+=line.length();
            }

            file.close();
        }



        int operator[](int i) const
        {
            assert(i>=0);
            assert(i<num_keywords);
            return keyword_occurrences[i];
        }


        int symbol_occurrence(int i) const
        {
            assert(i>=0);
            assert(i<num_symbols);
            return symbol_occurrences[i];
        }


        int bracket_occurrence(char c) const
        {
            assert(c == '(' || c == '[' || c == '{');

            switch(c)
            {
                case '(':
                    return num_brackets[0];
                case '[':
                    return num_brackets[1];
                case '{':
                    return num_brackets[2];
                
                default:
                    assert(false);
            }
            assert(false);
        }


        long long int length() const
        {
            return num_char;
        }
};



int checksimilarity(const File&, const File&);

#endif