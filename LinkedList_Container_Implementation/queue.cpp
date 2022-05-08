template<typename T>
class MyQueue{
public:
    // Member type
    typedef T type_value;
    typedef size_t type_size;
    typedef const type_value& const_reference;

    // Member fuctions
    explicit MyQueue(): S(0), head(nullptr), tail(nullptr) {}

    type_size size() const{
        return S;
    }

    bool empty() const{
        return head == nullptr;
    }

    const_reference front() const{
        assert(!empty());
        return head -> data;
    }

    void push(const_reference x){
        struct Node *newNode = (Node*)malloc(sizeof(struct Node));
        newNode -> data = x;
        newNode -> next = nullptr;

        if(head == nullptr){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        ++S;
    }

    void pop(){
        assert(!empty());
        struct Node *temp = head;
        head = head -> next;
        free(temp);
        --S;
    }

    void swap(MyQueue& x) noexcept{
        swap(x, *this);
    }

private:
    type_size S;
    struct Node{
        type_value data;
        struct Node *next;
    }*head, *tail;
};
