#include <iostream>
#include <stdio.h>  
int main()
{
	setlocale(LC_ALL, "");
	using namespace std;
	FILE *outf;
	FILE *inf;
	fopen_s(&outf, "out.txt", "r");
	fopen_s(&inf,"in.txt", "w");
	if (!outf || !inf)
	{	
		printf("������ �������� �����\n");
		return 1;
	}	
    int numColumns;
    fscanf_s(outf, "%d", &numColumns);
    double num;
    int nowColumn = 1;
    int k;
    printf("������� ����� ������� k:");
    cin >> k;

    if (k <= 0 || k > numColumns) {
        printf("�������� ����� ��������:");
        return 1;
    }

    while (fscanf_s(outf, "%lf", &num) == 1)
    {
        if (nowColumn == k) 
        {
            fprintf(inf, "%lf\n", num);
        }
        nowColumn = (nowColumn % numColumns) + 1;
    }
    printf("������ ����������, ��������� ����");

    fclose(outf);
    fclose(inf);

    return 0;
}

