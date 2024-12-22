#include<bits/stdc++.h>
#include<string>
#include<cstring>
#include<string.h>
int BSc=40, BE=3, BU=4, BN=5, BSy=5;
int NE=0, NU=0, NN=0, NS=0, NL=0, Nope=0;
int BC, BFL, BFN, checkBC=1, checkBFL=1, checkBFN=1;
std::string s;
int i, length, t;
int score=0;
int main()
{
   std::cin>>s;
   length=s.size();
   for(i=0;i<length; i++)
   {
    t=(int) s[i];
    if(s[i]<='Z'&& s[i]>='A') NU++;
    else if(s[i]<='z'&& s[i]>='a') NL++;
    else if(s[i]<='9' && s[i]>='0')  NN++;
    else if(s[i]=='!' ||s[i]=='@' ||s[i]=='#' || s[i]=='$' || s[i]=='%' ||s[i]=='^' || s[i]=='&' ||s[i]=='*'|| s[i]=='?' ||s[i]== '_' ||s[i]=='~') NS++;
    else Nope++;
   }
   
   NE=length-8;
   
   if(NU>0&& NS>0&& NN>0) BC=25;
   else if(NU>0&&NS>0||NU>0&&NN>0||NS>0&&NN>0) BC=15;
   else BC=0;
   
   if(NL==length) BFL=-15; else BFL=0;

   if(NN==length) BFN=-35; else BFN=0;
   
   score=BSc+(BE*NE)+(NU*BU)+(NN*BN)+BSy*NS+BC+BFL+BFN;
   
   if(NE<0||Nope>0) std::cout<<"KhongHopLe"; 
   else 
   {
    if(score<50) std::cout<<"Yeu";
    else if(score>=50&& score<75) std::cout<<"Vua";
    else if(score>=75&&score<100) std::cout<<"Manh";
    else std::cout<<"RatManh";
   }
return 0;
}