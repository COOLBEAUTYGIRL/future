#include <stdio.h>
#include <time.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main(void)
{
    // 문이 각 5개 씩 있고 각 문마다 점점 어려워지는 수식퀴즈.
    srand(time(NULL));
    int count = 0;
    for (int i = 0; i <= 5; i++)
    {
        int num1 = getRandomNumber(i);
        int num2 = getRandomNumber(i);
        showQuestion(i, num1, num2);

        int answer = -1;
        scanf_s("%d", &answer);
        if(answer == -1)
        {
            printf("프로그램을 종료합니다.\n");
            exit(0);
        }
        else if (answer == num1 * num2)
        {
            success();
            count++;
        }
        else 
        {
            fail();
        }

    }
    printf("당신은 %d 개의 문제를 맞혔습니다.", count);
    
    return 0;
}

int getRandomNumber(int level)
{
    return srand() % (level * 7) + 1;
}

void showQuestion(int level, int num1, int num2)
{
    printf("\n\n\n########### %d 번째 비밀번호 ##########\n", level);
    printf("\n\t%d x %d 는? \n\n", num1, num2);
    printf("#############################################\n");
    printf("\n 비밀번호를 입력하세요 (종료버튼은 -1) >> ");
}

void success()
{
    printf("\n >> 축하합니다! 성공하셨습니다!");
}
void fail()
{
    printf("\n >> 실패했다 븅신아 ㅋㅋ");
}