#include "main.h"
#include "A/index.h"
#include "B/lib.h"

int main(){
    List<Object<MyPair>> my_list{};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Object<MyPair> new_pair = MyPair(i, j);
            my_list.push_back(new_pair);
        }
    }

    return 0;
}