#include <bits/stdc++.h>

using namespace std;

template <class T>
class mySet {
private:
    vector <T> items;
public:
    mySet() = default;
    void add(T item) {
        if (find(items.begin(), items.end(), item) == items.end()) {
            items.emplace_back(item);
            sort(items.begin(), items.end());
        }
    }

    void remove(T item) {
        if (!items.empty() && find(items.begin(), items.end(), item) != items.end()) {
            items.erase(find(items.begin(), items.end(), item));
        }
    }

    size_t set_size() {
        return items.size();
    }

    bool isExistent(T item) {
        if (find(items.begin(), items.end(), item) != items.end()) {
            cout << item << " Exists" << endl;
            return true;
        }
        return false;
    }

    T *dynamic_array() {
        T *ptr = new T[items.size()];
        for (int i {0}; i < items.size(); ++i) {
            ptr[i] = items[i];
        }
        return ptr;
    }
};



int main() {
    mySet<int> ahmed;

    ahmed.add(1);
    ahmed.add(2);
    ahmed.add(3);
    ahmed.add(4);
    ahmed.add(5);
    ahmed.add(6);
    ahmed.add(7);

    ahmed.remove(8);
    ahmed.remove(1);

    cout << ahmed.set_size() << endl;

    ahmed.isExistent(5);

    int *ptr = ahmed.dynamic_array();

    for (size_t i {0}; i < ahmed.set_size(); ++i) {
        cout << ptr[i] << " ";
    }

    delete ptr;

    return 0;
}
