#include "stdio.h"
#include "stdlib.h"
step(char*b,char**b2,int l,int*c2) {if(7*l>5*(*c2)){free(*b2);*c2*=2;*b2=malloc(*c2);}int l2=0;char seq=1;
    for(int i=0;i<l-1;++i){if(b[i]==b[i+1])seq++;else{(*b2)[l2++]=seq+'0';(*b2)[l2++]=b[i];seq=1;}}
    (*b2)[l2++]=seq+'0';(*b2)[l2++]=b[l-1];return l2;}
main() {printf("1");getchar();int c1=64,c2=64;int l1=1,l2=0;char*b1=malloc(c1),*b2=malloc(c2);b1[0]='1';
    while(1){l2=step(b1,&b2,l1,&c2);b2[l2]='\0';printf("%s",b2);getchar();
    l1=step(b2,&b1,l2,&c1);b1[l2]='\0';printf("%s",b1);getchar();}
    free(b1);free(b2);return 0;}