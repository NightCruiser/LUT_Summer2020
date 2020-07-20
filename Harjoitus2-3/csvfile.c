void monthToFile(MAnalyse_t *pStart)
{
        s_tulokset *pTul = NULL;
        FILE *pCsv = NULL;
        int valinta = 0;

        printf("Mikä kuukausianalyysi tallennetaan?\n"
        "1) Keskilämpötila\n"
        "2) Minimilämpötila\n"
        "3) Maksimilämpötila\n"
        "Valintasi: ");
        scanf(" %d", &valinta);
        if (valinta < 1 || valinta > 3 ) {
                printf("Tuntematon valinta, yritä uudestaan.\n");
                return;
        }
        if (!(pCsv = fopen("tulostiedot.csv", "wt"))) {
                perror("Tiedostoon kirjoittaminen epäonnistui");
                return;
        }
        pTul = pStart->pTulokset;
        while (pTul) {
                fprintf(pCsv, ";%s",pTul->month);
                pTul = pTul->pNext;
        }
        fprintf(pCsv, "\n");
        pTul = NULL;
        clearStdin();
        while(pStart) {
                pTul = pStart->pTulokset;
                fprintf(pCsv, "%s - %d",
                pStart->paikka, pStart->year);
                while(pTul) {
                        if (valinta == 1) {
                                fprintf(pCsv, ";%d", pTul->avgTemp );
                        } else if (valinta == 2) {
                                fprintf(pCsv, ";%d", pTul->minTemp );
                        } else if (valinta == 3) {
                                fprintf(pCsv, ";%d", pTul->maxTemp );
                        } else {
                                printf("Tuntematon valinta, yritä uudestaan.\n");
                        }
                        pTul = pTul->pNext;
                }

                fprintf(pCsv, "\n");
                pStart = pStart->pNext;
        }
        printf("Tiedot tallennettu tiedostoon: 'tulostiedot.csv'\n");
        fclose(pCsv);
}
/******************************************************************************/
void monthToFile(MAnalyse_t *pStart)
{
        s_tulokset *pTul = NULL;
        FILE *pCsv = NULL;
        int valinta = 0;
        /*Will check if file already exists. If not will create and
         *add the first string with months
         */
        if (!(pCsv = fopen("tulostiedot.csv", "r"))) {
                if (!(pCsv = fopen("tulostiedot.csv", "wt"))) {
                        perror("Tiedostoon kirjoittaminen epäonnistui");
                        return;
                }
                pTul = pStart->pTulokset;
                while (pTul) {
                        fprintf(pCsv, ";%s",pTul->month);
                        pTul = pTul->pNext;
                }
                fprintf(pCsv, "\n");
                pTul = NULL;
                fclose(pCsv);
        }
        printf("Mikä kuukausianalyysi tallennetaan?\n"
               "1) Keskilämpötila\n"
               "2) Minimilämpötila\n"
               "3) Maksimilämpötila\n"
               "Valintasi: ");
        scanf(" %d", &valinta);
        clearStdin();
        if (!(pCsv = fopen("tulostiedot.csv", "at"))) {
                perror("Tiedostoon kirjoittaminen epäonnistui");
                return;
        }
        switch (valinta) {
                case 1 :
                        while(pStart) {
                                pTul = pStart->pTulokset;
                                fprintf(pCsv, "%s - %d",
                                        pStart->paikka, pStart->year);
                                while(pTul) {
                                        fprintf(pCsv, ";%d", pTul->avgTemp );
                                        pTul = pTul->pNext;
                                }
                                fprintf(pCsv, "\n");
                                pStart = pStart->pNext;
                        }
                        break;
                case 2 :
                        while(pStart) {
                                pTul = pStart->pTulokset;
                                fprintf(pCsv, "%s - %d",
                                        pStart->paikka, pStart->year);
                                while(pTul) {
                                        fprintf(pCsv, ";%d", pTul->minTemp );
                                        pTul = pTul->pNext;
                                }
                                fprintf(pCsv, "\n");
                                pStart = pStart->pNext;
                        }
                        break;
                case 3 :
                        while(pStart) {
                                pTul = pStart->pTulokset;
                                fprintf(pCsv, "%s - %d",
                                        pStart->paikka, pStart->year);
                                while(pTul) {
                                        fprintf(pCsv, ";%d", pTul->maxTemp );
                                        pTul = pTul->pNext;
                                }
                                fprintf(pCsv, "\n");
                                pStart = pStart->pNext;
                        }
                        break;
                default:
                        printf("Tuntematon valinta, yritä uudestaan.\n");
        }
        printf("Tiedot tallennettu tiedostoon: 'tulostiedot.csv'\n");
        fclose(pCsv);
}
/******************************************************************************/
