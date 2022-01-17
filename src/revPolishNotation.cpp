#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
#include <stack>
#include <queue>

void getStackQueueRPNlikeNotatn(string str_a_argStr)
{
    int i=0;
    string str_t_tmpstr, st_t_exprsnStr;
    stack<string> in_nos;
    queue<string> in_exprsn;
        str_t_tmpstr.clear();
        cout<< str_a_argStr << "\t";
    bool exitFlag = false;
    bool typeInt = false;
    bool dot = false;
    while(str_a_argStr[i] != '\0')
    {
        typeInt = false;

        while ( 
            (str_a_argStr[i] != ',') &&
            (str_a_argStr[i] != ' ') &&
            (exitFlag != true)
        )
        {
            str_t_tmpstr.push_back(str_a_argStr[i]);
            if(
            (str_a_argStr[i] >= '0') &&
            (str_a_argStr[i] <= '9')
            )
            { typeInt = true; }
            if (str_a_argStr[i] == '.') dot = true;
            i++;
            typeInt &= typeInt;
            dot += dot;
            if (str_a_argStr[i] == '\0')    exitFlag = true;
        }
        if (exitFlag != true)   i++;
        if (typeInt == true) {  in_nos.push(str_t_tmpstr);  }
        else {  in_exprsn.push(str_t_tmpstr);   }
        str_t_tmpstr.clear();
    }

    string num;
        cout<< "\t \n";
        cout << "\t Number StackSize " << in_nos.size() << "\n";

    // for( ; in_nos.size() > 0; ) 
    // { 
    //     num = in_nos.top();
    //     cout << num << "\t";
    //     in_nos.pop();
    // }

    cout<< "\t \n";
        cout << "\t Operation QueueSize " << in_exprsn.size() << "\n";

    // for( ; in_exprsn.size() > 0; ) 
    // { 
    //     num = in_exprsn.front();
    //     cout << num << "\t";
    //     in_exprsn.pop();
    // }
    
    string lfelips = "( ";
    string rtelips = " )";
    int elipsCount = 0;
    bool addOper = false;
    st_t_exprsnStr.clear();
    st_t_exprsnStr.append(lfelips);

    for( int i = 1 ; in_nos.size() > 0; i++ ) 
    {
        num = in_nos.top();
        st_t_exprsnStr.append(" ");
        st_t_exprsnStr.append(num);
        in_nos.pop();
        if (addOper == true) 
        {
            st_t_exprsnStr.append(" ");
            st_t_exprsnStr.append(rtelips);
            st_t_exprsnStr.append(" ");
        }
        if (in_exprsn.size() > 0)
        {
            num = in_exprsn.front();
            st_t_exprsnStr.append(" ");
            st_t_exprsnStr.append(num); 
            in_exprsn.pop();
            addOper = true;
            elipsCount++;
        }
        st_t_exprsnStr.append(" ");
        // st_t_exprsnStr.append(" ");
        // st_t_exprsnStr.append(in_nos.top()); in_nos.pop();
    }
    st_t_exprsnStr.append(rtelips);
   
    cout << "\n";
    for (int j = elipsCount; j > 0 ; j--)
    { cout << "("; }
    cout << st_t_exprsnStr << "\n";

}

void RevesePolishNotationExmp()
{
    string str_t_inputStr;
    cout << "Enter a string in reverse polish notation separated by a comma (,) \n";
    getline(cin, str_t_inputStr);
    // cin.getline (about_y, MAX_ABOUT_LEN, '$');    //$ is a delimiter
    cout << "The given input corresponds to RPN as follows : \n \t";
    getStackQueueRPNlikeNotatn(str_t_inputStr);
} 