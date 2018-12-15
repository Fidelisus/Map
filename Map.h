#pragma once
#include <iostream>

using namespace std;

template <class Key, class Value>
struct Record {
public:
    Record(Key key, Value value) {
        this->value = value;
        this->key = key;
        this->nextRecord = nullptr;
    }
    Record() {};
    Key key;
    Value value;
    Record<Key, Value> *nextRecord;
};

template <class Key, class Value>
class Map
{
public:
    Map();
    Map(const Map<Key, Value> &map);
    ~Map();
    void add(Key key, Value value);
    Map<Key, Value> & operator=(const Map<Key, Value> &map);
    Value* find(Key key);
    
    friend std::ostream &operator<<(std::ostream &out, const Map<Key, Value> &map) {
        Record<Key, Value>* temp = map.head;
        while (temp) {
            out << "\n" << temp->key << "\n" << temp->value << "\n";
            temp = temp->nextRecord;
        }
        return out;
    }
    
private:
    Record<Key, Value> *head;
    void destroyMap(Record<Key, Value> * list);
};

template <class Key, class Value>
Map<Key, Value>::Map() {
    this->head = nullptr;
}

template <class Key, class Value>
Map<Key, Value>::Map(const Map<Key, Value> &map) {
    this->head = nullptr;
    *this = map;
}

template <class Key, class Value>
Map<Key, Value>::~Map() {
    this->destroyMap(this->head);
}

template <class Key, class Value>
void Map<Key, Value>::destroyMap(Record<Key, Value> * map) {
    Record<Key, Value>* temp = map;
    Record<Key, Value>* next;
    while (temp) {
//        		std::cout << "Delete:\n" << temp->value;
        next = temp->nextRecord;
        delete(temp);
        temp = next;
    }
}

template <class Key, class Value>
Value* Map<Key, Value>::find(Key key) {
    Record<Key, Value>* temp = this->head;
    
    while (temp) {
        if (temp->key == key) {
            return &(temp->value);
        }
        temp = temp->nextRecord;
    }
    return nullptr;
}

template <class Key, class Value>
void Map<Key, Value>::add(Key key, Value value) {
    //	std::cout << "add:\n" << value;
    if (find(key) != nullptr) {
        cout << "Key in database" << endl;
        return;
    }
    
    Record<Key, Value>* newRecord = new Record<Key, Value>(key, value);
    newRecord->nextRecord = head;
    head = newRecord;
}

template <class Key, class Value>
Map<Key, Value> &Map<Key, Value>::operator=(const Map<Key, Value> &map) {
    Record<Key, Value>* temp1;
    Record<Key, Value>* temp2;
//    Record<Key, Value>* deletion = this->head;
    
    destroyMap( this->head);
    this->head = new Record<Key, Value>(map.head->key, map.head->value);
    temp1 = this->head;
    temp2 = map.head;

    while (temp2->nextRecord) {
            temp2 = temp2->nextRecord;
            delete temp1->nextRecord;
            temp1->nextRecord = new Record<Key, Value>(temp2->key, temp2->value);
            temp1 = temp1->nextRecord;
    }
    
    return *this;
}
