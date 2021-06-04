//
// Created by Nitzan on 5/28/2021.
//

#ifndef EX2_EXAMDETAILS_H
#define EX2_EXAMDETAILS_H
#include <iostream>
#include "sortedList.h"
//#include "examDetails.c"

using std::cout;
using std::endl;
using std::string;
//using namespace mtm;


namespace mtm {
    class ExamDetails
    {
        int course_num;
        int month;
        int day;
        double time;
        int duration;
        string zoom_link;

    public:
        //constructors: there are 2. notes the variables.

        ExamDetails(const int course_num, int month, int day, double time, int duration , string zoom_link = "");
        //destructor
        ~ExamDetails() = default;

        //copy constructor
        ExamDetails(const ExamDetails& exam) = default;

        // methods that handle zoom links.

        string getLink() const;
        void setLink(string new_zoom_link);


        class InvalidDateException : public std::exception{};

        class InvalidTimeException : public std::exception{};

        class InvalidArgsException : public std::exception{};


        // operator overloading
        bool operator<(const ExamDetails& exam) const;

        int operator-(const ExamDetails& exam1)const;
        friend std::ostream& operator<<(std::ostream& out, const ExamDetails& exam);

        ExamDetails static makeMatamExame();

    };


}




#endif //EX2_EXAMDETAILS_H
