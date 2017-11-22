#include <iostream>
using namespace std;

// Create a class Float based on the examples from the two previous files and Your experiences from before.
// Try out all it's functions incrementally and print out the results in main().
// Good coding! :)

class Float {
    public:
        Float()
        {
            mNum = 0;
        };
        Float(float _float)
        {
            mNum = _float;
        };
        Float(Float& _float_obj)
        {
            mNum = _float_obj.mNum;
        };
        void set_num(float _num)
        {
            mNum = _num;
        };
        float get_num()
        {
            return mNum;
        };
        void add(Float& _float_obj)
        {
            mNum+= _float_obj.mNum;
        };
        void add(float _float)
        {
            mNum+= _float;
        };
        Float& operator + (float _float)
        {
            mNum+= _float;
        }
    private:
        float mNum;

};

ostream& operator << (ostream& _stream, Float& _float_obj)
{
    _stream << _float_obj.get_num();

    return _stream;
}

void display(Float& _float)
{
    cout << "display(Float& _float_obj.mNum): " << _float.get_num() << endl;
};

int main()
{
    Float a;
    a.set_num(10.0f);
    display(a);

    Float b;
    display(b);

    Float c(100.0f);
    display(c);

    Float d(a);
    display(d);

    a.add(c);
    display(a);

    a.add(7);
    display(a);

    a + 1.45f;
    display(a);

    cout << "a using operator overloaded stream: " << a + 3.4567;

    return 0;
}
