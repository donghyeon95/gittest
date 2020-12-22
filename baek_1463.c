//당연히 메모리 초과 겠죠...

// #include <stdio.h>

// int i =0;
// int calc(int num){
//     int num_1, num_2;
//     if(num ==1) return 0;
    
//     if(num%3 ==0) calc(num/3);
//     else{
//         num_1=calc(num/2);
//         num_2=calc(num-1);
        
//         if(num_1>=num_2){
//             return num_1+1;
//         }
//         else return num_2+1;
//     }
    
// }

// int main(){
//     int number;
//     scanf("%d", &number);
//     printf("%d",calc(number));
// }


//----------------------------------------------//

//아이디어 (구현은 낼 해보자)
//1부터 하나씩 해본다. 그거를 배열로 만든다. 10^6
//배열에는 각 숫자의 최소가 들어있게한다.
//-1은 이전거의 최소 +1, /2는 나누기 2한거의 최소 +1, /3은 나누기 3한거의 최소 +1
//안나눠지면 임의의 큰ㄱ값을 지정.
//이거 세게중에 최솟ㄱ값을 배열에 저장한다. 
//n까지 반복한다. 

//이거를 구현을 깔쌈하게 하려면 어떻게 해야할까?
//조금 변형하면 n을 6으로 나누어 떨어지는지 보고 역으로 계산해나가면 배열이 필요없을 지도...
//알고리즘 시간은 O(log n)이 나올듯....
//메모리도 4*N byte쓰겠네....


//정답입니다. 5024kb, 4ms
#include <stdio.h>
#include <malloc.h>

int main(){
    int number = 0;
    int num_1, num_2, num_3;
    int i = 1; 
    scanf("%d", &number);
    int* min_arr = (int*)malloc(sizeof(int)*number+1);
    min_arr[1]=0;

    for(i=2; i<=number; i++){
        num_1 = min_arr[i-1]+1;
        if(i%3 == 0){
            num_3 = min_arr[i/3]+1;
            num_2 = 1000000;
        }
        else if(i%2 == 0){ 
            num_3 = 1000000;
            num_2 =min_arr[i/2]+1;
        }
        else{
            num_2 = 1000000;
            num_3 = 1000000;
        }

        //최솟값구하기, 안멋있음.
        // if(num_1 <= num_2 && num_1<=num_3){
        //     min_arr[i]=num_1;
        // }
        // else if(num_2<=num_1 && num_2<=num_3){
        //     min_arr[i]=num_2;
        // }
        // else if(num_3<=num_1 && num_3<=num_2){
        //     min_arr[i]=num_3;
        // }   

        //간단하게 원리는 우선순위 큐 같이...
        if(num_1>num_2) num_1 = num_2;
        if(num_1>num_3) num_1= num_3;

        min_arr[i]= num_1;     
    }

    printf("%d", min_arr[number]);
}
