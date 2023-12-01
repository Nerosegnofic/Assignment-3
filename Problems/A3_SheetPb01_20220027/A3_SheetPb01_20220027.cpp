#include "FileLabelGenerator.h"

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

