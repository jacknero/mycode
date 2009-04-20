c;
main(s){
	for(;read(0,&c,1);s-=c<11)
		s%3||putchar(c-65u<26?c%70%44+65:c);
}
