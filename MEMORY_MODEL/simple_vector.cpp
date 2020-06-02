#include<iostream>
#include <algorithm>

using namespace std;

template<typename T>
class SimpleVector {
public:
//    explicit SimpleVector(size_t size_) : size(size_) {
////        data = *T[size];
//        data = new T[size_];
//        end_ = data + size;
//    }
    SimpleVector() = default;

    explicit SimpleVector(size_t size_);

//    SimpleVector(const SimpleVector& other)
//        : data(new T[other.capacity])
//        , size(other.size)
//        , capacity(other.capacity)
//        {
//            copy(other.begin(), other.end(), begin());
//        }
    SimpleVector(const SimpleVector &other);

    SimpleVector(SimpleVector &&other); // move constructor

    ~SimpleVector();

    T at(size_t position) {
        return data[position];
    }

    T &operator[](size_t index);

    T *getData() const;

    size_t getSize() const;

    size_t getCapacity() const;

    T *begin() {
        return data;
    };

    T *end() {
        return end_; // data + size;
    };

    [[nodiscard]] const T *begin() const {
        return data;
    };

    [[nodiscard]] const T *end() const {
        return end_; // data + size;
    };

    [[nodiscard]] const T *cbegin() const { return data; };

    [[nodiscard]] const T *cend() const {
        return end_; // data + size;
    };
//    [[nodiscard]] int some1() {
//        return 1;
//    }

    void PrintForI() {
        for (int i = 0; (size_t) i < size; ++i) {
            cout << *(data + i) << ", ";
        }
    }

    void operator=(SimpleVector &&rhs);

//    void operator=(const SimpleVector<T> &rhs);
    SimpleVector& operator=(const SimpleVector &rhs);

private:
    T *data = nullptr;
    T *end_ = nullptr;
    size_t size = 0;
    size_t capacity = 0;
};

template<typename T>
SimpleVector<T>::SimpleVector(size_t size_)
        : data(new T[size_]), size(size_), capacity(size_) {
            end_ = data + size;
        }

template<typename T>
SimpleVector<T>::~SimpleVector() {
    delete[] data;
}

template<typename T>
SimpleVector<T>::SimpleVector(const SimpleVector<T> &other)
        : data(new T[other.capacity]), size(other.size), capacity(other.capacity) {
    copy(other.begin(), other.end(), begin());
}

template<typename T>
SimpleVector<T>::SimpleVector(SimpleVector &&other)
        : data(other.data), size(other.size), capacity(other.capacity) {
    other.data = nullptr;
    other.size = other.capacity = 0;
}


template<typename T>
T &SimpleVector<T>::operator[](size_t index) {
//        return *(data + index);
    return data[index];
}

template<typename T>
T *SimpleVector<T>::getData() const {
    return data;
}

template<typename T>
size_t SimpleVector<T>::getSize() const {
    return size;
}

template<typename T>
size_t SimpleVector<T>::getCapacity() const {
    return capacity;
}

template<typename T>
//void SimpleVector<T>::operator=(const SimpleVector<T> &rhs) {
SimpleVector<T>& SimpleVector<T>::operator=(const SimpleVector<T> &rhs) {
//    cout << "&rhs: " << &rhs << "; this: " << this << endl;
    if (&rhs != this) {
        delete[] data;
        data = new T[rhs.capacity];
        size = rhs.size;
        capacity = rhs.capacity;
        end_ = data + size;
        copy(rhs.begin(), rhs.end(), begin());
    }
    return *this;
//    // OR That way
//    // from left to right
//    // левый - только что созданный
//    // и мы в этот левый вставляем данные из правого
//    if(rhs.size <= capacity) {
//        copy(rhs.begin(), rhs.end(), begin());
//    } else {
//        // Это так называемая идиома copy-and-swap.
//        // Мы создаём временный вектор с помощью
//        // конструктора копирования, а затем обмениваем его поля со своими.
//        // Так мы достигаем двух целей:
//        //  - избегаем дублирования кода в конструкторе копирования
//        //    и операторе присваивания
//        //  - обеспечиваем согласованное поведение конструктора копирования
//        //    и оператора присваивания
//
//        // мы используем конструктор копирования
//        // т.е. сейчас у нас всё что в tmp равно тому что в rhs
//        SimpleVector<T> tmp(rhs);
//        // теперь мы меняем местами что в tmp
//        // в новый сейчас сознанный и заполняющийся объект
//        swap(tmp.data, data);
//        swap(tmp.size, size);
//        swap(tmp.capacity, capacity);
//    }
};

