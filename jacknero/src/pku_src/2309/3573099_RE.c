main(n){
    for(gets();~scanf("%d",&n);)
        printf("%d %d\n",1|n&n-1,n|n-1);
}
