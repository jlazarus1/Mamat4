//
// Created by Or David on 04/01/2019.
//

#include "Person.h"

int Person :: p_cnt = 0;
int Person :: get_p_cnt() {
    return p_cnt;
}

Person :: Person(int id_, char *name_):
id(id_), name(name_){p_cnt++;};

int Person ::getID() const {
    return id;
}

char* Person ::getName() const {
    return name;
}

Person :: ~Person() {p_cnt--;}