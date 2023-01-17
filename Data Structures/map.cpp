#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
using namespace std;

void Map()
{
    map<string, string> myDictionary;

    // Insert value inside the Dictionary
    myDictionary.insert(pair<string, string>("213232442443", "Ashish"));
    myDictionary.insert(pair<string, string>("210310216694", "Astitva"));

    // Printing a dictionary
    for (auto pair : myDictionary)
    { //=> For every pair in myDictionary
        cout << pair.first << " : " << pair.second << endl;
    }

    //Accesing Elements of a Map
    // cout<<myDictionary["210310216694"]<<endl;

    // Changing Elements Value
    // myDictionary["210310216694"] = "Taru";
    // cout<<myDictionary["210310216694"]<<endl;

    // cout<<myDictionary.size()<<endl;

    // myDictionary.clear() //deletes all the elements from the map
    // myDictionary.erase("210310216694"); //deletes a particular key value pair

    // Map containing complex data type as value
    map <string,list<string>> pokedex;
}

int main(){
    Map();
    return 0;
}

// Map stores key value pairs of data
// key is always a simple data type but the value can be a complex data type
// Map orders elements by keys in the ascending order
// keys must be unique

//If you dont want your elements to be ordered, you can use Un-Ordered Maps

void UnorderedMap()
{
    unordered_map<string, string> unorderedMap;
    unorderedMap.insert(pair<string, string>("Ram", "Singh"));
    unorderedMap.insert(pair<string, string>("Arihant", "Singh"));
    unorderedMap.insert(pair<string, string>("Krishna", "Yadav"));
    unorderedMap.insert({"Rajat","Sharma"});
    unorderedMap.insert(make_pair("Sumit","Chaubey"));

    for (auto pair : unorderedMap)
        cout << pair.first << " : " << pair.second << endl;
}


