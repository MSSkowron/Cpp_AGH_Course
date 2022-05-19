//
// Created by mateuszskowron on 5/5/22.
//

#ifndef ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYSORTING_H
#define ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYSORTING_H

#include <algorithm>
#include "vector"
#include "myList.h"
#include <cstring>

template <typename T>
void mySort(T &arr) {
    std::sort(std::begin(arr), std::end(arr));
}

template <int x, int y>
void mySort(char (&arr)[x][y]){
    for(int i = 0; i < x; i++){
        char curr_str[y+1];
        memcpy(curr_str,arr[i],y);
        for(int j = i; j < x; j++){
            if(strcasecmp(arr[i],arr[j]) > 0){
                char temp_str[y+1];
                memcpy(temp_str,arr[i],y);
                memcpy(arr[i],arr[j],y);
                memcpy(arr[j],temp_str, y);
            }
        }
    }
}

template <typename T>
void mySort(MyList<T> &myList){
    int size = myList.size();
    if(size < 2){
        return;
    }
    for(int i = 0; i < size; i++){
        auto curr = myList.begin();
        for(int j = 0; j < i; j++){
            curr++;
        }
        for(auto next = curr; next != myList.end(); ++next){
            if(*next < *curr){
                auto temp = *curr;
                *curr = *next;
                *next = temp;
            }
        }
    }
}

#endif //ZAD5MYLISTANDSORTING_DLASTUDENTOW_MYSORTING_H
