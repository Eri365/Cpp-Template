#include <stdio.h>
#include <assert.h>
#include <memory.h>

template<typename T>
class MyStack{
public:
    // Member Type
    typedef T type_value;
    typedef size_t type_size;
    typedef const type_value& const_reference; 

    // Member function
    explicit MyStack(): S(0), tail(nullptr) {}

    type_size size() const{
        return S;
    }

    bool empty() const{
        return tail == nullptr;
    }

    const_reference top() const{
        assert(!empty());
        return tail -> data;
    }

    void push(const_reference x){
        struct Node *newNode = (Node*)malloc(sizeof(struct Node));
        newNode -> data = x;
        newNode -> prev = nullptr;

        if(tail == nullptr){
            tail = newNode;
        }
        else{
            newNode -> prev = tail;
            tail = newNode;
        }
        ++S;
    }

    void pop(){
        assert(!empty());
        struct Node *temp = tail;
        tail = tail -> prev;
        free(temp);
        --S;
    }

private:
    type_size S;
    struct Node{
        type_value data;
        struct Node *prev;
    }*tail;
};

int main(){
    return 0;
}
