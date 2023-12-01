#include "LabelGenerator.h"

ostream &operator<<(ostream &lhs, const LabelGenerator &rhs) {
    cout << rhs.label << " " << rhs.number;
    return lhs;
}

LabelGenerator LabelGenerator::nextLabel() {
    LabelGenerator temp {label, number};
    ++number;
    return temp;
}
