#ifndef TEAM_3_STATUS_H
#define TEAM_3_STATUS_H
#include <iostream>


class Status
{
private:
    int id_pessoa; //TODO tipo status
    int _saturacao;
    int _bpm;
    int _freq;
    std::string pressao;

public:
    Status(int id_pessoa, int _saturacao, int _bpm, int _freq, std::string pressao);
    ~Status();
    int atualizar();
};
#endif
