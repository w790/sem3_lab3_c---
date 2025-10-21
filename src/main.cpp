#include "../include/sequential_container.h"
#include "../include/DoubleLinkedList.h"
#include "../include/single_linked_list.h"
#include <iostream>

void test_sequential_container() {
    std::cout << "Тест контейнера вектор" << std::endl;

    //создаем контейнер
    SequentialContainer<int> container1;
    std::cout << " 1.Контейнер создан " << std::endl;

    //добавляем 10 эдементов в контейнер
    for (int i = 0; i < 10; i++) {
        container1.push_back(i);
    }
    std::cout << " 2.Добавлены элементы 0-9 " << std::endl;

    //вывод
    std::cout << " 3. Содержимое контейнера " << std::endl;
    for (size_t i = 0; i < container1.size(); i++) {
        std::cout << container1[i] << std::endl;
    }

    //вывод размера
    std::cout<<" 4. Размер контейнера :"<< container1.size()<<std::endl;


    // 5. Удаление третьего (по счёту), пятого и седьмого элементов
    // Индексы: 2 (третий), 4 (пятый), 6 (седьмой)
    container1.erase(2);
    container1.erase(3);
    container1.erase(4);
    std::cout << "5. Удалены 3-й, 5-й и 7-й элементы" << std::endl;

    std::cout << "6. Содержимое после удаления" << std::endl;
    for (size_t i = 0; i < container1.size(); i++) {
        std::cout << container1[i] << std::endl;
    }
    // Ожидаемый результат: 0, 1, 3, 5, 7, 8, 9

    // 7. Добавление элемента 10 в начало контейнера
    container1.insert(0,10);
    std::cout << "7. Добавлен элемент 10 в начало" << std::endl;

    // 8. Вывод содержимого контейнера на экран
    std::cout << "8. Содержимое после добавления в начало" << std::endl;
    for (size_t i = 0; i < container1.size(); i++) {
        std::cout << container1[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9

    // 9. Добавление элемента 20 в середину контейнера
    // Вставляем на позицию 4 (после 3, перед 5)
    container1.insert(4, 20);
    std::cout << "9. Добавлен элемент 20 в середину (позиция 4)" << std::endl;

    // 10. Вывод содержимого контейнера на экран
    std::cout << "10. Содержимое после добавления в середину" << std::endl;
    for (size_t i = 0; i < container1.size(); i++) {
        std::cout << container1[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9

    // 11. Добавление элемента 30 в конец контейнера
    container1.push_back(30);
    std::cout << "11. Добавлен элемент 30 в конец" << std::endl;

    // 12. Вывод содержимого контейнера на экран
    std::cout << "12. Финальное содержимое" << std::endl;
    for (size_t i = 0; i < container1.size(); i++) {
        std::cout << container1[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30

    std::cout << "Размер после выполненных операций: " << container1.size() << std::endl;
    std::cout << "ТЕСТ ВЕКТОРА ЗАВЕРШЕН" << std::endl << std::endl;

}

void double_linked_list_container() {
    std::cout << "Тест контейнера двусвязный список" << std::endl;

    //создаем контейнер
    DoublyLinkedList<int> container2;
    std::cout << " 1.Контейнер создан " << std::endl;

    //добавляем 10 эдементов в контейнер
    for (int i = 0; i < 10; i++) {
        container2.push_back(i);
    }
    std::cout << " 2.Добавлены элементы 0-9 " << std::endl;

    //вывод
    std::cout << " 3. Содержимое контейнера " << std::endl;
    for (size_t i = 0; i < container2.size(); i++) {
        std::cout << container2[i] << std::endl;
    }

    //вывод размера
    std::cout<<" 4. Размер контейнера :"<< container2.size()<<std::endl;


    // 5. Удаление третьего (по счёту), пятого и седьмого элементов
    // Индексы: 2 (третий), 4 (пятый), 6 (седьмой)
    container2.erase(2);
    container2.erase(3);
    container2.erase(4);
    std::cout << "5. Удалены 3-й, 5-й и 7-й элементы" << std::endl;

    std::cout << "6. Содержимое после удаления" << std::endl;
    for (size_t i = 0; i < container2.size(); i++) {
        std::cout << container2[i] << std::endl;
    }
    // Ожидаемый результат: 0, 1, 3, 5, 7, 8, 9

    // 7. Добавление элемента 10 в начало контейнера
    container2.push_front(10);
    std::cout << "7. Добавлен элемент 10 в начало" << std::endl;

    // 8. Вывод содержимого контейнера на экран
    std::cout << "8. Содержимое после добавления в начало" << std::endl;
    for (size_t i = 0; i < container2.size(); i++) {
        std::cout << container2[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9

    // 9. Добавление элемента 20 в середину контейнера
    // Вставляем на позицию 4 (после 3, перед 5)
    container2.insert(4, 20);
    std::cout << "9. Добавлен элемент 20 в середину (позиция 4)" << std::endl;

    // 10. Вывод содержимого контейнера на экран
    std::cout << "10. Содержимое после добавления в середину" << std::endl;
    for (size_t i = 0; i < container2.size(); i++) {
        std::cout << container2[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9

    // 11. Добавление элемента 30 в конец контейнера
    container2.push_back(30);
    std::cout << "11. Добавлен элемент 30 в конец" << std::endl;

    // 12. Вывод содержимого контейнера на экран
    std::cout << "12. Финальное содержимое" << std::endl;
    for (size_t i = 0; i < container2.size(); i++) {
        std::cout << container2[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30

    std::cout << "Размер после выполненных операций: " << container2.size() << std::endl;
    std::cout << "ТЕСТ ДВУСВЯЗНОГО СПИСКА ЗАВЕРШЕН " << std::endl << std::endl;

}


void single_linked_list_container() {
    std::cout << "Тест контейнера односвязный список" << std::endl;

    //создаем контейнер
    SinglyLinkedList<int> container3;
    std::cout << " 1.Контейнер создан " << std::endl;

    //добавляем 10 эдементов в контейнер
    for (int i = 0; i < 10; i++) {
        container3.push_back(i);
    }
    std::cout << " 2.Добавлены элементы 0-9 " << std::endl;

    //вывод
    std::cout << " 3. Содержимое контейнера " << std::endl;
    for (size_t i = 0; i < container3.size(); i++) {
        std::cout << container3[i] << std::endl;
    }

    //вывод размера
    std::cout<<" 4. Размер контейнера :"<< container3.size()<<std::endl;


    // 5. Удаление третьего (по счёту), пятого и седьмого элементов
    // Индексы: 2 (третий), 4 (пятый), 6 (седьмой)
    container3.erase(2);
    container3.erase(3);
    container3.erase(4);
    std::cout << "5. Удалены 3-й, 5-й и 7-й элементы" << std::endl;

    std::cout << "6. Содержимое после удаления" << std::endl;
    for (size_t i = 0; i < container3.size(); i++) {
        std::cout << container3[i] << std::endl;
    }
    // Ожидаемый результат: 0, 1, 3, 5, 7, 8, 9

    // 7. Добавление элемента 10 в начало контейнера
    container3.push_front(10);
    std::cout << "7. Добавлен элемент 10 в начало" << std::endl;

    // 8. Вывод содержимого контейнера на экран
    std::cout << "8. Содержимое после добавления в начало" << std::endl;
    for (size_t i = 0; i < container3.size(); i++) {
        std::cout << container3[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 5, 7, 8, 9

    // 9. Добавление элемента 20 в середину контейнера
    // Вставляем на позицию 4 (после 3, перед 5)
    container3.insert(4, 20);
    std::cout << "9. Добавлен элемент 20 в середину (позиция 4)" << std::endl;

    // 10. Вывод содержимого контейнера на экран
    std::cout << "10. Содержимое после добавления в середину" << std::endl;
    for (size_t i = 0; i < container3.size(); i++) {
        std::cout << container3[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9

    // 11. Добавление элемента 30 в конец контейнера
    container3.push_back(30);
    std::cout << "11. Добавлен элемент 30 в конец" << std::endl;

    // 12. Вывод содержимого контейнера на экран
    std::cout << "12. Финальное содержимое" << std::endl;
    for (size_t i = 0; i < container3.size(); i++) {
        std::cout << container3[i] << std::endl;
    }
    // Ожидаемый результат: 10, 0, 1, 3, 20, 5, 7, 8, 9, 30

    std::cout << "Размер после выполненных операций: " << container3.size() << std::endl;
    std::cout << "ТЕСТ ОДНОСВЯЗНОГО СПИСКА ЗАВЕРШЕН " << std::endl << std::endl;

}

void Sequential_Container_test_move_semantics() {
    std::cout << "ТЕСТ СЕМАНТИКИ ПЕРЕМЕЩЕНИЯ " << std::endl;

    //перемещающий конструктор
    SequentialContainer<int> container1;
    container1.push_back(1);
    container1.push_back(2);
    container1.push_back(3);

    std::cout << "До перемещения - container1: ";
    for (size_t i = 0; i < container1.size(); i++) {
        std::cout << container1[i] << " ";
    }
    std::cout << std::endl;

    //используем перемещающий конструктор
    SequentialContainer<int> container2 = std::move(container1);

    std::cout << "После перемещения - container1 (должен быть пустой): ";
    std::cout << "размер = " << container1.size() << std::endl;

    std::cout << "После перемещения - container2: ";
    for (size_t i = 0; i < container2.size(); i++) {
        std::cout << container2[i] << " ";
    }
    std::cout << std::endl;

    //Перемещающее присваивание
    SequentialContainer<int> container3;
    container3 = std::move(container2);

    std::cout << "После присваивания - container2 (должен быть пустой): ";
    std::cout << "размер = " << container2.size() << std::endl;

    std::cout << "После присваивания - container3: ";
    for (size_t i = 0; i < container3.size(); i++) {
        std::cout << container3[i] << " ";
    }
    std::cout << std::endl;

    //push_back с r-value
    std::string temp_string = "Hello";
    SequentialContainer<std::string> str_container;

    str_container.push_back(temp_string);           // Копирование
    str_container.push_back(std::move(temp_string)); // Перемещение
    str_container.push_back("World");               // Перемещение (временный объект)

    std::cout << "Строковый контейнер: ";
    for (size_t i = 0; i < str_container.size(); i++) {
        std::cout << str_container[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Исходная строка после std::move: " << temp_string << std::endl;

    std::cout << " ТЕСТ ЗАВЕРШЕН " << std::endl << std::endl;
}

void test_doubly_linked_list_move_semantics() {
    std::cout << " ТЕСТ ПЕРЕМЕЩЕНИЯ ДВУСВЯЗНОГО СПИСКА " << std::endl;

    //тест перемещающего конструктора
    DoublyLinkedList<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    std::cout << "до перемещения - list1: ";
    for (size_t i = 0; i < list1.size(); i++) {
        std::cout << list1[i] << " ";
    }
    std::cout << std::endl;

    //перемещающий конструктор
    DoublyLinkedList<int> list2 = std::move(list1);

    std::cout << "После перемещения - list1 размер: " << list1.size() << std::endl;
    std::cout << "После перемещения - list2: ";
    for (size_t i = 0; i < list2.size(); i++) {
        std::cout << list2[i] << " ";
    }
    std::cout << std::endl;

    DoublyLinkedList<int> list3;

    // перемещающий оператор присваивания
    list3 = std::move(list2);

    std::cout << "После присваивания - list2 (должен быть пустой): ";
    std::cout << "размер = " << list2.size() << std::endl;

    std::cout << "После присваивания - list3: ";
    for (size_t i = 0; i < list3.size(); i++) {
        std::cout << list3[i] << " ";
    }
    std::cout << std::endl;

    //тест push_back с перемещением
    std::string str = "Hello";
    DoublyLinkedList<std::string> str_list;

    str_list.push_back(str);              // Копирование
    str_list.push_back(std::move(str));   // Перемещение
    str_list.push_back("World");          // Перемещение (временный объект)

    std::cout << "Строковый список: ";
    for (size_t i = 0; i < str_list.size(); i++) {
        std::cout << str_list[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Исходная строка после std::move: '" << str << "'" << std::endl;

    std::cout << " ТЕСТ ЗАВЕРШЕН " << std::endl << std::endl;
}

void test_singly_linked_list_move_semantics() {
    std::cout << "ТЕСТ ПЕРЕМЕЩЕНИЯ ОДНОСВЯЗНОГО СПИСКА" << std::endl;

    //тест перемещающего конструктора
    SinglyLinkedList<int> list1;
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);

    std::cout << "До перемещения - list1: ";
    for (size_t i = 0; i < list1.size(); i++) {
        std::cout << list1[i] << " ";
    }
    std::cout << std::endl;

    //Перемещающий конструктор
    SinglyLinkedList<int> list2 = std::move(list1);

    std::cout << "После перемещения - list1 размер: " << list1.size() << std::endl;
    std::cout << "После перемещения - list2: ";
    for (size_t i = 0; i < list2.size(); i++) {
        std::cout << list2[i] << " ";
    }
    std::cout << std::endl;

    //тест push_back с перемещением
    std::string text = "Hello";
    SinglyLinkedList<std::string> str_list;

    str_list.push_back(text);              // Копирование
    str_list.push_back(std::move(text));   // Перемещение
    str_list.push_back("World");           // Перемещение (временный объект)

    std::cout << "Строковый список: ";
    for (size_t i = 0; i < str_list.size(); i++) {
        std::cout << str_list[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Исходная строка после std::move: '" << text << "'" << std::endl;

    //тест перемещающего присваивания
    SinglyLinkedList<int> list3;
    list3 = std::move(list2);

    std::cout << "После присваивания - list2 размер: " << list2.size() << std::endl;
    std::cout << "После присваивания - list3: ";
    for (size_t i = 0; i < list3.size(); i++) {
        std::cout << list3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "ТЕСТ ЗАВЕРШЕН" << std::endl << std::endl;
}


void test_sequential_container_iterators(){
    std::cout << "ТЕСТ sequential ИТЕРАТОРОВ" << std::endl;

    SequentialContainer<int> container;
    container.push_back(10);
    container.push_back(20);
    container.push_back(30);

    auto begin_it = container.begin();

    auto end_it = container.end();

    //operator*() работает
    std::cout << "begin(): " << *begin_it << std::endl;

    //get() работает
    std::cout << "begin().get(): " << begin_it.get() << std::endl;

    // Демонстрация, что это разные итераторы
    std::cout << "begin() != end(): " << (&*begin_it != &*end_it) << std::endl;

    std::cout << "ТЕСТ ЗАВЕРШЕН" << std::endl << std::endl;
}

void test_doubly_linked_list_container_iterators(){
    std::cout << "ТЕСТ doubly_linked_list_container ИТЕРАТОРОВ" << std::endl;

    DoublyLinkedList<int> container;
    container.push_back(100);
    container.push_back(200);
    container.push_back(300);

    auto begin_it = container.begin();

    auto end_it = container.end();

    //operator*() работает
    std::cout << "begin(): " << *begin_it << std::endl;

    //get() работает
    std::cout << "begin().get(): " << begin_it.get() << std::endl;

    std::cout<< "end(): "<< end_it.get() <<std::endl;

    std::cout << "ТЕСТ ЗАВЕРШЕН" << std::endl << std::endl;
}

void test_singly_linked_list_container_iterators(){
    std::cout << "ТЕСТ singly_linked_list_container ИТЕРАТОРОВ" << std::endl;

    SinglyLinkedList<int> container;
    container.push_back(1000);
    container.push_back(2000);
    container.push_back(3000);

    auto begin_it = container.begin();
    auto end_it = container.end();

    // operator*() работает
    std::cout << "begin(): " << *begin_it << std::endl;

    // get() работает
    std::cout << "begin().get(): " << begin_it.get() << std::endl;

    std::cout << "end(): " << end_it.get() << std::endl;

    std::cout << "ТЕСТ ЗАВЕРШЕН" << std::endl << std::endl;
}

int main() {
    test_sequential_container();
    double_linked_list_container();
    single_linked_list_container();
    Sequential_Container_test_move_semantics();
    test_doubly_linked_list_move_semantics();
    test_singly_linked_list_move_semantics();
    test_sequential_container_iterators();
    test_doubly_linked_list_container_iterators();
    test_singly_linked_list_container_iterators();
    return 0;
}