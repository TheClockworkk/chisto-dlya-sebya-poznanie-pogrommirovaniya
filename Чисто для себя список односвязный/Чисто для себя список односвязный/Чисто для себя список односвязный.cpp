#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

typedef struct Node
{
	int value;
	struct Node* next;
} Node;

Node* head = NULL; //это типа конец списка Null. Поэтому при создании нового узла мы поместим его до головы

void push(Node** head, int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = data;
	newNode->next = (*head);
	(*head) = newNode; // мы делаем головой новый узелочекк
}

//cначала идёт голова, потом тело и хвост в виде Null'a

int pop(Node** head) //удаление головы
{
	Node* prev = NULL;
	int val;
	if (head == NULL)
		exit(-1);
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
	return val;       
}

//после вот этих двух функций это типа список-стек

//указатель на указатель нужен, когда мы собираемся менять данные под ним. А вот если работаем с чем-то, чо менять не надо - юзаем просто указатель

Node* getLast(Node* head)
{
	if (head == NULL)
		return NULL;
	while (head->next)
		head = head->next;
	return head;
}

int getLastNum(Node* head)
{
	int count = 0;
	if (head == NULL)
		return NULL;
	while (head->next)
	{
		head = head->next;
		count++;
	}
	count++;
	return count;
}

Node* getAnyElement(Node* head, int n)
{
	int counter = 0;
	while(counter < n && head)
	{
		head = head->next;
		counter++;
	}
	return head;
}

void enqueue(Node* head, int value)//добавление эл-та в конец списка
{
	Node* last = getLast(head);
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	last->next = newNode;
}

//теперь это ещё и очередь

//если нам надо удалить последний элемент, то надо изменить указатель next предпоследнего элемента
//то есть нам нужжна функция, вохвращающая указатель на предпоследний эл-т йоу

Node* getSecondLast(Node* head)
{
	if (head == NULL)
		exit(-2);
	if (head->next == NULL)
		return NULL;

	while (head->next->next) //если после "головы" есть два элемента - двигаем голову. Как только после головы нет двух элементов - стопаемся
		head = head->next;
	return head;
}

void popBack(Node** head)//вот теперь удоляем последний элемент
{
	Node* lastbn = NULL; //lastbn - типа предпоследний эл-т
	if (!head)
		exit(-1);

	if (!(*head))
		exit(-1);

	lastbn = getSecondLast(*head);
	if (lastbn = NULL)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		free(lastbn->next);
		lastbn->next = NULL;
	}
}

void insert(Node* head, unsigned n, int val)// а теперь вставка нового значения в узел
{
	unsigned i = 0;
	Node* newNode = NULL;

	while (i < n && head->next)
	{
		head = head->next;
		i++;
	}

	newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;

	if (head->next)
		newNode->next = head->next;
	else
		newNode->next = NULL;

	head->next = newNode;
}

int deleteAnyElement(Node** head, int n)
{
	if (n == 0)
		return pop(head);
	else
	{
		Node* prev = getAnyElement(*head, n - 1); //получаем указател на элемент, стоящий до удаляемого
		Node* element = prev->next;//перекидываем ссылку на следующий элемент, т.е. удаляемый
		int val = element->value;

		prev->next = element->next;
		free(element);
		return val;
	}
}

void deleteList(Node** head)
{
	Node* prev = NULL;
	while ((*head)->next)
	{
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

void fromArray(Node** head, int* arr, size_t size)
{
	size_t i = size - 1;
	if (arr == NULL || size == 0)
		return;

	do
		push(head, arr[i]);
	while (i-- != 0);
}

int* toArray(Node* head)
{
	int leng = getLastNum(head);
	int* values = (int*)malloc(leng * sizeof(int));
	while (head)
	{
		values[--leng] = head->value;
		head = head->next;
	}
	return values;
}

void printfList(const Node* head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}


int main()	
{
	Node* head = NULL;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	fromArray(&head, arr, 10);
	printfList(head);

	insert(head, 4, 333);
	printfList(head);

	enqueue(head, 11);
	enqueue(head, 1765);
	printfList(head);

	printf("\n%d\n\n", pop(&head));
	
	deleteAnyElement(&head, 2);
	printfList(head);
	deleteList(&head);
}