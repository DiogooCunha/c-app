#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

#include "contact.h"
#include "agenda.h"

int main() {
    Agenda* agenda = create_agenda();
    int option = 0;
    char nome[100];
    char numero[20];

    while (option != 5) {
        printf("----------------------------------\n");
        printf("[1] Incluir contato\n");
        printf("[2] Listar contatos\n");
        printf("[3] Consultar contato pelo nome\n");
        printf("[4] Excluir contato\n");
        printf("[5] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%i", &option);
        printf("----------------------------------\n");

        switch (option)
        {
        case 1:
            printf("Nome do novo contato:\n");
            scanf("%100s", nome);
            printf("Número do novo contato:\n");
            scanf("%20s", numero);
            
            Contact* contato = create_contact(nome, numero);
            add_contact(agenda, contato);

            printf("Usuário criado com sucesso.\n");
            sleep(1);
            break;
        case 2:
            list_contacts(agenda);
            sleep(1);
            break;
        case 3:
            printf("Nome do contato:\n");
            scanf("%100s", nome);

            list_contact_by_name(agenda, nome);
            sleep(1);
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Opção inválida\n");
            break;
        }
    }
    

    return 0;
}