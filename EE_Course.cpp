//
// Created by josh on 1/5/19.
//

#include <cstring>
#include <cmath>
#include "EE_Course.h"

EE_Course::EE_Course(int Course_Num, char *Course_Name, int Num_Of_HW, int HW_Weight):
        Course(Course_Num,Course_Name,Num_Of_HW,HW_Weight), Factor(0){

}

int EE_Course::getFactor() const {

    return Factor;

}

bool EE_Course::setFactor(int Fact) {

    return Factor=Fact;

}

int EE_Course::getCourseGrade() const {

    int grade=0;

    grade=((1-getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage())+0.5+getFactor();

    if (grade>=100) return 100;
    else return grade;

}



