#include <stdio.h>
void put();
void add();
void jmpe();
void prn();
void jmpu();
void halt();
int START_WITH();


int main(void){
	
char THE_LINES[32];
char CH_LINES[100][100];
int i=0,j=0;
int registers[32];
FILE* file;

file= fopen("from1to10.sla","r");
printf("______________THE INPUT______________\n");
while(fgets(THE_LINES,32,file)!= NULL){
	
	for(i=0;THE_LINES[i]!='\n';i++){
        CH_LINES[j][i]=THE_LINES[i];
    }
		CH_LINES[j][i] = '\0';
    printf("%d-%s\n",j+1,CH_LINES[j]);
        j++;
    }
    
i=0;
j=0;
printf("______________THE OUTPUT______________\n");
    while(CH_LINES[i][j]!='\0'){
    	
    if(START_WITH(CH_LINES[i],"put"))
    {
        put(CH_LINES[i],registers);
    }
    else if(START_WITH(CH_LINES[i],"add"))
    {
        add(CH_LINES[i],registers);
    }
    else if(START_WITH(CH_LINES[i],"jmpe"))
    {
        jmpe(CH_LINES[i],registers,&i);
    }
    else if(START_WITH(CH_LINES[i],"prn"))
    {
        prn(CH_LINES[i],registers);
    }
    else if(START_WITH(CH_LINES[i],"jmpu"))
    {
        jmpu(CH_LINES[i],&i);
    }
    else if(START_WITH(CH_LINES[i],"halt"))
    {
        halt(CH_LINES[i],&i,&j);
    }
    
    i++;
}
return 0;
}


int START_WITH(char line[],char word[]){
    int x=0;
    while(line[x]!= ' ' && word[x]!='\0' && line[x]==word[x]){
        x
        ++;
    }

    if(word[x]=='\0'){
        return 1;
    }else{
        return 0;
    }
}

void put(char line[],int r[]){
    int x=0;
    int value=0;
    int index=0;
    while(line[x]!='\0'){
        if(line[x-1]==' '){
            while(line[x]!=','){
                value=value*10+(line[x]-'0');
                x++;
            }
        }

        if(line[x-1]=='r'){
            while(line[x]!='\0'){
                index=index*10+(line[x]-'0');
                x++;
            }
        }

        
            if(line[x]!='\0'){
                x++;
            }
        }

            if(line[x]=='\0'){
            r[index-1]=value;
        }
}

void add(char line[],int r[]){
    int x=0;
    int index1=0;
    int index2=0;
    int value;
    while(line[x]!='\0'){

        if(line[x-2]==' ' && line[x-1]=='r'){

            while(line[x]!=','){
                index1=index1*10+(line[x]-'0');
                x++;
            }

        }
        
        if(line[x-1]=='r' && line[x-2]==','){
            while(line[x]!='\0'){
                index2=index2*10+(line[x]-'0');
                x++;
            }
        }

        if(line[x]!='\0'){
            x++;
        }
    }
        value= r[index1-1];
        r[index2-1]= value + r[index2-1];
}

void prn(char line[],int r[]){
    int x=0;
    int index=0;
    while(line[x]!='\0'){
        if(line[x-2]==' ' && line[x-1]=='r'){
            while(line[x]!='\0'){
                index=index*10+(line[x]-'0');
                x++;
            }
        }

        if(line[x]!='\0'){
            x++;
        }
    }

    printf("%d\n",r[index-1]);
}

void jmpu(char line[],int* i){
    int x=0;
    int index=0;

    while(line[x]!='\0'){
        if(line[x-1]==' '){
            while(line[x]!='\0'){
                index=index*10+(line[x]-'0');
                x++;
            }
        }

        if(line[x]!='\0'){
            x++;
        }
    }

    *i = index-2;
}

void jmpe(char line[],int r[],int *i){
    int x=0;
    int index1=0,index2=0;
    int loc=0;
    while(line[x]!='\0'){
        if(line[x-2]==' ' && line[x-1]=='r'){
            while(line[x]!=','){
                index1=index1*10+(line[x]-'0');
                x++;
            }
        }
        if(line[x-2]==',' && line[x-1]=='r'){
            while(line[x]!=','){
                index2=index2*10+(line[x]-'0');
                x++;
            }
            
        } 
        if(line[x-1]==',' && line[x]!='r'){
            while(line[x]!='\0'){
                loc=loc*10+(line[x]-'0');
                x++;
            }
        }

        if(line[x]!='\0'){
            x++;
        }
    }

    if(r[index1-1]==r[index2-1]){
        *i=loc-2;
    }
}

void halt(char line[],int* i,int* j){
    int x=0;
    while(line[x]!='\0'){
        x++;
    }
    *j=x;
    *i=*i-1;
}
