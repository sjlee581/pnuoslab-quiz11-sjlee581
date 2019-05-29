
#include <stdio.h>
#include <string.h>
#define MAX 50
char PASSWORD[20] = { 'q', 'w', 'e', 'r', '1', '2', '3' , '4' };
char entered_pw[20];
int size = 0;
char search[20];
int whileCondition = 1; //while�� ���������� ���� ����
int selection;
void pi_register();
void persoanlprint();
void allprint();
void deletePI();
void swap(struct phoneBook* _PI);
struct phoneBook
{
	char phoneNum[20];
	char name[20];
}PI[MAX];			//���������� ũ�Ⱑ 50�� phonebook����ü �迭�� ����

int main()
{

	while (whileCondition)      //1,2,3 ���� �� �۾� ������ ��� ���� �� �� �ֵ��� whlie�� �ȿ� ����
	{
		printf("��ȭ��ȣ ����\n\n");
		printf("1.���   2.��ü�˻�  3.Ư���ΰ˻� 4. ����  5.���� \n\n");
		printf("�޴� ����: ");
		scanf("%d", &selection);
		printf("\n");
		switch (selection)
		{
		case 1:
			pi_register();
			break;
		case 2:
			allprint();
			break;
		case 3:
			persoanlprint();
			break;
		case 4:
			deletePI();
			break;
		case 5:
			printf("���α׷��� �����մϴ�. \n");
			whileCondition = 0;           //�����Ҷ��� while�� ������������ ���ǰ˻� ���� 0���� ����
			break;
		default:
			printf("1~5������ ���� �Է��ϼ���. \n");
			break;
		}
	}
	system("pause");
}

void pi_register()    //����������� �Լ��� ����
{

	printf("��й�ȣ �Է�: ");
	scanf("%s", entered_pw);
	while (1)
	{
		static int pwWrongCounter;    //��й�ȣ ���� Ƚ���� ���� ���� ������ �޸𸮻� ������ �� �ֵ��� static����, 0���� �ʱ�ȭ
		if ((strcmp(entered_pw, PASSWORD) == 0))
		{

			printf("����� �̸�: ");
			scanf("%s", (*(PI + size)).name);		//�������� ������ ��� ����ü �����͸� �̿��� ����, �ؿ����� []�����ڷ� ��ü
			printf("��ȭ��ȣ: ");
			scanf("%s", PI[size].phoneNum);
			printf("%s ���� ��� �Ϸ�!\n\n", PI[size].name);
			size++;
			break;
		}
		else if (pwWrongCounter < 2)
		{
			pwWrongCounter++;
			printf("��й�ȣ(%dȸ����): ", pwWrongCounter);
			scanf("%s", entered_pw);
			continue;
		}
		else
			pwWrongCounter++;
		printf("��й�ȣ(%dȸ����): ����� �� ����! \n", pwWrongCounter);
		printf("���α׷��� �����մϴ�. \n");
		whileCondition = 0;
		break;
	}
}

void persoanlprint()
{
	printf("�˻��� �̸�: ");
	scanf("%s", search);
	for (int i = 0; i < size; i++)
	{
		if ((strcmp(PI[i].name, search) == 0))
		{
			printf("\n%s   ", PI[i].name);
			printf("%s\n\n", PI[i].phoneNum);
		}
	}
}

void allprint()
{
	printf("  << ��ȭ��ȣ��� >>\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s   ", PI[i].name);
		printf("%s\n", PI[i].phoneNum);
	}
	printf("\n");
}

void deletePI()
{
	printf("������ �̸�: ");
	scanf("%s", search);
	for (int i = 0; i < size; i++)
	{
		if ((strcmp(PI[i].name, search) == 0))
		{
			for (i; i < size - 1; i++)
			{
				swap(&PI[i]);
			}
			printf("\n%s ���� ���� �Ϸ�!\n", PI[i].name);		//��ü�˻��� ������ �ʰ� ��Ͻ� ��������Ƿ� ������ ���� ���� �ʰ� ��������.
			size--;
		}
	}
}

//4�� ���ű�� �����ϱ����� swap�Լ� ����
void swap(struct phoneBook* _PI)
{
	struct phoneBook tmp = *(_PI);
	*(_PI) = *(_PI + 1);
	*(_PI + 1) = tmp;
}