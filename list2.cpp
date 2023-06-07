#include <iostream>

using namespace std;

template <typename T>
class List
{
    struct Item
    {
        T inf;
        Item* next;
        Item* prev;
        Item(T x, Item* ref = nullptr, Item* prevRef = nullptr) : inf(x), next(ref), prev(prevRef) {}
    }
    *first = nullptr,
        * last = nullptr;
    unsigned int size = 0;

public:
    List() : first(nullptr), last(nullptr), size(0) {}
    List(const List& other) : first(nullptr), last(nullptr), size(0)
    {
        for (Item* t = other.first; t != nullptr; t = t->next)
        {
            this->add(t->inf);
        }
    }
    Item* begin() {
        return this->first;
    }
    Item* end() {
        return this->last;
    }
    //добавить новый эл. в конец списка
    void add(T x)
    {
        Item* t = new Item(x);
        if (size == 0)
        {
            first = t;
            last = t;
        }
        else
        {
            last->next = t;
            t->prev = last;
            last = t;
        }
        size++;
    }
    //удалить последний эл
    void pop_back()
    {
        if (size == 0)
        {
            return;
        }
        else if (size == 1)
        {
            delete last;
            first = nullptr;
            last = nullptr;
            size = 0;
        }
        else
        {
            Item* t = last->prev;
            t->next = nullptr;
            delete last;
            last = t;
            size--;
        }
    }
    ~List()
    {
        while (first != nullptr)
        {
            this->pop_back();
        }
    }
    //удаление эл-та
    void erase(Item* t)
    {
        if (t == nullptr)
        {
            return;
        }
        if (t == first)
        {
            this->pop_head();
            return;
        }

        if (t == last)
        {
            this->pop_back();
            return;
        }
        t->prev->next = t->next;
        t->next->prev = t->prev;
        delete t;
        size--;
    }
    //возвращает макс эл
    T get_max()
    {
        T mn = this->first->inf;
        for (Item* t = first; t != nullptr; t = t->next)
        {
            if (t->inf > mn)
            {
                mn = t->inf;
            }
        }
        return mn;
    }
    //удалить первый эл
    void pop_head()
    {
        if (first == nullptr)
        {
            return;
        }
        Item* t = first;
        first = t->next;
        if (first != nullptr)
        {
            first->prev = nullptr;
        }
        else
        {
            last = nullptr;
        }
        delete t;
        size--;
    }
    //удаление эл-тов с заданным значением
    void delete_value(T value)
    {
        Item* t = first;
        while (t != nullptr)
        {
            if (t->inf == value)
            {
                Item* toDelete = t;
                t = t->next;
                erase(toDelete);
            }
            else
            {
                t = t->next;
            }
        }
    }
    //вставка эл-та справа
    void insert_after(Item* t, T x)
    {
        if (t == nullptr)
        {
            return;
        }
        Item* newItem = new Item(x, t->next, t);
        if (t->next != nullptr)
        {
            t->next->prev = newItem;
        }
        else
        {
            last = newItem;
        }
        t->next = newItem;
        size++;
    }
    //печатает список
    void print()
    {
        for (Item* t = first; t != nullptr; t = t->next)
            cout << t->inf << " ";
        cout << endl;
    }
    //печатает наоборот(навсякий)
    void reverse_print()
    {
        for (Item* t = last; t != nullptr; t = t->prev)
            cout << t->inf << " ";
        cout << endl;
    }
    T& operator[](int index)
    {
        Item* t = first;
        for (int i = 0; i < index; i++)
        {
            t = t->next;
        }
        return t->inf;
    }
};

int main()
{
    List<int> lst;
    int t, n = 10;
    //добавляем с клавиатуры эл-ты в список
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        lst.add(t);
    }
    //находим макс эл
    int m = lst.get_max();
    //удаляем все эл-ты с заданным значением (макс)
    lst.delete_value(m);
    lst.print();
    /*List<int> lst1;
    lst1.add(1);
    lst1.add(2);
    lst1.add(3);
    auto t = lst1.begin();*/
    // Вставка после первого
    //lst1.insert_after(t, 4);
    // Вставка после второго
    //t = t->next;
    //lst1.insert_after(t, 4);
    //Вставка после третьего
    //t = t->next;
    //lst1.insert_after(t, 4);
    // Вставка после последнего
    //auto y = lst1.end();
    //lst1.insert_after(y, 4);
    // Вставка перед последним
    //y = lst1.end()->prev;
    //lst1.insert_after(y, 77);
    //lst1.print();
    system("pause");
}
