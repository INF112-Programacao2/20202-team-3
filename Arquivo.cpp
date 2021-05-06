#include "arquivo/rapidcsv.h"
#include "Arquivo.h"

Arquivo::Arquivo(std::string dirArquivo) {
    //TODO: criar arquivo se nao existir


    //abre o arquivo
    rapidcsv::Document doc(dirArquivo, rapidcsv::LabelParams(0, -1));
    this->arquivo =  doc;



}

std::vector<std::vector<std::string>> Arquivo::getConteudo() {
    std::vector<std::vector<std::string>> lines;

    for(int i = 0; i < this->arquivo.GetRowCount()-1; i++) {
        lines.push_back(this->arquivo.GetRow<std::string>(i));
    }


    return lines;


}