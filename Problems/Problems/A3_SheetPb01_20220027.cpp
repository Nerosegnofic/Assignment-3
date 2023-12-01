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

ostream &operator<<(ostream &lhs, const LabelGenerator &rhs) {
    cout << rhs.label << " " << rhs.number;
    return lhs;
}

LabelGenerator LabelGenerator::nextLabel() {
    LabelGenerator temp {label, number};
    ++number;
    return temp;
}

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

int main() {
    LabelGenerator figureNumbers("Figure", 1);
    LabelGenerator pointNumbers("P", 0);

    cout << "Figure numbers: ";
    for (int i {0}; i < 3; ++i) {
        cout << figureNumbers.nextLabel();
        if (i != 2) {
            cout << ", ";
        } else {
            continue;
        }
    }

    cout << endl << "Point numbers: ";
    for (int i {0}; i < 5; ++i) {
        cout << pointNumbers.nextLabel();
        if (i != 4) {
            cout << ", ";
        } else {
            continue;
        }
    }

    cout << endl << "More figures: ";
    for (int i {0}; i < 3; ++i) {
        cout << figureNumbers.nextLabel();
        if (i != 2) {
            cout << ", ";
        } else {
            continue;
        }
    }
    cout << endl;

    FileLabelGenerator figureLabels ("Figure", 1, "labels.txt");

    cout << "\nFigure labels: \n";
    for (int i {0}; i < 3; i++) {
        cout << figureLabels.nextLabel() << endl;
    }

    return 0;
}
