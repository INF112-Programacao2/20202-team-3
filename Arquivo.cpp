#include "arquivo/rapidcsv.h"
#include "Arquivo.h"

Arquivo::Arquivo(std::string dirArquivo) {
    //abre o arquivo
    rapidcsv::Document doc(dirArquivo, rapidcsv::LabelParams(-1, -1));
    this->arquivo =  doc;
}

std::vector<std::vector<std::string>> Arquivo::getConteudo() {
    std::vector<std::vector<std::string>> lines;

    for(int i = 0; i < this->arquivo.GetRowCount(); i++) {
        lines.push_back(this->arquivo.GetRow<std::string>(i));
    }


    return lines;


}

/*std::vector<std::vector<std::string>> Arquivo::setConteudo(){
    std::


}
*/