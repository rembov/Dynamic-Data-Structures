#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <Windows.h>
typedef struct Data {
	int number;
	char Name[40];
	struct Spec {
		int Speed;
		int Power;
	} info;
	int Volume;
	struct Data* nextNode;
}Dat;
struct Data* InputStruct() {
	struct Data* p = NULL;
	int k;
	int i = 0;
	printf("Введите '1' если хотите продолжить или '0' если нет: ");
	scanf("%d", &k);
	if (k == 1) {
		i++;
		p = (struct Data*)malloc(sizeof(struct Data));
		printf("Введите номер: ");
		scanf_s("%d", &p->number);

		printf("введите название: ");
		scanf("%s", &p->Name);

		printf("Введите макс.Скорость: ");
		scanf_s("%d", &p->info.Speed);

		printf("Введите мощность: ");
		scanf_s("%d", &p->info.Power);

		printf("Введите объём: ");
		scanf_s("%d", &p->Volume);
		p->nextNode = InputStruct();
		return p;
	}
	else
		return NULL;
}
void Up() {
	printf("|---------------+--------+---------------+---------------|\n");
	printf("| --Номер П/П---|Название|Характеристики-|---Объём ДВС---|\n");
	printf("|               |        |Скор.|Мощность |               |\n");

}
void Output(struct Data* p) {
	struct Data* p1 = p;

	if (p != NULL)
	{
		printf("|%-15d|%-8s|%-5d|%-9d|%-15d|\n", p1->number, p1->Name, p1->info.Speed, p1->info.Power, p1->Volume);
		Output(p->nextNode);
	}
	else
		printf("+---------------+--------+---------------+---------------+\n");
}
struct Data* Change(struct Data* p, struct Data* One, struct Data* last) {

	if (p->nextNode != NULL)
		return Change(p->nextNode, One, p);
	else {
		p->nextNode = One->nextNode;
		last->nextNode = One;
		One->nextNode = NULL;
		return p;
	}
}
int main(int i) {
	system("chcp 1251");
	system("cls");
	struct Data* p = NULL;
	p = InputStruct();
	Up();
	Output(p);
	printf("\n\n");
	p = Change(p, p, NULL);
	Up();
	Output(p);
	getchar();
	return 0;
}
