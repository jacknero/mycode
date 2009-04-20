double ans;
int k,n,r;

main(){

    for( ; scanf("%d%d",&n,&r) == 2; )
    {
        if( (n+r) == 0 ) break;// n=r=0で終了

        ans = 1;
        // rが大きいときはn-rにして計算回数を減らす
        r = (r>n/2)? n-r: r;

        for( k = 1; k <= r; )
        {
            ans = ans*n/k;// ans*=n/kはダメ
            --n;
            ++k;
        }

        // あってる？
        printf("%.lf\n", ans);
    }

}
