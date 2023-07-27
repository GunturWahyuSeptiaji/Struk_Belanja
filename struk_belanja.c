#include <stdio.h>
#include <stdlib.h>

int main()
{

  int jml_beli;

  puts("================================");
  puts("+    PROGRAM STRUK BELANJA     +");
  puts("================================");
  printf("\n");

  // Bagian 1
  puts("----- Input Data Pembelian -----");
  printf("\nJumlah Barang \t: ");
  scanf("%d", &jml_beli);
  printf("\n");
  puts("Masukkan Data Barang : ");
  puts("--------------------------------");

  int harga_barang[jml_beli], jumlah_barang[jml_beli], total = 0, bayar = 0;
  char nama_barang[jml_beli][50];

  // Bagian 2
  for (int i = 0; i < jml_beli; i++)
  {
    printf("%d. Nama Produk\t: ", i + 1);
    scanf("%s", &nama_barang[i]);

    printf("   Harga\t: ", i + 1);
    scanf("%d", &harga_barang[i]);

    printf("   Jumlah\t: ");
    scanf("%d", &jumlah_barang[i]);
    puts("--------------------------------");
  };

  // Bagian 3
  puts("=================================================================");
  puts("+                         STRUK BELANJA                         +");
  puts("=================================================================\n");

  puts("No\tBarang\t\tHarga\t\tJumlah\t\tSub Total");
  for (int i = 0; i < jml_beli; i++)
  {
    int sub_total = harga_barang[i] * jumlah_barang[i];
    total += sub_total;
    printf("%d\t%s\t\tRp. %d\t%d\t\tRp. %d\n", i + 1, nama_barang[i], harga_barang[i], jumlah_barang[i], sub_total);
  }
  puts("-----------------------------------------------------------------");
  printf("Jumlah Bayar\t: Rp. %d\n", total);
  printf("PPN 10%%\t\t: Rp. %d\n", total / 10);
  printf("Total Bayar\t: Rp. %d\n", total + (total / 10));
  printf("Bayar\t\t: Rp. ", &bayar);
  scanf("%d", &bayar);
  printf("Kembali\t\t: Rp. %d", bayar - (total + (total / 10)));
  puts("\n-----------------------------------------------------------------");

  // Bagian 4
  FILE *fptr;
  fptr = fopen("Struk Belanja.txt", "w");
  if (fptr == NULL)
  {
    puts("File tidak bisa dibuka");
    exit(1);
  }

  puts("Print Struk ke .txt");

  total = 0;

  // Bagian 5
  fputs("=================================================================\n", fptr);
  fputs("+                         STRUK BELANJA                         +\n", fptr);
  fputs("=================================================================\n", fptr);

  fputs("No\tBarang\t\tHarga\t\tJumlah\t\tSub Total\n", fptr);
  for (int i = 0; i < jml_beli; i++)
  {
    int sub_total = harga_barang[i] * jumlah_barang[i];
    total += sub_total;
    fprintf(fptr, "%d\t%s\t\tRp. %d\t%d\t\tRp. %d\n", i + 1, nama_barang[i], harga_barang[i], jumlah_barang[i], sub_total);
  }
  fputs("-----------------------------------------------------------------\n", fptr);
  fprintf(fptr, "Jumlah Bayar\t: Rp. %d\n", total);
  fprintf(fptr, "PPN 10%%\t\t: Rp. %d\n", total / 10);
  fprintf(fptr, "Total Bayar\t: Rp. %d\n", total + (total / 10));
  fprintf(fptr, "Bayar\t\t: Rp. %d\n", bayar);
  fprintf(fptr, "Kembali\t\t: Rp. %d\n", bayar - (total + (total / 10)));
  fputs("-----------------------------------------------------------------\n", fptr);

  // bagian 6
  fclose(fptr);

  puts("Cetak Struk Berhasil!");

  return 0;
}