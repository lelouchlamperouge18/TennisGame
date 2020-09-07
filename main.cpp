#include <iostream>
#include <fstream>

using namespace std;
int k = -1;
string a[100]={};
void readFile()
{
    ifstream inFile;
    inFile.open("tennis.txt");
    if (inFile.fail()) {
        cout << "Error!" << endl;
        inFile.close();
    }
    string line;
    while (getline(inFile, line))
    {
        k++;
        a[k] = line;
    }
    inFile.close();
}
int main(){
    readFile();
    string m("0");
    string n("0");
    string result = "Game Start";
    cout << result << endl;
    for (int i=0;i<=k;i++){
        if (a[i]=="1" && m=="0") m = "15"; else
        if (a[i]=="1" && m=="15") m = "30"; else
        if (a[i]=="1" && m=="30" && n!="40") m = "40"; else
        if (a[i]=="1" && ((m=="30" && n=="40")||n=="Advantage Player 2")) {
                m = "Deuce"; n = "Deuce";
        }
        else
        if (a[i]=="1" && m=="Deuce") m = "Advantage Player 1"; else
        //if (a[i]=="1" && (m=="Advantage Player 1"||m=="40")) m = "Game Player 2";
        if (a[i]=="1" && (m=="Advantage Player 1"||(m=="40"&&(n=="0"||n=="15"||n=="30")))) m = "Game Player 1";
        //--------------------------------
        if (a[i]=="2" && n=="0") n = "15"; else
        if (a[i]=="2" && n=="15") n = "30"; else
        if (a[i]=="2" && n=="30" && m!="40") n = "40"; else
        if (a[i]=="2" && ((n=="30" && m=="40")||m=="Advantage Player 1")) {
                m = "Deuce"; n = "Deuce";
        }
        else
        if (a[i]=="2" && n=="Deuce") n = "Advantage Player 2"; else
        //if (a[i]=="2" && (n=="Advantage Player 2"||n=="40")) n = "Game Player 2";
        if (a[i]=="2" && (n=="Advantage Player 2"||(n=="40"&&(m=="0"||m=="15"||m=="30")))) n = "Game Player 2";
        //--------------------------------
        if (m=="Game Player 1") result = "Game Player 1"; else
        if (n=="Game Player 2") result = "Game Player 2"; else
        if (m=="Advantage Player 1") result = "Advantage Player 1"; else
        if (n=="Advantage Player 2") result = "Advantage Player 2"; else
        if (m=="Deuce"||n=="Deuce"||(m=="40"&&n=="40")) result = "Deuce"; else
        if (m=="0") result = "love-" + n; else
        if (n=="0") result = m + "-love"; else
        if (m==n) result = m + "-all"; else
        if (m!=n) result = m + "-" + n;
        //
        cout << result << endl;
        if ((result=="Game Player 1"||result=="Game Player 2")&&i<=k){
            result = "Game Start";
            m="0";
            n="0";
            if (i<k) cout << result << endl;;
        }
    }
    return 0;
}





