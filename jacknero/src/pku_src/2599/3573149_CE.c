i,a[998];
d(b,j,w,x){
    for(j=*a*2,x=a;--j-1;)
        a[j^1]==b?a[j]-=w=a[j],x=d(w)|x<w?x:w:1;
    i=x<a?x:0;          //returnが無いのに関数が評価できるのはなぜ……？
    //x<a?i=x:(i=0);    //これだけで通らなくなる。同じ意味じゃないの？　i=i;とかを後に入れても同じ。
}
main(){
    for(;~scanf("%d",a+i++););
    printf(d(a[1])?"%swins flying to airport %d"
        :"%sloses","First player ",i);
}
