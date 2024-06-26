#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "2005036_SymbolTable.cpp"

using namespace std;

int main() {
    string INPUT_FILE = "input.txt";
    string OUTPUT_FILE = "output.txt";

    ifstream fin;
    ofstream fout;

    fin.open(INPUT_FILE);
    fout.open(OUTPUT_FILE);

    if (!fin || !fout){
        cout << " Cannot open file \n";
        return 1;
    }

    /* redirect cout buffer to fout buffer
       now cout will write in the file */
    streambuf* COUT_BUFFER = cout.rdbuf();
    cout.rdbuf(fout.rdbuf());

    int cmdCount = 0;
    int bucketNum;
    string inputLine;
    string* arguments;

    getline(fin, inputLine);
    stringstream ss(inputLine);

    ss >> bucketNum;

    SymbolTable* symbolTable = new SymbolTable(bucketNum);

    while(!fin.eof()){
        getline(fin, inputLine);
        stringstream ss(inputLine);
       
        arguments = new string[4];
        int count = 0;

        /* tokenize input line */
        while(!ss.eof()){
            if(!ss.fail()){
                ss >> arguments[count++];
            }   
        }

        /* print cmd */
        fout << "Cmd " << ++cmdCount << ": " << inputLine << endl;
        
        /* handling commands */
        if(arguments[0] == "I"){
            
            if(count != 3)
                fout << "\t" << "Wrong number of arugments for the command " << 
                    arguments[0] << endl;
            else{
                symbolTable->insert(arguments[1], arguments[2]);
            }
                

        }
        else if(arguments[0] == "L"){

            if(count != 2)
                fout << "\t" << "Wrong number of arugments for the command " << 
                    arguments[0] << endl;
            else
                symbolTable->lookup(arguments[1]);

        }
        else if(arguments[0] == "D"){

            if(count != 2)
                fout << "\t" << "Wrong number of arugments for the command " << 
                    arguments[0] << endl;
            else
                symbolTable->remove(arguments[1]);

        }
        else if(arguments[0] == "P"){

            if(count != 2)
                fout << "\t" << "Wrong number of arugments for the command " << 
                    arguments[0] << endl;
            else if(arguments[1] == "A")
                symbolTable->printAllScopeTables();
            else if(arguments[1] == "C")
                symbolTable->printCurrScopeTable();
            else
                fout << "\t" << "Invalid argument for the command " << 
                    arguments[0] << endl;

        }
        else if(arguments[0] == "S"){

            if(count != 1)
                fout << "\t" << "Wrong number of arugments for the command " << 
                    arguments[0] << endl;
            else
                symbolTable->enterScope();

        }
        else if(arguments[0] == "E"){

            if(count != 1)
                fout << "\t" << "Wrong number of arugments for the command " << 
                    arguments[0] << endl;
            else
                symbolTable->exitScope();

        }
        else if(arguments[0] == "Q"){

            if(count != 1)
                fout << "\t" << "Wrong number of arugments for the command " << 
                    arguments[0] << endl;
            else
                delete symbolTable;

        }
        else {
            fout << "\t" << "Invalid operation " << 
                    arguments[0] << endl;
        }

    
        delete[] arguments;
    }

    /* restore original cout buffer */
    cout.rdbuf(COUT_BUFFER);

    fin.close();
    fout.close();

    return 0;
}