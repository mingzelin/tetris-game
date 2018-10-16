

#include <string>
#include <stdlib.h>
#include <iostream>
#include "command.h"
#include "board.h"
#include <fstream>
#include <time.h>
using namespace std;


int main(int argc, char *argv[]) {
    
    string level0file="sequence.txt";
    int setlevel=0;
    bool graphics=true;
    int seed=1;
    for(int i=1;i<argc;i++){
        string cmdline=argv[i];
        if(cmdline=="-text"){
            graphics=false;
        }
        else if(cmdline=="-seed"){
            seed=atoi(argv[i+1]);
            i++;
            srand(seed);
        }
        else if(cmdline=="-scriptfile"){
            level0file = argv[i+1];
            i++;
        }
        else{
            setlevel=atoi(argv[i+1]);
            i++;
            
        }
    }
    
    //srand(time(NULL));
    //cin
    string cmd;
    //create a board
    Board b;
    Command c;
    int count=0;
    b.init(level0file,graphics);
    int endgame=1;
    cout<<b<<endl;
    bool testing= false;
    bool norand=false;
    ifstream myfile;
    string norandfilename;
    
    
    while(true){
        //read command
        if(testing==false){
            cin>>cmd;
            if(cin.eof()){
                break;
            }
        }
        else{
            //Get the command in the file
            myfile>>cmd;
            if(myfile.eof()){
                myfile.close();
                testing=false;
            }
        }
        //interpret command
        c.interpreter(cmd, count);
        //loop command
        if(cmd=="norandom"){
            cin>>norandfilename;
            if(b.getlevel()>=3){
                norand=true;
            }
        }
        else if(cmd=="random"){
            //restores level
            if(b.getlevel()>=3){
                norand=false;
            }
        }
        else if(cmd=="rename"){
            //finished
            string old;
            string n;
            cin>>old;
            cin>>n;
            c.interpreter(old, count);
            c.changeName(old,n);
        }
        else if(cmd=="sequence"){
            string file_name;
            //Get the file name
            cin>>file_name;
            myfile.open(file_name);
            testing=true;
            
        }
        else if(cmd=="I"){
            b.resetBlock('I',norand,norandfilename);
            //b.setBlock('I');
        }
        else if(cmd=="J"){
            b.resetBlock('J',norand,norandfilename);
            //b.setBlock('J');
        }
        else if(cmd=="L"){
            b.resetBlock('L',norand,norandfilename);
            //b.setBlock('L');
        }
        else if(cmd=="O"){
            b.resetBlock('O',norand,norandfilename);
            //b.setBlock('O');
        }
        else if(cmd=="S"){
            b.resetBlock('S',norand,norandfilename);
            //b.setBlock('S');
        }
        else if(cmd=="Z"){
            b.resetBlock('Z',norand,norandfilename);
            //b.setBlock('Z');
        }
        else if(cmd=="T"){
            b.resetBlock('T',norand,norandfilename);
            //b.setBlock('T');
        }
        else if(cmd=="hint"){
            b.hint();
        }
        else if(cmd=="restart"){
            b.init(level0file,graphics);
        }
        else if(cmd=="nomatch"){
            cout<<"no matching commands"<<endl;
        }
        else if(cmd=="mulmatch"){
            cout<<"multiple commands matching"<<endl;
        }
        else if(cmd=="left"){
            b.move(-1*count,0);
        }
        else if(cmd=="right"){
            //finished
            b.move(count,0);
        }
        else if(cmd=="down"){
            //finished
            b.move(count,1);
        }
        else{
            for(int i=0;i<count;i++){
                if(cmd=="clockwise"){
                    b.rotate(0);
                }
                else if(cmd=="counterclockwise"){
                    b.rotate(1);
                }
                else if(cmd=="drop"){
                    //setblock
                    endgame=b.drop();
                    if(endgame==0){
                        cout<<"You lost. See you next time~"<<endl;
                        return 0;
                    }
                    else{
                        endgame=b.setBlock('A',false,norand,norandfilename);
                        if(endgame==0){
                            cout<<b<<endl;
                            cout<<"Cannot Place Anymore. You lost. See you next time~"<<endl;
                            return 0;
                        }
                    }
                }
                else if(cmd=="levelup"){
                    //level up
                    b.levelUp();
                }
                else if(cmd=="leveldown"){
                    //level down
                    b.levelDown();
                }
            }
        }
        if(b.getlevel()>=3 && (cmd=="left"||cmd=="right"||cmd=="down"||cmd=="clockwise"||cmd=="counterclockwise"||cmd=="drop")){
            b.move(1, 1);
        }
        //set level from command line
        for(int i=0;i<setlevel;i++){
            b.levelUp();
        }
        cout<<b<<endl;
    }
    
    return 0;
}

