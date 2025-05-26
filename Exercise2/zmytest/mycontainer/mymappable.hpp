#ifndef MYMAPPABLE_HPP
#define MYMAPPABLE_HPP
#include <string>
#include <algorithm>
#include <cmath>

void AppendDot(std::string& s) {
    s += ".";
}

void ToLowerStr(std::string& s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](char c){ return std::tolower(static_cast<unsigned char>(c)); });
}

void ShiftChar(char& c) {
    c = c + 1;
}

void ToUpperChar(char& c) {
    c = std::toupper(static_cast<unsigned char>(c));
}

void Reciprocal(double& val) {
    if (val != 0.0) val = 1.0 / val;
}

void RoundDouble(double& val) {
    val = std::round(val);
}

void SquareInt(int& val) {
    val *= val;
}

void IncrementInt(int& val) {
    val++;
}

#endif