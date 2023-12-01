#include <bits/stdc++.h>
using namespace  std;

class StringSet {
    multiset<string>words;
    set<string>distinctwords;
    vector<string>tokenization(string str);
public:
    void add(string word);
    void add(vector<string>linewords);
    void remove(string word);
    void clear();
    int Size();
    int distinct_size();
    void Print_words();
    void Print_distinctwords();
    StringSet();
    StringSet(string FileName , int x);
    StringSet(string str);
    StringSet operator+(StringSet& s2);
    StringSet operator*(StringSet& s2);
    double getSim(StringSet s2);
};

vector<string> StringSet::tokenization(string str) {
    vector<string>ret;
    string word = "";
    for(auto letter : str)
    {
        if(!isalpha((letter)))
        {
            if(!word.empty())
            {
                ret.emplace_back((word));
            }
            word = "";
            continue;
        }
        word += tolower(letter);
    }
    if(!word.empty())
        ret.emplace_back(word);
    return ret;
}

void StringSet::add(string word) {
    for(auto& l : word)
        l = tolower(l);
    words.insert(word);
    distinctwords.insert(word);
}

void StringSet::remove(string word) {
    auto it = words.find(word);
    if(it != words.end())
    {
        words.erase(it);
        if(!words.count(word))
        {
            distinctwords.erase(word);
        }
    }
}

void StringSet::clear() {
    distinctwords.clear();
    words.clear();

}

int StringSet::Size() {
    return words.size();
}

int StringSet::distinct_size() {
    return distinctwords.size();
}

void StringSet::Print_words() {
    for(auto word : words)
        cout<<word<<" ";
    cout<<'\n';

}

void StringSet::Print_distinctwords() {
    for(auto word : distinctwords)
        cout<<word<<" ";
    cout<<'\n';
}

StringSet::StringSet(string FileName, int x) {
    ifstream  InputFile(FileName);
    if(InputFile.is_open())
    {
        string line;
        while(getline(InputFile , line))
        {
            vector<string>linewords = tokenization(line);
            add(linewords);

        }
        InputFile.close();
    }
}

StringSet::StringSet(string str) {
    vector<string>temp = tokenization(str);
    add(temp);

}

void StringSet::add(vector<string> linewords) {
    words.insert(linewords.begin() , linewords.end());
    distinctwords.insert(linewords.begin() , linewords.end());

}

StringSet StringSet::operator+(StringSet &s2) {
    StringSet ret;
    for(auto w : this->words)
        ret.words.insert(w) , ret.distinctwords.insert(w);
    for(auto w : s2.words)
        ret.words.insert(w) , ret.distinctwords.insert(w);
    return ret;

}

StringSet StringSet::operator*(StringSet &s2) {
    StringSet ret;
    for(auto w : this->words)
        if(ret.words.count(w) < min(this->words.count(w) , s2.words.count(w)))
        {
            ret.words.insert(w);
            ret.distinctwords.insert(w);
        }
    return ret;
}

StringSet::StringSet() {

}

double StringSet::getSim(StringSet s2) {
    int cnt_words{};
    for(auto w : this->distinctwords)
        cnt_words += s2.distinctwords.count(w);
    double sqrt_sz1 = sqrt(distinct_size());
    double sqrt_sz2 = sqrt(s2.distinct_size());
    double denominator = sqrt_sz1 * sqrt_sz2;
    if(!denominator)
        return 0;
    return double (cnt_words / denominator);
}


int main() {
    StringSet s1("Hello World, my name is Ali Hello hello");
    StringSet s2("Hi world, my name is Ahmed. How are you doing?");
    StringSet s3;
    s3 = s1 * s2;
    StringSet s4 = s1 + s2;
    s4.Print_distinctwords();
    cout<< s4.distinct_size()<<'\n';
    s4.add("Ok");
    s4.Print_distinctwords();
    s4.remove("hello");
    s4.remove("ok");
    s4.remove("aa");
    s4.Print_distinctwords();
    cout<<s4.distinct_size()<<'\n';
    cout<<s4.Size()<<'\n';
   cout << s4.getSim(s3)<<'\n';

s4.clear();
cout<<s3.getSim(s4)<<'\n';
s3.Print_words();
s3.Print_distinctwords();
cout<<"Programm ended\n";
}
