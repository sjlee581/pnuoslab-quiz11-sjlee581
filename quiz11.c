
#include <stdio.h>
#include <string.h>
#define MAX 50
char PASSWORD[20] = { 'q', 'w', 'e', 'r', '1', '2', '3' , '4' };
char entered_pw[20];
int size = 0;
char search[20];
int whileCondition = 1; //while문 빠져나가는 조건 변수
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
}PI[MAX];			//개인정보를 크기가 50인 phonebook구조체 배열로 선언

int main()
{

	while (whileCondition)      //1,2,3 선택 시 작업 끝나도 계속 실행 될 수 있도록 whlie문 안에 선언
	{
		printf("전화번호 관리\n\n");
		printf("1.등록   2.전체검색  3.특정인검색 4. 제거  5.종료 \n\n");
		printf("메뉴 선택: ");
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
			printf("프로그램을 종료합니다. \n");
			whileCondition = 0;           //종료할때는 while문 빠져나가도록 조건검사 변수 0으로 변경
			break;
		default:
			printf("1~5사이의 값을 입력하세요. \n");
			break;
		}
	}
	system("pause");
}

void pi_register()    //개인정보등록 함수로 구현
{

	printf("비밀번호 입력: ");
	scanf("%s", entered_pw);
	while (1)
	{
		static int pwWrongCounter;    //비밀번호 오류 횟수를 세기 위한 변수가 메모리상에 유지될 수 있도록 static선언, 0으로 초기화
		if ((strcmp(entered_pw, PASSWORD) == 0))
		{

			printf("등록할 이름: ");
			scanf("%s", (*(PI + size)).name);		//문제에서 제시한 대로 구조체 포인터를 이용한 참조, 밑에서는 []연산자로 대체
			printf("전화번호: ");
			scanf("%s", PI[size].phoneNum);
			printf("%s 정보 등록 완료!\n\n", PI[size].name);
			size++;
			break;
		}
		else if (pwWrongCounter < 2)
		{
			pwWrongCounter++;
			printf("비밀번호(%d회실패): ", pwWrongCounter);
			scanf("%s", entered_pw);
			continue;
		}
		else
			pwWrongCounter++;
		printf("비밀번호(%d회실패): 등록할 수 없음! \n", pwWrongCounter);
		printf("프로그램을 종료합니다. \n");
		whileCondition = 0;
		break;
	}
}

void persoanlprint()
{
	printf("검색할 이름: ");
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
	printf("  << 전화번호목록 >>\n");
	for (int i = 0; i < size; i++)
	{
		printf("%s   ", PI[i].name);
		printf("%s\n", PI[i].phoneNum);
	}
	printf("\n");
}

void deletePI()
{
	printf("삭제할 이름: ");
	scanf("%s", search);
	for (int i = 0; i < size; i++)
	{
		if ((strcmp(PI[i].name, search) == 0))
		{
			for (i; i < size - 1; i++)
			{
				swap(&PI[i]);
			}
			printf("\n%s 정보 삭제 완료!\n", PI[i].name);		//전체검색시 나오지 않고 등록시 덮어써지므로 실제로 제거 하지 않고도 구현가능.
			size--;
		}
	}
}

//4번 제거기능 구현하기위해 swap함수 정의
void swap(struct phoneBook* _PI)
{
	struct phoneBook tmp = *(_PI);
	*(_PI) = *(_PI + 1);
	*(_PI + 1) = tmp;
}