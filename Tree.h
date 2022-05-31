#ifndef TREE_H
#define TREE_H
#include"Coda.h"
#include "Persona.h"


template <class T>
class NodoBST
{
public:
    T val;

    NodoBST<T>* sx;
    NodoBST<T>* dx;
    NodoBST<T>* padre;
};

template <class T>
class Tree
{
    private:
        NodoBST<T>* root;

    public:
        Tree();
        NodoBST<T>* getRoot(){return root;}
        void inserisci (T);
        bool BSTisEmpty() const;
        NodoBST<T>* minimo (NodoBST<T>*);
        int getAltezza(NodoBST<T>*) const;
        NodoBST<T>* cerca(T);
        void trapianta (NodoBST<T>*,NodoBST<T>*);
        void cancellaNodo(NodoBST<T>*);
        NodoBST<T>* elimina_eta (NodoBST<T>*, int);



        friend
        ostream &operator << (ostream &out, const Tree<T> &b)
        {
          if(b.BSTisEmpty())
            cout<<"albero vuoto"<<endl;
          int h = b.getAltezza(b.root);

            for(int i = 0; i < h; i++)
            {
                stampaLivello(b.root, i);
                cout << endl;
            }
            return out;
        }








};




#endif // TREE_H

template <typename T>
Tree<T>::Tree() : root(nullptr){}
template<typename T>
void Tree<T>::inserisci(T valore){

  NodoBST<T> *nuovo = new NodoBST<T>;
  NodoBST<T> *x = root, *y = nullptr;

  nuovo->val = valore;

  nuovo->sx = nullptr;
  nuovo->dx = nullptr;

  while(x != nullptr)
  {
      y = x;

      if(valore < x->val)
      {
          x = x->sx;
      }
      else
      {
          x = x->dx;
      }
  }

  nuovo->padre = y;
  if(y == nullptr)
  {
      root = nuovo;
  }
  else if(valore < y->val)
  {
      y->sx = nuovo;
  }
  else
  {
      y->dx = nuovo;
  }
}

template<typename T>
bool Tree<T>::BSTisEmpty()const{return root == nullptr;}

template<typename T>
NodoBST<T>* Tree<T>::minimo(NodoBST<T> *x)
      {
          NodoBST<T> *min = x;
          while(min->sx != nullptr)
          {
              min = min->sx;
          }

          return min;
      }

template<typename T>
int Tree<T>::getAltezza(NodoBST<T> *p) const
{
    if(p == nullptr)
    {
        return 0;
    }
    else
    {
        int altezzasx= getAltezza(p->sx);
        int altezzadx= getAltezza(p->dx);


        if(altezzasx > altezzadx)
        {
            return altezzasx+1;
        }
        else
        {
            return altezzadx+1;
        }
    }
}

template<typename T>
NodoBST<T>* Tree<T>::cerca(T valore){
  Nodo<T>* x=root;
  while(x!=nullptr && x->val!=valore){
      if(x->val>valore)
        x=x->sx;
      else
        x=x->dx;
    }
  return x;
}

template<typename T>
void Tree<T>::trapianta(NodoBST<T> *u, NodoBST<T> *v)
{
    if(u->padre == nullptr)
    {
        root = v;
    }
    else if(u == u->padre->sx)
    {
        u->padre->sx = v;
    }
    else
    {
        u->padre->dx = v;
    }

    if(v != nullptr)
    {
        v->padre = u->padre;
    }
}
template<typename T>

void Tree<T>::cancellaNodo(NodoBST<T> *z)
{
    NodoBST<T> *y;



    if(z->sx == nullptr)
    {
        trapianta(z, z->dx);
    }
    else if(z->dx == nullptr)
    {
        trapianta(z, z->sx);
    }


    else
    {
        y = minimo(z->dx);

        if(y->padre != z)
        {
            trapianta(y, y->dx);
            y->dx = z->dx;
            y->dx->padre = y;
        }

        trapianta(z, y);
        y->sx = z->sx;
        y->sx->padre = y;
    }

    delete z;
}

template<typename T>
NodoBST<T>* Tree<T>::elimina_eta(NodoBST<T>* nodo, int etalimite)
{
  if(nodo == nullptr)
    return nodo;
  nodo->sx = elimina_eta(nodo->sx,etalimite);
  nodo->dx = elimina_eta(nodo->dx,etalimite);

  NodoBST<T>* nuovo = nodo;

  if(nodo->val.eta < etalimite){
      nodo = nodo->dx;
      cancellaNodo(nuovo);
    }
  return nodo;

}


template<typename T>
void stampaLivello(NodoBST<T> *p, int livello)
{
    if(p == nullptr)
    {
        cout << "NULL\t";
        return;
    }

    if(livello == 0)
    {
        cout << p->val << "\t";
    }
    else if(livello > 0)
    {
        stampaLivello(p->sx, livello-1);
        stampaLivello(p->dx, livello-1);
    }
}






