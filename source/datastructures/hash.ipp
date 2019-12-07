template<class K, class V>
Pair<K, V>::Pair() {
}

template<class K, class V>
Pair<K, V>::Pair(K first, V *second){
    this->first = first;
    this->second = second;
}

template<class K, class V>
bool Pair<K, V>::operator==(const Pair &rhs) {
    return this->first == rhs.first;
}

template<class K, class V>
HashTable<K, V>::HashTable(int table_size){
    size = table_size;
    collision_count = 0;
    elements_count = 0;
    entries = new list<Pair<K, V>>[table_size];
}

template<class K, class V>
HashTable<K, V>::~HashTable<K, V>(){
    delete entries;
}


template<class K, class V>
bool HashTable<K, V>::insert(K key, V *value){
    int hash_code = key.hashCode(size);

    list<Pair<K, V>> entry_list = entries[hash_code];

    auto element = Pair<K, V>(key, value);

    // Verify if the value is already there
    for(Pair<K, V> entry : entry_list){
        if ((entry.first).compare(key) == 0) {
            entry_list.remove(entry);
            entry_list.push_back(element);
            entries[hash_code] = entry_list;
            return true;
        }
    }

    // if isn't, put it on the vector
    if (!entry_list.empty())
        collision_count++;
    entry_list.push_back(element);
    entries[hash_code] = entry_list;
    elements_count++;
//    cout << key << endl;
    return true;
}

template<class K, class V>
V* HashTable<K, V>::get(K key){
    int hash_code = key.hashCode(size);

    // Search through the aux vector
    list<Pair<K, V>> entry_list = entries[hash_code];

    for (auto entry : entry_list){
        if (entry.first.compare(key) == 0){
            return entry.second;
        }
    }

    // if it has not found the element in the vector, he will return -1 code
    return nullptr;
}

template<class K, class V>
bool HashTable<K, V>::remove(K key){
    // TODO Implement deletion

    /*int hash_code = string_hash(*table, element);

    if (table.entries[hash_code].value.compare(element) == 0){
        table.entries[hash_code].occupied = false;
        return true;
    } else {
        // Chaining case
        if (table.collision_treatment == CHAINING){

            // Search throught the aux vector
            list<string> vector = table.entries[hash_code].aux;
            vector.remove(element);
            return true;

        } else if (table.collision_treatment == EABQ){
            for (int i = 0; i < table.m; i++){
                hash_code = (hash_code + (C1*i + C2*i*i)) % (table.m);
                Entry entry = table.entries[hash_code];

                if ((entry.occupied) && (entry.value.compare(element) == 0)){
                    table.entries[hash_code].occupied = false;
                    return true;
                }
            }

            // if it has not found the element in the hashtable, return -1
            return false;
        } else {
            return false;
        }
    }*/
    return true;
}


template<class K, class V>
float HashTable<K, V>::occupancy_rate(){
    int occupancy = 0;

    for (int i = 0; i < size; i++){
        if (!entries[i].empty()){
            occupancy++;
        }
    }

    return ((float) occupancy/((float) size));
}

template<class K, class V>
void HashTable<K, V>::show(){
    printf("-----------HEADER--------\n");
    printf("| m = %d, n = %d, ccount = %d, occuprate = %.3f |\n", size, elements_count, collision_count, occupancy_rate());
    printf("-------------------------\n");

    for (int i = 0; i < size; i++){
        list<Pair<K, V>> values = entries[i];

        cout << "| " ;
        for (auto name : values){
            cout << name.first << ":" << *(name.second) << ";";
        }
        cout << " |"  << endl;
    }
    cout << "-------------------------\n";
}

template<class K, class V>
void HashTable<K, V>::show_info(){

    cout << "-------------------------" << endl;
    cout << "Table size: " << size << endl;
    cout << "Elements count: " << elements_count << endl;;
    cout << "Collision count: " << collision_count << endl;
    printf("Occupancy rate: %.3f\n", occupancy_rate());
    cout << "-------------------------" << endl;
}