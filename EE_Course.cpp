//
// Created by josh on 1/5/19.
//

#include <cstring>
#include <cmath>
#include <iostream>
#include "EE_Course.h"

EE_Course::EE_Course(int Course_Num, char *Course_Name, int Num_Of_HW, double HW_Weight):
        Course(Course_Num,Course_Name,Num_Of_HW,HW_Weight), Factor(0){

}

int EE_Course::getFactor() const {

    return Factor;

}

bool EE_Course::setFactor(int Fact) {


    Factor=Fact;
    return true;
}

int EE_Course::getCourseGrade() const {

    int grade=0;

    grade= round((1-getHwWeigh())*getExamGrade() + getHwWeigh()*getHwAverage())+getFactor();

    if (grade>=100) return 100;
    if (grade<=0) return 0;
    else return grade;

}



