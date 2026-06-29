#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include <string.h>

#include "contact.h"
#include "agenda.h"

void setColor(int cor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

int main() {
    Agenda* agenda = create_agenda();
    int option = 0;
    char nome[100];
    char numero[20];
    int index;

    while (option != 6) {
        system("cls");
        setColor(11);
        printf("----------------------------------\n");
        printf("[1] Incluir contato\n");
        printf("[2] Listar contatos\n");
        printf("[3] Consultar contato pelo nome\n");
        printf("[4] Exportar CSV\n");
        printf("[5] Excluir contato\n");
        printf("[6] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%i", &option);
        printf("----------------------------------\n");

        switch (option)
        {
        case 1:
            setColor(10);
            printf("Nome do novo contato:\n");
            scanf(" %[^\n]", nome);
            printf("Número do novo contato:\n");
            scanf("%20s", numero);
            
            Contact* contato = create_contact(nome, numero);
            add_contact(agenda, contato);

            printf("Usuário criado com sucesso.\n");
            Sleep(1000);
            break;
        case 2:
            setColor(14);
            list_contacts(agenda);
            Sleep(2000);
            break;
        case 3:
            setColor(14);
            printf("Nome do contato:\n");
            scanf("%100s", nome);

            list_contact_by_name(agenda, nome);
            Sleep(1000);
            break;
        case 4:
            setColor(10);
            export_to_csv(agenda);
            printf("Conteúdo exportado com sucesso!\n");
            Sleep(1000);
            break;
        case 5:
            setColor(12);
            printf("Digite o índice do contato que deseja excluir:\n");
            scanf("%i", &index);
            drop_contact(agenda, index);
            printf("Usuário excluido com sucesso\n");
            Sleep(1000);
            break;
        case 6:
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }
    
    destroy_agenda(agenda);
    setColor(7);

    return 0;
}