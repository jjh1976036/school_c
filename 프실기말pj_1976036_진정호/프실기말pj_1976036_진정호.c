#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>



#define ROWSIZE 30  // ���� �� ũ��
#define COLSIZE 30

int score(const char *a[ROWSIZE][COLSIZE], int type);  // ���� ��� �Լ�

int main()
{
     FILE* fpR1, * fpR2, * fpW;  // ���� ������ ����
     int a, b, x, t;  // ��ǥ �� �޴� �Է� ����, ���ڿ� �ٲ� ���� ��ġ ����
     int y, ch;  // �׸� ���� ���ϱ� ���� ����, ���� ���� ����� ���� ����
     char string[600];  // ������ ����

     char draw[ROWSIZE][COLSIZE] = { "         | | | | | | | | | | \n",  // ������
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

     do {  // �޴� ����
          puts("�޴� : �׸� ���� �ҷ����� (1), ����� (2), �����ϱ�(3), ����(4)");
          puts("�׸� ��(5), ���� ��(6)�� �����ϼ���:");
          scanf("%d", &x);
          switch (x) {
          case 1:  // �׸� ���� �ҷ�����
               printf("������ �����ϼ���(1, 2)");
               scanf("%d", &y);
               if (y == 1) {
                    fpR1 = fopen("c:\\temp\\nonogram1.txt", "r");
                    if (fpR1 == NULL)
                    {
                         puts("������ �ҷ��� �� �����ϴ�.");
                    }
                    else
                    {
                         while ((ch = fgetc(fpR1)) != EOF)
                         {
                              putchar(ch);   // ���� ���� ���
                         }
                         printf("\n");
                         fclose(fpR1);
                    }
               }
               else if (y == 2) {
                    fpR2 = fopen("c:\\temp\\nonogram2.txt", "r");
                    if (fpR2 == NULL)
                    {
                         puts("������ �ҷ��� �� �����ϴ�.");
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
               system("cls");   // �ʱ�ȭ �Լ�
               puts(draw);
               break;

          case 3:  // ���� �����ϱ�
               fpW = fopen("c:\\temp\\nonogram1.txt", "w+"); // ���� Ÿ������ ����
               if (fpW == NULL) {
                    puts("���� ���� �Ұ���");
               }
               else {
                    puts("�ٲٰ� ���� ��ġ�� �Է��ϼ���:");
                    scanf("%d", &t);
                    fsetpos(fpW, &t);  // ���� ������ ��ġ ����

                    puts("�ٲٰ� ���� ������ �Է��ϼ���:");
                    gets(string);
                    fputs(string, fpW);  // ���� �Է�

                    fflush(fpW);  // �׿� �κ� ����
                    fclose(fpW);
               }
          case 4:  // �����ϱ�
               puts("�����մϴ�.");
               return 1;
               break;

          case 5:  // �Է� ��ǥ 1
               puts("��ǥ�� �Է��ϼ���: ");
               scanf("%d %d", &a, &b);
               draw[a][b] = '��';
               for (int i = 0; i < ROWSIZE; i++) {
                    for (int j = 0; j < COLSIZE; j++) {
                         printf("%c", draw[i][j]);
                    }
               }

               break;

          case 6:  // �Է� ��ǥ 2
               puts("��ǥ�� �Է��ϼ���: ");
               scanf("%d %d", &a, &b);
               draw[a][b] = '��';
               for (int i = 0; i < ROWSIZE; i++) {
                    for (int j = 0; j < COLSIZE; j++) {
                         printf("%c", draw[i][j]);
                    }
               }
               break;

          default:
               puts("��ȣ�� �߸� �ԷµǾ����ϴ�.");
          }

     } while (1);

     printf("\n������ -%d�Դϴ�.", score(draw, y));
}

int score(const char *a[ROWSIZE][COLSIZE], int type) {  // ���� ���� �Լ�
     int ret = 0;
     if (type == 1) {
          FILE* f = fopen("c:\\temp\\nonogram1.txt", "r");
          ret = strncmp(a, f, 600);  // ���� ��
     }
     else if (type == 2) {
          FILE* f = fopen("c:\\temp\\nonogram2.txt", "r");
          ret = strncmp(a, f, 600);
     }

     return ret;
}
