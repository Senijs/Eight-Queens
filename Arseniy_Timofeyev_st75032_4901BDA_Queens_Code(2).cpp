#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
    
    const int SIZE=8;
    int arrField[SIZE][SIZE]={0};
    int x=0;
    int y=0;
    int c=1;
    bool again=true;
    bool jkl=true;


    void clear_field(){
        for (int i=0; i<SIZE; i++){
            for (int j=0; j<SIZE; j++)
                arrField[i][j]=0;
            }
            x=0;

            c++;
            
    }


    void test_column(){
        bool skip=false;//skip clear_board, meaning no "2" are found in same column
        for (int i=0; i<SIZE; i++){
            if (arrField[x][i]!=2){ //if this happens, that means there is at leastr 1 free tile for queen to sit on in this column x
                skip=true;
                again=false;
                //break;
            }
        }
        if (skip==false){
            clear_field();
        }

    }

    void place_queen(){
        while (jkl==true){
            y=rand()%SIZE;
            if (arrField[x][y]==0){
                arrField[x][y]=1;
                jkl=false;
            }
        }
        jkl=true;

    }

    void place_attack(){
        int i=x;
        int j=y;
        while (i>=0 && i<SIZE-1 && j>=0 && j<=SIZE-1){
            arrField[i+1][j]=2;
            i++;
        }

        i=x;
        j=y;
        while (i>=0 && i<SIZE-1 && j>0 && j<=SIZE-1){
            arrField[i+1][j-1]=2;
            i++;
            j--;
        }

        i=x;
        j=y;
        while (i>=0 && i<SIZE-1 && j>=0 && j<SIZE-1){
            arrField[i+1][j+1]=2;
            i++;
            j++;
        }


    }




int main(){
    srand(time(0));

    for (int i=0; i<SIZE; i++){    
        for (int j=0; j<SIZE; j++){
            arrField[j][i]=0;
        }
        cout << endl;
    }


    while (x<SIZE){
        while (again==true){
        test_column();
        }
        again=true;

        place_queen();
        place_attack();
        x++;
    }


    cout << endl;


    for (int i=0; i<SIZE; i++){    
        for (int j=0; j<SIZE; j++){
            if (arrField[j][i]==0 || arrField[j][i]== 2)
                cout << "* ";
            if (arrField[j][i]==1)
                cout << "Q ";
        }
        cout << endl;
    }
    
    
    cout << endl << "PROGRAM SUCCEEDED AFTER " << c << " ATTEMPTS!" << endl;
    cout << "Hint: try changing \"const int SIZE=8\" to any other variable and run the program again (eg. const int SIZE=25)." << endl;



    return 0;
}




