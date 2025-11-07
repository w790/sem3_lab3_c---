#ifndef SEM3_LAB3_C_DOUBLELINKEDLIST_H
#define SEM3_LAB3_C_DOUBLELINKEDLIST_H

#include <cstddef>
#include <stdexcept>
#include <utility> //для std::move
#include <memory>

template<typename T>
class DoublyLinkedList {
private:
    struct Node{
        T data;
        std::unique_ptr<Node> next;
        Node* prev;

        Node(const T& value) : data(value),next(nullptr),prev(nullptr){}
        //конструктор перемещения
        Node(T&& value) : data(std::move(value)),next(nullptr),prev(nullptr){}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;
    size_t size_;

    Node* get_node(size_t index) {
    	if (index >= size_) throw std::out_of_range("index out of range");

    	Node* current = head_.get();
    	for (size_t i = 0; i < index; i++) {
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

    //конструктор
    DoublyLinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}
    //перемещающийся конструктор
    DoublyLinkedList(DoublyLinkedList&& other) noexcept : head_(std::move(other.head_)),tail_(other.tail_), size_(other.size_){
        other.tail_ = nullptr;
        other.size_ = 0;
    }

    //перемещащий оператор присваивания
    DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept {
        if (this != &other) {
            clear();//освобождаем старые данные

            //крадем ресурсы у other
            head_ = std::move(other.head_);
            tail_ = other.tail_;
            size_ = other.size_;

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
        head_.reset();  //автоматически удаляет всю цепочку!
        tail_ = nullptr;
        size_ = 0;
    }

    void push_back(const T& value){
        auto new_node = std::make_unique<Node>(value);
        Node* new_raw = new_node.get();

        if (tail_ == nullptr){
            head_ = std::move(new_node);
            tail_ = new_raw;
        } else {
            new_raw->prev = tail_;
            tail_->next = std::move(new_node);
            tail_ = new_raw;
        }
        size_++;
    }
    //для r-value
    void push_back(T&& value){
        auto new_node = std::make_unique<Node>(std::move(value));
        Node* new_raw = new_node.get();

        if (tail_ == nullptr){
            head_ = std::move(new_node);
            tail_ = new_raw;
        } else {
            new_raw->prev = tail_;
            tail_->next = std::move(new_node);
            tail_ = new_raw;
        }
        size_++;
    }

    void push_front(const T& value){
        auto new_node = std::make_unique<Node>(value);
        Node* new_raw = new_node.get();

        if (head_ == nullptr){
            head_ = std::move(new_node);
            tail_ = new_raw;
        } else{
            new_raw->next = std::move(head_);
            new_raw->next->prev = new_raw;
            head_ = std::move(new_node);
        }
        size_++;
    }
    //для r-value
    void push_front(T&& value){
        auto new_node = std::make_unique<Node>(std::move(value));
        Node* new_raw = new_node.get();

        if (head_ == nullptr){
            head_ = std::move(new_node);
            tail_ = new_raw;
        } else{
            new_raw->next = std::move(head_);
            new_raw->next->prev = new_raw;
            head_ = std::move(new_node);
        }
        size_++;
    }

    void insert(size_t index, const T& value) {
        if (index > size_) {
            throw std::out_of_range("index out of range");
        }

        if (index == 0) {
            push_front(value);
            return;
        }
        if (index == size_) {
            push_back(value);
            return;
        }

        // НАЙДИ УЗЕЛ ПЕРЕД позицией вставки, а не саму позицию!
        Node* prev_node = get_node(index - 1);  // ← ИЗМЕНЕНИЕ ЗДЕСЬ
        auto new_node = std::make_unique<Node>(value);
        Node* new_raw = new_node.get();

        // Вставляем между prev_node и prev_node->next
        new_raw->prev = prev_node;
        new_raw->next = std::move(prev_node->next);

        // Обновляем указатели соседних узлов
        if (new_raw->next) {
            new_raw->next->prev = new_raw;
        }

        prev_node->next = std::move(new_node);
        size_++;
    }

    void insert(size_t index, T&& value) {
        if (index > size_) {
            throw std::out_of_range("index out of range");
        }

        if (index == 0) {
            push_front(std::move(value));
            return;
        }
        if (index == size_) {
            push_back(std::move(value));
            return;
        }

        // Тот же принцип - используй prev_node
        Node* prev_node = get_node(index - 1);  // ← ИЗМЕНЕНИЕ ЗДЕСЬ
        auto new_node = std::make_unique<Node>(std::move(value));
        Node* new_raw = new_node.get();

        new_raw->prev = prev_node;
        new_raw->next = std::move(prev_node->next);

        if (new_raw->next) {
            new_raw->next->prev = new_raw;
        }

        prev_node->next = std::move(new_node);
        size_++;
    }

    void erase(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("index out of range");
        }

        if (index == 0) {
            // Удаляем первый элемент
            if (size_ == 1) {
                head_.reset();
                tail_ = nullptr;
            } else {
                head_ = std::move(head_->next);
                head_->prev = nullptr;
            }
        } else if (index == size_ - 1) {
            // Удаляем последний элемент
            tail_ = tail_->prev;
            tail_->next.reset();
        } else {
            // Удаляем из середины - ИСПРАВЛЕННАЯ ЧАСТЬ
            Node* to_delete = get_node(index);

            // Сохраняем указатель на следующий узел ДО перемещения
            Node* next_node = to_delete->next.get();

            // Перемещаем владение следующим узлом к предыдущему
            to_delete->prev->next = std::move(to_delete->next);

            // Обновляем prev у следующего узла
            if (next_node) {
                next_node->prev = to_delete->prev;
            }
        }
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