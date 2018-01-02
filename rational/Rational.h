#ifndef ZMPO_4B_RATIONAL_H
#define ZMPO_4B_RATIONAL_H

/**
 *  Rational
 *
 *  Klasa reprezentująca liczby rzeczywiste zdefiniowane jako liczby, które można przedstawić jako iloraz
 *  dwóch liczb całkowitych. W poniższej implementacji klasa posiada dwa pola - licznik (numerator) oraz mianownik
 *  (denominator). Wszystkie konstruktory i metody klasy zostały stworzone w ten sposób, by licznik przechowywał informację
 *  o znaku reprezentowanej liczby rzeczywistej, a mianownik był zawsze liczbą większą od 0. Ze względu na czytelność
 *  kodu oraz problemy związane z konwersją typów unsigned int i int, pomimo, że mianownik nigdy nie powinien przyjmować
 *  wartości ujemnych, jest on reprezentowany z wykorzystaniem typu int (ze znakiem).
 *  Poniższa klasa posiada zdefiniowane dwa kkonstruktory - dwuparametrowy, w którym podawana jesst wartość licznika
 *  i mianownika oraz jednoparametrowy w którym mianownik przyjmuje domyślną wartość 1. Dla poniższej klasy nie definiowano
 *  konstruktora kopiującego i przenoszącego, odpowiadających im operatorów przypisania ("=") oraz destruktora. Klasa ta
 *  posiada tylko dwa pola typów podstawowych, w związku z tym nie ma problemów związanych z alokacją pamięci i domyślnie
 *  tworzone przez kompilator implementacje wspomnianych funkcjonalności spełniają wszelkie wymagania związane
 *  głównie z zapewnieniem hermetyzacji obiektów klasy.
 *  Poniższa klasa nie posiada żadnych metod i wszelkie interakcje z obiektami tej klasy wykonywane są z wykorzystaniem
 *  operatorów. Zdefiniowano dla tej klasy operator wyjścia, który wyświetla liczbę w postaci "n/d" lub "n" dla przypadków,
 *  gdy mianownik jest równy 1. Analogicznie operator wejścia przyjmuje liczbę zarówno w formacie "n/d" jak i "n".
 *  w obecnej implementacji w operatorze wejścia wykorzystywana jest funkcja "stoi" i w związku z tym program może
 *  w nieoczekiwany sposób akceptować "dziwne" wartości, takie jak na przykład "12sdf1233/1sd333". W późniejszych iteracjach
 *  programu planuje się dodanie obsługi tego typu sytuacji.
 *  Poza operatorami wejścia wyjścia zdefiniowano również operatory podstawowych operacji (+, -, *, /), operacji "w miejscu"
 *  (+=, -=, *=, /=) oraz operacji porównania (==, <=, >=, <, >). Każda  z tych operacji została zdefiniowana dla par liczb
 *  rzeczywistych oraz dla pary liczba rzeczywista-liczba całkowita. W kolejnych iteracjach programu planuje się utworzenie
 *  podobnego zestawu operacji i porównań dla par liczba rzeczywista - liczba zmiennoprzecinkowa oraz operatorów inkrementacji
 *  i dekrementacji (++, --).
 *  Wewnętrznie liczba rzeczywista przechowywana jest w postaci skróconego ułamka zwykłego, którego mianownik jest liczbą
 *  większą od zera. Dlatego też, dla każdej operacji, która może spowodować zachwianie tego warunku sprawdzana jest dodatność
 *  mianownika oraz obliczany jest największy wspólny dzielnik licznika i mianownika.
 */
class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational(int numerator, int denominator);
    Rational(int numerator): numerator(numerator), denominator(1) {};
    Rational operator +(const Rational& rational);
    Rational operator +(const int integer);
    Rational& operator +=(const Rational& rational);
    Rational& operator +=(const int integer);
    Rational operator -(const Rational& rational);
    Rational operator -(const int integer);
    Rational& operator -=(const Rational& rational);
    Rational& operator -=(const int integer);
    Rational operator *(const Rational& rational);
    Rational operator *(const int integer);
    Rational& operator *=(const Rational& rational);
    Rational& operator *=(const int integer);
    Rational operator /(const Rational& rational);
    Rational operator /(const int integer);
    Rational& operator /=(const Rational& rational);
    Rational& operator /=(const int integer);
    bool operator ==(const Rational& rational);
    bool operator ==(const int integer);
    friend bool operator ==(const int integer, const Rational& rational);
    bool operator <=(const Rational& rational);
    bool operator <=(const int integer);
    friend bool operator <=(const int integer, const Rational& rational);
    bool operator >=(const Rational& rational);
    bool operator >=(const int integer);
    friend bool operator >=(const int integer, const Rational& rational);
    bool operator <(const Rational& rational);
    bool operator <(const int integer);
    friend bool operator <(const int integer, const Rational& rational);
    bool operator >(const Rational& rational);
    bool operator >(const int integer);
    friend bool operator >(const int integer, const Rational& rational);
    friend std::ostream& operator<<(std::ostream& o, const Rational& rational);
    friend std::istream& operator>>(std::istream& o, Rational& rational);
};


#endif //ZMPO_4B_RATIONAL_H
