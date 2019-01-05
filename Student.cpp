//
// Created by Or David on 05/01/2019.
//

#include "Student.h"

Student::Student():
EE_C_num(0), CS_C_num(0) {
    EE_C_array = new Course*[MAX_COURSE_NUM];
    CS_C_array = new Course*[MAX_COURSE_NUM];
}

Student ::getCoursCnt(){
    return (EE_C_num + CS_C_num);
}

Student :: addEE_Course(Course* pEE_C){
    if (EE_C_num > MAX_COURSE_NUM) // The EE_C_num tels where is the next free slot in the array
        return 0;
    EE_C_array[EE_C_num] = pEE_C;
    EE_C_num++;
    return 1;
}

Student :: addCS_Course(Course* pCS_C){
    if (CS_C_num > MAX_COURSE_NUM) // Same like EE_C_num
        return 0;
    CS_C_array[CS_C_num] = pCS_C;
    CS_C_num++;
}

Student :: remCourse(int c_num){
    if ((EE_C_num + CS_C_num)==0)
        return 0;
    int i ,k;
    for (i=0 ; i<EE_C_num ; i++){
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

Student :: getEE_Course (int c_num){
    if ((EE_C_num==0)
        return NULL;
    int i;
    for (i=0 ; i<EE_C_num ; i++) {
        if (EE_C_array[i]->getNum() == c_num) {
            return EE_C_array[i];
        }
    }
    return NULL;
}

Student :: getCS_Course (int c_num){
    if ((CS_C_num==0)
        return NULL;
    int i;
    for (i=0 ; i<CS_C_num ; i++) {
        if (CS_C_array[i]->getNum() == c_num) {
            return CS_C_array[i];
        }
    }
    return NULL;
}

Student :: getAvg(){
    int course_num = EE_C_num + CS_C_num;
    if (course_num == 0)
        return -1;

    int sum_grades = 0;
    for (i=0 ; i<EE_C_num ; i++){
        sum_grades = sum_grades + EE_C_array[i]->getCourseGrade();
    }
    for (i=0 ; i<CS_C_num ; i++){
        sum_grades = sum_grades + CS_C_array[i]->getCourseGrade();
    }

    return (average_grade = round(sum_grades/course_num));
}

Student :: print(){
    if (this->getAvg < 0) {
        printf("No courses taken");
        return;
    }
    printf("Student name: %s\nStudent ID: %d\nAverage grade: %d\n", this->getName , this->getID , this->getAvg);
    int i;
    printf("EE courses:\n");
    for (i=0 ; i<EE_C_num ; i++){
        printf("%d %s %d\n", EE_C_array[i]->getNum(), EE_C_array[i]->getName(), EE_C_array[i]->getCourseGrade());
    }
    printf("CS courses:\n")
    for (i=0 ; i<CS_C_num ; i++){
        printf("%d %s %d\n", CS_C_array[i]->getNum(), CS_C_array[i]->getName(), CS_C_array[i]->getCourseGrade());
    }
    return;
}