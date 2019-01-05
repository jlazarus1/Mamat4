//
// Created by Or David on 04/01/2019.
//

#ifndef HW4_STUDENT_H
#define HW4_STUDENT_H

#include "Person.h"
#include "Course.h"
#include "Proj.h"

class Student : public Person:{
private:
    Course* EE_C_array[MAX_COURSE_NUM];
    int EE_C_num;
    Course* CS_C_array[MAX_COURSE_NUM];
    int CS_C_num;

public:
    Student();
    ~Student();
    int get_CourseCnt();
    bool addEE_Course(Course* pEE_C); //TODO check if bool is valid
    bool addCS_Course(Course* pCS_C);
    bool remCourse(int c_num);

};
#endif //HW4_STUDENT_H
