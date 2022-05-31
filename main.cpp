#include <iostream>
#include<ctime>
#include "Tree.h"


using namespace std;

int main()
{
  srand(time(NULL));
  string array_nomi [15]={"Luca","Gaetano","Alessandro","Eugenio","Carmelo","Costanza",
                          "Lucia","Elena","Teresa","Martina","Malena","Sasha","Ludovica",
                          "Claudia","Giorgia"};

  int eta_da_eliminare;
  Tree<Studente> albero_studenti;
  Tree<Lavoratore> albero_lavoratori;
  Tree<Pensionato> albero_pensionato;
  Coda<Studente> coda_studenti;
  Coda<Lavoratore> coda_lavoratore;
  Coda<Pensionato> coda_pensionato;
  int numero_persone;
  cout<<"Quante persone vorresti creare?"<<endl;
  cin>>numero_persone;
  int count_studenti = 0,count_lavoratori = 0,count_pensionati=0;
  for(int i = 0; i <numero_persone; i++){
      int random_eta = rand()%91;
      int random_tipo = rand()%3;
      switch (random_tipo) {
        case 0: {
            Studente studente(random_eta,array_nomi[rand()%15]);
            coda_studenti.enQueue(studente);
            count_studenti++;
            break;
          }
        case 1:{
            Lavoratore lavoratore(random_eta,array_nomi[rand()%15]);
            coda_lavoratore.enQueue(lavoratore);
            count_lavoratori++;
            break;
          }
        case 2:
          {
            Pensionato pensionato(random_eta,array_nomi[rand()%15]);
            coda_pensionato.enQueue(pensionato);
            count_pensionati++;
            break;
          }

        }



    }

cout<<"________________________________________________________"<<endl;
cout<<endl;
cout<<endl;
cout<<"                          CODE                          ";
cout<<endl;
cout<<endl;
cout<<"________________________________________________________"<<endl<<endl;

  cout<<"ecco la coda degli studenti"<<coda_studenti<<endl;
  cout<<"ecco la coda dei lavoratori"<<coda_lavoratore<<endl;
  cout<<"ecco la coda dei pensionati"<<coda_pensionato<<endl;


  for(int i = 0; i<count_studenti; i++){
      albero_studenti.inserisci(coda_studenti.deQueue());
    }
  for(int i = 0; i<count_lavoratori; i++){
      albero_lavoratori.inserisci(coda_lavoratore.deQueue());
    }
  for(int i = 0; i<count_pensionati; i++){
      albero_pensionato.inserisci(coda_pensionato.deQueue());
    }

    cout<<"________________________________________________________"<<endl;
cout<<endl;
cout<<endl;
cout<<"                            ALBERI                          ";
cout<<endl;
cout<<endl;
cout<<"________________________________________________________"<<endl<<endl;


  cout<<"ALBERO STDENTI:"<<endl;
  cout<<albero_studenti<<endl;
  cout<<"ALBERO LAVORATORI"<<endl;
  cout<<albero_lavoratori<<endl;
  cout<<"ALBERO PENSIONATI"<<endl;
  cout<<albero_pensionato;

 cout<<"da quale eta in giu' vuoi cancellare dagli alberi:";
 cin>>eta_da_eliminare;

 NodoBST<Studente>* radice_studente = albero_studenti.getRoot();
 NodoBST<Lavoratore>* radice_lavoratore = albero_lavoratori.getRoot();
 NodoBST<Pensionato>* radice_pensionato = albero_pensionato.getRoot();

cout<<"________________________________________________________"<<endl;
cout<<endl;
cout<<endl;
cout<<"                ALBERI DOPO LA CANCELLAZIONE            ";
cout<<endl;
cout<<endl;
cout<<"________________________________________________________"<<endl<<endl;



 albero_studenti.elimina_eta(radice_studente,eta_da_eliminare);
 cout<<"-----------ALBERO STDENTI-----------"<<endl;
 cout<<albero_studenti<<endl;

 albero_lavoratori.elimina_eta(radice_lavoratore,eta_da_eliminare);
 cout<<"----------ALBERO LAVORATORI---------"<<endl;
 cout<<albero_lavoratori<<endl;

 albero_pensionato.elimina_eta(radice_pensionato,eta_da_eliminare);
 cout<<"---------ALBERO PENSIONATI----------"<<endl;
 cout<<albero_pensionato;

system("pause");

  return 0;
}
