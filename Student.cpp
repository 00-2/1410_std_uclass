//
//  23.04.2022.
//

#include <iostream>
#include "Student.h"


std::ostream& operator << (std::ostream &os, const Student &p){
    return  os << p.fio << " " << p.facult << " " << p.record_book_num << " " << p.marks[0] << p.marks[1] << p.marks[2] << p.marks[3];
}