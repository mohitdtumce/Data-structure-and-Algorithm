#include<iostream>
using namespace std;
int sumDigits(int num){
    if(num/10==0){
        return num;
    }else{
        int sum=0;
        while(num){
            sum+=num%10;
            num=num/10;
        }
        return sum+sumDigits(sum);
    }
}
int main(){
	cout<<sumDigits(987);
}
