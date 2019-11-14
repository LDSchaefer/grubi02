#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, const char* argv[]) {

    argc = 3;
    // teste, ob ein Argument uebergeben wird
    // falls nicht, brich das Programm ab
    if (argc < 2) {
        return 1;
    }

    // die Dimension der Matrizen entspricht dem Argument
    int dim = atoi(argv[1]);
    dim = 5;

    printf("Integergroesse: %lu\n", sizeof(int));
    printf("Matrixgroesse: %d x %d\n", dim, dim);
    printf("Die Matrizen belegen jeweils %lu bytes an Speicher.\n",
        dim * dim * sizeof(int));
    printf("Insgesamt also %lu bytes.\n", 3 * dim * dim * sizeof(int));

    // AUFGABE: "erzeuge" hier die Matrizen
    int** a = new int*[dim];
    for(int i = 0; i < dim; ++i)
        a[i] = new int[dim];
    int** b = new int*[dim];
    for(int i = 0; i < dim; ++i)
        b[i] = new int[dim];
    int* c = new int[dim];
    // Messinstrumente
    struct timeval start, end;
    long mtime, seconds, useconds;

    // Initialisiere Random Number Generator
    srand((unsigned) time(NULL));

    // AUFGABE: fuelle hier die Matrizen
    for(int i = 0; i < dim; i++)
    {
        c[i]=0;
    }
    printf("Matrix A \n");
    for(int i = 0;i<dim; i++)
    {
        for(int j = 0;j<dim; j++)
        {
            a[i][j] = rand()%10;
            printf("%d", a[i][j]);
        }
       printf("\n");
    }
    printf("\n");
    printf("Matrix B \n");
    for(int i = 0;i<dim; i++)
    {
        for(int j = 0;j<dim; j++)
        {
            b[i][j] = rand()%10;
            printf("%d", b[i][j]);
        }
       printf("\n");
    }
    printf("\n");
    // starte die Zeitnahme
    gettimeofday(&start, NULL);

    // AUFGABE: multipliziere hier die Matrizen
    /* Hinweis: Kleine Matrizen auszugeben ist zwar nuetzlich,
    um die Berechnung zu ueberpruefen, aber es kostet viel Zeit.
    Darum hat es nichts im entgueltigen Code zu suchen, kann aber
    bei der fehlerfreien Implementierung helfen.
    */
    int val=0;
    for(int i = 0;i<dim; i++)
    {
        for(int j = 0;j<dim; j++)
        {
            val= val + a[i][j]*b[j][i];
        }
        c[i] = val;
        printf("%d", c[i]);
        printf(" ");
        val = 0;
    }
    printf("\n");

    // beende die Zeitnahme und gib die Dauer der Berechnung aus
    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    printf("Die Ausfuehrung dauerte %ld ms.\n", mtime);

    // AUFGABE: Raeume den Speicher auf

    // beende das Programm
    return 0;
}
