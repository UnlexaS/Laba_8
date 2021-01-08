// Project4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma once
#include <vector>
#include<iostream>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Exception
{
protected:
    int error;
public:
    Exception()
    {
        error = 0;
    }
    Exception(int _error)
    {
        error = _error;
    }
    ~Exception()
    {

    };
    void Show()
    {
        if (this->error == 0)
        {
            cout << "Input error! Enter int!" << endl;
        }
        if (this->error == 1)
        {
            cout << "Opening error!" << endl;
        }
    }
};


class Cats
{
private:
    int price;
    string id;
public:
    string name;
    Cats() : name("Cat"), price(0), id("0") {}
    Cats(string f, int g, string s) : name(f), price(g), id(s) {}
    void setname(string f)
    {
        name = f;
    }
    void setprice(int g)
    {
        price = g;
    }
    void setid(string s)
    {
        id = s;
    }
    string getname()
    {
        return name;
    }
    int getprice()
    {
        return price;
    }
    string getid()
    {
        return id;
    }

    friend ostream& operator<<(ostream& out, const Cats t)
    {
        out << "\nCat name : " << t.name << "\nPrice : " << t.price << "\nID =" << t.id << endl;
        return out;
    }

    friend istream& operator>>(istream& in, Cats& t)
    {
        in >> t.name;
        in >> t.price;
        in >> t.id;
        return in;
    }

    friend bool operator==(Cats t1, Cats t2) {
        if (t1.price == t2.price && t1.id == t2.id && t1.name == t2.name)
            return true;
        else
            return false;
    }

    friend bool operator<(const Cats t1, const Cats t2)
    {
        if (t1.price < t2.price)
            return true;
        else
            return false;
    }

    friend bool operator>(const Cats t1, const Cats t2)
    {
        if (t1.price > t2.price)
            return true;
        else
            return false;
    }
};

using namespace std;

//class  Node
//{
//public:
//    Cats data;
//    Node* next;
//    Node* prev;
//    Node() : data(), next(nullptr) { }
//
//    Node(Cats d) : data(d), next(nullptr) { }
//};
//
//
//class Deque
//{
//private:
//    Node* head;
//    Node* tail;
//    int size;
//public:
//
//    Deque() :head(nullptr), size(0) {}
//
//    void push_front(Cats x)
//    {
//        if (head == nullptr)
//        {
//            Node* element = new Node(x);
//            head = new Node(x);
//            element->next = head;
//            head = element;
//            size++;
//        }
//        else
//        {
//            Node* tmp = head;
//            int i = 0;
//            while (i < size - 1)
//            {
//                tmp = tmp->next;
//                i++;
//            }
//            tmp->next = new Node(x);
//            tmp->next->next = head;
//            size++;
//        }
//    }
//    void pop_front()
//    {
//        if (size == 0)
//            throw Exception();
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//        size--;
//        Node* t = head;
//        int i = 0;
//        while (i < size - 1)
//        {
//            t = t->next;
//            i++;
//        }
//        t->next = head;
//        tail = 0;
//    }
//
//    void outputTaskByprice(int ye)
//    {
//        if (size == 0)
//            throw Exception();
//        Node* temp = head;
//        int i = 0;
//        while (i < size)
//        {
//            if (temp->data.getprice() >= ye) {
//                cout << "   " << temp->data;
//            }
//            temp = temp->next;
//            i++;
//        }
//    }
//
//    Node* getNode()
//    {
//        return head;
//    }
//
//    int getSize()
//    {
//        return size;
//    }
//
//    friend ostream& operator<<(ostream& out, const Node& node)
//    {
//        out << node.data;
//        return out;
//    }
//};


class Vector : public Cats
{
protected:

    vector <Cats> vector_cats;

public:

    Vector() {}
    
    void del(int i) {
        vector_cats.erase(vector_cats.begin() + i);
    }

    void outputTaskByprice(int temp) {
        for (int i = 0; i < vector_cats.size(); i++ ) {
            if (vector_cats[i].getprice() == temp)
            {
                cout << vector_cats[i];
                return;
            }
        }
    }

    void output(int i) {
        int n = 0;;
        while (1) {
            if (n == i) {
                vector_cats.pop_back();
                return;
            }
            else n++;
        }
    }

    void show() {
        for (int i = 0; i < vector_cats.size(); i++) {
            cout << endl << "-------------" << i << "-------------" << endl;
            cout << vector_cats[i];
            cout << "___________________________" << endl;
        }
    }

    void add(Cats& elem) {
        vector_cats.push_back(elem);
    }



    int getSize()
    {
        return size;
    }

private:
    size_t size;
    Cats* data;
};


class my_iterator :public std::iterator<std::output_iterator_tag, Cats>
{
    //friend class vector;
private:
    int size;
    my_iterator(Cats* p);
public:

    my_iterator(const my_iterator& it);
    bool operator!=(my_iterator const& other) const;
    bool operator==(my_iterator const& other) const;
    Cats& operator*() const;
    Cats* operator->() const;
    my_iterator& operator++();
    Cats& operator[](int);
private:
    Cats* p;
};

