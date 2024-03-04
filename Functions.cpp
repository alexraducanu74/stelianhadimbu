#include "Functions.h"
int CompareNames(Student s1, Student s2) {
	int a = 0;
	int b = 0;
	while (s1.GetName()[a] != '\0')
		a++;
	while (s2.GetName()[b] != '\0')
		b++;
	if (a > b)
		a = b;
	for (int i = 0; i < a; i++)
	{
		if (s1.GetName()[i] > s2.GetName()[i])
			return 1;
		if (s1.GetName()[i] < s2.GetName()[i])
			return -1;
	}
	
	return 0;	
}
int CompareMathematicsGrades(Student s1, Student s2) {
	if (s1.GetMathematicsGrade() > s2.GetMathematicsGrade())
		return 1;
	if (s1.GetMathematicsGrade() < s2.GetMathematicsGrade())
		return -1;
	return 0;
}
int CompareEnglishGrades(Student s1, Student s2) {
	if (s1.GetEnglishGrade() > s2.GetEnglishGrade())
		return 1;
	if (s1.GetEnglishGrade() < s2.GetEnglishGrade())
		return -1;
	return 0;
}
int CompareHistoryGrades(Student s1, Student s2) {
	if (s1.GetHistoryGrade() > s2.GetHistoryGrade())
		return 1;
	if (s1.GetHistoryGrade() < s2.GetHistoryGrade())
		return -1;
	return 0;
}
int CompareAverageGrades(Student s1, Student s2) {
	if (s1.RetrieveAverageGrade() > s2.RetrieveAverageGrade())
		return 1;
	if (s1.RetrieveAverageGrade() < s2.RetrieveAverageGrade())
		return -1;
	return 0;
}