#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <regex>

template<typename T>
class list : public std::vector<T> {
    public:
        void append(T s);
        void insert(int i, T s);
        void remove(int i);
        void reverse();
        void sort();
        void shuffle();
        T pop();
        T shift();
        int index(T s);
        bool contains(T s);
};

class str : public std::string {
    public:
        str(std::string s);
        str(char const *s);
        list<str> split(str delimiter);
        int find(str s);
        int removeprefix(str s);
        int removesuffix(str s);
        str replace(str s, str t);
        str strip();
        str lstrip();
        str rstrip();
        str lower();
        str upper();
        bool isdigit();
        bool isalpha();
        bool isalnum();
        bool isspace();
};

namespace vi {
    template<typename T>
    T input();
    template<typename T>
    T input(std::string prompt);
};

list<str> init(int, char **);
