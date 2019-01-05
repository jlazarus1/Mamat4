//
// Created by josh on 1/5/19.
//

#ifndef HW4_CS_COURSE_H
#define HW4_CS_COURSE_H


class CS_Course {

private:

    bool Is_Takef;
    char* Book_Name;

public:
    CS_Course(int Course_Num, char Course_Name, int Num_Of_HW, int HW_Weight,bool Is_Takef, char* Book_Name);
    bool isTakef() const;
    char* getBook() const;
    int setTakef(bool is_takef);
    bool setBook(char* Book);
    int getCourseGrade() const;



};


#endif //HW4_CS_COURSE_H
