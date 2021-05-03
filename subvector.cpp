#include <iostream>
#include <stdlib.h>
//#include <chrono>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

struct subvector {
    int* arr;
    int size;
    int capacity;
};

bool init(subvector *qv){
    qv -> size = 0;
    qv -> capacity = 2;
    qv -> arr = (int*) malloc ((qv -> capacity)*sizeof(int));
    qv -> arr[0] = NULL;
    return true;
}

bool push_back(subvector *qv, int d){
        qv -> size = qv -> size + 1;
        qv -> arr[qv -> size - 1] = d;
    if (qv -> size >= qv -> capacity) {
        qv -> capacity = 2*(qv -> size);
        int* arr_sh = (int*) malloc (qv -> capacity*sizeof(int));
        memcpy(arr_sh, qv -> arr, (qv -> size)*sizeof(int));
        free(qv -> arr);
        qv -> arr = arr_sh;
    }
    return true;
}

int pop_back (subvector *qv) {
    int e = qv -> arr[qv -> size - 1];
    qv -> size = qv -> size - 1;
    if ((qv -> size)/static_cast<float>(qv -> capacity) <= 0.25) {
        qv -> capacity = 2*(qv -> size);
        int* arr_sh = (int*) malloc ((qv -> size)*sizeof(int));
        memcpy(arr_sh, qv -> arr, (qv -> size)*sizeof(int));
        free(qv -> arr);
        qv -> arr = arr_sh;
    }
    return e;
}

bool resize (subvector *qv, unsigned int new_capacity) {
    int* arr_sh = (int*) malloc ((new_capacity)*sizeof(int));
    memcpy(arr_sh, qv -> arr, (qv -> size)*sizeof(int));
    free(qv -> arr);
    qv -> arr = arr_sh;
    qv -> capacity = new_capacity;
    
}

void shrink_to_fit (subvector *qv) {
    if (2*(qv -> size) < qv -> capacity) {
        int* arr_sh = (int*) malloc (2*(qv -> size)*sizeof(int));
        memcpy(arr_sh, qv -> arr, (qv -> size)*sizeof(int));
        free(qv -> arr);
        qv -> arr = arr_sh;
        qv -> capacity = 2*(qv -> size);
    }
}

void clear (subvector *qv) {
    for (int i=0; i<qv -> size; ++i) {
        qv -> arr[i] = NULL;
    }
    qv -> size = 0;
}

void destructor (subvector* qv) {
    free(qv -> arr);
    init(qv);
}


int main() {
    subvector* a = (subvector*) malloc (sizeof(subvector));
    init(a);
    for(int i=0; i<10; i++){
        push_back(a, 444);
    }
    
    /*for(int i=0; i<1000000; i++){
        auto start = chrono::high_resolution_clock::now();
        pop_back(a);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> dur = end - start;

        ofstream out("D:\\hello.txt", ios::app);
        if (out.is_open())
        {
            out << dur.count() << endl;
        }
        out.close();
        //printf("%.12lf", dur.count());
    }*/

    for(int i=0; i<12; i++){cout << i << ' ' << a -> arr[i] << " " << a -> capacity << endl;}
    cout << "##############" << endl;
    pop_back(a);
    for(int i=0; i<12; i++){cout << i << ' ' << a -> arr[i] << " " << a -> capacity << endl;}
    cout << "##############" << endl;
    pop_back(a);
    for(int i=0; i<12; i++){cout << i << ' ' << a -> arr[i] << " " << a -> capacity << endl;}
    cout << "##############" << endl;
    pop_back(a);
    for(int i=0; i<12; i++){cout << i << ' ' << a -> arr[i] << " " << a -> capacity << endl;}
    cout << "##############" << endl;
    pop_back(a);
    for(int i=0; i<12; i++){cout << i << ' ' << a -> arr[i] << " " << a -> capacity << endl;}
    cout << "##############" << endl;
    pop_back(a);
    destructor(a);
    for(int i=0; i<12; i++){cout << i << ' ' << a -> arr[i] << " " << a -> capacity << endl;}
    cout << "##############" << endl;
    resize(a, 12);
    clear(a);
    for(int i=0; i<12; i++){cout << i << ' ' << a -> arr[i] << " " << a -> capacity << endl;}
    cout << "##############" << endl;
    return 0;
}
