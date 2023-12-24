#include <iostream>

class Node {
public:
    int key;
    Node* p;
    Node(int k) : key(k), p(nullptr) {}
};

class Stack {
private:
    Node* head;

public:
    Stack() : head(nullptr) {}

    ~Stack() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->p;
            delete tmp;
        }
    }

    void push(int key) {
        Node* node = new Node(key);
        node->p = head;
        head = node;
    }

    void pop() {
        if (head == nullptr) {
            std::cout << "Стек пуст" << std::endl;
        }
        else {
            Node* tmp = head;
            std::cout << "Удаленый элемент: " << tmp->key << std::endl;
            head = head->p;
            delete tmp;
        }
    }

    void remove() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->p;
            delete tmp;
        }
        std::cout << "Стек очищен" << std::endl;
    }

    void print() {
        Node* tmp = head;
        std::cout << "Стек: ";
        while (tmp != nullptr) {
            std::cout << tmp->key << " ";
            tmp = tmp->p;
        }
        std::cout << std::endl;
    }

    int size() {
        int s = 0;
        Node* tmp = head;
        while (tmp != nullptr) {
            s++;
            tmp = tmp->p;
        }
        return s;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    Stack stack;
    int choice, element;

    while (true) {
        std::cout << "1. Запушить элемент" << std::endl;
        std::cout << "2. Удалить элемент" << std::endl;
        std::cout << "3. Очистить стек" << std::endl;
        std::cout << "4. Вывести весь стек" << std::endl;
        std::cout << "5. Получить количество элементов в стеке" << std::endl;
        std::cout << "6. Выйти" << std::endl;
        std::cout << "Введите номер: ";
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Введите элемент: ";
            std::cin >> element;
            stack.push(element);
        }
        else if (choice == 2) {
            stack.pop();
        }
        else if (choice == 3) {
            stack.remove();
        }
        else if (choice == 4) {
            stack.print();
        }
        else if (choice == 5) {
            std::cout << "Количество элементов в стеке: " << stack.size() << std::endl;
        }
        else if (choice == 6) {
            break;
        }
        else {
            std::cout << "Неверный ввод" << std::endl;
        }
    }

    return 0;
}