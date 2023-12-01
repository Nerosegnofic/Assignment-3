#ifndef FILELABELGENERATOR_H
#define FILELABELGENERATOR_H

#include "LabelGenerator.h"

class FileLabelGenerator: public LabelGenerator {
    friend ostream &operator<<(ostream &lhs, const FileLabelGenerator &rhs);
private:
    const char *labels_file;
    vector <string> label_texts;
    size_t i {0};
public:
    FileLabelGenerator(const string &label, const int &number, const char *labels_file);
    FileLabelGenerator nextLabel();
};

#endif //FILELABELGENERATOR_H
