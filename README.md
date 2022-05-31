# Progetto-programmazione-2
<h2>ANALISI DEL PROBLEMA</h2>
Il progetto richiede l’implementazione di due strutture (ADT), uno
a preferenza del programmatore e un BST. Le procedure che
bisogna compiere sono, inserimento degli oggetti nelle strutture
dati create, estrazione dalle struttura nei BST e un metodo che
cancelli tutti i nodi sotto un certo valore dall’albero binario di
ricerca. Il numero di oggetti da creare viene dettato dell’utente,
mentre il tipo e attributi vengono creati in modo casuale.

<h2>COSNIDERAZIONI PROGETTUALI</h2>
Come struttura dati iniziale al fine di raccogliere gli oggetti ed
estrarli è stata creata una coda, essendo una struttura di tipo
FIFO permette di inserire gli oggetti nel BST nello stesso ordine in
cui si trovano nella struttura precedente, inoltre essendo un
implementazione dinamica permette di effettuare le procedure
di inserimento ed estrazione con una complessità di O(1).
<H3>I metodi utilizzati per la Coda sono:</H3>
<br>
  <li>
enQueue: metodo di inserimento
  <li>
deQueue: metodo di cancellazione e estrazione
    <li>
isEmpty: ci inidica se la coda è vuota
      <li>
operatore <<: per effettuare la stampa della lista.
        
 <H3>I metodi utilizzati nel BST sono: </H3>
<li>
  getRoot(): ritorna la radice
<li>
  inserisce: metodo di inserimento
<li>
  BSTisEmpty: indica se l’albero è vuoto
<li>
  Minimo: torna il valore minimo dell’albero
<li>
  getAltezza: ritorna l’altezza dell’albero
<li>cerca: cerca un elemento nell’albero
<li>trapianta: effettua il trapianto di due nodi per compiere la
<li>cancellazione mantenendo le leggi di un BST
<li>cancellaNodo: elimina un nodo dall’albero
<li>elimina_eta: metodo che ci cancella i nodi inferiori al
parametro dato in input dall’utente.
<li>Overloading operatore <<: permette la stampa dell’albero
  
  <H2>CLASSI UTILIZZATE</h2>
Per completare il progetto sono state implementate quattro
classi. Una classe base denominata “Persone” che contiene due
attributi uno intero e una stringa, e tre classi derivate una
Studente con due membri, un costruttore che prende in input un
intero e una stringa un costruttore di default e l’overloading
dell’operatore < e <<. Le altre due classi sono denominate
Lavoratore e Pensionato e hanno le stesse caratteristiche della
classe Studente.
                      <H2> ANALISI COMPLESSITA' </H2>
L’inserimento e l’estrazione dalla coda avvengono in tempo O(1),
tutte le operazioni nel BST invece avvengono con complessità
O(n).

<h2> ESEMPIO OUTPUT </H2>
<img src="https://github.com/Xorion99/Progetto-programmazione-2/blob/main/esempio%20output/1.PNG">
<img src="https://github.com/Xorion99/Progetto-programmazione-2/blob/main/esempio%20output/2.PNG">
