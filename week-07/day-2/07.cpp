#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise and create two operators for it:
// a + operator that takes and Integer& and adds it's member variables value to this.
// a + operator that takes an int and adds it's value to the member variable of this.
//
// Consider what the return value of the operator should be: Integer& or void? Or something else?
// Make it so that the code below compiles and works.

class Integer {

    public:
        Integer()
        {
            mNum = 0;
        }
        Integer(Integer& _integer_obj)
        {
            mNum = _integer_obj.get_mnum();
        }
        Integer(int a)
        {
            mNum = a;
        };
        Integer& operator + (Integer& _integer_obj)
        {
            mNum += _integer_obj.mNum;

            return *this;
        }
        Integer& operator + (int a)
        {
            mNum+= a;
            return *this;
        }
        int get_mnum()
        {
            return mNum;
        };
    private:
        int mNum;

};

void display(Integer& _integer_obj)
{
    cout << "Displaying Integer i.mNum: " << _integer_obj.get_mnum() << endl;
};

int main ()
{
    Integer a(12);
    Integer b(12);

    cout << (a + b).get_mnum() << endl;
    cout << (a + 12).get_mnum() << endl;
    cout << (a + b + 12).get_mnum() << endl;

    return 0;
}

