//
// Created by Or David on 04/01/2019.
//

#ifndef HW4_PERSON_H
#define HW4_PERSON_H

class Person {

private:
    int id;     //person's id
    char *name; //person's name
    static int p_cnt;

public:
    Person(int id_, char *name_); //constructor
    ~Person(); //destructor
    int getID() const ;       //return id
    char *getName() const ;   //return name
    static int get_p_cnt();
};

#endif //HW4_PERSON_H
