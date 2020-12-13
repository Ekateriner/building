code = """#include<iostream>

template<class T>
class Object{
public: 
    void set(T new_val) {
        value = new_val;
    }

    T get() {
        return value;
    }

    Object() {}

    Object(T val):
        value(val) {}
        
    Object(Object const &other):
        value(other.value) {}
        
    Object& operator= (const Object& other) {
        value = other.value;
        return *this;
    }
    
    Object& operator= (Object&& other) {
        value = other.value;
        return *this;
    }
    
    Object& operator= (Object other) {
        value = other.value;
        return *this;
    }

private:
    T value;
};
"""

file = open('index.h', "w+")
file.write(code)

