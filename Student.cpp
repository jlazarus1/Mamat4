//
// Created by Or David on 05/01/2019.
//
#include <iostream>
#include "Student.h"
#include "Person.h"
#include "Course.h"
#include "EE_Course.h"
#include "CS_Course.h"

Student::Student(int id_, char *name_):
Person(id_, name_), EE_C_num(0), CS_C_num(0), EE_C_array(new Course*[MAX_COURSE_NUM]), CS_C_array(new Course*[MAX_COURSE_NUM]) {}

Student :: ~Student(){
    for(int i=0 ; i<EE_C_num ; i++){ //going through all EE courses first and calling their destructor
        EE_C_array[i] -> ~Course();
    }
    delete []EE_C_array;

    for(int i=0 ; i<EE_C_num ; i++){ //going through all CS courses first and calling their destructor
        CS_C_array[i] -> ~Course();
    }
    delete []CS_C_array;
}

int Student :: get_CourseCnt(){
    return (EE_C_num + CS_C_num);
}

int Student :: addEE_Course(Course* pEE_C) {
    if (EE_C_num > MAX_COURSE_NUM) // The EE_C_num tels where is the next free slot in the array
        return 0;
    EE_C_array[EE_C_num] = pEE_C;
    EE_C_num++;
    return 1;
}

int Student :: addCS_Course(Course* pCS_C){
    if (CS_C_num > MAX_COURSE_NUM) // Same like EE_C_num
        return 0;
    CS_C_array[CS_C_num] = pCS_C;
    CS_C_num++;
    return 1;
}

int Student :: remCourse(int c_num){
    if (get_CourseCnt()==0)
        return 0;
    int i ,k;
    for (i=0 ; i<EE_C_num ; i++){ // going through all courses and try to find the right course number
        if (EE_C_array[i]->getNum() == c_num){
            EE_C_array[i]->~Course();
            EE_C_num--;
            if (i == EE_C_num)
                return 1;
            for (k=i ; k<EE_C_num ; k++){
                EE_C_array[k] = EE_C_array[k+1];
            }
            return 1;
        }
    }
    // doing the same loop for CS
    for (i=0 ; i<CS_C_num ; i++){
        if (CS_C_array[i]->getNum() == c_num){
            CS_C_array[i]->~Course();
            CS_C_num--;
            if (i == CS_C_num)
                return 1;
            for (k=i ; k<CS_C_num ; k++){
                CS_C_array[k] = CS_C_array[k+1];
            }
            return 1;
        }
    }
    return 0;
}

EE_Course* Student :: getEE_Course (int c_num){
    if (EE_C_num==0)
        return nullptr;
    int i;
    for (i=0 ; i<EE_C_num ; i++) {
        if (EE_C_array[i]->getNum() == c_num) {
            return (dynamic_cast<EE_Course*> (EE_C_array[i]));
        }
    }
    return nullptr;
}

CS_Course* Student :: getCS_Course (int c_num){
    if (CS_C_num==0)
        return nullptr;
    int i;
    for (i=0 ; i<CS_C_num ; i++) {
        if (CS_C_array[i]->getNum() == c_num) {
            return (dynamic_cast<CS_Course*> (CS_C_array[i]));
        }
    }
    return nullptr;
}

int Student :: getAvg(){
    int course_num = get_CourseCnt();
    if (course_num == 0)
        return -1;

    int i, sum_grades = 0;
    for (i=0 ; i<EE_C_num ; i++){
        sum_grades = sum_grades + EE_C_array[i]->getCourseGrade();
    }
    for (i=0 ; i<CS_C_num ; i++){
        sum_grades = sum_grades + CS_C_array[i]->getCourseGrade();
    }

    return (int(0.5+(sum_grades/course_num)));
}

void Student :: print(){
    if (getAvg() < 0) {
        printf("No courses taken");
        return;
    }
    std::cout << "Student name: "<<getName()<<"\nStudent ID: "<<getID()<<"\nAverage grade: getAvg()\n";
    int i;
    std::cout<<"EE courses:\n";
    for (i=0 ; i<EE_C_num ; i++){
        std::cout << EE_C_array[i]->getNum()<<" "<<EE_C_array[i]->getName()<<" "<<EE_C_array[i]->getCourseGrade()<<"\n";
    }
    std::cout<<"CS courses:\n";
    for (i=0 ; i<CS_C_num ; i++){
        std::cout << CS_C_array[i]->getNum()<<" "<<CS_C_array[i]->getName()<<" "<<CS_C_array[i]->getCourseGrade()<<"\n";
    }
}

