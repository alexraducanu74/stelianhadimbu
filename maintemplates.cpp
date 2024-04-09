#include <iostream>
#include "Templates.h"
using namespace std;

float operator"" _Kelvin(unsigned long long int x) {
    return (float(x) - 273.15);
}
float operator"" _Fahrenheit(unsigned long long int x) {
    return ((float(x) - 32) / 1.8);
}

template<typename T>
bool compare(T a, T b)
{
    return a < b;
}

int main() {
    float a = 300_Kelvin;
    float b = 120_Fahrenheit;
    cout << "Kelvin "<< a << " Fahrenheit " << b << endl;
    Node<int> root(1);
    root.add_node(2, &root);
    root.add_node(3, &root);
    root.add_node(4, &root);
    root.add_node(25, &root);
    cout << "DFS peste tot" << endl;
    cout << "initial:" << endl;
    root.print();
    cout << endl; 
    cout << "sterg copilul de pe poz 1:" << endl;
    root.delete_node(root.GetChildren()[1]);
    root.print();
    cout << endl;
    cout << "find(2):" << endl;
    Node<int> *g = root.find(2);
    cout << g->GetValue();
    cout << endl;
    cout << "inseram nodul gasit anterior pe poz 1:" << endl;
    root.insert(30, 1, &root);
    root.print(); 
    cout << endl;
    int count = 0;
    cout << "count(apelat pe root):" << endl;
    count=root.get_count();
    cout << count;
    cout << endl;
 //   root.add_node(25, root.GetChildren()[1]);
    cout << "find(25)" << endl;
    Node<int>* f = root.find(25);
    cout << f->GetValue();
    cout << endl;
    cout << "adaugam 7 ca copil al primului 2 gasit:" << endl;
    root.add_node(7, f);
    root.print();
    cout << endl;
    root.add_node(1, &root);
    cout << "adaugam 1 direct pe root:" << endl;
    root.print();
    cout << endl;
    cout << "sortam:" << endl;
    root.sort(compare);
    root.print();
    cout << endl;
    cout << "sterg radacina:" << endl;
    root.delete_node(&root);
    root.print();
    return 0;

  
}