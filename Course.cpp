//
// Created by josh on 1/1/19.
//

#include <cstring>
#include <cmath>
#include "Course.h"


Course::Course(int Course_Num, char *Course_Name, int Num_Of_HW, int HW_Weight):
Number(Course_Num),Num_Of_HW(Num_Of_HW),HW_weight(HW_Weight){
    int tmp;
    tmp = strlen(Course_Name);
    Name = new char[tmp+1];
    strcpy(Name,Course_Name);
    HW_Grades = new int[Num_Of_HW];

}



Course::~Course() {

    delete []Name;
    delete []HW_Grades;

}


int Course::getNum() const {

    return Number;

}

char* Course::getName() const {

    return Name;
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

float Course::getHwWeigh() const {

    return HW_weight;

}


float Course::getHwAverage() const {

    int tmp=0;
    int i=0;

    for (i=0;i<Num_Of_HW; i++){
        tmp+=HW_Grades[i];
    }

    return ((float)tmp)/((float)Num_Of_HW);
}

int Course::getCourseGrade() const {


    return round((1-HW_weight)*Exam_Grade + HW_weight*getHwAverage());
}

bool Course::setExamGrade(int Grade) {

    return Exam_Grade=Grade;        //TODO: not sure if this will work, need to check

}

bool Course::setHwGrade(int HW, int Grade) {

    return HW_Grades[HW]=Grade;  //TODO: not sure if this will work, need to check

}
