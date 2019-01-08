//
// Created by josh on 1/5/19.
//

#include <cstring>
#include <cmath>
#include "CS_Course.h"


CS_Course::CS_Course(int Course_Num, char *Course_Name, int Num_Of_HW, int HW_Weight, bool Is_Takef, char *Book_Name):
Course(Course_Num,Course_Name,Num_Of_HW,HW_Weight), Is_Takef(Is_Takef), Book_Name(Book_Name){

    int tmp;
    tmp = strlen(Book_Name);
    Book_Name = new char[tmp+1];
    strcpy(Book_Name,Course_Name);

}

bool CS_Course::isTakef() const {

    return Is_Takef;


}

char* CS_Course::getBook() const {
    int size;
    char* Book_Name_return;
    size = strlen(Book_Name);
    Book_Name_return = new char[size+1];
    strcpy(Book_Name_return,Book_Name);
    return Book_Name_return;
}

int CS_Course::setTakef(bool is_takef) {

    Is_Takef = is_takef;
    return 1;
}

bool CS_Course::setBook(char *Book) {
    int size;
    delete Book_Name;
    size = strlen(Book);
            Book_Name = new char[size+1];
            strcpy(Book_Name,Book);
            return Book_Name;

}

int CS_Course::getCourseGrade() const {
    int tmp;
    tmp=0.5+((1-getHwWeigh())*getExamGrade()+getHwWeigh()*getHwAverage());
    if (Is_Takef==true)
        return tmp;
    else

                 if (tmp>getExamGrade())
                     return tmp;
                 else return getExamGrade();


}

CS_Course::~CS_Course() {

    delete []Book_Name;

}
