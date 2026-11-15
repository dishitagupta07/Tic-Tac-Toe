#include<stdio.h>

void printboard();    // Function to display the board
void playerturn();   // Function to take input from the current player 
char boardnum[]={'0','1','2','3','4','5','6','7','8','9'};
int playernum=1,input,result; 
char mark; 
int checkwin(); // Function to check win,draw,lose condition


int main(){
    int status=-1; // -1 means game is ongoing, 0 means draw, 1 means win
    printf("\n\n");
    printf("Hi there! Welcome to the game zone.Let us start playing!!\n");
    printf("========================\n");
    printf("      TIC-TAC-TOE       \n");
    printf("========================\n");

    printf("\n");
    printboard();    // printboard() function called
    
    // MAIN GAME LOOP
    while(status==-1){ 
        playerturn();                     
        printboard();                    
        status=checkwin();             
        result=status;                
        playernum=(playernum==1)?2:1; 
    }
    
    //RESULT ANNOUNCEMENT
    if(result==1){                          
        int winner=(playernum%2==0)?1:2;   
        printf("Congratulations!! Player %d WINS!!!",winner);  
    }
    else if(result==0){              
        printf("It is a DRAW!");
    }
    return 0;
}
    void printboard(){

    printf("   %c   |   %c   |   %c  \n",boardnum[1],boardnum[2],boardnum[3]);
    printf("_______|_______|______\n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c  \n",boardnum[4],boardnum[5],boardnum[6]);
    printf("_______|_______|______\n");
    printf("       |       |      \n");
    printf("   %c   |   %c   |   %c \n",boardnum[7],boardnum[8],boardnum[9]);
    printf("\n\n");
}
    void playerturn(){
        
        //For handling player input and updating the board
        
        mark=(playernum==1)?'X':'O';
        printf("Player %d(%c) enter your place: ",playernum,mark);
        scanf("%d",&input);
        printf("\n");
        
        // checking conditions of invalidity
        while(input<1 || input>9 || boardnum[input]=='X' || boardnum[input]=='O'){
            printf("Invalid or already taken position.Please enter again.\n");
            printf("Enter your place: ");
            scanf("%d",&input);
            printf("\n");
        }
        boardnum[input]=mark; //If input valid,update the board

        
}
    int checkwin(){ 
        if(boardnum[1]==boardnum[2] && boardnum[2]==boardnum[3]){
            return 1;     // If winning condition matched,return 1,winner declared 
        }
        if(boardnum[4]==boardnum[5] && boardnum[5]==boardnum[6]){
            return 1;
        }
        if(boardnum[7]==boardnum[8] && boardnum[8]==boardnum[9]){
            return 1;
        }
        if(boardnum[1]==boardnum[4] && boardnum[4]==boardnum[7]){
           return 1;
        }
        if(boardnum[2]==boardnum[5] && boardnum[5]==boardnum[8]){
           return 1;
        }
        if(boardnum[3]==boardnum[6] && boardnum[6]==boardnum[9]){
           return 1;
        }
        if(boardnum[1]==boardnum[5] && boardnum[5]==boardnum[9]){
           return 1;
        }
        if(boardnum[3]==boardnum[5] && boardnum[5]==boardnum[7]){
           return 1;
        }

        // DRAW CONDITION IF ALL POSITIONS ARE FILLED
    int count=0;
        for(int i=1;i<=9;i++){
        if(boardnum[i]=='X'|| boardnum[i]=='O'){
            count++;
        }
    }

        if(count==9){  // If count reached till 9--means game is DRAW
        return 0;      
    }
    return -1;
}




            
    

    
    
    
    
    
    
    
    
    
    
    
    
    
  

