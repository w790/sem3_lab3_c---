#ifndef SEM3_LAB3_C_SEQUENTIAL_CONTAINER_H
#define SEM3_LAB3_C_SEQUENTIAL_CONTAINER_H

#include <cstddef> //для size_t
#include <utility> // для std::move
#include <memory>


template<typename T> //T-шаблонный параметр
class SequentialContainer {

private:
    std::unique_ptr<T[]> data; // память
    size_t size_; //размер
    size_t capacity_;//выделенная емкость


public:

    class Iterator {
    private:
        T* ptr_;
    public:
        Iterator(T* ptr) : ptr_(ptr) {}

        T& operator*(){
            return *ptr_;
        }

        T* get(){
            return ptr_;
        }
    };

    SequentialContainer(): data(nullptr),size_(0),capacity_(0) {}//конструктор со списком инициализации

    Iterator begin() {
        return Iterator(data.get());//возвращает итератор на начало
    }

    Iterator end() {
        return Iterator(data.get() + size_);;//возвращает итератор на конец
    }

    //перемещающий конструктор
    SequentialContainer(SequentialContainer&& other) noexcept : data(std::move(other.data)), size_(other.size_), capacity_(other.capacity_) {
    other.size_ = 0;
    other.capacity_ = 0;
    }

    //перемещающий оператор присваивания
    SequentialContainer& operator=(SequentialContainer&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);//автоматическое освобождение старой памяти
            size_ = other.size_;
            capacity_ = other.capacity_;
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }

    //~SequentialContainer(){ // деструктор - освобождаем память(можно при использовании умных указателей не писать)
    //    delete[] data;
    //}

    //резервирование памяти
    void reserve(size_t new_capacity){
        if (new_capacity <= capacity_) return;
        auto new_data = std::make_unique<T[]>(new_capacity);//создание нового массива
        for(size_t i = 0; i < size_; i++){
            new_data[i] = std::move(data[i]); //используем перемещение для эффективности
        }
        data = std::move(new_data);//заменяем старый массив новым (автоматическое освобождение)
        capacity_ = new_capacity;
    }

    void push_back(const T& value) {
        if (capacity_ == 0) {
            size_t new_capacity = 1;
            reserve(new_capacity); // выделяем память
        }
        else if (size_ >= capacity_){
            size_t new_capacity = capacity_ * 2;
            reserve(new_capacity);
        }
        data[size_] = value;
        size_++;
    }
    // перегрузка для временных объектов
    void push_back(T&& value) {
        if (capacity_ == 0) {
            size_t new_capacity = 1;
            reserve(new_capacity); // выделяем память
        }
        else if (size_ >= capacity_){
            size_t new_capacity = capacity_ * 2;
            reserve(new_capacity);
        }
        data[size_] = std::move(value);
        size_++;
    }

    //операторы делают код удобным в использовании кароче можно к ним обращаться как к встроенным массивам
    T& operator[](size_t index){ // ссылка на T можно менять значения
        return data[index];
    }

    const T& operator[](size_t index) const { // константная ссылка на T можно читать значения
        return data[index];
    }

    size_t size() const { //зачем const в конце ?чтобы не изменить состояние объекта
        return size_;
    }

    void insert(size_t index, const T& value) {
        if (index > size_) return;

        if (capacity_ == 0) {
            size_t new_capacity = 1;
            reserve(new_capacity); // выделяем память
        }
        else if (size_ >= capacity_){
            size_t new_capacity = capacity_ * 2;
            reserve(new_capacity);
        }
        // сдвигаем элементы вправо
        for (size_t i = size_; i > index; --i) {
            data[i] = std::move(data[i - 1]);
        }

        data[index] = value;
        size_++;
    }

    void erase(size_t index) {
        if (index > size_) {
            return;
        }
        for(size_t i = index;i<size_ - 1;i++){
            data[i] = data[i + 1];
        }
        size_--;

    }


};


#endif //SEM3_LAB3_C_SEQUENTIAL_CONTAINER_H