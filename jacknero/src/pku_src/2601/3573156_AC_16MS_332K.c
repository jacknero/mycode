main(i,n){
    float a,v;
    scanf("%d%f%f",&n,&v,&a);
    for(a+=v*n;n;a-=2*n--*v)i+=scanf("%f",&v);
    printf("%.2f",a/i);
}
