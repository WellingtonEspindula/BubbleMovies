#define N_LETTERS 27
#define ASCII_A_CODE 65
#define MAX_ARRAY_SIZE 1000000
#define LEAF_SIZE 32

using namespace std;

template <typename T>
void insertion_sort(T* vector[], int size) {
    int i = 0;
    int j = 0;
    T* key;
    for (j=1; j < size; j++) {
            key = vector[j];
            i = j-1;
            while ( (i >= 0) && (*(vector[i]) < *key)) {
                    vector[i+1] = vector[i];
                    i--;
            }
            vector[i+1] = key;
    }
}

template <typename T>
void insertion_sort(T* vector[], int lo, int hi) {
    int i, j;
    T* key;
    for (j = lo; j <= hi; j++) {
            key = vector[j];
            i = j-1;
            while ( (i >= lo) && (*(vector[i]) < *key)) {
                    vector[i+1] = vector[i];
                    i--;
            }
            vector[i+1] = key;
    }
}

template <typename T>
void merge(T* vector[], T* aux[], int lo, int mid, int hi) {
    // copy to aux[]
    for (int k = lo; k <= hi; k++) {
        aux[k] = vector[k]; 
    }

    // merge back to a[]
    int i = lo, j = mid+1;
    for (int k = lo; k <= hi; k++) {
        if (i > mid) {
            vector[k] = aux[j++];
        }
        else if (j > hi) {              
            vector[k] = aux[i++];
        }
        else if ( *(aux[j]) > *(aux[i])) {
            vector[k] = aux[j++];
        }
        else {
            vector[k] = aux[i++];
        }
    }
}

template <typename T>
void merge_sort(T* vector[], T* aux[], int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    merge_sort<T>(vector, aux, lo, mid);
    merge_sort<T>(vector, aux, mid + 1, hi);
    merge(vector, aux, lo, mid, hi);
}

template <typename T>
void merge_sort(T* vector[], int size) {
    T* aux[size];
    merge_sort<T>(vector, aux, 0, size-1);
}

template <typename T>
void hybrid_sort(T* vector[], T* aux[], int lo, int hi) {
    if (hi <= lo) {
        return;
    }
    int mid = lo + (hi - lo) / 2;
    merge_sort<T>(vector, aux, lo, mid);
    merge_sort<T>(vector, aux, mid + 1, hi);
    
    if ((hi - lo) <= LEAF_SIZE){
        insertion_sort(vector, lo, hi);
    } else {
        merge(vector, aux, lo, mid, hi);
    }
}

template <typename T>
void hybrid_sort(T* vector[], int size) {
    T* aux[size];
    hybrid_sort<T>(vector, aux, 0, size-1);
}

/*int letters_to_int(string word, int d) {
    if ((d < 0) || (d > word.length())){
        printf("Letters to int exception: Digit out of the bound\n");
    }
    if (d == word.length()) return -1;
    return word.at(d) - (int) 'A';
}*/
