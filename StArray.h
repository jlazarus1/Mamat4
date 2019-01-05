//
// Created by Or David on 05/01/2019.
//

#ifndef HW4_STARRAY_H
#define HW4_STARRAY_H

#include "Person.h"
#include "Student.h"

class StArray{
private:
    Student** pS_array;
    int S_num;

public:
    StArray();
    ~StArray();
    int addStudent(int s_id , char* s_name);
    int addEE_Course(int s_id, int c_num, char* c_name, int hw_num, int hw_weight);
    int addCS_Course(int s_id, int c_num, char* c_name, int hw_num, int hw_weight, int isTkf, char* b_name);
    int setHwGrade(int s_id, int c_num, int hw_num, hw_grd);
    int setExamGrade(int s_id, int c_num, t_grd);
    int setFactor(int c_num, int factor);
    int printStudent(int s_id);
    void printAll();
    void reserStArray();

};


#endif //HW4_STARRAY_H
