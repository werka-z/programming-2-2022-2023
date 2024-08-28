#include <iostream>
#include <vector>
using namespace std;


template <typename T>
class Node{
public:
    T val;
    Node* next;

    explicit Node(const T& val, Node* next = nullptr): val(val) , next(next) {}
};


template <typename T>
class Stack{
    Node<T>* topNode;
    int size;

public:

    Stack() : topNode(nullptr), size(0){}
    ~Stack(){
        while (!empty()) pop();
    }

    bool empty(){
        return size==0;
    }

    void push(T& val){
        auto* newNode = new Node<T>(val, topNode);
        topNode = newNode;
        size++;
    }

    T pop(){
        if (empty()) {
            throw out_of_range("Stack is empty\n");
        }


        Node<T>* toDelete = topNode;
        T val = toDelete->val;
        topNode = topNode->next;
        delete toDelete;
        size--;
        return val;
    }

    void print(ostream& os){
        Node<T>* current = topNode;
        while (current){
            os << current->val << " ";
            current = current->next;
        }
    }

    int getSize(){
        return size;
    }
};

template <typename T>
ostream& operator<<(ostream& os, Stack<T>& stack){ //przeładowanie << dla klasy Stack
    stack.print(os);
    return os;
}

template <>
class Stack<int>{
        vector<int> array; //dla intow przechowywane na vectorze - specjalizacja

    public:
        Stack() = default;
        ~Stack() { array.clear(); }

        bool empty(){
            return array.empty();
        }

        void push(int a){
            array.push_back(a);
        }

        int pop(){
            if (empty()) return -1;
            int value = array.back();
            array.pop_back();
            return value;
        }

        int size(){
            return array.size();
        }

        void print(std::ostream& os) const {
            for (auto i = array.rbegin(); i < array.rend(); ++i) {
                os << *i << " ";
            }
        }
    };

class ComplexNumbers { //klasa liczb zespolonych z poprzedniego zadania
    float R;
    float I;
public:
    ComplexNumbers &operator=(ComplexNumbers other) {
        R = other.R;
        I = other.I;
        return *this;
    }

    friend ostream &operator<<(ostream &os, const ComplexNumbers &num) {
        os << num.R << "+" << num.I << "i";
        return os;
    }

public:
    ComplexNumbers() : R(0), I(0) {}
    ComplexNumbers(float a, float b) : R(a), I(b) {}
};


int main() {

    cout << "Complex numbers stack: \n";
    Stack<ComplexNumbers> stack;

    ComplexNumbers n1(3, 9);
    ComplexNumbers n2(2, 2.3);
    ComplexNumbers n3(4.1, 7);

    stack.push(n1);
    stack.push(n2);

    cout << "Size of stack after pushing n1 and n2: " << stack.getSize() << endl;
    cout << "n2 popped: "<< stack.pop() << endl;
    cout << "printed stack: ";
    stack.print(cout);

    stack.push(n3);
    stack.push(n2);

    cout << "\nAfter pushing n3 and n2: \n";
    stack.print(cout);


    cout << "\n\nInt stack:\n";
    Stack<int> intStack;

    for (int i=10; i<30;i+=2){
        intStack.push(i);
    }
    cout << "Size: " << intStack.size() << ", stack: ";
    intStack.print(cout);

    for (int i=0; i<7; i++) intStack.pop();

    cout << "\nAfter popping 7 elements:\n";
    cout << "Size: " << intStack.size() << ", stack: ";
    intStack.print(cout);

    return 0;

    /*output:
    Complex numbers stack:
    Size of stack after pushing n1 and n2: 2
    n2 popped: 2+2.3i
    printed stack: 3+9i
    After pushing n3 and n2:
    2+2.3i 4.1+7i 3+9i

    Int stack:
    Size: 10, stack: 28 26 24 22 20 18 16 14 12 10
    After popping 7 elements:
    Size: 3, stack: 14 12 10
     */
}
