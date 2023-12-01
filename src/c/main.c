#include "../h/funcs.h" // Inclui as declarações das funções que você definiu em funcs.h

int main(int argc, char *argv[])
{
    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 2)
    {
        printf("Numero de parametros errados.\n");
        exit(1); // Encerra o programa com um código de erro
    }

    // Tenta abrir o arquivo para leitura
    file = fopen(argv[1], "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1); // Encerra o programa com um código de erro
    }

    // Aloca memória para o buffer
    allocate_buffer();
    listLexema = initLexemaList();

    printf("\n\n----------------------------Analisador Léxico----------------------------\n\n");
    // analisadorSintatico();
    parse();

    printf("\n\n----------------------------Analisador Semântico----------------------------\n\n");

    // Libera a memória alocada para o buffer
    deallocate_buffer();

    deallocateNode(raizDaArvore);

    // Fecha o arquivo
    fclose(file);

    return 0; // Encerra o programa com sucesso
}
