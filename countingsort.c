void countingsort(int *array,int arraySize){
    /*
     * range 1 7
     * vettore di appoggio b con 7 elementi
     * 1) contare occorenze vettore a e inseriamo nel vettore b
     *
     */
    int i,b[100]; //100 dimensione dell intervallo che va da 1 a 100
    int res[100];

    //inizializzare vettore
     for(i=0;i<100;i++){
        b[i]=0;
    }
    //contare occorenze di ogni valore all'interno del vettore a
    for(i=0;i<arraySize;i++){
        b[array[i]]++;
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
    for(i=1;i<100;i++){
        b[i]=b[i]+b[i-1];
    }
    //Nel vettore risultante l'elemento i sarà messo nella posizione [b[i]]
    //procedendo leggendo a dall'ultima posizione
    //dall'elemento a vado a leggere la posizione del vettore b
    //ci dice che l'elemento a deve essere posizionato nella posizione b[i]
    //decrementare b[i]
    for(i=arraySize-1;i>=0;i--){
        res[b[array[i]]-1]=array[i];
        b[array[i]]--;
    }
    
    for(i=0;i<arraySize;i++){
        array[i]=res[i];
    }
    
}
