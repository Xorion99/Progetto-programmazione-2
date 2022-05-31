#include<iostream>
#ifndef PERSONA_H
#define PERSONA_H



class Persona{
 public:
  int eta;
  std::string nome;
};


class Studente: public Persona{
public:
  int eta;
  std::string nome;
  Studente(int, std::string);
  Studente(){}
  bool operator <(const Studente&);
  friend
  std::ostream& operator <<(std::ostream& out, const Studente&);

};

class Lavoratore: public Persona{
public:
int eta;
std::string nome;
Lavoratore(int,std::string);
Lavoratore(){}
bool operator<(const Lavoratore&);
friend
std::ostream& operator <<(std::ostream& out, const Lavoratore&);
};

class Pensionato: public Persona{
public:
  int eta;
  std::string nome;
  Pensionato(){}
  Pensionato(int,std::string);
  bool operator<(const Pensionato& p);
  friend
  std::ostream& operator <<(std::ostream& out, const Pensionato&);
};
#endif // PERSONA_H

Studente::Studente(int _eta, std::string _nome):eta(_eta),nome(_nome){}
Lavoratore::Lavoratore(int _eta, std::string _nome):eta(_eta),nome(_nome){}
Pensionato::Pensionato(int _eta, std::string _nome):eta(_eta),nome(_nome){}


bool Studente::operator<(const Studente& s){
  return eta < s.eta;
}
bool Lavoratore::operator<(const Lavoratore &l){
  return eta < l.eta;
}
bool Pensionato::operator<(const Pensionato &p){
  return eta < p.eta;
}




std::ostream& operator<<(std::ostream& out, const Studente& s){
  out<<s.nome<<"("<<s.eta<<")"<<std::endl;
  return out;
}

std::ostream& operator<<(std::ostream& out, const Lavoratore& l){
  out<<l.nome<<"("<<l.eta<<")"<<std::endl;
  return out;
}

std::ostream& operator<<(std::ostream& out, const Pensionato& p){
  out<<p.nome<<"("<<p.eta<<")"<<std::endl;
  return out;
}
