#include "FileLabelGenerator.h"

ostream &operator<<(ostream &lhs, const FileLabelGenerator &rhs) {
    cout << rhs.label;
    return lhs;
}

FileLabelGenerator::FileLabelGenerator(const string &label, const int &number, const char *labels_file) {
    this->label = label;
    this->number = number;
    this->labels_file = labels_file;

    ifstream input_file(labels_file);


    if (!input_file.is_open()) {
        cerr << "Unable to open labels file." << endl;
        label_texts.emplace_back("UNDEFINED TEXT");
    } else {
        while (!input_file.eof()) {
            string text;
            getline(input_file, text);
            label_texts.emplace_back(text);
        }
    }
    input_file.close();
}

FileLabelGenerator FileLabelGenerator::nextLabel() {
    FileLabelGenerator temp {label, number, labels_file};
    temp.label = label + " " + to_string(number) + " " + label_texts[i];
    ++number;
    ++i;
    return temp;
}
