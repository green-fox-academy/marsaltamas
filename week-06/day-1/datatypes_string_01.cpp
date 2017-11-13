#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// An average Green Fox attendee codes 6 hours daily
// The semester is 17 weeks long
//
// Print how many hours is spent with coding in a semester by an attendee,
// if the attendee only codes on workdays.
//
// Print the percentage of the coding hours in the semester if the average
// work hours weekly is 52

int main()
{
    int hours_coded_per_day = 6;
    int working_days_per_week = 5;
    int semester_length_in_weeks = 17;
    int working_hours_per_week = 52;

    int total_hours_coded = hours_coded_per_day * working_days_per_week * semester_length_in_weeks;

    cout << "Total hours coded by an attendee during the course: " << total_hours_coded << endl;

    float proportion_of_coding_hours = (float) total_hours_coded / (working_hours_per_week * semester_length_in_weeks);

    cout << "Proportion of coding hours compared to working hours: " << setprecision(3) << proportion_of_coding_hours << endl;

    return 0;
}
