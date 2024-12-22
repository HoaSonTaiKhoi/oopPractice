#include <stdio.h>
#include <windows.h>

double Sk_p(int ATK, int p.P){
    double Dame ;
    if (p.P >= 100){
    Dame = ATK*1.5;
    }
    else {
        Dame= ATK;

    }
return Dame;

}


double Sk_l(int ATK, int p.L){
    double Dame;
    if (p.L>=100){

    
    Dame= ATK*6;
    }
    else {
    Dame = ATK;
    }
    return Dame;
}
int speed_L(int p.L, int s.L){
    if (p.L>=100){
        s.L+=5;
    }
 return s.L;
 }
int power_L(int p.L, int cl){
    if (p.L<100 && p.L>0){
        if (cl==1){
        p.L+=15;

        }
        else{
        p.L+=50;
        }
    }    
    else {
        p.L=0;
    }
    return p.L;
}
int power_P(int p.P, int dp){
    if(p.P<100 && p.P>0){
        if (dp==1){
        p.P+=15;
        }
    else{
        p.P +=50;
        }
    }
    else{
        p.P=0;
    }
    return p.P;
}    

int turn_L(int p.L){
    if (p.L>=100) {
      int cl=0;

    }
    else{
       int cl=1;
    }
return cl;
}
int turn_P(int p.P){
     if (p.P>=100){
       int dp=0;
     } 
     else{
       int dp=1;
     }
     return dp;
}

main(){
    const int HP.P=20000000;
    const int HP.L=15800000;
    const int A.P=15000;
    const int A.L=17560;
    const int S.P=1056;
    const int S.L=1055;
    int hp.P, hp.L, a.P, a.L, s.P, s.L, p.P, p.L;
    int cl, dp;
    int i,n;
    i=1;
s.P=S.P;
s.L=S.L;
hp.P=HP.P;
hp.L=HP.L;
a.P=A.P;
a.L=A.L;
p.L=50;
p.P=50;


    While (i<=15 || hp.P==0 || hp.L ==0){
         Sleep(1000);
         

        
        if (s.L> s.P){
            hp.P -= Sk_l(a.L,power_L(p.L, ));
            dp=power_P(p.P);




            printf("%d", hp.P,"/","%d", HP.P); printf("    "); printf("%d",hp.L,"/", "%d", HP.L);
                     system("cls");
                     Sleep(1000);




            hp.L-= Sk_p(a.P, pow_P(p.P, dp));
            printf("%d", hp.P,"/","%d", HP.P); printf("    "); printf("%d",hp.L,"/", "%d", HP.L);
        } else {
            hp.L -=Sk_p(a.P);
        }


    }
}