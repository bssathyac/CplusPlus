#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>

#define CHAR_ARR_SIZE 60 // 125 - 65
#define ASCII_CHAR_VAL_A 65 

void updateStrWithatoZ(string *str_ap_inStr)
{
    for(char ch = (char)ASCII_CHAR_VAL_A ; ch <= 122; ch++)
    {
        str_ap_inStr->push_back(ch);
    }
    cout << "STRING ADDRESS: " << str_ap_inStr << "\t" << "\n";
    cout << "STRING ACCESSED with *PTR: " << *str_ap_inStr << "\t" << "\n";
    cout << "STRING ACCESSED with (*PTR)[0]: " << (*str_ap_inStr)[0] << "\t" << "\n";
    cout << "STRING INDEXED with PTR same as above: " << str_ap_inStr << "\t" << "\n";
    for (int countLettrs = 0; countLettrs < str_ap_inStr->size(); countLettrs++) {
    cout << (*str_ap_inStr)[countLettrs]; // operator[] has higher precedence than operator*, 
    // so *str[0] is same as *(str[0]),  str[0] returns a std::string, and calling operator* on std::string doesn't make sense. 
    }
    cout << "\t \n";
}

char ch_chek_unique(string ap_str)
{
	int arr[CHAR_ARR_SIZE];
	char tc_ch, ret_char;
	ret_char = '\0';

    for(int k=0; k < (int)CHAR_ARR_SIZE; k++)
	{
        arr[k] = 0;
    }
	
    cout << "\nRECEIVED STRING passed byValue : ";
	for(int i=0; ap_str[i] != '\0'; i++)
	{
		tc_ch = ap_str[i];
		arr[tc_ch - ASCII_CHAR_VAL_A] = arr[tc_ch - ASCII_CHAR_VAL_A] + 1;
        cout << tc_ch << " ";
    }
	
	for(int j = (int)0; j < (int)CHAR_ARR_SIZE; j++)
	{
		if(arr[j] == 1)
		{ 
			ret_char = char(j + ASCII_CHAR_VAL_A); 
			break;
		}
	}
	
	return ret_char;
}

void checkStringPassByRef(string &str_ap_arg)
{
    str_ap_arg.append(" append to this string");

}

void checkStringArrIndexWithChar(void)
{
    string str_t_input;
    string myStr = "alternatively";
    char c;
    int arr[125];
    arr[122] = 212; //ascii of 'z' = 122
    cout << arr['z'] << "\n"; // this is to just try indexing with char
    updateStrWithatoZ(&str_t_input); // pass by address
    cout << "STRING DATA : " << str_t_input << "\n";
    cout << "STRING SIZE : " << str_t_input.size() << "\n";
    cout << "\nSTRING INDEXED with Global String var: \t ";
    for (int countLettrs = 0; countLettrs < str_t_input.size(); countLettrs++) {
    cout << str_t_input[countLettrs];}
    cout << "\n";
    cout << "INPUT STRING CHARS : \t ";
    for (auto lettrs : myStr) {
    cout << lettrs << " "; }
    c = ch_chek_unique(myStr); // pass by value
    cout << "\n";
    cout << "\n first unique char = " << c << "\n";
        cout << "\n";
    checkStringPassByRef(myStr); // pass by reference
    cout << "INPUT STRING Modified :\t" << myStr << "\n";


    int m,*n;
    m = 10;
    n = &m;
    cout << m << " " << n  << "\n";
    cout << &m << " " << *n  << "\n";
    *n = *n+2;
    *n = ++(*n);
      (*n)++;
    cout << m << " " << n  << "\n";
     *n =  (*n)++;
    cout << m << " " << n  << "\n";
    int &o = *n;
    o++;
    cout << m << " " << n ;
}