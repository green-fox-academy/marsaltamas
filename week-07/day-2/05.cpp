#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise.
// Create 3 constructors for them:
// One empty which sets the member varibale to 0;
// A copy constructor, that takes an Integer& argument
// A third one which takes an int as argument and makes the member variable equal to the int it took.
//
// Write code that uses these and prints out the value of the member variable of the integers created.
// (You will have to create a get method to do this appropriately.)

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
        int get_mnum()
        {
            return mNum;
        };
        int add(Integer& _integer1)
        {
            return mNum + _integer1.get_mnum();
        };
    private:
        int mNum;

};

void display(Integer& _integer_obj)
{
    cout << "Integer mNum: " << _integer_obj.get_mnum() << endl;
};

int main()
{
    cout << "Test empty(0) constructor: ";
    Integer a;
    display(a);

    cout << "Test int(2) constructor: ";
    Integer b(2);
    display(b);

    cout << "Test copy (of b.mNum = 2) constructor: ";
    Integer c(b);
    display(c);

	return 0;
}
