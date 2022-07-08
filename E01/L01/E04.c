#include <stdio.h>
#define P 3.14

int main() {
float area,diagonale,lato,diametro,raggio;
char scelta_poligono,scelta_area;

printf("Vuoi calcolare area quadrato(Q) o area cerchio(C)");
scanf(" %c",&scelta_poligono);

switch(scelta_poligono) {
    case 'C':
        printf("Scegli diagonale o raggio");
        scanf(" %c",&scelta_area);
        if (scelta_area == 'D'){
            printf("inserisci diagonale");
            scanf(" %f",&diagonale);
            area = P*diagonale*diagonale/4;
        }else if (scelta_area == 'R'){
            printf("inserisci raggio");
            scanf(" %f",&raggio);
            area = P*raggio*raggio;
        }
        printf(" Area cerchio = %.2f ",area);
        break;
    case 'Q':
        printf("Scegli diagonale o lato");
        scanf(" %c",&scelta_area);
        if (scelta_area == 'D'){
            printf("inserisci diagonale");
            scanf(" %f",&diagonale);
            area = diagonale*diagonale/2;
        }else if (scelta_area == 'L'){
            printf("inserisci lato");
            scanf(" %f",&lato);
            area = lato*lato;
        }
        printf(" Area quadrato = %.2f ",area);
        break;
    default:
        printf("valori errati");
}



return 0;
}

