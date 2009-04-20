a,b,m,p,q,n;
main(s){
    for(;~scanf("%d%d",&a,&b);printf("%d %d %d\n",a,b,m),m=0)
        for(p=a<b?a:b,q=a^b^p;p<=q;m=m<s?s:m,s=1)
            for(n=p++;n-1;s++)
                n=n&1?n*3+1:n/2;
}
