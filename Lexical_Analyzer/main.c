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

    // Matriz principal dos estados
    int matriz[13][21] = {
        // Colunas: letra numero < > = + - * / ! ; , ( ) [ ] { } espaço \n \0
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

    // Variaveis auxiliares
    char c;
    int estado = 0, novo_estado = 0;
    int coluna = 0;
    int i = 0;
    int lines = 1; // Inicializa a contagem de linhas

    initHashTable(); // Inicializando o Hash

    // Loop principal que fica até encontrar EOF
    while ((c = get_next_char(file)) != EOF)
    {
        if (c == '\n')
        {
            lines++;
        }

        // Loop até encontrar um lexema válido (ou um erro)
        while (1)
        {
            // Pega a coluna em que o caractere se refere
            coluna = get_position(c);

            // Se coluna == -1, significa que não foi encontrado o caractere
            // Logo não é um caractere pertencente a linguagem C-
            if (coluna == -1)
            {
                printf("Erro: caractere: '%c', na linha %d não eh válido\n", c, lines);
                return -1;
            }

            // Pegar o estado em que o caractere está transitando para
            novo_estado = matriz[estado][coluna];

            // Verificação de comentário, se o estado atual for = 7, e o estado que esta
            // sendo transitado para for = 8, então entramos no loop de comentario
            if (estado == 7 && novo_estado == 8)
            {
                // A primeira '/' do comentario é colocada no lexema, pois não satisfaz
                // a condição de estado = 7 e novo_estado = 8, então para não pegá-la,
                // iremos colocar um \0 para zerar
                lexema[aux].lexemaBuffer[0] = '\0';

                int comentarioFechado = 0;
                c = get_next_char(file);

                // While que ira pegar caractere por caractere dentro do comentario
                while (!comentarioFechado && c != EOF)
                {
                    if (c == '\n')
                    {
                        lines++;
                    }

                    // Caso o caractere seja = '*', então pegar o proximo char
                    if (c == '*')
                    {
                        c = get_next_char(file);

                        // Caso o próxio caractere seja igual a '/', então, acabou a
                        // condição de comentário, logo sair
                        if (c == '/')
                        {
                            comentarioFechado = 1;
                            // Pegar o caractere seguinte, pois o atual é o '/' e ele
                            // não pode ser adicionado como lexema
                            c = get_next_char(file);
                            break;
                        }
                    }
                    c = get_next_char(file);
                }

                // Se não encontrar o final do comentário, '*/' isso é um erro, logo printar erro
                if (!comentarioFechado)
                {
                    printf("Erro: comentario nao fechado antes do fim do arquivo na linha %d\n", lines);
                    return -1;
                }
            }

            // Else para caso não satisfaça comentário
            else
            {
                // Verificar se estou no estado inicial, final ou de erro
                if (novo_estado == 0 || novo_estado == 10 || novo_estado == 11)
                {
                    // Caso esteja no estado final (10), reprocessar o último caractere, para ser analisado
                    if (novo_estado == 10)
                    {
                        reprocess = 1;
                    }

                    // Dar break no loop de dentro para analisar se é estado final ou erro
                    break;
                }

                // Se não for nenhum desses estados, então apenas adicionar o caractere no lexema
                lexema[aux].lexemaBuffer[i] = c;
                i++;
                c = get_next_char(file);

                // If para verificação de caso o caractere seguinte ser o EOF, então o que tiver no lexema
                // precisa ainda ser salvo
                if (c == EOF)
                {
                    lexema[aux].linha = lines;

                    // Se veio do estado 1, então é uma palavra, verificar, com complexidade > 0(n) se é palavra
                    // reservada ou se é um identificador
                    if (estado == 1)
                    {
                        lexema[aux].lexemaBuffer[i] = '\0';
                        identify_keyword_or_id_using_hash(lexema[aux].lexemaBuffer, &lexema, aux);
                        aux++;
                    }
                    // Se não for um identificador apenas mandar para analisar o token
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

        // Se o próximo estado for o final, então quer dizer que chegou numa condição que o lexema precisa
        // ser classificado
        if (novo_estado == 10)
        {
            lexema[aux].linha = lines;

            // Se veio do estado 1, então é uma palavra, verificar, com complexidade > 0(n) se é palavra
            // reservada ou se é um identificador
            if (estado == 1)
            {
                lexema[aux].lexemaBuffer[i] = '\0';
                identify_keyword_or_id_using_hash(lexema[aux].lexemaBuffer, &lexema, aux);
                aux++;
            }
            // Se não for um identificador apenas mandar para analisar o token
            else
            {
                lexema[aux].lexemaBuffer[i] = '\0';
                get_lexema(lexema[aux].lexemaBuffer, &lexema, aux, i);
                aux++;
            }
        }


        // Estado de erro. Para esse caso especifico, a unica condicao de erro da matriz é caso seja digitado
        // '!' e não seguir de '='
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