#ifndef SEM3_LAB3_C_SINGLE_LINKED_LIST_H
#define SEM3_LAB3_C_SINGLE_LINKED_LIST_H

#include <cstddef>
#include <stdexcept>
#include <utility>
#include <memory>

template<typename T>
class SinglyLinkedList{
private:
    struct Node{
        T data;
        std::unique_ptr<Node> next;
        Node(const T& value): data(value),next(nullptr){}
        //конструктор перемещения для Node
        Node(T&& value) : data(std::move(value)),next(nullptr){}
    };
    std::unique_ptr<Node> head_;
    Node* tail_;
    size_t size_;

    Node* get_node(size_t index) const{
        if (index>=size_) throw std::out_of_range{"index out of range"};
        Node* current = head_.get();
        for (size_t i =0;i<index;i++){
            current = current->next.get();
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
        return Iterator(head_.get());//возвращает итератор на начало
    }

    Iterator end() {
        return Iterator(nullptr);//возвращает итератор на конец(после последнего элемента)
    }

    SinglyLinkedList():head_(nullptr),tail_(nullptr),size_(0){}

    //перемещающий конструктор
    SinglyLinkedList(SinglyLinkedList&& other) noexcept : head_(std::move(other.head_)),tail_(other.tail_), size_(other.size_){
        other.tail_ = nullptr;
        other.size_ = 0;
    }


    //перемещащий оператор присваивания
    SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept {
        if (this != &other) {
            // Автоматическое освобождение старой памяти через reset()
            head_.reset();

            //крадем ресурсы у other
            head_ = std::move(other.head_);
            tail_ = other.tail_;
            size_ = other.size_;

            other.tail_ = nullptr;
            other.size_ = 0;
        }
        return *this;
    }
    //теперь его можно не писать умные указатели сами работают с
    //~SinglyLinkedList(){
    //    clear();
    //}

    void clear(){
        head_.reset(); //автоматически удаляет всю цепочку узлов
        tail_= nullptr;
        size_ = 0;
    }

    void push_back(const T& value){
        auto new_node = std::make_unique<Node>(value);
        Node* new_raw = new_node.get();

        if (!tail_){
            // Список пустой
            head_ = std::move(new_node);
            tail_ = new_raw;
        } else {
            tail_->next = std::move(new_node);
            tail_ = new_raw;
        }
        size_++;
    }

    void push_back(T&& value){
        auto new_node = std::make_unique<Node>(std::move(value));
        Node* new_raw = new_node.get();

        if (tail_ == nullptr){
            head_ = std::move(new_node);
            tail_ = new_raw;
        } else {
            tail_->next = std::move(new_node);
            tail_ = new_raw;
        }
        size_++;
    }

    void push_front(const T& value){
        auto new_node = std::make_unique<Node>(value);

        if (head_ == nullptr){
            head_ = std::move(new_node);
            tail_ = head_.get();
        } else{
            new_node->next = std::move(head_);
            head_ = std::move(new_node);
        }
        size_++;
    }

    void push_front(T&& value){
        auto new_node = std::make_unique<Node>(std::move(value));

        if (head_ == nullptr){
            head_ = std::move(new_node);
            tail_ = head_.get();
        } else{
            new_node->next = std::move(head_);
            head_ = std::move(new_node);
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
        auto new_node = std::make_unique<Node>(value);

        new_node->next = std::move(current->next);
        current->next = std::move(new_node);

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
        auto new_node = std::make_unique<Node>(std::move(value));

        new_node->next = std::move(current->next);
        current->next = std::move(new_node);

        size_++;
    }


    void erase(size_t index){
        if (index >= size_){
            throw std::out_of_range("index out of range");
        }

        if (index == 0) {
            // Удаляем первый элемент
            head_ = std::move(head_->next);
            if (!head_) {
                tail_ = nullptr;
            }
        } else {
            Node* prev = get_node(index - 1);
            auto& to_delete = prev->next;

            if (to_delete.get() == tail_) {
                tail_ = prev;  // Сначала обновляем tail если нужно
            }
            to_delete = std::move(to_delete->next);  // Затем переключаем указатели
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