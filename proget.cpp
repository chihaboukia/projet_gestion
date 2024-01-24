#include <stdio.h>

void add(int Q, int code, int t[][2], int *taille) {
    int produit_existe = 0;
    for (int i = 0; i < *taille; i++) {
        if (t[i][0] == code) {
            t[i][1] += Q;
            produit_existe = 1;
            break;
        }
    }

    if (produit_existe != 1) {
        t[*taille][0] = code;
        t[*taille][1] = Q; 
        (*taille)++;  
    }
}

void removeProduct(int Q, int code, int t[][2], int *taille) {
    int produit_existe = 0;
    for (int i = 0; i < *taille; i++) {
        if (t[i][0] == code) {
            if (Q <= t[i][1]) {
                t[i][1] -= Q;
                produit_existe = 1;
            } else {
                printf("Erreur : La quantite a retirer non valable.\n");
            }
        }
    }

    if (produit_existe == 0) {  
        printf("Le produit n'existe pas.\n");
    }
}

void affiche(int t[][2], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("code = %d quantite = %d\n", t[i][0], t[i][1]);  
    }
}

int main() {
    int t[3][2] = {{999, 30}, {666, 20}, {777, 40}};
    int code, Q, taille = 3;  
    char choix;

    do {
        printf("Menu : \n");
        printf("1 - Ajouter un produit :\n");
        printf("2 - Retirer un produit : \n");
        printf("3 - Afficher le stock : \n");
        printf("4 - Quitter : \n");
        printf("5 - Votre choix : \n");
        scanf(" %c", &choix);

        switch (choix) {
            case '1':
                printf("Entrer le code de produit :\n");
                scanf("%d", &code);  
                printf("Entrer la quantite de produit :\n");
                scanf("%d", &Q);  
                add(Q, code, t, &taille);
                break; 

            case '2':
                printf("Entrer le code de produit :\n");
                scanf("%d", &code);  
                printf("Entrer la quantite de produit :\n");
                scanf("%d", &Q);  
                removeProduct(Q, code, t, &taille);  
                break;  

            case '3':
                affiche(t, taille);
                break;  

            case '4':
                printf("Vous avez quitte!\n");
                break;
                
            default:
                printf("Choix invalide. Veuillez entrer un choix entre 1 et 4.\n");
        }
    } while (choix != '4');  

    return 0;
}

