#ifndef ZMPO_4B_VALUE_H
#define ZMPO_4B_VALUE_H


template <class T> class Value {
private:
    T value;
public:
    Value(T value) {this->value = value;}
    inline T evaluate() { return this->value;}
protected:
    Value() {};
    inline void setValue(T value) {this->value = value;}
};


#endif //ZMPO_4B_VALUE_H
