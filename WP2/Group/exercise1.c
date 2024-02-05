#include <stdio.h>
#include <string.h>

#define END_CHARACTER 'f'


enum DIRECTION{
    N,
    E,
    S,
    W
};

typedef struct 
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;


void move(ROBOT *robot){
    if(robot->dir == 0){
        robot->ypos++;
    } else if (robot->dir == 1){
        robot->xpos++;
    } else if (robot->dir == 2){
        robot->ypos--;
    } else if (robot->dir == 3){
        robot->xpos--;
    }
}

void turn(ROBOT *robot){
    if(robot->dir == 3){
        robot->dir = 0;
    } else {
        robot->dir++;
    }

}

int main(int argc, char *argv[]){
    char inputInstructions[100];
    ROBOT robot = {0,0,N};
    char currentInputChar;

do{
    printf("What is the robot's starting position?\n");
    printf("Enter x-coordinate:");
    scanf("%d", &robot.xpos);
    printf("Enter y-coordinate:");
    scanf("%d", &robot.ypos);
    robot.dir = N;

    printf("Enter the instructions for the robot as a sequence of the letters m for move and t for turn:");
    scanf("%s", inputInstructions);

    for(int i=0; i<strlen(inputInstructions); i++){
        currentInputChar = inputInstructions[i];
        if(inputInstructions[i] == 'm'){
            move(&robot);
        }else if(inputInstructions[i] == 't'){
            turn(&robot);
        }
    }

    printf("The final position of the robot is:\n X-coordinate: %d\n Y-coordinate: %d\n", robot.xpos, robot.ypos);
} while(currentInputChar != END_CHARACTER);
    
}