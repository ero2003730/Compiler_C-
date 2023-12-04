#include "../h/funcs.h" // Inclui as declarações das funções funcs.h
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

    if (final == 1)
    {
        printf("\n");
        printf("\n\n----------------------------Analisador Sintática----------------------------\n\n");
        printf("\n");
        print_ast(raizDaArvore, 1);

        printf("\n\n----------------------------Analisador Semântico----------------------------\n\n");

        initHash();

        pushTabela(R_fun_declaracao, 0, "input", "global", 1);
        pushTabela(R_fun_declaracao, 1, "output", "global", 1);

        searchTree(raizDaArvore, "global");

        imprimirTabela();
    }

    if (final == -1)
    {
        printf("\n\nERRO NO ANALISADOR LÉXICO, CORRIJA O ERRO, RODE DE NOVO PARA PODER CONTINUAR COM O SINTÁTICO\n\n");
    }

    // Libera a memória alocada para o buffer
    deallocate_buffer();

    deallocateNode(raizDaArvore);

    // Fecha o arquivo
    fclose(file);

    return 0; // Encerra o programa com sucesso
}
