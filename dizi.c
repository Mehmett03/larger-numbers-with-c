#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

void topla(char s1[MAX], char s2[MAX])
{
    // TOPLAMA
    int num1[255], num2[255], sum[255];

    int l1, l2;
    int i;
    /* convert character to integer*/

    for (l1 = 0; s1[l1] != '\0'; l1++)
        num1[l1] = s1[l1] - '0';

    for (l2 = 0; s2[l2] != '\0'; l2++)
        num2[l2] = s2[l2] - '0';

    int carry = 0;
    int k = 0;

    i = l1 - 1;
    int j;
    j = l2 - 1;
    for (; i >= 0 && j >= 0; i--, j--, k++)
    {
        sum[k] = (num1[i] + num2[j] + carry) % 10;
        carry = (num1[i] + num2[j] + carry) / 10;
    }
    if (l1 > l2)
    {

        while (i >= 0)
        {
            sum[k++] = (num1[i] + carry) % 10;
            carry = (num1[i--] + carry) / 10;
        }
    }
    else if (l1 < l2)
    {
        while (j >= 0)
        {
            sum[k++] = (num2[j] + carry) % 10;
            carry = (num2[j--] + carry) / 10;
        }
    }
    else
    {
        if (carry > 0)
            sum[k++] = carry;
    }

    if (strlen(s1) > strlen(s2))
    {
        printf("%s\n", s1);
        for (i = 0; i < strlen(s1) - strlen(s2); i++)
        {
            printf(" ");
        }
        printf("%s\n", s2);
    }
    else
    {

        for (i = 0; i < strlen(s2) - strlen(s1); i++)
        {
            printf(" ");
        }

        printf("%s\n", s1);
        printf("%s\n", s2);
    }
    printf("+_______\n");

    for (k--; k >= 0; k--)
        printf(" %d", sum[k]);
}
//ÇARPMA
void carp(char s1[MAX], char s2[MAX])
{
    int a[100], b[100];
    int ans[200] = {0};
    int i, j, tmp;

    int l1 = strlen(s1);
    int l2 = strlen(s2);
    for (i = l1 - 1, j = 0; i >= 0; i--, j++)
    {
        a[j] = s1[i] - '0';
    }
    for (i = l2 - 1, j = 0; i >= 0; i--, j++)
    {
        b[j] = s2[i] - '0';
    }
    for (i = 0; i < l2; i++)
    {
        for (j = 0; j < l1; j++)
        {
            ans[i + j] += b[i] * a[j];
        }
    }
    for (i = 0; i < l1 + l2; i++)
    {
        tmp = ans[i] / 10;
        ans[i] = ans[i] % 10;
        ans[i + 1] = ans[i + 1] + tmp;
    }
    for (i = l1 + l2; i >= 0; i--)
    {
        if (ans[i] > 0)
            break;
    }

    if (l1 > l2)
    {
        printf("%s\n", s1);
        for (j = 0; j < l1 - l2; j++)
        {
            printf(" ");
        }
        printf("%s\n", s2);
    }
    else
    {

        for (j = 0; j < l2 - l1; j++)
        {
            printf(" ");
        }

        printf("%s\n", s1);
        printf("%s\n", s2);
    }
    printf("*_______\n");
    // printf("\nsonuc:\t");
    for (; i >= 0; i--)
    {
        printf(" %d", ans[i]);
    }

    //ÇIKARMA
}

