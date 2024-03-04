#pragma once
class Student
{
private:
	char Name[10];
	float MathematicsGrade;
	float EnglishGrade;
	float HistoryGrade;	
public:
	void SetName(const char *name);
	char *GetName();
	void SetMathematicsGrade(float grade);
	float GetMathematicsGrade();
	void SetEnglishGrade(float grade);
	float GetEnglishGrade();
	void SetHistoryGrade(float grade);
	float GetHistoryGrade();
	float RetrieveAverageGrade();
};	

