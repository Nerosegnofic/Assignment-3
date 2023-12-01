#ifndef LABELGENERATOR_H
#define LABELGENERATOR_H

#include <bits/stdc++.h>

using namespace std;

class LabelGenerator {
    friend ostream &operator<<(ostream &lhs, const LabelGenerator &rhs);
protected:
    string label;
    int number;
public:
    LabelGenerator() : label{"Undefined Label"}, number{0} {}
    LabelGenerator(string label, int number) : label{std::move(label)}, number{number} {}
    LabelGenerator nextLabel();
};

#endif //LABELGENERATOR_H