template<typename T>
void SimpleVector<T>::operator=(SimpleVector<T> &&rhs) {
    if (&rhs != this) {
        delete[] data;
        data = rhs.data;
        size = rhs.size;
        capacity = rhs.capacity;

        rhs.data = nullptr;
    }
}

// Print Functions
template<typename T>
ostream &operator<<(ostream &os, const SimpleVector<T> &vect) {
//    for (auto it = vect.begin(); it != vect.end(); ++it) {
//        cout << *it << ", ";
//    }
    if (vect.getData() != nullptr) {
        for (int i = 0; i < vect.getSize(); ++i) {
            cout << vect.getData()[i] << endl;
        }
    }
    return os;
}

template<typename T>
void PrintForEach(const SimpleVector<T> &sv_) {
//    for (const auto& x : sv_) {
//        cout << x << ", ";
//    }
//    for (auto it = sv_.cbegin(); it != sv_.cend(); ++it) {
//        cout << *it << ", ";
//    }
    for (auto it = sv_.begin(); it != sv_.end(); ++it) {
        cout << *it << ", ";
    }
    cout << endl;
}

// Main Functions
void Run_run_SimpleVector() {
    SimpleVector<int> sv(5);
    for (int i = 0; i < 5; ++i) {
        sv[i] = i;
    }
    sv.PrintForI();

//    int* data1 = new int[5];
//    delete[] data1;
}

void Run_run_ForEachPrint() {
    SimpleVector<int> sv(5);
    sv[0] = 5;
    sv[1] = 3;
    sv[2] = 4;
    sv[3] = -1;
    sv[4] = -200;
    for (int x : sv) {
        cout << x << ", ";
    }
    cout << endl;

    sort(sv.begin(), sv.end());
//    for (const auto& x : sv) {
//        cout << x << ", ";
//    }
    PrintForEach<int>(sv);
}

//void TestNoDiscard() {
//    SimpleVector<int> sv(5);
//    sv.some1();
//}

void Run_Copy_operator_constructor() {
    SimpleVector<int> source(1);
    source[0] = 8;
//    SimpleVector<int> target = source;
    cout << source << endl;
//    cout << target << endl;
}

void Run_Move_constructor_Expr() {
    SimpleVector<int> source(1);
    SimpleVector<int> target(1);

//    SimpleVector<int> target = move(source);
    target = move(source);
    cout << "source: " << source << endl;
    cout << "target: " << target << endl;
    cout << source.getSize() << endl;
    cout << target.getSize() << endl;
}

void Run_This_Init() {
    SimpleVector<int> e(5);
    for (int i = 0; i < 5; ++i) {
        e[i] = 5 - i;
    }
    SimpleVector<int> a,b,c,d;
    a = b = (c = (d = e));
    cout
        << a.getSize() << ", "
        << b.getSize() << ", "
        << c.getSize() << ", "
        << d.getSize() << ", "
        << e.getSize() << endl;
}

int main(int argc, char *argv[]) {
//    Run_run_SimpleVector();
//    Run_run_ForEachPrint();
//    TestNoDiscard();
//    Run_Copy_operator_constructor();
//    Run_Move_constructor_Expr();
    Run_This_Init();

    return EXIT_SUCCESS;
}