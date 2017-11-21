#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise and add two methods:
// One which takes an Integer& parameter and adds the value of it to the member variable of this.
// One which takes an int and adds the value of it to the member variable of this.
//
// Write code which uses them both and Prints out the results respectively

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
        int add(Integer& _integer1, Integer& _integer2)
        {
            return mNum + _integer1.get_mnum() + _integer2.get_mnum();
        };
        int add(Integer& _integer1, Integer& _integer2, Integer& _integer3)
        {
        return mNum + _integer1.get_mnum() + _integer2.get_mnum() + _integer3.get_mnum();
        };
        int add(Integer& _integer1, Integer& _integer2, Integer& _integer3, Integer& _integer4)
        {
            return mNum + _integer1.get_mnum() + _integer2.get_mnum() + _integer3.get_mnum() + _integer4.get_mnum();
        };
        int add(Integer& _integer1, Integer& _integer2, Integer& _integer3, Integer& _integer4, Integer& _integer5)
        {
            return mNum + _integer1.get_mnum() + _integer2.get_mnum() + _integer3.get_mnum() + _integer4.get_mnum() + _integer5.get_mnum();
        };
        void add_permanently(Integer& _integer1)
        {
            mNum+= _integer1.get_mnum();
        };
        void add_permanently(int a)
        {
            mNum+= a;
        };
    private:
        int mNum;

};

void display(Integer& _integer_obj)
{
    cout << "Displaying Integer i.mNum: " << _integer_obj.get_mnum() << endl;
};

int main()
{
    cout << "Creating Integer a(1): ";
    Integer a(1);
    display(a);

    cout << "Adding 1 to a.mNum = 1: ";
    a.add_permanently(1);
    display(a);

    cout << "Adding a.mNum to a.mNum = 2: ";
    a.add_permanently(a);
    display(a);


	return 0;
}
