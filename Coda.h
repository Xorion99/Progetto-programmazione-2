#ifndef CODA_H
#define CODA_H

#include <iostream>

using namespace std;

template <class T>
class Nodo
{
    public:
// attributi
        T ele;
        Nodo<T> *next;
        Nodo(T n) : ele(n), next(nullptr){}
};

template <class T>
class Coda
{
    private:
        Nodo<T> *fronte, *fine;

    public:
        Coda();

        void enQueue(T x);

        T deQueue();

        bool isEmpty() const;


    friend ostream &operator << (ostream &out, const Coda<T> &q)
    {
        Nodo<T> *iter;
        if(q.isEmpty())
        {
            out << "Coda vuota!" << endl;
        }
        else
        {

            for(iter = q.fronte; iter != nullptr; iter = iter->next)
            {
                out<<endl;
                out << " | " << iter->ele;
            }
            out << " | ";
        }

        out << endl;

        return out;
    }
};


#endif // CODA_H

template<typename T>
void Coda<T>::enQueue(T x)
{
    Nodo<T> *tmp = new Nodo<T>(x);

    if(fine == nullptr)
    {
        fronte = fine = tmp;
    }
    else                                                            
    {
        fine->next = tmp;
        fine = tmp;
    }
}
template<typename T>
Coda<T>::Coda(){ fronte = fine = nullptr;}

template<typename T>
T Coda<T>::deQueue(){
  Nodo<T> *tmp = fronte;                                          
  fronte = fronte->next;                                          
  if(fronte == nullptr)                                           
  {
      fine = nullptr;
  }

  return tmp->ele;
  delete tmp;
}

template <typename T>

bool Coda<T>::isEmpty()const{return fine == nullptr;}
