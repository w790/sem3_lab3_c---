#ifndef SEM3_LAB3_C_DOUBLELINKEDLIST_H
#define SEM3_LAB3_C_DOUBLELINKEDLIST_H

#include <cstddef>
#include <stdexcept>
#include <utility> //для std::move

template<typename T>
class DoublyLinkedList {
private:
    struct Node{
        T data;
        Node* next;
        Node* prev;

        Node(const T& value) : data(value),next(nullptr),prev(nullptr){}
        //конструктор перемещения
        Node(T&& value) : data(std::move(value)),next(nullptr),prev(nullptr){}
    };

    Node* head_;
    Node* tail_;
    size_t size_;

    Node* get_node(size_t index) {
    	if (index >= size_) throw std::out_of_range("index out of range");

    	Node* current = head_;
    	for (size_t i = 0; i < index; i++) {
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

    //конструктор
    DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
    //перемещающийся конструктор
    DoublyLinkedList(DoublyLinkedList&& other) noexcept : head_(other.head_),tail_(other.tail_), size_(other.size_){
        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }

    //перемещащий оператор присваивания
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
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

    //деструктор
    ~DoublyLinkedList(){
        clear();
    }

    void clear(){
        Node* current = head_;
        while (current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
        head_ = tail_ =nullptr;
        size_ = 0;
    }

    void push_back(const T& value){
        Node* new_node = new Node(value);

        if (tail_ == nullptr){
             head_ = tail_ = new_node;
        } else {
            tail_->next = new_node;
            new_node->prev = tail_;
            tail_ = new_node;
        }
        size_++;
    }
    //для r-value
    void push_back(T&& value){
        Node* new_node = new Node(std::move(value));

        if (tail_ == nullptr){
            head_ = tail_ = new_node;
        } else {
            tail_->next = new_node;
            new_node->prev = tail_;
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
            head_->prev = new_node;
            head_ = new_node;
        }
        size_++;
    }
    //для r-value
    void push_front(T&& value){
        Node* new_node = new Node(std::move(value));

        if (head_ == nullptr){
            head_ = tail_ = new_node;
        } else{
            new_node->next = head_;
            head_->prev = new_node;
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
        Node* current = get_node(index);
        Node* new_node = new Node(value);

        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;

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
        Node* current = get_node(index);
        Node* new_node = new Node(std::move(value));

        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;

        size_++;
    }

    void erase(size_t index){
        if (index > size_){
    	    throw std::out_of_range("index out of range");
	    }
	    Node* to_delete = get_node(index);
	    if (to_delete->prev){
		    to_delete->prev->next = to_delete->next;
	    } else {
		    head_ = to_delete->next;
	    }

	    if (to_delete->next){
		    to_delete->next->prev = to_delete->prev;
	    } else {
		    tail_ = to_delete->prev;
	    }

	    delete to_delete;
	    size_--;
    }

    T& at(size_t index){
        return get_node(index)->data;
    }

    const T& at(size_t index) const {
        return get_node(index)->data;
    }

    T& operator[](size_t index){
        return at(index);
    }

    const T& operator[](size_t index) const{
        return at(index);
    }

    size_t size() const{
        return size_;
    }

    bool empty() const{
        return size_ == 0;
    }
};

#endif //SEM3_LAB3_C_DOUBLELINKEDLIST_H