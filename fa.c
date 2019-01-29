#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*CH SRAVANTHI BT16CSE022*/
int check(char * inp, char * sym, int m)
{ int flag=0,i,j; 
for(i=0;i<strlen(inp);i++)
{ flag=0;
  for(j=0;j<m;j++)
  { if(inp[i]==sym[j])
    {flag=1;}
  }
  if(flag==0)
  {return 0;}
}
return 1;
}
int place(char ch, char * sym, int m)
{ for(int i=0;i<m;i++)
  { if(sym[i]==ch){return i;}
  }
  return -1;
}
int main()
{ int n,m,x,ini, i,temp;
printf("give number of states");
scanf("%d",&n);
printf("give number of elements");
scanf("%d",&m);
char sym[m];int func[n+1][m]; char inp[10];
for(i=0;i<m;i++)
{ 
printf("give the elements");
scanf("%s",&sym[i]);
}
printf("give number of final states");
scanf("%d",&x);int final[x];
for(i=0;i<x;i++)
{printf("give the states");
scanf("%d",&final[i]);
}
printf("give initial state");
scanf("%d",&ini);
for(int j=0;j<n;j++)
{for(i=0;i<m;i++)
{printf("give the mapping from %d on %c",j,sym[i]);
scanf("%d",&func[j][i]);//printf("	%d",func[j]['a']);
}
}
for(i=0;i<m;i++)
{ func[n][i]=sym[i];
}
printf("now give any sequence to test the automata::");
scanf("%s",inp);
int ch=check(inp,sym,m);char c;int flag=0;
if(ch)
{
for(i=0;i<strlen(inp);i++)
{c=inp[i]; temp=place(c,sym,m);
ini=(func[ini][temp]);
} 
for(i=0;i<x;i++)
{ if(ini==final[i])
  { flag=1;printf("ACCEPT");break;}
}
}
if(flag==0){printf("REGECT");}
}
