#ifndef YANDEX_RED_RATIONAL_H
#define YANDEX_RED_RATIONAL_H


class Rational {
public:
    Rational() = default;
    Rational(int nn, int dd);

    [[nodiscard]]
    int Numerator() const;
    [[nodiscard]]
    int Denominator() const;
private:
    int n = 0;
    int d = 1;
};


#endif //YANDEX_RED_RATIONAL_H
