#ifndef SEM3_LAB3_C_SINGLE_LINKED_LIST_H
#define SEM3_LAB3_C_SINGLE_LINKED_LIST_H

#include <cstddef>
#include <stdexcept>

template<typename T>
class SinglyLinkedList{
private:
    struct Node{
        T data;
        Node*next;
        Node(const T& value): data(value),next(nullptr){}
        //конструктор перемещения для Node
        Node(T&& value) : data(std::move(value)),next(nullptr){}
    };
    Node* head_;
    Node* tail_;
    size_t size_;

    Node* get_node(size_t index) const{
        if (index>=size_) throw std::out_of_range{"index out of range"};
        Node* current = head_;
        for (size_t i =0;i<index;i++){
            current = current->next;
        }
        return current;
    }

public:

    class Iterator {
    private:
        Node* node_;
    public:
        Iterator(Node* node) : node_(node) {}

        T& operator*(){
            return node_->data;
        }

        T* get(){
            return &node_->data;
        }
    };

    Iterator begin() {
        return Iterator(head_);//возвращает итератор на начало
    }

    Iterator end() {
        return Iterator(nullptr);//возвращает итератор на конец(после последнего элемента)
    }

    SinglyLinkedList():head_(nullptr),tail_(nullptr),size_(0){}

    //перемещающий конструктор
    SinglyLinkedList(SinglyLinkedList&& other) noexcept : head_(other.head_),tail_(other.tail_), size_(other.size_){
        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }


    //перемещащий оператор присваивания
    SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept {
        if (this != &other) {
            clear();//освобождаем старые данные

            //крадем ресурсы у other
            head_ = other.head_;
            tail_ = other.tail_;
            size_ = other.size_;

            other.head_ = nullptr;
            other.tail_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }

    ~SinglyLinkedList(){
        clear();
    }

    void clear(){
        Node* current = head_;
        while (current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
        head_ = tail_= nullptr;
        size_ = 0;
    }

    void push_back(const T& value){
        Node* new_node = new Node(value);

        if (tail_ == nullptr){
            head_ = tail_ = new_node;
        } else {
            tail_->next = new_node;
            tail_ = new_node;
        }
        size_++;
    }

    void push_back(T&& value){
        Node* new_node = new Node(std::move(value));

        if (tail_ == nullptr){
            head_ = tail_ = new_node;
        } else {
            tail_->next = new_node;
            tail_ = new_node;
        }
        size_++;
    }

    void push_front(const T& value){
        Node* new_node = new Node(value);

        if (head_ == nullptr){
            head_ = tail_ = new_node;
        } else{
            new_node->next = head_;
            head_ = new_node;
        }
        size_++;
    }

    void push_front(T&& value){
        Node* new_node = new Node(std::move(value));

        if (head_ == nullptr){
            head_ = tail_ = new_node;
        } else{
            new_node->next = head_;
            head_ = new_node;
        }
        size_++;
    }

    void insert(size_t index,const T& value){
        if (index > size_){
            throw std::out_of_range("index out of range");
        }

        if (index == 0){
            push_front(value);
            return;
        }
        if(index == size_){
            push_back(value);
            return;
        }
        // Находим узел ПЕРЕД тем, куда вставляем
        Node* current = get_node(index-1);
        Node* new_node = new Node(value);

        new_node->next = current->next;
        current->next = new_node;

        size_++;
    }

    void insert(size_t index,T&& value){
        if (index > size_){
            throw std::out_of_range("index out of range");
        }

        if (index == 0){
            push_front(std::move(value));
            return;
        }
        if(index == size_){
            push_back(std::move(value));
            return;
        }
        // Находим узел ПЕРЕД тем, куда вставляем
        Node* current = get_node(index-1);
        Node* new_node = new Node(value);

        new_node->next = current->next;
        current->next = new_node;

        size_++;
    }


    void erase(size_t index){
        if (index >= size_){
            throw std::out_of_range("index out of range");
        }
        if (index == 0) {
            Node* to_delete = head_;
            head_ = head_->next;
            if (head_ == nullptr){
                tail_ = nullptr;
            }
            delete to_delete;
        } else {
            Node* current = get_node(index-1);
            Node* to_delete = current->next;

            current->next = to_delete->next;

            if (to_delete == tail_){
                tail_ = current;
            }

            delete to_delete;
        }
        size_--;
    }

    T& at(size_t index) {
        return get_node(index)->data;
    }

    const T& at(size_t index) const {
        return get_node(index)->data;
    }

    T& operator[](size_t index) {
        return at(index);
    }

    const T& operator[](size_t index) const {
        return at(index);
    }

    size_t size() const {
        return size_;
    }

    bool empty() const {
        return size_ == 0;
    }

};

#endif //SEM3_LAB3_C_SINGLE_LINKED_LIST_H