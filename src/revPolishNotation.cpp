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
    cout << "The given input [ "<< str_a_argStr << " ] corresponds to RPN as follows : \n";
    bool exitFlag = false;
    bool typeInt = false;
    bool dot = false;

    while(str_a_argStr[i] != '\0')
    {
        typeInt = false;

        while ( // this loop is for fetching any floating point numbers present in the given str
            (str_a_argStr[i] != ',') &&
            (str_a_argStr[i] != ' ') &&
            (exitFlag != true)
        )
        {
            str_t_tmpstr.push_back(str_a_argStr[i]);
            if (
            (str_a_argStr[i] >= '0') &&
            (str_a_argStr[i] <= '9')
            )
            { typeInt = true; }

            if (str_a_argStr[i] == '.') dot = true;
            i++;
            typeInt &= typeInt;
            // dot += dot;
            if (str_a_argStr[i] == '\0')    exitFlag = true;
        }

        if (exitFlag != true)   i++;
        if (typeInt == true) {  in_nos.push(str_t_tmpstr);  }
        else {  in_exprsn.push(str_t_tmpstr);   }
        str_t_tmpstr.clear();
    }

    // for( ; in_nos.size() > 0; ) 
    // { 
    //     num = in_nos.top();
    //     cout << num << "\t";
    //     in_nos.pop();
    // }

    // for( ; in_exprsn.size() > 0; ) 
    // { 
    //     num = in_exprsn.front();
    //     cout << num << "\t";
    //     in_exprsn.pop();
    // }
    
    string num;
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

    cout<< "\n";
    cout << "[ Number StackSize " << in_nos.size();        
    cout << "\t Operation QueueSize " << in_exprsn.size() << "] \n";

}

void RevesePolishNotationExmp(void)
{
    string str_t_inputStr;
    cout << "\n Enter a string in reverse polish notation separated by a comma (,) \n";
    getchar();
    cin >> str_t_inputStr;
    // getline(cin, str_t_inputStr);
    // cin.getline (about_y, MAX_ABOUT_LEN, '$');    //$ is a delimiter
    getStackQueueRPNlikeNotatn(str_t_inputStr);
} 