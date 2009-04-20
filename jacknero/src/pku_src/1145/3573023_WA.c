main(){
    int a[6],s,r=3,n=0,l=0,f;
    while(n+1){
        if (scanf("%d",&n)) {
            if (!l) {
                printf(&"no\n\0yes\n\0"+r);
                s=r=0,n=-n;
            }
            s+=a[l]=n;
            f=0;
        }
        n=getchar();
        if(n==40) a[++l]=0,f++;
        if(n==41) {
            if(++f==4 && !s) r=4;
            s-=a[l--];
        }
    }
}
