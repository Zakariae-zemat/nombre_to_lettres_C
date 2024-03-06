#include <stdio.h>
#include <string.h>

const char *unites[] = {"", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf"};
const char *dix_19[] = {"dix", "onze", "douze", "treize", "quatorze", "quinze", "seize", "dix-sept", "dix-huit", "dix-neuf"};
const char *dizaines[] = {"", "", "vingt", "trente", "quarante", "cinquante", "soixante", "soixante", "quatre-vingt", "quatre-vingt"};

void convertirSection(int nombre, char *resultat) {
    if (nombre >= 100) {
        strcat(resultat, unites[nombre / 100]);
        if (nombre >= 200) strcat(resultat, " cents");
        else if (nombre == 100) strcat(resultat, " cent");
        if (nombre % 100 > 0) strcat(resultat, " ");
        nombre %= 100;
    }
    if (nombre >= 20) {
        int dizaine = nombre / 10;
        int unite = nombre % 10;
        strcat(resultat, dizaines[dizaine]);
        if ((dizaine == 7 || dizaine == 9) && unite > 0) {
            strcat(resultat, "-");
            strcat(resultat, dix_19[unite]);
        } else {
            if (unite == 1 && dizaine != 8) {
                strcat(resultat, " et un");
            } else if (unite > 1) {
                strcat(resultat, "-");
                strcat(resultat, unites[unite]);
            }
        }
    } else if (nombre > 0) {
        strcat(resultat, unites[nombre]);
    }
}
void nombreEnMots(long long int nombre, char *resultat) {
    if (nombre == 0) {
        strcpy(resultat, "zéro");
    }

    int section[7];
    for (int i = 0; i < 7; i++) {
        section[i] = nombre % 1000;
        nombre /= 1000;
    }


    for (int i = 6; i >= 0; i--) {
        char sectionMots[100] = "";
        convertirSection(section[i], sectionMots);
        if (section[i] != 0 ) {
            strcat(resultat, sectionMots);
            strcat(resultat, " ");
            switch (i) {
            case 1:
                strcat(resultat, "mille");
                break;
            case 2:
                strcat(resultat, (section[i] == 1) ? "million" : "millions");
                break;
            case 3:
                strcat(resultat, (section[i] == 1) ? "milliard" : "milliards");
                break;
            case 4:
                strcat(resultat, (section[i] == 1) ? "billion" : "billions");
                break;
            case 5:
                strcat(resultat, (section[i] == 1) ? "billiard" : "billiards");
                break;
            case 6:
                strcat(resultat, (section[i] == 1) ? "trillion" : "trillions");
                break;
            case 7:
                strcat(resultat, (section[i] == 1) ? "trilliard" : "trillards");
                break;
        }
        strcat(resultat, " ");

            }
        }
    }
int main() {
    long long int nombre;
    char mots[1000] = "";

    printf("Entrez un nombre pour le convertir en lettres : ");
    scanf("%lld", &nombre);

    nombreEnMots(nombre, mots);
    printf("%lld en lettres est : %s\n", nombre, mots);
    return 0;
}
