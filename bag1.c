#include<stdio.h>

#define z 10

int sayi,kap,agir[z],deg[z],i;


int toplam=0;
int max(int a,int b)
{
  if(a>b)
    return a;
  else
    return b;
}

void kullanici_gir(){

  printf("Lutfen girilecek esyalarin sayisini giriniz: ");
  scanf("%d",&sayi);
  printf("Lutfen cantanın kapasitesini giriniz: ");
  scanf("%d",&kap);
  for(i = 1; i<=sayi; i++){
    printf("lutfen %d esyanin agirligini giriniz: ",i);
    scanf("%d",&agir[i]);
    printf("Lutfen %d esyanin degerini giriniz: ",i);
    scanf("%d",&deg[i]);
  }
}


void canta(int a,int b,int c[],int d[])
{
  int v[50][50],x[10],i,j; //v adında bir matris yapıyor..
  for(i=0;i<=a;i++)
  v[0][i]=0;
  for(i=1;i<=b;i++)
  {
    for(j=0;j<=a;j++)
    {
      if(j>=c[i])
      v[i][j]=max(v[i-1][j],v[i-1][j-c[i]]+d[i]); //matris degerleri atanıyor...
      else
      v[i][j]=v[i-1][j];
    }
  }
  /*for (i=0;i<15;i++){ //debug amacli.. Burayi calistirip anlamaya calisin..
    printf("\n");
    for(j=0;j<15;j++){
      printf("\t%i", v[i][j]);
    }
  }*/
  for(i=1;i<=b;i++)
  x[i]=0;
  i=b;
  j=a;
  while(i>0 && j>0)
  {
    if(v[i][j]!=v[i-1][j]) // karsılastırmalar yapılıyor..
    {
      x[i]=1; //Cantadaki degerleri 1 basiyor..
      j=j-c[i];
    }
    i--;
  }
  printf("\nCantanin ici:\n");
  for(i=1;i<=b;i++)
  {
    if(x[i]==1)
    {
      printf("X%d=1\t",i); //vektor şeklinde cantada bulunması gereken kumeler ekrana basılıyor..
      toplam=toplam+d[i];
    }
    else
    printf("X%d=0\t",i);
  }
  printf("\nToplam = %d\n",toplam); //toplam para degeri ekrana basılıyor..
}
int main()
{
  kullanici_gir();
  canta(kap,sayi,agir,deg);
  return 0;
}
