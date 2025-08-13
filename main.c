#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <direct.h>

#ifdef _WIN32
#define LIMPAR_TELA "cls"
#else
#define LIMPAR_TELA "clear"
#endif


void Limpa_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void limparTela() {
    system(LIMPAR_TELA);
}

void pausar() {
    printf("Pressione Enter para continuar...\n");
    Limpa_buffer();
    getchar();
}

int lerOpcao() {
    int opcao;
    if (scanf("%d", &opcao) != 1) {
        Limpa_buffer();
        printf("Opção inválida! Digite apenas números.\n");
        pausar();
        return -1;
    }
    return opcao;
}

void DesenhoLogo() {
    printf("        ___          __________                                \n");
    printf("       / _ \\         | _______\\                             \n");
    printf("      / / \\ \\        | |       \\ \\                         \n");
    printf("     / /   \\ \\       | |        \\ \\                        \n");
    printf("    / /     \\ \\      | |________/ /                          \n");
    printf("   / /_______\\ \\     | |_________/                           \n");
    printf("  / /_________\\ \\    | |                                     \n");
    printf(" / /           \\ \\   | |                                     \n");
    printf("/_/             \\_\\  |_|                                     \n");
}

void AvisoInicial() {
    printf("##########################################################################################################\n");
    printf("   ATENÇÃO: Execute este programa como Administrador para funcionamento ideal.                           \n");
    printf("\n");
    printf("   AVISO: Alguns programas podem ser detectados como vírus por antivírus. Trata-se de falso positivo.    \n");
    printf("##########################################################################################################\n");
    pausar();
}

int MenuPrincipal() {
    printf("========================== MENU PRINCIPAL ===========================\n");
    printf("1 - Recuperação\n");
    printf("2 - CMD Hacks\n");
    printf("0 - Sair\n");
    printf("Escolha uma opção: ");
    return lerOpcao();
}

int MenuRecuperacao() {
    printf("=========================== MENU DE RECUPERAÇÃO ===========================\n");
    printf("1 - fileRecovery - Recupera arquivos apagados\n");
    printf("2 - PartRecovery - Recupera partições apagadas\n");
    printf("3 - EasyfileRecovery - Layout mais amigável\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
    return lerOpcao();
}

int MenuCmdHacks() {
    printf("=========================== MENU DE HACKS DE CMD ===========================\n");
    printf("1 - Sfc /scannow - Verifica e repara arquivos do Windows\n");
    printf("0 - Voltar ao menu principal\n");
    printf("Escolha uma opção: ");
    return lerOpcao();
}

void executarPrograma(const char *dir, const char *exe) {
    if (_chdir(dir) != 0) {
        perror("Erro ao mudar para o diretório do programa");
        return;
    }
    if (system(exe) != 0) {
        printf("Falha ao executar: %s\n", exe);
    }
    _chdir("..\\..");
    pausar();
}


void logicaMenuRecuperacao() {
    int opcao;
    do {
        limparTela();
        opcao = MenuRecuperacao();
        switch (opcao) {
            case 1:
                executarPrograma("MenuC\\softwares\\Recuperação", "FileRecovery.exe");
                break;
            case 2:
                executarPrograma("MenuC\\softwares\\Recuperação", "PartRecovery.exe");
                break;
            case 3:
                executarPrograma("MenuC\\softwares\\Recuperação", "EasyFileRecovery.exe");
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}

void logicaMenuCmdHacks() {
    int opcao;
    do {
        limparTela();
        opcao = MenuCmdHacks();
        switch (opcao) {
            case 1:
                printf("Executando: sfc /scannow\n");
                system("sfc /scannow");
                pausar();
                break;
            case 0:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida\n");
                pausar();
                break;
        }
    } while (opcao != 0);
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("color 02");

    limparTela();
    DesenhoLogo();
    AvisoInicial();

    int opcao;
    do {
        limparTela();
        opcao = MenuPrincipal();
        switch (opcao) {
            case 1:
                logicaMenuRecuperacao();
                break;
            case 2:
                logicaMenuCmdHacks();
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida\n");
                pausar();
                break;
        }
    } while (opcao != 0);

    system("color f");
    limparTela();
    printf("Obrigado por usar o Menu Interativo!\n");
    pausar();
    limparTela();
    return 0;
}
