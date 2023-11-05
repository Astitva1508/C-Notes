#include<iostream>
using namespace std;

// Always try to avoid making a copy for maps , sets , vectors because it is a time consuming operation


// We can directly assign value to an element that does not exist in map

// map<int,vector<int>> mapp;
// mapp[2].insert(4)  This is perfectly fine(even if 2 does not exist in mapp).mapp[2] is a vector and we can perform operations on it that we can perform on vectors