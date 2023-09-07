#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void input();
void jumlah();
void total();
void bulan();
void tahun();

int main()
{
    int pilihan;
    do
    {
    	printf("\n_________________________________________________________________________________\n");
        printf("================================= Selamat Datang ================================\n");
        printf("****************************** Silahkan Pilih Menu ******************************\n");
        printf("1. Input Pengeluaran\n");
        printf("2. Jumlah Pengeluaran\n");
        printf("3. Total Pengeluaran perorang\n");
        printf("4. Total Pengeluaran Perbulan\n");
        printf("5. Total Pengeluaran Pertahun\n");
        printf("6. Keluar\n");
        printf("_________________________________________________________________________________\n");
        printf("_________________________________________________________________________________\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
        	system("cls");
            input();
            getchar();
            break; 
        case 2:
        	system("cls");
            jumlah();
            getchar();
            break;
        case 3:
        	system("cls");
            total();
            getchar();
            break;
        case 4:
        	system("cls");
            bulan();
            getchar();
            break;
        case 5:
        	system("cls");
            tahun();
            getchar();
            break;
        case 6:
        	system("cls");
            printf("Terima Kasih\n");
            getchar();
            break;
        default:
            printf("Pilihan tidak tersedia\n");
            break;
        }
    } while (pilihan != 6);
    return 0;
}

//menu input (NO 1)
void input()
{
    FILE *fp;
    char nama[100], tanggal[100], bulan[100], pengeluaran[100], tahun[100];
    fp = fopen("Expense.txt", "a");
    printf("Nama : ");
    scanf("%s", nama);
    printf("Tanggal : ");
    scanf("%s", tanggal);
    printf("Bulan : ");
    scanf("%s", bulan);
    printf("Tahun : ");
    scanf("%s", tahun);
    printf("Pengeluaran : ");
    scanf("%s", pengeluaran);
    fprintf(fp, "%s %s %s %s %s\n", nama, tanggal, bulan,tahun, pengeluaran);
    fclose(fp);
}

//menu jumlah (NO 2)
void jumlah()
{
    FILE *fp;
    char nama[100], tanggal[50], bulan[50],tahun[4], pengeluaran[50];
    int total = 0;
    fp = fopen("expense.txt", "r");
    while (fscanf(fp, "%s %s %s %s %s", nama, tanggal, bulan, tahun, pengeluaran) != EOF)
    {
        total += atoi(pengeluaran);
    }
    printf("Jumlah pengeluaran Keseluruhan : %d\n", total);
    fclose(fp);
}

//menu total (NO 3)
void total()
{
    FILE *fp;
    char nama[100], tanggal[50], bulan[100], tahun[4], pengeluaran[50];
    char name[100];
    int total = 0;
    int total_pengeluaran = 0;
    printf("Nama  : ");
    scanf("%s", name);
    fp = fopen("Expense.txt", "r");
    while (fscanf(fp, "%s %s %s %s %s", nama, tanggal, bulan,tahun, pengeluaran) != EOF)
    {
        if (strcmp(nama, name) == 0)
        {
        	printf("\n___________________________\n");
            printf("\nNama\t\t: %s \nTanggal\t\t: %s \nBulan\t\t: %s \nTahun\t\t: %s \npengeluaran\t: %s\n", nama, tanggal, bulan,tahun, pengeluaran);
            total += atoi(pengeluaran);
        }
    }
    printf("_____________________________________\n");
     printf("Total pengeluaran %s : %d\n",name, total);
    fclose(fp);
}

//menu pengeluaran bulanan (NO 4)
void bulan()
{
    FILE *fp;
    char nama[100], tanggal[100], bulan[100], pengeluaran[100],tahun[100];
    char month[100];
    char year[100];
    char name[100];
    int total = 0;
    printf("Masukkan Nama : ");
    scanf("%s", name);
    printf("Masukkan bulan : ");
    scanf("%s", month);
    printf("Masukkan Tahun : ");
    scanf("%s", year);
    fp = fopen("expense.txt", "r");
    printf("\n\nTotal Pengeluaran di Bulan %s\n", month);
    while (fscanf(fp, "%s %s %s %s %s ", nama, tanggal, bulan,tahun, pengeluaran) != EOF)
    {
        if (strcmp(bulan, month ) == 0)
        if (strcmp(nama, name)== 0)
        if (strcmp(tahun, year)== 0)
		{
        {
            printf("\nNama\t\t: %s \nTanggal\t\t: %s \nBulan\t\t: %s \nTahun\t\t: %s \npengeluaran\t: %s\n", nama, tanggal, bulan,tahun, pengeluaran);
            printf("___________________________");
            total += atoi(pengeluaran);
        }
		}
    }
    	if (total == 0){
        	printf("\n\t\t\tTidak ada pengeluaran dalam bulan ini\n\n");
		}
    printf("_____________________________________\n");
    printf("Total pengeluaran %s : %d\n",name, total);
    fclose(fp);
}

//menu pengeluaran tahunan (NO 5)
void tahun()
{
    FILE *fp;
    char nama[100], tanggal[100], bulan[100], pengeluaran[100],tahun[100];
    char year[100];
    char name[100];
    int total = 0;
    printf("Masukkan Nama : ");
    scanf("%s", name);
    printf("Masukkan Tahun : ");
    scanf("%s", year);
    fp = fopen("expense.txt", "r");
    printf("Total Pengeluaran di Tahun %s\n", year);
    while (fscanf(fp, "%s %s %s %s %s ", nama, tanggal, bulan,tahun, pengeluaran) != EOF)
    {
        if (strcmp(tahun, year ) == 0)
        if (strcmp(nama, name)== 0)
		{
        {
            printf("\nNama\t\t : %s \nTanggal\t\t : %s  \nBulan\t\t : %s \nTahun\t\t : %s \npengeluaran \t: %s\n", nama, tanggal, bulan,tahun, pengeluaran);
            total += atoi(pengeluaran);
        }
	}
    }
    	if (total == 0){
        	printf("\n\t\t\tTidak ada pengeluaran di tahun ini\n\n");
		}
		 
    printf("_____________________________________\n");
    printf("Total pengeluaran %s : %d\n",name, total);
    fclose(fp);
}

