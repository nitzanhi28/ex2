//
// Created by Nitzan on 5/28/2021.
//

#include "examDetails.h"
//#include "exceptions.h"
#include "cmath"
//#include "string.h"


/*====================================================================================================================
                                        static functions
====================================================================================================================*/

static int dayDifference(int month1, int day1, int month2, int day2){
    int diff = 0;
    if (month1 >= month2){
        diff = ((month2 - month1)*30) -day2 +day1;
        if(diff < 0 ){
            return -diff;
        }
    }
    else{
        diff = ((month1 - month2)*30) -day1 +day2;
        return diff;
    }
    return diff;
}

static mtm::ExamDetails makeMatamExam(){
    string temp_s = "https://tinyurl.com/59hzps6m";
    return mtm::ExamDetails(234124 , 7 , 28 , 13.0 , 3 , temp_s);
}

/*====================================================================================================================
                                       end of static functions
====================================================================================================================*/

static int timeDifference(double time_1 , double time_2){
    int hour_1 = (int) time_1;
    int hour_2 = (int) time_2;
    int min_1 = ((int)time_1 * 10)%10;
    int min_2 = ((int)time_2 * 10)%10;
    if (hour_1 < hour_2){
        return -1;
    }
    if (hour_1 == hour_2 && min_1 < min_2){
        return -1;
    }
    return 1;
}




using std::string;

using namespace mtm;

ExamDetails::ExamDetails(const int course_num, int month, int day, double time, int duration, string zoom_link):
        course_num(course_num), month(month), day(day), time(time), duration(duration), zoom_link(zoom_link) {
    if (month > 12 || month < 1) {
        throw InvalidDateException();
    }
    if (day < 1 || day > 30) {
        throw InvalidDateException();
    }
    if (fmod(time, 1) != 5 || fmod(time, 1) != 0) {
        throw InvalidTimeException();// TODO: is it needed?
    }
    if (course_num > 0) {
        throw InvalidArgsException();
    }

}

string ExamDetails::getLink() const{
    return this->zoom_link;
}
void ExamDetails::setLink(string new_zoom_link){

    this->zoom_link = new_zoom_link;
}

int ExamDetails::operator-(const ExamDetails& exam1)const{
    return dayDifference(exam1.month, exam1.day, this->month, this->day);

}


bool ExamDetails::operator<(const ExamDetails& exam) const{
    if (month<exam.month){
        return true;
    }
    if (month == exam.month && day<exam.day){
        return true;
    }
    if (month == exam.month && day == exam.day && timeDifference(time , exam.time)<0){
        return true;
    }
    return false;
}




namespace mtm {
    std::ostream &operator<<(std::ostream &out, const ExamDetails &exam) {
        string min = "00";
        if (((int)time*10)%10 == 5) {
            min = "30";
        }
        int hour = (int) time;
        return (out << "Time: " << exam.day << "." << exam.month << " at " << hour << ":" << min << '\n');
    }
}

