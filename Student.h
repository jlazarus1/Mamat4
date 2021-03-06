//
// Created by Or David on 04/01/2019.
//

#ifndef HW4_STUDENT_H
#define HW4_STUDENT_H

#include "Person.h"
#include "Course.h"
#include "EE_Course.h"
#include "CS_Course.h"
#include "Proj.h"
#include "EE_Course.h"

class Student : public Person {

private:
    int EE_C_num;
    int CS_C_num;
    Course** EE_C_array;
    Course** CS_C_array;


public:
    Student(int id_, char *name_);
    ~Student();
    int get_CourseCnt();
    int addEE_Course(Course* pEE_C);
    int addCS_Course(Course* pCS_C);
    int remCourse(int c_num);
    EE_Course* getEE_Course (int c_num);
    CS_Course* getCS_Course (int c_num);
    int getAvg();
    void print();

};
#endif //HW4_STUDENT_H
