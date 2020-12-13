struct MyPair{
    int first;
    int second;

    MyPair() {}

    MyPair(MyPair const &other){
        first = other.first;
        second = other.second;
    }

    MyPair(int f, int s){
        first = f;
        second = s;
    }

    MyPair& operator= (const MyPair& other) {
        first = other.first;
        second = other.second;
        return *this;
    }

    MyPair& operator= (MyPair&& other) {
        first = other.first;
        second = other.second;

        other.first = 0;
        other.second = 0;
        return *this;
    }

    MyPair& operator= (MyPair other) {
        first = other.first;
        second = other.second;
        return *this;
    }
};
