//
// Created by josh on 1/1/19.
//

#include <cstring>
#include <cmath>
#include <iostream>
#include "Course.h"


Course::Course(int Course_Num, char *Course_Name, int Num_Of_HW, double HW_Weight):
Number(Course_Num),Num_Of_HW(Num_Of_HW),HW_weight(HW_Weight){
    int tmp;
    tmp = strlen(Course_Name);
    Name = new char[tmp+1];
    strcpy(Name,Course_Name);
    HW_Grades = new int[Num_Of_HW+1];

}




Course::~Course() {

    delete []Name;
    delete []HW_Grades;

}


int Course::getNum() const {

    return Number;

}

char* Course::getName() const {
    int size;
    char* Name_return;
    size = strlen(Name);
    Name_return = new char[size+1];
    strcpy(Name_return,Name);
        return Name_return;
}

int Course::getExamGrade() const {

    return Exam_Grade;

}

int Course::getHwGrade(int Hw_Num) const {

    return HW_Grades[Hw_Num];

}

int Course::getHwNum() const {

    return Num_Of_HW;
}

double Course::getHwWeigh() const {

    return HW_weight;

}


double Course::getHwAverage() const {

    int tmp=0;
    int i=0;

    for (i=0;i<Num_Of_HW; i++){
        tmp+=HW_Grades[i];
    }
    if (Num_Of_HW==0)
        return 0;
    else
    return ((double)tmp/(double)Num_Of_HW);
}

int Course::getCourseGrade() const {


    return round((1 - HW_weight) * Exam_Grade + HW_weight * getHwAverage());
}

bool Course::setExamGrade(int Grade) {


    Exam_Grade=Grade;
    if (Exam_Grade==Grade)
        return true;
    else
        return false;
}

bool Course::setHwGrade(int &HW, int Grade) {
    if (HW<getHwNum() && HW>=0) {
        HW_Grades[HW] = Grade;
        return true;
    }
    else return false;
}
