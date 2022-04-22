#include <array>
#include <vector>
#include <deque>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "Student.h"

int main() {
    // count of Students
    int n = 0;
    std::string temp_fio, temp_facult, temp_record_book_num;
    std::array<int, 4> temp_marks;

    std::ifstream fin("input.txt");
    fin >> n;
    std::vector<Student> vec_input;
    vec_input.reserve(n);
    for(int i = 0;i<n;++i){
        fin >> temp_fio >> temp_facult >> temp_record_book_num;
        fin >> temp_marks[0] >> temp_marks[1] >> temp_marks[2] >> temp_marks[3];
        vec_input.push_back(Student(temp_fio, temp_facult, temp_record_book_num, temp_marks));
    }
    fin.close();
    // копируем - сортируем - выводим
    std::vector<Student> vec_sorted;
    vec_sorted.reserve(n);
    std::copy(vec_input.begin(), vec_input.end(), std::back_inserter(vec_sorted));
    std::sort(vec_sorted.begin(), vec_sorted.end());
    // создаем деку, копируем
    std::deque<Student> deq;
    std::copy(vec_input.begin(), vec_input.end(),  std::back_inserter(deq));


    std::ofstream fout("output.txt");
    fout << "Исходный вектор:" << std::endl;
    for (int i = 0; i<n; ++i){
        fout << vec_input[i];
    }
    fout << "Сортированный вектор:" << std::endl;
    for (int i = 0; i<n; ++i){
        fout << vec_sorted[i];
    }
    fout << "Скопированная очередь:" << std::endl;
    for (int i = 0; i<n; ++i){
        fout << deq[i];
    }
    fout.close();


    return 0;
}
