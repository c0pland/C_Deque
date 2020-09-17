#include <stdlib.h>
#include <iostream>
using namespace std;


struct Node                             //Структура, являющаяся звеном списка
{
    float x;                             //Значение x будет передаваться в список
    Node* Next, * Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
};

class Deque                              //Создаем тип данных Список
{
    Node* Head, * Tail;                 //Указатели на адреса начала списка и его конца
public:
    Deque() :Head(NULL), Tail(NULL) {};    //Инициализируем адреса как пустые
    ~Deque();                           //Прототип деструктора
    void show();                       //Прототип функции отображения списка на экране
    void pushBack(float x);                 //Прототип функции добавления элементов в список
    float popBack();
    int size();
    void pushFront(float x);
    float popFront();
    void clear();
    bool isEmpty();
};

Deque::~Deque()                           //Деструктор
{
    while (Head)                       //Пока по адресу на начало списка что-то есть
    {
        Tail = Head->Next;             //Резервная копия адреса следующего звена списка
        delete Head;                   //Очистка памяти от первого звена
        Head = Tail;                   //Смена адреса начала на адрес следующего элемента
    }
}

void Deque::pushBack(float x)
{
    Node* temp = new Node;               //Выделение памяти под новый элемент структуры
    temp->Next = NULL;                   //Указываем, что изначально по следующему адресу пусто
    temp->x = x;                         //Записываем значение в структуру

    if (Head != NULL)                    //Если список не пуст
    {
        temp->Prev = Tail;               //Указываем адрес на предыдущий элемент в соотв. поле
        Tail->Next = temp;               //Указываем адрес следующего за хвостом элемента
        Tail = temp;                     //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->Prev = NULL;               //Предыдущий элемент указывает в пустоту
        Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
    }
}

float Deque::popBack()
{
    if (this->size() != 0)
    {
        float popValue = Tail->x;
        Node* newTail = Tail->Prev;
        delete Tail;
        Tail = newTail;
        Tail->Next = NULL;
        return popValue;
    }
    else
        throw out_of_range("Nothing to pop!");
}

int Deque::size()
{
    int i = 0;
    Node* temp = Head;                       //Временно указываем на адрес первого элемента
    while (temp != NULL)              //Пока не встретим пустое значение
    {
        i++;        
        temp = temp->Next;             //Смена адреса на адрес следующего элемента
    }
    return i;
}

void Deque::pushFront(float x)
{

    Node* temp = new Node;               //Выделение памяти под новый элемент структуры
    temp->Next = Head;                   //Указываем, что изначально по следующему адресу пусто
    temp->x = x;                         //Записываем значение в структуру

    if (Head != NULL)                    //Если список не пуст
    {
        temp->Prev = NULL;               //Указываем адрес на предыдущий элемент в соотв. поле
        temp->Next = Head;               //Указываем адрес следующего за хвостом элемента
        Head = temp;                     //Меняем адрес хвоста
    }
    else //Если список пустой
    {
        temp->Prev = NULL;               //Предыдущий элемент указывает в пустоту
        Head = Tail = temp;              //Голова=Хвост=тот элемент, что сейчас добавили
    }
}

float Deque::popFront()
{
    if (this->size() != 0)
    {
        float popValue = Head->x;
        if (this->size() == 1)
        {
            delete Head;
            return popValue;
        }
        else
        {
            Node* newHead = Head->Next;
            delete Head;
            Head = newHead;
            Head->Prev = NULL;
            return popValue;
        }
    }
    
    else
        throw out_of_range("Nothing to pop!");
}

void Deque::clear()
{
    while (this->size() != 1)              //Пока не встретим пустое значение
    {
        this->popFront();
    }
    Head = NULL;
    Tail = NULL;
}

bool Deque::isEmpty()
{
    return this->size() == 0;
}

void Deque::show()
{
    /*
    //ВЫВОДИМ СПИСОК С КОНЦА
    Node* temp = Tail;                   //Временный указатель на адрес последнего элемента

    while (temp != NULL)               //Пока не встретится пустое значение
    {
        cout << temp->x << " ";        //Выводить значение на экран
        temp = temp->Prev;             //Указываем, что нужен адрес предыдущего элемента
    }
    cout << "\n"; */

    //ВЫВОДИМ СПИСОК С НАЧАЛА
    Node* temp = Head;                       //Временно указываем на адрес первого элемента
    while (temp != NULL)              //Пока не встретим пустое значение
    {
        cout << temp->x << " ";        //Выводим каждое считанное значение на экран
        temp = temp->Next;             //Смена адреса на адрес следующего элемента
    }
    cout << "\n";
}

int main()
{
    system("CLS");
    Deque lst; //Объявляем переменную, тип которой есть список
    lst.pushBack(100); //Добавляем в список элементы
    lst.pushBack(200);
    lst.pushBack(900);
    lst.pushBack(888);
    lst.show();
    cout << "Size: " << lst.size() << endl;
    lst.clear();
    lst.show();//Отображаем список на экране
    cout << "Size: " << lst.size() << endl;
    system("PAUSE");
    return 0;
}