enum Key {
    no = 0,
    txt,
    bin
};

class File
{
private:
    fstream file;
    string name;
    Key key;
    int size;
public:
    File() : name("-"), key(no), size(0) {}
    File(string n, Key k) : name(n), key(k), size(0) {}
    friend File& operator<<(File& file, const char* s)
    {
        try {
            if (!file.file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.Show();
        }

        string str = s;
        file.file << str;
        return file;
    }
    friend fstream& operator<<(fstream& out, Cats& t) {

        try {
            if (!out.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.Show();
        }
        int a = out.tellg();
        string name = t.getname();

        size_t len1 = name.length() + 1;

        int _yearNumber = t.getprice();

        string _phoneNumber = t.getid();

        size_t len2 = _phoneNumber.length() + 1;

        out.write((char*)(&len1), sizeof(len1));

        out.write((char*)(name.c_str()), len1);

        out.write((char*)(&_yearNumber), sizeof(_yearNumber));

        out.write((char*)(&len2), sizeof(len2));

        out.write((char*)(_phoneNumber.c_str()), len2);


        return out;
    }
    friend File& operator<<(File& file, Cats& t)
    {
        int pos = 0, a = 0, size = 0;

        if (!file.file.is_open())
        {
            cout << "1";
        }

        if (file.key == txt) {
            file.file << t.getname() << " " << t.getprice() << " " << t.getid() << endl;
        }

        return file;
    }
    friend ostream& operator<<(ostream& out, File& file)
    {
        int a = 0;

        if (!file.file.is_open())
        {
            throw 1;
        }

        //if (file.key == txt) {
            string str;
            while (!file.file.eof()) {
                getline(file.file, str);
                a = file.file.tellg();
                cout << str << endl;
            }
        //}

        return out;
    }

    ~File() {
        file.close();
    }
    void open(string mode)
    {


        if (mode == "r") {
            file.open(name, ios_base::in);
        }
        else if (mode == "add") {
            file.open(name, ios_base::app);
        }
        else if (mode == "w") {
            file.open(name, ios_base::out);
        }
        else if (mode == "wr") {
            file.open(name, ios_base::in | ios_base::out);
        }


        if (!file.is_open())
        {
            throw;
        }

    }
    void close()
    {
        file.close();
    }
    void begin()
    {
        file.seekg(0, ios_base::beg);
    }
    void setSize(int s) {
        size = s;
    }
    int getSize() {
        return	size;
    }
    Cats read()
    {
        string str;
        Cats abnt;

        getline(this->file, str, ' ');
        abnt.setname(str);

        getline(this->file, str, ' ');
        abnt.setprice(stoi(str));

        getline(this->file, str);
        abnt.setid(str);

        return abnt;
    }



    void deleteCat(int line, Cats mas[]) {
        this->open("wr");

        int a, b;

        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.Show();
            return;
        }
        Cats temp;
        if (this->key == txt) {
            string str;
            for (int i = 0; i < line - 1; i++)
                getline(this->file, str);


            getline(this->file, str, ' ');
            temp.setname(str);

            getline(this->file, str, ' ');
            temp.setprice(stoi(str));

            getline(this->file, str, ' ');
            temp.setid(str);
        }

        string fi = "";
        rewind(stdin);
        temp.setname(fi);

        int yn = NULL;
        temp.setprice(yn);
        rewind(stdin);

        string pn = "";
        rewind(stdin);

        temp.setid(pn);

        a = file.tellg();
        file.seekg(0, ios_base::end);
        b = file.tellg();
        this->file.seekg(0, ios_base::beg);
        if (this->key == txt) {
            string tmp;
            for (int i = 0; i < line - 1; i++)
                getline(this->file, tmp);
            int pos = this->file.tellg();
            this->file.seekg(pos, ios_base::beg);
            this->file << tmp;
            return;
        }


        this->close();
    }

    void bouble_name()
    {
        string temp;
        string str1, str2;
        int position;
        this->open("wr");
        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.Show();
            return;
        }
        for (int i = 0; i < this->size - 1; i++) {
            for (int j = 0; j < this->size - i - 1; j++)
            {
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++)
                    getline(this->file, str1);

                getline(this->file, str1, ' ');

                getline(this->file, str2);

                getline(this->file, str2, ' ');

                if (str1 > str2)
                {
                    this->file.seekg(0, ios_base::beg);
                    position = this->file.tellg();
                    for (int k = 0; k <= j; k++)
                    {
                        getline(this->file, str1);
                        position = this->file.tellg();
                    }
                    temp = str1;
                    getline(this->file, str2);
                    this->file.seekg(0, ios_base::beg);
                    for (int k = 0; k < j; k++)
                    {
                        getline(this->file, str1);
                    }
                    position = this->file.tellg();
                    this->file.seekg(position, ios_base::beg);
                    this->file << str2 << '\n';
                    this->file << temp << '\n';
                }
            }
        }
        this->close();
    }
    
    void bouble_price() {
        string temp;
        string str1, str2;
        int i1, i2;
        int position;
        this->open("wr");
        try {
            if (!file.is_open())
            {
                throw 1;
            }
        }
        catch (int i)
        {
            Exception ex(i);
            ex.Show();
            return;
        }
        for (int i = 0; i < this->size - 1; i++) {
            for (int j = 0; j < this->size - i - 1; j++)
            {
                this->file.seekg(0, ios_base::beg);
                for (int k = 0; k < j; k++)
                    getline(this->file, str1);
                for (int t = 0; t < 2; t++)
                    getline(this->file, str1, ' ');
                getline(this->file, str2);
                for (int t = 0; t < 2; t++)
                    getline(this->file, str2, ' ');
                i1 = stoi(str1);
                i2 = stoi(str2);
                if (i1 > i2)
                {
                    this->file.seekg(0, ios_base::beg);
                    position = this->file.tellg();
                    for (int k = 0; k <= j; k++) {
                        getline(this->file, str1);
                        position = this->file.tellg();
                    }
                    temp = str1;
                    getline(this->file, str2);
                    this->file.seekg(0, ios_base::beg);
                    for (int k = 0; k < j; k++) {
                        getline(this->file, str1);
                    }
                    position = this->file.tellg();
                    this->file.seekg(position, ios_base::beg);
                    this->file << str2 << '\n';
                    this->file << temp << '\n';
                }
            }
        }
        this->close();
    }
    //void BoublePhoneNumber()
    //{
    //    string temp;
    //    string str1, str2;
    //    int i1, i2;
    //    int position;
    //    this->open("wr");
    //    try {
    //        if (!file.is_open())
    //        {
    //            throw 1;
    //        }
    //    }
    //    catch (int i)
    //    {
    //        Exception ex(i);
    //        ex.Show();
    //        return;
    //    }
    //    for (int i = 0; i < this->size - 1; i++) {
    //        for (int j = 0; j < this->size - i - 1; j++) {
    //            this->file.seekg(0, ios_base::beg);
    //            for (int k = 0; k < j; k++) {
    //                getline(this->file, str1);
    //            }
    //            for (int t = 0; t < 4; t++)
    //                getline(this->file, str1, ' ');
    //            getline(this->file, str1);
    //            for (int t = 0; t < 4; t++)
    //                getline(this->file, str2, ' ');
    //            getline(this->file, str2);
    //            i1 = stoi(str1);
    //            i2 = stoi(str2);
    //            if (i1 > i2) {
    //                this->file.seekg(0, ios_base::beg);
    //                position = this->file.tellg();
    //                for (int k = 0; k <= j; k++) {
    //                    getline(this->file, str1);
    //                    position = this->file.tellg();
    //                }
    //                temp = str1;
    //                getline(this->file, str2);
    //                this->file.seekg(0, ios_base::beg);
    //                for (int k = 0; k < j; k++) {
    //                    getline(this->file, str1);
    //                }
    //                position = this->file.tellg();
    //                this->file.seekg(position, ios_base::beg);
    //                this->file << str2 << '\n';
    //                this->file << temp << '\n';
    //            }
    //        }
    //    }
    //    this->close();
    //}
};

