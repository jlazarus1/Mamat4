//
// Created by josh on 1/5/19.
//

#ifndef HW4_CS_COURSE_H
#define HW4_CS_COURSE_H
#include "Course.h"

class CS_Course: public Course {

private:

    bool Is_Takef;
    char* Book_Name;

public:
    CS_Course(int Course_Num, char *Course_Name, int Num_Of_HW, double HW_Weight,bool Is_Takef, char* Book_Name);
    ~CS_Course();
    bool isTakef() const;
    char* getBook() const;
    int setTakef(bool is_takef);
    bool setBook(char* Book);
    int getCourseGrade() const;



};


#endif //HW4_CS_COURSE_H
