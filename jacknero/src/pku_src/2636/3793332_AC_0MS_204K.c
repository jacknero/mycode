k;
main(o,s){
    for(gets(s);~scanf("%d",&o);k||printf("%d\n",s+1))
        s=!k++?k=-o:s+o;
}