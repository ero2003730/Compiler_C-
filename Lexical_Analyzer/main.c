#include "funcs.h" // Inclui as declarações das funções que você definiu em funcs.h

int main(int argc, char *argv[])
{

    int aux = 0;
    struct Lexema *lexema;

    // Verifica se o número correto de argumentos foi fornecido
    if (argc != 2)
    {
        printf("Numero de parametros errados.\n");
        exit(1); // Encerra o programa com um código de erro
    }

    // Tenta abrir o arquivo para leitura
    FILE *file = fopen(argv[1], "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (file == NULL)
    {
        printf("Nao foi possivel abrir o arquivo.\n");
        exit(1); // Encerra o programa com um código de erro
    }

    // Aloca memória para o buffer
    allocate_buffer(&lexema);

    int matriz[13][21] = {
        {1, 2, 3, 3, 3, 4, 4, 4, 7, 6, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0},                       // estado q0 (inicial)
        {1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},   // estado q1
        {10, 2, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},   // estado q2
        {10, 10, 10, 10, 4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},   // estado q3
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},  // estado q4
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},  // estado q5
        {11, 11, 11, 11, 12, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},  // estado q6
        {10, 10, 10, 10, 10, 10, 10, 8, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},   // estado q7
        {8, 8, 8, 8, 8, 8, 8, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},                       // estado q8
        {8, 8, 8, 8, 8, 8, 8, 8, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},                       // estado q9
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},                       // estado q10 (final)
        {11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11},  // estado q11 (erro)
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}}; // estado de transicao para '!=' pois estava dando erro

    char c;
    int estado = 0, novo_estado = 0;
    int coluna = 0;
    int i = 0;
    int lines = 1; // inicializa a contagem de linhas

    initHashTable(); // Inicializando o Hash

    while ((c = get_next_char(file)) != EOF)
    {
        if (c == '\n')
        {
            lines++;
        }

        while (1)
        {
            coluna = get_position(c);

            if (coluna == -1)
            {
                printf("Erro: caractere: '%c', na linha %d não eh válido\n", c, lines);
                return -1;
            }

            novo_estado = matriz[estado][coluna];

            if (estado == 7 && novo_estado == 8)
            {
                int comentarioFechado = 0;
                c = get_next_char(file);

                while (!comentarioFechado && c != EOF)
                {
                    if (c == '\n')
                    {
                        lines++;
                    }

                    if (c == '*')
                    {
                        c = get_next_char(file);
                        if (c == '/')
                        {
                            comentarioFechado = 1;
                            break;
                        }
                    }
                    c = get_next_char(file);
                }

                if (!comentarioFechado)
                {
                    printf("Erro: comentario nao fechado antes do fim do arquivo na linha %d\n", lines);
                    return -1;
                }
            }
            else
            {
                if (novo_estado == 0 || novo_estado == 10 || novo_estado == 11)
                {
                    if (novo_estado == 10)
                    {
                        reprocess = 1;
                    }

                    break;
                }

                lexema[aux].lexemaBuffer[i] = c;
                i++;
                c = get_next_char(file);

                if (c == EOF)
                {
                    lexema[aux].linha = lines;

                    if (estado == 1)
                    {
                        lexema[aux].lexemaBuffer[i] = '\0';
                        identify_keyword_or_id_using_hash(lexema[aux].lexemaBuffer, &lexema, aux);
                        aux++;
                    }
                    else
                    {
                        lexema[aux].lexemaBuffer[i] = '\0';
                        get_lexema(lexema[aux].lexemaBuffer, &lexema, aux, i);
                        aux++;
                    }
                    return -1;
                }

                estado = novo_estado;
            }
        }

        if (novo_estado == 10)
        {
            lexema[aux].linha = lines;

            if (estado == 1)
            {
                lexema[aux].lexemaBuffer[i] = '\0';
                identify_keyword_or_id_using_hash(lexema[aux].lexemaBuffer, &lexema, aux);
                aux++;
            }
            else
            {
                lexema[aux].lexemaBuffer[i] = '\0';
                get_lexema(lexema[aux].lexemaBuffer, &lexema, aux, i);
                aux++;
            }
        }
        else if (novo_estado == 11)
        {
            printf("Erro na linha %d: O caractere '!' foi encontrado, mas deve ser seguido imediatamente por um '=' para formar o operador '!=' válido.\n", lines);
            return -1;
        }

        i = 0;
        estado = 0;
    }

    // Libera a memória alocada para o buffer
    deallocate_buffer(&lexema);

    // Fecha o arquivo
    fclose(file);

    return 0; // Encerra o programa com sucesso
}
