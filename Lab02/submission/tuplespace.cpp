/*
* AUTHOR: ASHWIN ABRAHAM
*/

#include <iostream>
#include <vector>
#include <string>

template <typename key, typename val>
class Tuple{
    //models one key value pair
    private:
        key tuple_key;
        val tuple_value;
    public:
        Tuple(){}
        Tuple(key K, val V): tuple_key(K), tuple_value(V){}
        key& Key(){ //returns non-const reference to the key
            return tuple_key;
        }
        val& Value(){ //returns non-const reference to the value
            return tuple_value;
        }
};

template <typename key, typename val>
class Tuplespace{
    private:
        std::vector<Tuple<key, val> > tuples; //dynamic array of key-value pairs
    public:
        Tuplespace(): tuples(0){}
        void Insert(const key& Key, const val& Value){
            //inserts a new key value pair only if the key is not already present, else does nothing
            for(int i = 0; i<tuples.size(); ++i){
                if(tuples[i].Key() == Key) return;
            }
            tuples.push_back(Tuple<key, val>(Key, Value));
            return;
        }
        void Delete(const key& Key){
            //deletes the key value pair corresponding to given Key, if it exists
            //else does nothing
            for(int i = 0; i<tuples.size(); ++i){
                if(tuples[i].Key() == Key){
                    tuples.erase(tuples.begin()+i);
                    return;
                }
            }
            return;
        }
        val& operator[](const key& Key){
            //returns a non-const reference to the value corresponding to the given Key, if the key value pair exists
            //otherwise creates a Key Value pair for the given key and adds it to the tuple space and returns a reference the Value
            for(int i = 0; i<tuples.size(); ++i){
                if(tuples[i].Key() == Key) return tuples[i].Value();
            }
            Tuple<key, val> t;
            t.Key() = Key;
            tuples.push_back(t);
            return tuples[tuples.size()-1].Value();
        }
        unsigned int size() const{
            //returns number of key value pairs
            return tuples.size();
        }
};

int main(int argc, char* argv[]){
    //example demonstrating usage of the class
    Tuplespace<std::string, int> fruits;
    fruits.Insert("Apple", 3);
    fruits.Insert("Mango", 7);
    fruits.Insert("Apple", 7);
    fruits.Insert("Banana", 20);
    fruits.Insert("Watermelon", 15);
    std::cout << fruits.size() << '\n';
    std::cout << "Banana: " << fruits["Banana"] << '\n';
    std::cout << "Apple: " << fruits["Apple"] << '\n';
    fruits.Delete("Apple");
    std::cout << fruits.size() << '\n';
    fruits["Orange"] = 13;
    std::cout << fruits.size() << '\n';
    std::cout << "Orange: " << fruits["Orange"] << '\n';
    return 0;
}
