# include <iostream>

int move[9][9]={
   //A,B,C,D,E,F,G,H,I
	{1,1,0,1,1,0,0,0,0},//move1
	{1,1,1,0,0,0,0,0,0},//move2
	{0,1,1,0,1,1,0,0,0},//move3
	{1,0,0,1,0,0,1,0,0},//move4
	{0,1,0,1,1,1,0,1,0},//move5
	{0,0,1,0,0,1,0,0,1},//move6
	{0,0,0,1,1,0,1,1,0},//move7
	{0,0,0,0,0,0,1,1,1},//move8
	{0,0,0,0,1,1,0,1,1} //move9
};
int clock[9];//original
int temp[9];//for try
int m[9];//record the times of each move

void LoadClock();
void Move();
bool Check();
void Output();

void main(){
	
	LoadClock();

	for (m[0]=0;m[0]<=3;m[0]++)
	for (m[1]=0;m[1]<=3;m[1]++)
	for (m[2]=0;m[2]<=3;m[2]++)
	for (m[3]=0;m[3]<=3;m[3]++)
	for (m[4]=0;m[4]<=3;m[4]++)
	for (m[5]=0;m[5]<=3;m[5]++)
	for (m[6]=0;m[6]<=3;m[6]++)
	for (m[7]=0;m[7]<=3;m[7]++)
	for (m[8]=0;m[8]<=3;m[8]++)
	{
		
		Move();
		if (Check()==true){
			Output();
			break;
		}		
	}
}

void LoadClock(){
	int i;
	for (i=0;i<9;i++)
		cin>>clock[i];
}

void Move(){
	int i,j;
	for (i=0;i<9;i++){
		temp[i]=clock[i];
		for (j=0;j<9;j++) if(move[j][i])
			temp[i] += m[j];
		temp[i] %= 4;
	}
}

bool Check(){
	int i;
	for (i=0;i<9;i++)	if (temp[i]!=0)	return false;
	return true;
}

void Output(){
	int i,j;
	for (i=0;i<9;i++){
		if (m[i]>0)
			for (j=0;j<m[i];j++)
				cout<<i+1<<' ';
	}
	cout<<endl;
}
