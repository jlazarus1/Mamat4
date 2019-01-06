//
// Created by josh on 1/5/19.
//

#ifndef HW4_EE_COURSE_H
#define HW4_EE_COURSE_H


#include "Course.h"

class EE_Course: public Course {

private:
    int Factor;

public:
    EE_Course(int Course_Num, char *Course_Name, int Num_Of_HW, int HW_Weight);
    int getFactor() const;
    bool setFactor(int Fact);
    int getCourseGrade() const;

};


#endif //HW4_EE_COURSE_H
