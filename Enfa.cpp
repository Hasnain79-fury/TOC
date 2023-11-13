#include<stdio.h>
#include<string.h>

int n,c,p=0,len;
int reached=0;
char str[20];
char in,out;
char transition[50][50][50];
int num_transitions[50][50];
char arr[50];
int digits[50];
char path[40];


int nfa(char currentstate,char finalstate,int index){
	
	int i,j;
	if(index==len && currentstate == finalstate){
        reached=1;
        path[p] = currentstate;
        p++;
        
        for(int i=0;i<p;i++)
        	printf("%c|",path[i]);
        printf("\n");
        return reached;
    }
    else if(index==len && currentstate != finalstate){
    	p--;
    	return 0;
    }
   
    for(i=0;i<n;i++)
       if(arr[i]==currentstate)
          break;
          
    for(j=0;j<c;j++)
       if(str[index]==digits[j])
          break;
    
    if(num_transitions[i][j]==0)
    	return 0;
    	   
	printf("1\n");
	for(int k=0;k<num_transitions[i][j];k++)
	  if(reached!=1){
		path[p]=currentstate;
		p++;
		//num_transitions[i][j]--;
		currentstate=transition[i][j][k];
		printf("1");
		nfa(currentstate,finalstate,index+1);
	}
	return reached;
}

int main(){
	printf("ENTER YOUR NFA!\n");
	printf("Total number of states-");
	scanf("%d",&n);
	
	getchar();
	
	for(int i=0;i<n;i++){
		printf("Enter State%d-",i+1);
		scanf("%c",&arr[i]);
		getchar();
		//printf("%c",arr[i]);
	}
	
	printf("Number of characters in your language-");
	scanf("%d",&c);
		
	printf("Enter characters-");
	for(int i=0;i<c;i++)
		scanf("%d",&digits[i]);
	
	for(int i=0;i<n;i++)
	   for(int j=0;j<c;j++)
	      for(int k=0;k<n;k++)
	          transition[i][j][k]='E';
	          
	
	int input;
	printf("Enter transition stages-\n");
	for(int i=0;i<n;i++){
		printf("Present State-%c \n",arr[i]);
		for(int j=0;j<c;j++){
			printf("How many state for input %d-",digits[j]);
			scanf("%d",&num_transitions[i][j]);
			if(num_transitions[i][j]!=0)
			   for(int k=0;k<num_transitions[i][j];k++){
					printf("Enter %dth state-",k+1);
					scanf("%c",&transition[i][j][k]);
					getchar();
				}  
			}
	}
	
	printf("Enter starting state-");
	scanf("%c",&in);
	getchar();
	
	printf("Enter accepting state-");
	scanf("%c",&out);
	getchar();
	
	printf("Enter you string-");    
	scanf("%s",str);
	
	len=strlen(str);
	
	//nfa(in,out,0);
	
	if(nfa(in,out,0)==1)
	  printf("String is accepted!\n");
	else
	 printf("NO!Not accepted\n"); 
	
	return 0;
	

}
/*
	int flag=s;
	printf("%s |",arr[s]);
	for(int i=0;i<len;i++){
	    for(int j=0;j<c;j++)	
		if(str[i]-'0'==digits[j]){
		   {
		   	printf("%s |",arr[transition[flag][j]]);
		   	   flag=transition[flag][j];
		   	   break;
		   }  
		 break;    
		}
*/

