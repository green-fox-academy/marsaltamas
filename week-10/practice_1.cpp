#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Student {
    public:
        void add_grade(int _new_grade)
        {
            if (_new_grade > 5 || _new_grade < 1)
                cout << "invalid grade." << endl;
            else
                grades_.push_back(_new_grade);
        }

        float get_average()
        {
            float sum;

            if (grades_.size() != 0) {

                for (int i = 0; i < grades_.size(); ++i) {
                    sum+= grades_.at(i);
                }
            }

            return sum / grades_.size();
        }

        void displayGrades()
        {
            try {
                if (grades_.size() == 0)
                    throw runtime_error ("Student has no grades.");

                for (int i = 0; i < grades_.size(); ++i) {
                    cout << "grade " << i << ": " << grades_.at(i) << endl;
                }

            } catch (runtime_error &error) {
                cout << error.what() << endl;
            }
        }
    private:
        vector<int> grades_;
};

int main()
{
    Student s;

    s.displayGrades();

    s.add_grade(0);
    s.add_grade(6);
    s.add_grade(2);
    s.add_grade(3);
    s.add_grade(2);

    s.displayGrades();

    cout << "avg: " << s.get_average() << endl;

    return 0;
}
