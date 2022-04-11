#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
static char inputCommand[80];
static char outputCommand[80];
static char a[80];
static char b[80];
static float ketqua;
void printftinyport(){
    printf("tiny_portpt $ ");
}
int parseCmd(char *inputcmd, char *output,char *a,char *b){
    const int len=strlen(inputcmd);
    int n=0;
    for(int i=0;i<len-1;i++){
        if(isspace(inputcmd[i])) n=n+1;
    }
    char *temp = strtok(inputcmd," ");
   if(n!=2){
       printf("Loi cu phap moi nhap lai\n");
       return 0;
   }
   else{
          for (int i=0;i<n+1;i++)
            {
                if(i==0)
                    strcpy(output,temp);
                else if(i==1)
                    strcpy(a,temp);
                else if(i==2)
                    strcpy(b,temp);
                temp = strtok(NULL," ");
            }
        return 1;
   }

}
int sum(float *ketqua,char *a,char *b){
    *ketqua=atof(a)+atof(b);
    return 0;
}
int sub(float *ketqua,char *a,char *b){
    *ketqua=atof(a)-atof(b);
    return 0;
}
int mul(float *ketqua,char *a,char *b){
    *ketqua=atof(a)*atof(b);
    return 0;
} 
int Div(float *ketqua,char *a,char *b){
    *ketqua=atof(a)/atof(b);
    return 0;
}
void kiemtra(char *output,char *a,char *b,float *ketqua){
    if(strcmp(output, "sum")==0){
        sum(ketqua,a,b);
        printf("SUM %f\n",*ketqua);
    }
    else if(strcmp(output, "sub")==0){
        sub(ketqua,a,b);
        printf("SUB %f\n",*ketqua);
    }
    else if(strcmp(output, "mul")==0){
        mul(ketqua,a,b);
        printf("MUL %f\n",*ketqua);
    }
    else if(strcmp(output, "div")==0){
        Div(ketqua,a,b);
        printf("DIV %f\n",*ketqua);
    }
    else
        printf("Phep toan khong hop le\n");
}
int main(){
    while(1){
    printftinyport();
    char *inp=inputCommand;
    *inp=getchar();
    
    while(*inp !='\n')
    {
        inp++;
        *inp=getchar();
    }
    if(parseCmd(inputCommand,outputCommand,a,b)==1)
        kiemtra(outputCommand,a,b,&ketqua);
    }
    return 0;
}
