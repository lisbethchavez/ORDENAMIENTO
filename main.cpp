#include <iostream>
#include <stdio.h>
#define largo 10


using namespace std;


void intercambiar(int &a, int &b)
{
    int aux=a;
    a=b;
    b=aux;
}
void ordensecuencial(int vector[], int total)
{
    for(int i=0;i<total;i++)
    {
        for(int j=i+1;j<total;j++)
        {
            if(vector[i]>vector[j])
                intercambiar(vector[i],vector[j]);
        }
    }
}
void OrdenamientoQuicksort(int a[],int primerValor, int ultimoValor)
{
    int central, i, j, pivote;
    central=(primerValor+ultimoValor)/2; //Posicion central del arreglo
    pivote=a[central];//Capturar el valor medio del arreglo
    i=primerValor;
    j=ultimoValor;

    do{
        //Separando en dos partes el arreglo
        while(a[j]<pivote)i++;//Separando los valores menores al pivote
        while(a[j]<pivote)j--;//Separando los valores mayores al pivote
        if(i<=j){
            int temporal;
            //intercambio de valores
            temporal=a[i];
            a[i]=a[j];
            a[j]=temporal;
            i++;
            j--;
        }
    }while(i<=j);
    if(primerValor<j)
        OrdenamientoQuicksort(a,primerValor,j);
    if(i<ultimoValor)
        OrdenamientoQuicksort(a,i,ultimoValor);
}
void ordenShell(int a[],int n){
    int ints,i,aux;
    bool band;
    ints=n;
    while(ints>1){
        ints=ints/2;
        band=true;
        while(band==true){
            band=false;
            i=0;
            while((i+ints)<n){
                if(a[i]>a[i + ints]){
                    aux=a[i];
                    a[i]=a[i+ints];
                    a[i+ints]=aux;
                    band=true;
                }
                i++;
            }
        }
    }
}
void ordenShell2(int a[], int n){//optimizado

    int i,j,inc;
    int temp;
    for(inc=1;inc<n;inc=inc*3+1);
    while(inc>0){
        for(i=inc;i<n;i++){
            j=i;
            temp=a[i];
            while((j>=inc)&&(a[j-inc]>temp)){
                a[j]=a[j-inc];
                j=j-inc;
            }
            a[j]=temp;
        }
        inc=inc/2;
    }

}

void ordenamientoBurbuja(int v[],int n){
    int i=0,j=0;
    int aux;
    for(i=1;i<n;j++)
        for(j=0;j<(n-1);j++){
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
}
void burbujaMejorado(int arreglo[], int tamano)
{
    int comparaciones=tamano;
    bool termino=false;
    for(int i=0; i<(tamano-1);i++)
    {
        if(termino)
            break;
        termino=true;
        for(int j=0;j<comparaciones-1;j++)
            if(arreglo[j]>arreglo[j+1])
            {
                intercambiar(arreglo[j],arreglo[j+1]);
                termino= false;
            }
        comparaciones--;
    }
}
int main() {

    //INTERCAMBIAR

    int aux,a,b;
    a=5;
    b=7;

    intercambiar(a)=a;
    intercambiar(b)=b;

    cout<<"El VALOR DE a ES: "<<intercambiar(a)<<endl;
    cout<<"EL VALOR DE b ES: "<<intercambiar(b)<<endl;

    //ORDEN SECUENCIAL

    cout<<endl<<endl<<"ORDENACION SECUENCIAL ";
    ordensecuencial(largo,tamano);

    //ORDENAMIENTO QUICKSORT
    int a[largo],n;
    do{
        cout<<"NUMEROS A INGRESAR: ";cin>>n;
        if(n<=0||n>largo);
        cout<<"Ingresar un valor mayor a cero y menor a: "<<largo<<endl;

    }while(n<=0||n>largo);
    OrdenamientoQuicksort(a,0,n-1);

    //ORDENAMIENTO SHELL

    int a[largo],n;
    do{
        cout<<"NUMEROS POR INGRESAR: ";cin>>n;
        if(n<=0||n>largo)
            cout<<"Ingresar un valor mayor a cero y menor a:  "<<largo<<endl;
    }while(n<=0||n>largo);

    ordenShell(a,n);
    //ORDENAMIENTO SHELL 2

    int numeros[]={35,65,43,34,83,65};
    for(int i=0;i<6;i++)
    {
        cout<<numeros[i]<<" ";
    }
    cout<<endl;
    ordenShell2(numeros,6);
    for(int i=0;i<6;++i){
        cout<<numeros[i]<<" ";
    }
    cout<<endl;
    //ORDENAMIENTO BURBUJA


    int tamano[]={13,29,3,2,4,8};
    cout<<"LOS NUMEROS ORDENADOS SON: "<<endl;
    ordenamientoBurbuja(tamano,n);


    //ORDENAMIENTO BURBUJA MEJORADO

    const int tamano=20;
    int arreglo[tamano]={3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
    cout<<"ARREGLO SIN ORDENAR: "<<endl;
    burbujaMejorado(arreglo,tamano);
    cout<<"ARREGLO ORDENADO: "<<endl;
    burbujaMejorado(arreglo,tamano);


    return 0;
}
