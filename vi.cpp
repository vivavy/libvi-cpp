#include <vi.hpp>

template<typename T>
T input() {
    T s;
    std::cin >> s;
    return s;
}

template<typename T>
T input(std::string prompt) {
    T s;
    std::cout << prompt;
    std::cin >> s;
    return s;
}

str::str(std::string s) : std::string(s) {}

str::str(char const *s) : std::string(s) {}

list<str> str::split(str delimiter) {
    list<str> s;
    std::string::size_type pos = 0;
    while ((pos = this->find(delimiter)) != std::string::npos) {
        s.append(this->substr(0, pos));
        this->erase(0, pos + delimiter.length());
    }
    s.append(this->substr(0, pos));
    return s;
}

int str::find(str s) {
    return std::string::npos != this->find(s);
}

int str::removeprefix(str s) {
    return this->erase(0, this->find(s));
}

int str::removesuffix(str s) {
    return this->erase(this->find(s));
}

str str::replace(str s, str t) {
    return this->replace(this->find(s), t.length(), t);
}

str str::strip() {
    return this->replace(str(" "), str(""));
}

str str::lstrip() {
    return this->replace(str(" "), str(""));
}

str str::rstrip() {
    return this->replace(str(" "), str(""));
}

str str::lower() {
    return this->replace(str(" "), str(""));
}

str str::upper() {
    str s = this->lower();
    for (int i = 0; i < s.length(); i++) {
        s[i] = std::toupper(s[i]);
    }
    return s;
}

bool str::isdigit() {
    return std::isdigit(this->at(0));
}

bool str::isalpha() {
    return std::isalpha(this->at(0));
}

bool str::isalnum() {
    return std::isalnum(this->at(0));
}

bool str::isspace() {
    return std::isspace(this->at(0));
}

bool str::contains(str s) {
    return this->find(s) != std::string::npos;
}

template<typename T>
void list<T>::append(T s) {
    this->push_back(s);
}

template<typename T>
void list<T>::insert(int i, T s) {
    this->insert(this->begin() + i, s);
}

template<typename T>
void list<T>::remove(int i) {
    this->erase(this->begin() + i);
}

template<typename T>
void list<T>::reverse() {
    std::reverse(this->begin(), this->end());
}

template<typename T>
void list<T>::sort() {
    std::sort(this->begin(), this->end());
}

template<typename T>
void list<T>::shuffle() {
    std::shuffle(this->begin(), this->end());
}

template<typename T>
T list<T>::pop() {
    T s = this->back();
    this->pop_back();
    return s;
}

template<typename T>
T list<T>::shift() {
    T s = this->front();
    this->pop_front();
    return s;
}

template<typename T>
int list<T>::index(T s) {
    return std::distance(this->begin(), std::find(this->begin(), this->end(), s));
}

template<typename T>
bool list<T>::contains(T s) {
    return std::find(this->begin(), this->end(), s) != this->end();
}

list<str> init(int argc, char **argv) {
    list<str> s;
    for (int i = 1; i < argc; i++) {
        s.append(argv[i]);
    }
    return s;
}
