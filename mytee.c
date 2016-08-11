# include  <stdio.h>

int main(int argc, char **argv)
{
    FILE *fp;
    int c;

    if ( argc > 1 )   
    {   
        fp = fopen(argv[1], "w");
        if ( fp == NULL )   
        {   
            fprintf(stderr, "%s: can not open <%s>/n", argv[0], argv[1]);
            return -1; 
        }   
    }   
    else
       fp = stdout;

    while ( (c = fgetc(stdin)) )
    {   
        usleep(10*1000);
        if(c == EOF)
            continue;

        fputc(c,fp);
        fputc(c,stdout);
    }   

    return 0;
}