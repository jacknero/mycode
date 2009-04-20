short s[2000],t[2];
o,q,p,r,m,n;

f(int*a,int*b){return*a-*b;}
g(x,y){
    *t=x/2;t[1]=y/2;
    return x%2|y%2?0:bsearch(t,s,n,4,f);
}
main(i,j){
    for(;scanf("%d",&n),n;printf("%d\n",m/2)){
        for(m=i=0;i<n*2;++i)scanf("%d",s+i);
        for(i=!qsort(s,n,4,f);i<n*2;i+=2)
            for(o=s[i],p=s[j=i+1];++j<n*2;
                m+=g(o+q-p+r,o-q+p+r)&&g(o+q+p-r,-o+q+p+r))
                q=s[j],r=s[++j];
    }
}
