#include "Student.h"
#include <cstdio>
void Student::SetName(const char *name) {
	int i = 0;
	int j = 0;
	while (name[i] != '\0')
		i++;
	for ( j = 0; j < i; j++)
		Name[j] = name[j];
	Name[j] = '\0';
}
char *Student::GetName() {
	return Name;
}
void Student::SetMathematicsGrade(float grade) {
	MathematicsGrade = grade;
}
float Student::GetMathematicsGrade() {
	return MathematicsGrade;
}
void Student::SetEnglishGrade(float grade) {
	EnglishGrade = grade;
}
float Student::GetEnglishGrade() {
	return EnglishGrade;
}
void Student::SetHistoryGrade(float grade) {
	HistoryGrade = grade;
}
float Student::GetHistoryGrade() {
	return HistoryGrade;
}
float Student::RetrieveAverageGrade() {
	return (MathematicsGrade + EnglishGrade + HistoryGrade) / 3;
}