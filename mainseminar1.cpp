#include "NumberList.h"
#include "Student.h"
#include "Functions.h"
#include <iostream>
int main()
{
    NumberList ListaNumere;
    ListaNumere.Init();
    ListaNumere.Add(10);
    ListaNumere.Add(7);
    ListaNumere.Add(9);
    ListaNumere.Print();
    ListaNumere.Sort();
    ListaNumere.Print();
    
    Student student1,student2;
    student1.SetName("Andrei");
    student1.SetEnglishGrade(5);
    student1.SetMathematicsGrade(6);
    student1.SetHistoryGrade(7);
    student2.SetName("Andrei");
    student2.SetEnglishGrade(10);
    student2.SetMathematicsGrade(6);
    student2.SetHistoryGrade(3);
    std::cout << student1.GetName()<< " ";
    std::cout << student1.GetMathematicsGrade() << " ";
    std::cout << student1.GetHistoryGrade() << " ";
    std::cout << student1.GetEnglishGrade() << " ";
    std::cout << student1.RetrieveAverageGrade() << " ";
    
    std::cout << CompareNames(student1, student2) << " ";
    std::cout << CompareMathematicsGrades(student1, student2) << " ";
    std::cout << CompareHistoryGrades(student1, student2) << " ";
    std::cout << CompareEnglishGrades(student1, student2) << " ";
    std::cout << CompareAverageGrades(student1, student2) << " ";



    return 0;
}
