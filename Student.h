//
// 23.04.2022.
//

#ifndef INC_1410_STD_CONTAINER_USER_CLASS_STUDENT_H
#define INC_1410_STD_CONTAINER_USER_CLASS_STUDENT_H


#include <string>
#include <array>

class Student {
    private:
        std::string fio, facult, record_book_num;
        std::array<int,4> marks;
    public:
        explicit Student(std::string fio_, std::string facult_, std::string record_num_, const std::array<int,4> marks_)
            : fio(fio_), facult(facult_), record_book_num(record_num_), marks(marks_) {}
        Student & operator=(const Student &other)
        {
            if (this != &other) // защита от неправильного самоприсваивания
            {
                fio = other.fio;
                facult = other.facult;
                record_book_num = other.record_book_num;
                marks = other.marks;
            }
            return *this;
        }
        Student (const Student &other) {
            fio = other.fio;
            facult = other.facult;
            record_book_num = other.record_book_num;
            marks = other.marks;
        }
        Student (Student &&other)
            :   fio(std::move(other.fio)),
                facult(std::move(other.fio)),
                record_book_num(std::move(other.record_book_num)),
                marks(std::move(other.marks))
                {}
        bool operator < (const Student& other) const
        {
            return (fio < other.fio);
        }
        friend std::ostream& operator << (std::ostream &os, const Student &p);
};


#endif //INC_1410_STD_CONTAINER_USER_CLASS_STUDENT_H
