#include "csvreader.h"
CSVReader::CSVReader(){}
void CSVReader::setData(string filename) {
    this->fileName=filename;
}
void CSVReader::generarGrafo(){
    ifstream file(fileName);
    string line = "";
    int i=0;
    while(getline(file, line,'\n')) {
        int y=0;
        int vect[3];
        stringstream ss(line);
        if (i == 0){
            while(ss.good()){
                string substr;
                getline( ss, substr, ',' );
                int num=stoi (substr);
                vect[y]=num;
                y++;
            }grafo->setData(vect[0],vect[1]);
        }else{
            while(ss.good()){
                string substr;
                getline( ss, substr, ',' );
                int num=stoi (substr);
                vect[y]=num;
                y++;
            }grafo->addEdge(vect[0],vect[1],vect[2]);
        }i++;
    }file.close();
}