using namespace std;

int main()
{
    Cats Cat2("Cat", 23, "  7777777");
    Cats Cat1("Tat", 10, "  1111111");
    Cats Cat3("Wat", 36, "  2222222");
    Cats Cat4("Sat", 43, "  5555555");
    Cats Cat5("Rat", 12, "  8888888");

    Cats msCats[5] = {

        Cat1,
        Cat2,
        Cat3,
        Cat4,
        Cat5
    };


    File file1("1.txt", txt);

    file1.open("w");

    file1.setSize(5);

    file1 << Cat1;
    file1 << Cat2;
    file1 << Cat3;
    file1 << Cat4;
    file1 << Cat5;

    file1.close();

    file1.open("r");

    cout << file1;

    file1.close();

    cout << "\n";

    rewind(stdin);

    cout << "\n";

    cout << "Sort name:" << endl;
    file1.bouble_name();

    file1.open("r");

    cout << file1;

    file1.close();

    cout << "\n";
    cout << "Sort price:" << endl;
    file1.bouble_price();

    file1.open("r");

    cout << file1;

    file1.close();

    Vector vect;

    file1.open("r");

    Cats temp;

    for (int i = 0; i < file1.getSize(); i++)
    {
        temp = file1.read();
        vect.add(temp);
    }

    cout << "Cat with price - 23";

    vect.outputTaskByprice(23);
    file1.close();

    file1.open("r");
    Cats temp1;
    Vector vect1;
    for (int i = 0; i < 5; i++) {
        temp1 = file1.read();
        vect1.add(temp1);
    }

    cout << endl << "Cat to delete - 2" << endl;

    vect1.del(2);

    file1.close();

    file1.open("w");

    file1.setSize(4);

    Cats temp2;

    file1 << Cat1;
    file1 << Cat3;
    file1 << Cat4;
    file1 << Cat5;

    file1.close();

    file1.open("r");

    cout << file1;

    file1.close();

    //vect1.show();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
