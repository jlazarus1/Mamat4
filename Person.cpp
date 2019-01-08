//
// Created by Or David on 04/01/2019.
//

#include <cstring>
#include "Person.h"

int Person :: p_cnt = 0;
int Person :: get_p_cnt() {
    return p_cnt;
}

Person :: Person(int id_, char *name_):
id(id_){

    int tmp;
    tmp = strlen(name_);
    name = new char[tmp+1];
    strcpy(name,name_);

    p_cnt++;



};

int Person ::getID() const {
    return id;
}

char* Person ::getName() const {
    int size;
    char* Name_return;
    size = strlen(name);
    Name_return = new char[size+1];
    strcpy(Name_return,name);
    return Name_return;
}

Person :: ~Person() {
    p_cnt--;
    delete []name;
}