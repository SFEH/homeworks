#include <stdio.h>

#define max 10

int sayi,kap,i,j;
int agir[max],deg[max];
int y[max],x[max],fp=-1,fw;


void kullanici_gir(){

  printf("Lutfen girilecek esyalarin sayisini giriniz: ");
  scanf("%d",&sayi);
  printf("Lutfen cantanın kapasitesini giriniz: ");
  scanf("%d",&kap);
  for(i = 0; i<sayi; i++){
    printf("lutfen %d esyanin agirligini giriniz: ",i+1);
    scanf("%d",&agir[i]);
    printf("Lutfen %d esyanin degerini giriniz: ",i+1);
    scanf("%d",&deg[i]);
  }
}


float birlesim(float cp,float cw,int k)
{
  float b = cp;
  float c = cw;
  for(i=k;i<=sayi;i++)
  {
    c = c+agir[i];
    if( c < kap)
    b = b +deg[i];
    else
    return (b+(1-(c-kap)/ (float)agir[i])*deg[i]);
  }
  return b;
}

void canta(int k,float cp,float cw)
{
  if(cw+agir[k] <= kap)
  {
    y[k] = 1;
    if(k <= sayi)
    canta(k+1,cp+deg[k],cw+agir[k]);
    if(((cp+deg[k]) > fp) && ( k == sayi))
    {
      fp = cp+deg[k];
      fw = cw+agir[k];
      for(j=0;j<=k;j++)
      x[j] = y[j];
    }
  }
  if(birlesim(cp,cw,k) >= fp)
  {
    y[k] = 0;
    if( k <= sayi)
    canta(k+1,cp,cw);
    if((cp > fp) && (k == sayi))
    {
      fp = cp;
      fw = cw;
      for(j=0;j<=k;j++)
      x[j] = y[j];
    }
  }
}

void ekrana_bas()
{
  float s=0.0;
  printf("\nEsya\nAgirlik\tDeger\tSelected ");
  for(i=0;i<sayi;i++)
  printf("\n\t%d\t%d\t%d\t%d",i+1,agir[i],deg[i],x[i]);
  printf("\n\n Cantanin icindeki esyalar : ");
  for(i=0;i<sayi;i++)
  if(x[i]==1)
  {
    printf("%d\t",i+1);
    s += (float) deg[i] * (float) x[i];
  }

  printf("\n Toplam deger: %f ",s);
}

int main(){

  kullanici_gir();
  canta(0,0.0,0.0);
  ekrana_bas();
  return 0;
}
