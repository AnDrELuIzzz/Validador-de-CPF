#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
void estado(int digito)
{
    switch (digito)
    {
    case 0:
        printf("Rio Grande do Sul");
        break;
    case 1:
        printf("Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins");
        break;
    case 2:
        printf("Amazonas, Pará, Roraima, Amapá, Acre e Rondônia");
        break;
    case 3:
        printf("Ceará, Maranhão e Piauí");
        break;
    case 4:
        printf("Paraíba, Pernambuco, Alagoas e Rio Grande do Norte");
        break;
    case 5:

        printf("Bahia e Sergipe");
        break;
    case 6:
        printf("Minas Gerais");
        break;
    case 7:
        printf("Rio de Janeiro e Espírito Santo");
        break;
    case 8:
        printf("São Paulo");
        break;
    case 9:
        printf("Paraná e Santa Catarina");
        break;
    }
}
bool todosRepetidos(int cpf[])
{
    int i;
    for (i = 1; i <= 10; i++)
    {
        if (cpf[0] != cpf[i])
            return false;
    }
    return true;
}

int main()
{
    int cpf[11];
    int m1[9] = {10, 9, 8, 7, 6, 5, 4, 3, 2};
    int m2[10] = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    int i;
    printf("Entre com os 11 digitos do CPF:");
    for (i = 0; i < 11; i++)
    {
        scanf("%d", &cpf[i]);
    }
    // Cálculo do primeiro dígito verificador
    int soma = 0;
    for (i = 0; i < 9; i++)
    {
        soma = soma + cpf[i] * m1[i];
    }
    int resto1 = ((soma * 10) % 11) % 10;

    if (resto1 == cpf[9])
    {
        printf("\nPrimeiro verificador valido.");
    }
    else
    {
        printf("\nErro no primeiro verificador.");
    }

    // Cálculo do segundo dígito verificador
    soma = 0;

    for (i = 0; i < 10; i++)
    {
        soma = soma + cpf[i] * m2[i];
    }
    int resto2 = ((soma * 10) % 11) % 10;

    if (resto1 == cpf[9] && resto2 == cpf[10] && !todosRepetidos(cpf))
    {
        printf("\nCPF valido.");
        estado(cpf[8]);
    }
    else
    {
        printf("\n Erro no CFP");
    }
    return 0;
}