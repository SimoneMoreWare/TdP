void countingsort(int *a,int n){
    /*
     * range 1 7
     * vettore di appoggio b con 7 elementi
     * 1) contare occorenze vettore a e inseriamo nel vettore b
     *
     */
    int b[8];
    int i;

    //inizializzare vettore
    for(i=0;i<8;i++)
        b[i]=0;
    //contare occorenze di ogni valore all'interno del vettore a
    for(i=0;i<n;i++) {
        b[a[i]]++;
    }
    //ulteriore trasformazione
    //in ogni posizione inseriamo
    //la somma del valore della posizione corrente
    // + quella della posizione precedente
    //questo vettore ci dice:
    //esattamente per ogni posizione
    //quanti elementi <= indice
    //esistono all'interno del vettore a
    //
    for(i=1;i<8;i++){
        b[i]=b[i]+b[i-1];
    }
    //Nel vettore risultante l'elemento i sarà messo nella posizione [b[i]]
    //procedendo leggendo a dall'ultima posizione
    //dall'elemento a vado a leggere la posizione del vettore b
    //ci dice che l'elemento a deve essere posizionato nella posizione b[i]
    //decrementare b[i]
    int ris[10];
    for(i=9;i>=0;i--){
        ris[b[a[i]]]=a[i];
        b[a[i]]--;
    }
    visualizza(ris,10);
}
