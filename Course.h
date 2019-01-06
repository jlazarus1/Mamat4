//
// Created by josh on 1/1/19.
//

#ifndef HW4_COURSE_H
#define HW4_COURSE_H


class Course {

private:

int Number;
char *Name;
int Num_Of_HW;
float HW_weight;
int Exam_Grade;
int *HW_Grades;

public:

    Course(int Course_Num, char *Course_Name, int Num_Of_HW, int HW_Weight);


    virtual ~Course();
    int getNum() const;
    char* getName() const;
    int getExamGrade() const;
    int getHwGrade(int Hw_Num) const;
    int getHwNum() const;
    float getHwWeigh() const;
    float getHwAverage() const;
    virtual int getCourseGrade() const;
    bool setExamGrade(int Grade);
    bool setHwGrade(int &HW, int Grade);


};


#endif //HW4_COURSE_H
