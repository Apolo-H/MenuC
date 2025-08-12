#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif

void Limpa_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void Menu_interacao()
{
    printf("======== MENU PRINCIPAL ========\n");
    printf("ATENÇÃO: Para que o Software funcione corretamente é recomendado executa-lo no modo Administrador.\n");
    printf("1 - Recuperação\n");
    printf("2 - CMD Hacks\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
}

void Menu_cmdhacks()
{
    printf("=== MENU DE HACKS DE CMD ===\n");
    printf("1 - Sfc /scannow - Verifica a integridade dos arquivos do Windows e repara arquivos corrompidos ou ausentes.\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
}

void Menu_recuperacao()
{
    printf("=== MENU DE RECUPERAÇÃO ===\n");
    printf("1 - fileRecovery\n");
    printf("2 - PartRecovery\n");
    printf("3 - EasyfileRecovery\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
}

int main()
{
    system("color 02");
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int opcao, submenu;

    do
    {
        system(LIMPAR_TELA);
        Menu_interacao();

        if (scanf("%d", &opcao) != 1)
        {
            Limpa_buffer();
            printf("Opção inválida! Digite apenas números.\n");
            printf("Pressione Enter para continuar...\n");
            getchar();
            continue;
        }

        switch (opcao)
        {
        case 1:
            do
            {
                system(LIMPAR_TELA);
                Menu_recuperacao();

                if (scanf("%d", &submenu) != 1)
                {
                    Limpa_buffer();
                    printf("Opção inválida! Digite apenas números.\n");
                    printf("Pressione Enter para continuar...\n");
                    submenu = -1;
                    getchar();
                    continue;
                }

                switch (submenu)
                {
                case 1:
                    printf("Você escolheu fileRecovery\n");
                    system("\\Menu\\Menu\\softwares\\Recuperação\\fileRecovery.exe");
                    break;

                case 2:
                    printf("Você escolheu PartRecovery\n");
                    system("\\Menu\\Menu\\softwares\\Recuperação\\PartRecovery.exe");
                    break;

                case 3:
                    printf("Você escolheu EasyFileRecovery\n");
                    system("\\Menu\\Menu\\softwares\\Recuperação\\EasyFileRecovery.exe");
                    break;

                case 0:
                    printf("Voltando ao menu principal...\n");
                    break;

                default:
                    printf("Opção inválida\n");
                    break;
                }

                if (submenu != 0)
                {
                    printf("Pressione Enter para continuar...\n");
                    Limpa_buffer();
                    getchar();
                }

            } while (submenu != 0);
            break;

        case 2:
            do
            {
                system(LIMPAR_TELA);
                Menu_cmdhacks();

                if (scanf("%d", &submenu) != 1)
                {
                    Limpa_buffer();
                    printf("Opção inválida! Digite apenas números.\n");
                    printf("Pressione Enter para continuar...\n");
                    submenu = -1;
                    continue;
                }

                switch (submenu)
                {

                case 1:
                    printf("Você escolheu Sfc /scannow\n");
                    system("sfc /scannow");
                    break;

                default:
                    printf("Opção inválida\n");
                    break;
                }

                if (submenu != 0)
                {
                    printf("Pressione Enter para continuar...\n");
                    Limpa_buffer();
                    getchar();
                }
            } while (submenu != 0);
            break;

        case 0:
            printf("Saindo do programa...\n");
            break;

        default:
            printf("Opção inválida\n");
            printf("Pressione Enter para continuar...\n");
            Limpa_buffer();
            getchar();
            break;
        }

    } while (opcao != 0);

    system("color f");
    system(LIMPAR_TELA);
    printf("Obrigado por usar o Menu Interativo!\n");
    printf("Pressione Enter para sair...\n");
    Limpa_buffer();
    getchar();
    system(LIMPAR_TELA);
    return 0;
}
