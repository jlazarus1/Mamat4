//
// Created by Or David on 05/01/2019.
//

#include "StArray.h"
#include "Course.h"
#include "EE_Course.h"
#include "CS_Course.h"
#include "Person.h"
#include "Student.h"

StArray ::StArray():
S_num(0), pS_array(new Student*[MAX_STUDENT_NUM]){
    int i;
    for (i=0 ; i<MAX_STUDENT_NUM ; i++){
        pS_array[i]=NULL;
    }
}

StArray ::~StArray() {
    delete []pS_array;
}

int StArray ::addStudent(int s_id, char *s_name) {
    pS_array[S_num] = new Student(s_id, s_name);
    S_num++;
}

int StArray ::addEE_Course(int s_id, int c_num, char *c_name, int hw_num, int hw_weight) {
    if (S_num <= 0)
        return 0;
    int i;
    for (i=0 ; i<S_num ; i++){
        if (pS_array[i]->getID()==s_id){
            if (pS_array[i]->addEE_Course(new EE_Course(c_num, c_name, hw_num, hw_weight)) == 0)
                return 0;
            return 1;
        }
    }
    return 0;
}

int addCS_Course(int s_id, int c_num, char* c_name, int hw_num, int hw_weight, int isTkf, char* b_name){
    if (S_num <= 0)
        return 0;
    int i;
    for (i=0 ; i<S_num ; i++){
        if (pS_array[i]->getID()==s_id){
            ;
            if (pS_array[i]->addCS_Course(new CS_Course(c_num, c_name, hw_num, hw_weight, isTkf, b_name)) == 0)
                return 0;
            return 1;
        }
    }
    return 0;
}
