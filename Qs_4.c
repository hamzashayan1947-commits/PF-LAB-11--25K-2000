#include <stdio.h>

struct building
{
    int id ;
    int initial_height ;
    float growth_rate ;
};

int comp_height (int day , int current_height , float growth_rate){
    if(day == 0){
        return current_height ;
    }
    int increase = current_height * growth_rate ;
    int new_height = current_height + increase ;

    return comp_height( day -1 , new_height , growth_rate);

}

int main(){
    struct building b ;
    struct building *ptr = &b ;
    int n ;

    printf("Enter building id : ");
    scanf("%d" , &ptr->id);
    printf("Enter initial height : ");
    scanf("%d" , &ptr->initial_height);
    printf("Enter growth rate(if 5%% give 0.05) : ");
    scanf("%f" , &ptr->growth_rate);
    printf("Enter days : ");
    scanf("%d" , &n);
    
    int final_height  = comp_height(n , ptr->initial_height , ptr->growth_rate) ;
    printf("====Building Details====\n");
    printf("Building id : %d\n" , ptr->id);
    printf("Building initial height : %d\n" , ptr->initial_height);
    printf("Growth rate / day : %.2f%%\n" , ptr->growth_rate);
    printf("Height on day %d : %d\n" , n , final_height);


    return 0;
}