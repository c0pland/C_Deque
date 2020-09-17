#include <stdlib.h>
#include <iostream>
using namespace std;


struct Node                             //Структура, являющаяся звеном списка
{
    float x;                             //Значение x будет передаваться в список
    Node* Next, * Prev;                 //Указатели на адреса следующего и предыдущего элементов списка
};

class List                              //Создаем тип данных Список
{
    Node* Head, * Tail;                 //Указатели на адреса начала списка и его конца
public:
    List() :Head(NULL), Tail(NULL) {};    //Инициализируем адреса как пустые
    ~List();                           //Прототип деструктора
    void show();                       //Прототип функции отображения списка на экране
    void pushBack(float x);                 //Прототип функции добавления элементов в список
    float popBack();
    int size();
};

List::~List()                           //Деструктор
{
    while (Head)                       //Пока по адресу на начало списка что-то есть
    {
        Tail = Head->Next;             //Резервная копия адреса следующего звена списка
        delete Head;                   //Очистка памяти от первого звена
        Head = Tail;                   //Смена адреса начала на адрес следующего элемента
    }
}

void List::pushBack(float x)
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

float List::popBack()
{
    float popValue = Tail->x;
    Node* newTail = Tail->Prev;
    delete Tail;
    Tail = newTail;
    // сделать уменьшение размера
    return popValue;
}

int List::size()
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

void List::show()
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
    List lst; //Объявляем переменную, тип которой есть список
    lst.pushBack(100); //Добавляем в список элементы
    lst.pushBack(200);
    lst.pushBack(900);
    lst.pushBack(888);
    lst.show();
   // cout << lst.popBack() << endl;
    cout << lst.size() << endl;
    lst.show();//Отображаем список на экране
    system("PAUSE");
    return 0;
}