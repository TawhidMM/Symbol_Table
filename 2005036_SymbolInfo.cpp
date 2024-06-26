#include<iostream>
#include<string>

using namespace std;

class SymbolInfo {
private: 
    string name;
    string type;
    SymbolInfo* nextSymbolInfo;

public:
    SymbolInfo(string name, string type){
        this->name = name;
        this->type = type;
        this-> nextSymbolInfo = NULL;
    }

    string getName(){
        return name;
    }

    string getType(){
        return type;
    }

    SymbolInfo* getNext(){
        return nextSymbolInfo;
    }
    void setNext(SymbolInfo* nextSymbolInfo){
        this->nextSymbolInfo = nextSymbolInfo;
    }

    friend ostream& operator<<(ostream& os, const SymbolInfo& obj) {
        os << "(" << obj.name << "," << obj.type << ")";
        return os;
    }
};
