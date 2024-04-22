#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <cstring>
using namespace std;
ifstream fin("input.txt");

struct Compare {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) const {
        if (a.second != b.second)
            return a.second < b.second;
        else
            return a.first > b.first;
    }
};

int main() {
    string str;
    getline(fin, str);
    map<string, int> frecventa;
    istringstream finstring(str);
    string cuv;
    while (finstring >> cuv)
    {
        cuv.erase(remove_if(cuv.begin(), cuv.end(), ::ispunct), cuv.end());
        for (char& c : cuv)
            c = tolower(c);
        frecventa[cuv]++;
    }
    priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;
    for (const auto& cuvant : frecventa)
        pq.push(cuvant);
    while (!pq.empty())
    {
        cout << pq.top().first << " => " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}