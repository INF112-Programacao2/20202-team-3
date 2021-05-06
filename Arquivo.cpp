#include "arquivo/rapidcsv.h"
#include "Arquivo.h"

Arquivo::Arquivo(std::string dirArquivo) {
    //TODO: criar arquivo se nao existir


    //abre o arquivo
    rapidcsv::Document doc(dirArquivo, rapidcsv::LabelParams(0, -1));
    this->arquivo =  doc;


}
