//
// Created by Or David on 05/01/2019.
//

#include <iostream>
#include "StArray.h"
#include "Course.h"
#include "EE_Course.h"
#include "CS_Course.h"
#include "Person.h"
#include "Student.h"

int find_student_index (int s_id, Student** pS, int S_num){
    if (S_num <= 0)
        return -1;
    int i;
    for (i=0 ; i<S_num ; i++) {
        if (pS[i]->getID() == s_id)
            return i;
    }
    return -1;
}

StArray ::StArray():
S_num(0), pS_array(new Student*[MAX_STUDENT_NUM]){
    int i;
    for (i=0 ; i<MAX_STUDENT_NUM ; i++){
        pS_array[i]= nullptr;
    }
}

StArray ::~StArray() {
    int i;
    resetStArray();
    for (i=0;i<S_num;i++)
        delete pS_array[i];
}

int StArray ::addStudent(int s_id, char *s_name) {
    pS_array[S_num] = new Student(s_id, s_name);
    S_num++;
}

int StArray ::addEE_Course(int s_id, int c_num, char *c_name, int hw_num, double hw_weight) {
    int i = find_student_index(s_id, pS_array, S_num);
    if (i<0)
        return 0;
            if (pS_array[i]->addEE_Course(new EE_Course(c_num, c_name, hw_num, hw_weight)) == 0)
                return 0;
            return 1;
}

int StArray :: addCS_Course(int s_id, int c_num, char* c_name, int hw_num, double hw_weight, bool isTkf, char* b_name){
    int i = find_student_index(s_id, pS_array, S_num);
    if (i<0)
        return 0;
            if (pS_array[i]->addCS_Course(new CS_Course(c_num, c_name, hw_num, hw_weight, isTkf, b_name) ) == 0)
                 return 0;
            return 1;
}

int StArray :: setHwGrade(int s_id, int c_num, int hw_num, int hw_grd){
    int i = find_student_index(s_id, pS_array, S_num);
    if (i<0)
        return 0;
    Course* courseHW;
    courseHW = pS_array[i]->getEE_Course(c_num);
    if(courseHW != nullptr){
        courseHW->setHwGrade(hw_num, hw_grd);
        return 1;
    }
    courseHW = pS_array[i]->getCS_Course(c_num);
    if(courseHW != nullptr){
        courseHW->setHwGrade(hw_num, hw_grd);
        return 1;
    }
    return 0;
}

int StArray :: setExamGrade(int s_id, int c_num, int exam_grd){
    int i = find_student_index(s_id, pS_array, S_num);
    if (i<0)
        return 0;
    Course* courseHW;

    courseHW = pS_array[i]->getEE_Course(c_num);
    if(courseHW != nullptr){
        courseHW->setExamGrade(exam_grd);
        return 1;
    }
    courseHW = pS_array[i]->getCS_Course(c_num);
    if(courseHW != nullptr){
        courseHW->setExamGrade(exam_grd);
        return 1;
    }
    return 0;
}

int StArray :: printStudent(int s_id){
    int i = find_student_index(s_id, pS_array, S_num);
    pS_array[i]->print();
}

void StArray :: printAll(){
    for(int i=0 ; i<S_num ; i++){
        pS_array[i]->print();

    }
}

void StArray :: resetStArray(){
    for(int i=0 ; i<S_num ; i++){
        pS_array[i]-> ~Student();
    }
}

int StArray::setFactor(int c_num, int factor) {

    int i, success=0;

    for (i=0;i<S_num;i++)
    {

      if  (pS_array[i]->getEE_Course(c_num)!= nullptr)
      {
          pS_array[i]->getEE_Course(c_num)->setFactor(factor);
          success=1;
      }
    }
    if (success) return 1;
    return 0;
}


