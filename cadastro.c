
#include <stdio.h>
#include <stdlib.h>

#define max 20 // definido um cadastro de 20 clientes

int fim = 0;

typedef struct Data tipoData;

typedef struct Disciplina tipoDisc;

struct Data {
    int dia;
    int mes;
    int ano;
};

struct Disciplina{
    char disciplina[50];
    char professor[50];
    float notas[3];
    float media[3];
};

struct Aluno{
    int matricula;
    char aluno[50];
    char endereco[70];
    tipoData Data;
    tipoDisc Disc;
    
};
//Protótipos de funções
int Cadastro[max];

int menu(void); 
int verificaLista(void);
void inicia(void); 
void exibir(void);
int Cadastrar(void);



int main(void)
{
    Cadastrar();
    exibir();
    system("pause");
    return 0;
}

int menu(void) {
    
    char opc[50];
    int opcao;
    
    fflush(stdin);
    printf("\n(1) - Cadastrar aluno\n");
    printf("\n(2) - Listar todos os alunos\n");
    printf("\n(3) - Listar alunos Aprovados\n");
    printf("\n(4) - Buscar os alunos por nome\n");
    printf("\n(5) - Buscar os alunos por disciplina\n");
    printf("\n(6) - Alterar aluno\n");
    printf("\n(7) - Excluir aluno\n");
    printf("\n(8) - Sair\n");
    
    do {
        printf("\n> ");
        fflush(stdout);
        gets(opc);

        opcao = atoi(opc);        
        
    }while(opcao < 0 || opcao > 8);
    return opcao;
    
}

void inicia(void){
    register int i;
    for (i = 0; i < max; ++i) Cadastro[i].aluno[0] = '\0';
}

 Cadastrar(void) {
    
    int Cad = 0;
    float soma = 0;
    float media = 0; 
    
    Cad = verificaLista();//Cad recebe a função verifica lista

    fflush(stdin);
    printf("\nDigite a matricula do aluno: ");
    fflush(stdout);
    scanf("%d", &Cadastro[Cad].matricula);

    fflush(stdin);
    printf("\nDigite o nome do aluno: ");
    fflush(stdout);
    gets(Cadastro[Cad].aluno);

    fflush(stdin);
    printf("\nDigite o endereco do aluno: ");
    fflush(stdout);
    gets(Cadastro[Cad].endereco);
    
    fflush(stdin);
    printf("\nDigite a data de nascimento do aluno: (dd mm aaaa) :");
    fflush(stdout);
    scanf("%d %d %d",&Cadastro[Cad].Data.dia, &Cadastro[Cad].Data.mes, &Cadastro[Cad].Data.ano);
    
    fflush(stdin);
    printf("\nDisciplina: ");
    fflush(stdout);
    gets(Cadastro[Cad].Disc.disciplina);
    
    fflush(stdin);
    printf("\nProfessor: ");
    fflush(stdout);
    gets(Cadastro[Cad].Disc.professor);
    
    fflush(stdin);
    printf("\nDigite as 3 notas dos alunos: ");
    fflush(stdout);
    scanf("%f %f %f", &Cadastro[Cad].Disc.notas[0], &Cadastro[Cad].Disc.notas[1],&Cadastro[Cad].Disc.notas[2]);
    
    soma = Cadastro[Cad].Disc.notas[0] + Cadastro[Cad].Disc.notas[1] + Cadastro[Cad].Disc.notas[2];   
    
    
    Cadastro[Cad].Disc.media[0] = soma/3;
    
    fim++; //toda vez que efetuar cadastro a varável fim será incrementada
    
}

verificaLista(void) {
    register int t;
    for (t = 0; t < Cadastro[t].aluno[0] && t < max; t++);
        if (t == max) return -1;
    return t;
}
void exibir(void){
    
    int i;
    
    if (fim == 0){
        printf("\nNão existe nunhum cadastro no momento!");
        return;
    }else{
        for (i = 0; i < fim; i++){
            printf("\nMatricula : %d", Cadastro[i].matricula);
            printf("\nNome: %s", Cadastro[i].aluno);
            printf("\nEndereco: %s", Cadastro[i].endereco);
            printf("\nData de Nascimento: %d %d %d", Cadastro[i].Data.dia, Cadastro[i].Data.mes, Cadastro[i].Data.ano);
            printf("\nDisciplina: %s", Cadastro[i].Disc.disciplina);
            printf("\nProfessor: %s", Cadastro[i].Disc.professor);
            printf("\nNotas: %.1f %.1f %.1f",Cadastro[i].Disc.notas[0], Cadastro[i].Disc.notas[1], Cadastro[i].Disc.notas[2]);
            printf("\nEndereco de exclusao e alteracao: %d\n", i);
            
        }
        printf("\nTotal de alunos cadastrados -> %d\n"), fim;
    }
    
}

