
#include <stdexcept>
using namespace std;

const int MAX_SIZE = 20;

template<typename T>
class stack{
public:
    stack();
    void push(T val);
    void pop();
    T top();
    bool empty();
private:
    T data[MAX_SIZE];
    int size;
};

template<typename T>
stack<T>::stack()
{
    this -> size = 0;
}

template<typename T>
void stack<T>::push(T val)
{
    //try{
        if(size == MAX_SIZE)
            throw overflow_error("Called push on full stack.");
    //}
    //catch(const std::overflow_error& excpt){
    //    cout << excpt.what() << endl;
    //}


    this -> data[this -> size++] = val;
}

template<typename T>
void stack<T>::pop()
{
    //try{
        if(this -> empty())
            throw out_of_range("Called pop on empty stack.");
    //}
    //catch(const std::out_of_range& excpt){
    //    cout << excpt.what() << endl;
    //}
    size--;
}

template<typename T>
T stack<T>::top()
{
    //try{
        if(this -> empty())
            throw underflow_error("Called top on empty stack.");
    //}
    //catch(const std::underflow_error& excpt){
    //    cout << excpt.what() << endl;
    //}
    return this -> data[this->size-1];
}

template<typename T>
bool stack<T>::empty()
{
    return this -> size == 0;
}