int cik(char s1[MAX], char s2[MAX])
{

    int i, j;

    int num1[205] = {0}, num2[205] = {0};

    int n = strlen(s1);
    int x = strlen(s2);

    for (i = 0; i < n; i++)
    {
        num1[i] = s1[n - i - 1] - '0';
    }
    for (i = 0; i < x; i++)
    {
        num2[i] = s2[x - i - 1] - '0';
    }
    int k;
    if (n > x)
    {
        k = n;
    }
    else
    {
        k = x;
    }

    if (strlen(s1) > strlen(s2))
    {
        printf("%s\n", s1);
        for (i = 0; i < strlen(s1) - strlen(s2); i++)
        {
            printf(" ");
        }
        printf("%s\n", s2);

        for (i = 0; i < k; i++)
        { // Mainly in this part
            num1[i] -= num2[i];
            if (num1[i] < 0)
            {
                num1[i + 1]--;
                num1[i] += 10;
            }
        }
        printf("-_______\n");
        i = k;
        while (num1[i] == 0)
            i--;
        if (i < 0)
            printf("0");
        for (; i >= 0; i--)
        {
            printf(" %d", num1[i]);
        }
    }
    else if (strlen(s1) < strlen(s2))
    {
        for (i = 0; i < strlen(s1) - strlen(s2); i++)
        {
            printf(" ");
        }

        printf("%s\n", s1);
        printf("%s\n", s2);
        if (num1[k - i] < num2[k - i])
        {
            for (i = 0; i < k; i++)
            {
                num2[i] -= num1[i];
                if (num2[i] < 0)
                {
                    num2[i + 1]--;
                    num2[i] += 10;
                }
            }

            i = k;
            while (num2[i] == 0)
                i--;
            if (i < 0)
            {
                printf("0");
            }
            printf("-_______");
            printf("\nsonuc:");

            for (; i >= 0; i--)
            {
                printf(" %d", num2[i]);
            }
        }
    }

    else if (strlen(s1) == strlen(s2))
    {
        i = 1;
        while (i <= k)
        {
            if (num1[k - i] < num2[k - i])
            {
                for (j = 0; j < k; j++)
                {
                    num2[j] -= num1[j];
                    if (num2[j] < 0)
                    {
                        num2[j + 1]--;
                        num2[j] += 10;
                    }
                }
                printf("%s\n", s1);
                printf("%s\n", s2);
                printf("-_______\n");

                j = k;
                while (num2[j] == 0)
                    j--;
                if (j < 0)
                    printf("0");
                for (; j >= 0; j--)
                {
                    printf(" %d", num2[j]);
                }
                return 0;
            }
            else if (num1[k - i] > num2[k - i])

            {
                for (j = 0; j < k; j++)
                {
                    num1[j] -= num2[j];
                    if (num1[j] < 0)
                    {
                        num1[j + 1]--;
                        num1[j] += 10;
                    }
                }
                printf("%s\n", s1);
                printf("%s\n", s2);
                printf("-_______\n");
                j = k;
                while (num1[j] == 0)
                    j--;
                if (j < 0)
                    printf("0");
                for (; j >= 0; j--)
                {
                    printf(" %d", num1[j]);
                }
                return 0;
            }

            i++;
        }

        for (i = 0; i < k; i++)
        {
            num1[i] -= num2[i];
            if (num1[i] < 0)
            {
                num1[i + 1]--;
                num1[i] += 10;
            }
        }
        printf("%s\n", s1);
        printf("%s\n", s2);
        printf("-_______\n");
        i = k;
        while (num1[i] == 0)
            i--;
        if (i < 0)
            printf("0");
        for (; i >= 0; i--)
        {
            printf(" %d", num1[i]);
        }
    }
}

int main()
{
    int secim;
    int i;

    char s1[MAX], s2[MAX];
    printf(" 1- topla\n 2- carpma\n 3- cikarma\n");
    printf("islem secin: ");
    scanf("%d", &secim);

    if (secim == 1)
    {
        printf("sayi 1'i giriniz: ");
        scanf("%s", &s1);
        for (i = 0; i < strlen(s1); i++)

        {
            if (48 > s1[i] || s1[i] > 58)
            {
                printf("yalnizca rakam girebilirsiniz!");
                return 0;
            }
        }

        printf("sayi 2'yi giriniz: ");
        scanf("%s", &s2);
        for (i = 0; i < strlen(s1); i++)

        {
            if (48 > s1[i] || s1[i] > 58)
            {
                printf("yalnýzca rakam girebilirsiniz!");
                return 0;
            }
        }

        topla(s1, s2);
    }
    else if (secim == 2)
    {
        printf("sayi 1'i giriniz: ");
        scanf("%s", &s1);
        for (i = 0; i < strlen(s1); i++)

        {
            if (48 > s1[i] || s1[i] > 58)
            {
                printf("yalnizca rakam girebilirsiniz!");
                return 0;
            }
        }

        printf("sayi 2'yi giriniz: ");
        scanf("%s", &s2);
        for (i = 0; i < strlen(s1); i++)

        {
            if (48 > s1[i] || s1[i] > 58)
            {
                printf("yalnýzca rakam girebilirsiniz!");
                return 0;
            }
        }
        carp(s1, s2);
    }
    else if (secim == 3)
    {
        printf("sayi 1'i giriniz: ");
        scanf("%s", &s1);
        for (i = 0; i < strlen(s1); i++)

        {
            if (48 > s1[i] || s1[i] > 58)
            {
                printf("yalnizca rakam girebilirsiniz!");
                return 0;
            }
        }

        printf("sayi 2'yi giriniz: ");
        scanf("%s", &s2);
        for (i = 0; i < strlen(s1); i++)

        {
            if (48 > s1[i] || s1[i] > 58)
            {
                printf("yalnýzca rakam girebilirsiniz!");
                return 0;
            }
        }
        cik(s1, s2);
    }
    else
    {
        printf("hatali islem sectiniz!");
        return 0;
    }
}

