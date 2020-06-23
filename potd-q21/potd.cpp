#include "potd.h"

// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end){
    double toReturn = 0.0;
    for (auto it = start; it != end; it++){
        toReturn += *it;
    }
    //toReturn -= *end;
    return toReturn;
}

vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end){
    auto ptr = start;
    for (auto it = start; it != end; it ++){
        if (*it > *ptr){
            ptr = it;
        }
    }
    return ptr;
}

void sort_vector(vector<double>::iterator start, vector<double>::iterator end){
    double temp;
    for (auto it = start; it != end; it++){
        temp = *it;
        auto empty = it;
        for (auto iit = it -1 ; iit != start -1; iit--){
            if (temp > *iit){
                *(iit +1) = *(iit);
                empty = iit;
            }
        }
        *empty = temp;
    }
    return;
}
