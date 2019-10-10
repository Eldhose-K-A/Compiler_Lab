#include<stdio.h>
#include<stdlib.h>

int stack[20],visitedarray[20],vmax=-1,top=-1,tmax=0;
int qn1,qn2,qmax,i,j,k;
char ch;

void push(int v){
	stack[++top]=v;
}

int pop(){
	return stack[top--];
}

int searchVisited(int v){
	for(int y=0;y<=vmax;++y)
		if(visitedarray[y]==v)
			return 1;
	return 0;
}

int main(int argc, char *argv[]){
	FILE *fin;
	fin = fopen(argv[1],"r");
	fscanf(fin," %d %d",&qmax,&tmax);
	fclose(fin);
	for(i=0;i<qmax;++i){
		top = vmax = -1;
		push(i);
		printf("e-Closure(q%d) = { ",i);
		while(top!=-1){
			k = pop();
			if(searchVisited(k)==1)
				continue;
			visitedarray[++vmax] = k;
			printf("q%d ",k);
			fin = fopen(argv[1],"r");
			fscanf(fin," %d %d",&qmax,&tmax);
			for(j=0;j<tmax;++j){
				fscanf(fin," %d %c %d",&qn1,&ch,&qn2);
				if( qn1==k && ch=='e' && searchVisited(qn2)!=1 )
					push(qn2);
			}
			fclose(fin);
		}
		printf("}\n");
	}
	return 0;
}