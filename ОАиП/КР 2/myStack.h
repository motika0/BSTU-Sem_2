struct Stack
{
	char data;     //�������������� �������
	Stack* next;	 //��������� �� ��������� �������
};
void show(Stack*& myStk);
void push(char x, Stack*& myStk);
void toFile(Stack*& myStk);
