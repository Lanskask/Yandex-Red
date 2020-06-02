#include<iostream>
#include<fstream>

using namespace std;

pair<ifstream, ofstream> MakeStreamPair(const string& prefix) {
// Верно, объекты,
//     созданные с помощью прямого вызова конструктора,
//     являются временными.

    //    // Variant 1
//    // thats variable
//    ifstream input(prefix + ".in");
//    ofstream output(prefix + ".out");
////    return {input, output};
//    return {move(input), move(output)};
//    // input, output (not temporary)
//    //     => that's why they try to copy themselves to pair ctor
//    // input, output -> pair ctor -> returned temporary

    // Variant 2
    return {ifstream(prefix + ".in"), ofstream(prefix + ".out")};

}

ifstream MakeInputStream(const string& prefix) {
    /**
     * Если из функции возвращается временный объект или название локальной переменной
     *      всё оптимизируется и не происходит ни кирования ни перемещения
     * если возвращается поле локальной переменной
     *      - не срабатывает move семантика
     * если возвращается какой то вызов какого-то кнструтора,
     *      то эти объекты не будут по умолчанию в него перемещатся (случай с pair)
     *      - надо использовать move
     */

    auto streams = MakeStreamPair(prefix);
//    return streams.first; // error: use of deleted function
//    return move(streams).first;

// нельзя копировать i/o stream, но в месте `return move(streams.first);`
// вызывается copy ctor, т.к. не работает ни copy elision ни Retrun value optimisation
// т.к. stream это не временный объект, а локальная переменная
    return move(streams.first);
    // теперь переменная streams ведёт себя как временный объект
    // и её оле тоже временный объект
}

int main() {

    return EXIT_SUCCESS;
}