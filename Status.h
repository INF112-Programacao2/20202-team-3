#ifndef TEAM_3_STATUS_H
#define TEAM_3_STATUS_H
#include <iostream>


class Status
{
private:
    int _id_pessoa;
    int _saturacao;
    int _bpm;
    int _freq;
    std::string _pressao;

public:
    Status(int id_pessoa, int _saturacao, int _bpm, int _freq, std::string pressao);
    int atualizar();

    int  get_id_pessoa() const;
    int  set_id_pessoa(int id_pessoa);

    int  get_saturacao() const;
    void set_saturacao(int saturacao);

    int  get_bpm() const;
    void set_bpm(int bpm);

    int  get_freq() const;
    void set_freq(int freq);

    std::string get_pressao() const;
    void set_pressao(std::string pressao);

};
#endif
