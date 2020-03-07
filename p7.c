#include<stdio.h>
#include<stdlib.h>
//A->BaP|abQ
//P->AbbP|#
//B->DbQ|dQ
//Q->BddQ|#
//D->bbR
//R->DaaR|#
char stack[100];
int stacktop=0;
char instr[10]="abd#dd$";
int f=0;
int fwd=0;
void P();
void A();
void Q();
void B();
void D();
void R();

void advance()
{fwd++;
}

void error()
{printf("error\n");
 exit(0);
}

void A()
{if(instr[fwd]=='b' || instr[fwd]=='d')
    {pop(A);
	push(B);
	push(a);
	push(P);
	B();
     if(instr[fwd]=='a' && stack[stacktop]=='a')
	{pop(a);
	 advance();}
     else 
	error();
     P();
    }
 else if(instr[fwd]=='a' && stack[stacktop]=='a')
    {
	push(a);
	push(b);
	push(Q);
	pop(a);
	advance();
     if(instr[fwd]=='b' && stack[stacktop]=='b')
	{pop(b);
	 advance();}
     else 
	error();
     Q();
    }
 else 
	error();
}

void P()
{if(instr[fwd]=='b' || instr[fwd]=='a'|| instr[fwd]=='d')
 	{
	push(A);
	push(b);
	push(b);
	push(P);	
	A();
         if(instr[fwd]=='b' && stack[stacktop]=='b')
		{pop(b);
		 advance();}
         else
		error();
         if(instr[fwd]=='b' && stack[stacktop]=='b')
		{pop(b);
		 advance();}
         else
		error();
         P();
  
       	}
 else
	return;
}

void B()
{if(instr[fwd]=='b')
    {D();
     if(instr[fwd]=='b')
	advance();
     else
	error();
     Q();
    }
 else if(instr[fwd]=='d')
   {advance();
    Q();
   }
 else
   error();
   
}

void Q()
{ if(instr[fwd]=='b' || instr[fwd]=='d')
	{B();
         if(instr[fwd]=='d')
	    advance();
         else 
            error();
         if(instr[fwd]=='d')
            advance();
         else
            error();
	 Q();
	}
  else
	return;
}



void D()
{if(instr[fwd]=='b')
    {advance();
     if(instr[fwd]=='b')
	advance();
     else error();
      R();
    }
 else 
	error();       
}

void R()
{if(instr[fwd]=='b')
   {D();
    if(instr[fwd]=='a')
	advance();
    else
	error();
    if(instr[fwd]=='a')
	advance();
    else
	error();
    R();
   }
 else
	return;
}
void push(char c)
{
	if(stacktop>99)
	  error();
	stack[stacktop]=c;
}
void pop(char c)
{
	if(stacktop<0)
	  error();
	stacktop--;
}
void main()
{push(A);
 A();
 if(instr[fwd]=='$')
    printf("Successful\n");
 else
    printf("Error\n");
}

