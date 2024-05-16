#include <stdio.h>
#include <math.h>

// Funções para converter graus em radianos e vice-versa
double deg2rad(double degrees) {
    return degrees * (M_PI / 180.0);
}

double rad2deg(double radians) {
    return radians * (180.0 / M_PI);
}

void calcularLeiDosSenos(FILE *file) {
    double a, b, c, A, B, C;
    printf("Informe o valor do lado a: ");
    scanf("%lf", &a);
    printf("Informe o valor do ângulo A (em graus): ");
    scanf("%lf", &A);

    printf("Informe o valor do lado b: ");
    scanf("%lf", &b);
    printf("Informe o valor do ângulo B (em graus): ");
    scanf("%lf", &B);

    // Calculando o lado c usando a Lei dos Senos
    C = 180.0 - A - B;
    c = (a / sin(deg2rad(A))) * sin(deg2rad(C));

    fprintf(file, "Lei dos Senos:\n");
    fprintf(file, "a = %.2lf, A = %.2lf graus\n", a, A);
    fprintf(file, "b = %.2lf, B = %.2lf graus\n", b, B);
    fprintf(file, "c calculado = %.2lf, C calculado = %.2lf graus\n", c, C);
}

void calcularLeiDosCossenos(FILE *file) {
    double a, b, c, C;
    printf("Informe o valor do lado a: ");
    scanf("%lf", &a);
    printf("Informe o valor do lado b: ");
    scanf("%lf", &b);
    printf("Informe o valor do ângulo C (em graus): ");
    scanf("%lf", &C);

    // Calculando o lado c usando a Lei dos Cossenos
    c = sqrt(a * a + b * b - 2 * a * b * cos(deg2rad(C)));

    fprintf(file, "Lei dos Cossenos:\n");
    fprintf(file, "a = %.2lf, b = %.2lf\n", a, b);
    fprintf(file, "C = %.2lf graus\n", C);
    fprintf(file, "c calculado = %.2lf\n", c);
}

int main() {
    FILE *file = fopen("calculos.txt", "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    int escolha;
    printf("Escolha a operação:\n1. Lei dos Senos\n2. Lei dos Cossenos\n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        calcularLeiDosSenos(file);
    } else if (escolha == 2) {
        calcularLeiDosCossenos(file);
    } else {
        printf("Opção inválida!\n");
    }

    fclose(file);
    printf("Cálculos realizados e salvos em 'calculos.txt'\n");

    return 0;
}
