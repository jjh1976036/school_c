#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>



#define ROWSIZE 30  // 게임 판 크기
#define COLSIZE 30

int score(const char *a[ROWSIZE][COLSIZE], int type);  // 점수 계산 함수

int main()
{
     FILE* fpR1, * fpR2, * fpW;  // 파일 포인터 변수
     int a, b, x, t;  // 좌표 및 메뉴 입력 정수, 문자열 바꿀 파일 위치 정수
     int y, ch;  // 그림 파일 정하기 위한 정수, 파일 내용 출력을 위한 정수
     char string[600];  // 수정할 내용

     char draw[ROWSIZE][COLSIZE] = { "         | | | | | | | | | | \n",  // 게임판
         "| | | | | | | | | | \n",
         "| | | | | | | | | | \n",
         "| | | | | | | | | | \n",
         "| | | | | | | | | | \n",
         "| | | | | | | | | | \n",
         "| | | | | | | | | | \n",
         "| | | | | | | | | | \n",
         "| | | | | | | | | | \n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
         "________|_|_|_|_|_|_|_|_|_|_|\n",
     };  

     do {  // 메뉴 루프
          puts("메뉴 : 그림 파일 불러오기 (1), 재시작 (2), 수정하기(3), 종료(4)");
          puts("그릴 지(5), 지울 지(6)를 선택하세요:");
          scanf("%d", &x);
          switch (x) {
          case 1:  // 그림 파일 불러오기
               printf("파일을 선택하세요(1, 2)");
               scanf("%d", &y);
               if (y == 1) {
                    fpR1 = fopen("c:\\temp\\nonogram1.txt", "r");
                    if (fpR1 == NULL)
                    {
                         puts("파일을 불러올 수 없습니다.");
                    }
                    else
                    {
                         while ((ch = fgetc(fpR1)) != EOF)
                         {
                              putchar(ch);   // 파일 내용 출력
                         }
                         printf("\n");
                         fclose(fpR1);
                    }
               }
               else if (y == 2) {
                    fpR2 = fopen("c:\\temp\\nonogram2.txt", "r");
                    if (fpR2 == NULL)
                    {
                         puts("파일을 불러올 수 없습니다.");
                    }
                    else
                    {
                         while ((ch = fgetc(fpR2)) != EOF)
                         {
                              putchar(ch);
                         }
                         printf("\n");
                         fclose(fpR2);
                    }
               }
               break;

          case 2:
               system("cls");   // 초기화 함수
               puts(draw);
               break;

          case 3:  // 내용 수정하기
               fpW = fopen("c:\\temp\\nonogram1.txt", "w+"); // 쓰기 타입으로 설정
               if (fpW == NULL) {
                    puts("파일 생성 불가능");
               }
               else {
                    puts("바꾸고 싶은 위치를 입력하세요:");
                    scanf("%d", &t);
                    fsetpos(fpW, &t);  // 파일 포인터 위치 변경

                    puts("바꾸고 싶은 내용을 입력하세요:");
                    gets(string);
                    fputs(string, fpW);  // 내용 입력

                    fflush(fpW);  // 잉여 부분 삭제
                    fclose(fpW);
               }
          case 4:  // 종료하기
               puts("종료합니다.");
               return 1;
               break;

          case 5:  // 입력 좌표 1
               puts("좌표를 입력하세요: ");
               scanf("%d %d", &a, &b);
               draw[a][b] = '■';
               for (int i = 0; i < ROWSIZE; i++) {
                    for (int j = 0; j < COLSIZE; j++) {
                         printf("%c", draw[i][j]);
                    }
               }

               break;

          case 6:  // 입력 좌표 2
               puts("좌표를 입력하세요: ");
               scanf("%d %d", &a, &b);
               draw[a][b] = '□';
               for (int i = 0; i < ROWSIZE; i++) {
                    for (int j = 0; j < COLSIZE; j++) {
                         printf("%c", draw[i][j]);
                    }
               }
               break;

          default:
               puts("번호가 잘못 입력되었습니다.");
          }

     } while (1);

     printf("\n점수는 -%d입니다.", score(draw, y));
}

int score(const char *a[ROWSIZE][COLSIZE], int type) {  // 점수 세기 함수
     int ret = 0;
     if (type == 1) {
          FILE* f = fopen("c:\\temp\\nonogram1.txt", "r");
          ret = strncmp(a, f, 600);  // 내용 비교
     }
     else if (type == 2) {
          FILE* f = fopen("c:\\temp\\nonogram2.txt", "r");
          ret = strncmp(a, f, 600);
     }

     return ret;
}
