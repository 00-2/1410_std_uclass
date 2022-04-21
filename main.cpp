#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <algorithm>
#include "Student.h"

int main() {
    std::array<int, 4> marks = {1,2,3,4};
    Student s("ИВАНОВ", "two", "three", marks);
    std::cout << s;
    Student s1 = s;
    std::cout << s1 << std::endl;
    Student s2(Student("ЖДАНОВ","1","2",{1,1,3,4}));
    std::cout << s2 << std::endl << s << std::endl;
    std::vector<Student> vec_input{s,s1,s2};

    std::cout << "DATA FROM VECTOR" << std::endl;
    for (auto student : vec_input){
        std::cout << student << std::endl;
    }
    std::vector<Student> vec_second;
    vec_second.reserve(3);
    std::copy(vec_input.begin(), vec_input.end(), std::back_inserter(vec_second));
    std::cout << "DATA FROM VECTOR(COPY)" << std::endl;
    for (auto student : vec_second){
        std::cout << student << std::endl;
    }
    std::deque<Student> deq;
    std::copy(vec_input.begin(), vec_input.end(),  std::back_inserter(deq));
    std::cout << "DATA FROM DEQUE" << std::endl;
    for (auto student : deq){
        std::cout << student << std::endl;
    }
    std::sort(vec_second.begin(), vec_second.end());
    std::cout << "SORTED VECTOR" << std::endl;
    for (auto student : vec_second){
        std::cout << student << std::endl;
    }


    return 0;
}
