#include <stdio.h>
#include <math.h>

int main(void){
    int h,w,d,k;
    double m1,m2,m3,m4,m5,mo,pvp,pcp,pd;
    pvp=0.0007;
    pcp=0.0008;
    pd=0.00052;
    printf("vvedite h(180-220)\n");
    scanf("%d",&h);
    printf("vvedite w(80-120)\n");
    scanf("%d",&w);
    printf("vvedite d(50-90)\n");
    scanf("%d",&d);
    if (((h>=180) && (h<=220) && (w>=80)&&(w<=120) && (d>=50)&&(d<=90))){
    m1=h*w*0.5*pvp;
    m2=2*h*d*1.5*pcp;
    m3=2*pcp*w*d*1.5;
    m4=2*h*w*pd;
    k=h/40;
    m5=k*d*w*2;
    mo=(m1+m2+m3+m4+m5)/1000;
    printf("massa hkafa: %f",mo);
    }
    else{
        printf("takie hkafi ne vipuskautsa\n");
    }
}
