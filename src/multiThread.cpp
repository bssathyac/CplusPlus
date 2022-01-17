
// // CPP program to demonstrate multithreading
// // using three different callables.
#include <thread>
#include <process.h>
#include <windows.h>
#include <D:\TrialProjects\VSCode\InitCPP\header\commonHeaders.h>
#include "D:\TrialProjects\VSCode\InitCPP\header\cppFileHeaders.h"


int a[ 5 ];
int cnt = 100;

void Thread( void* pParams )
{ int i, num = 0;

//   while ( cnt > 0 )
//   {
//      for ( i = 0; i < 5; i++ ) a[ i ] = num;
//      num++;
//   }
  linkedListsFunction();
}



int noSync( void )
{
   _beginthread( Thread, 0, NULL );
    printf("Case 1 :::===>>> No synchronisation among the threads ");
   while( cnt > 0 )
   {
      printf("%d %d %d %d %d\n",
             a[ 0 ], a[ 1 ], a[ 2 ],
             a[ 3 ], a[ 4 ] );
    cnt--;
   }

 return 0;
}

int cnt2 = 100;
CRITICAL_SECTION cs;

void Thread2( void* pParams )
{
  int i, num = 0;

  while ( cnt2 > 0 )
  {
     EnterCriticalSection( &cs );
     for ( i = 0; i < 5; i++ ) a[ i ] = num;
     LeaveCriticalSection( &cs );
     num++;
  }
}

int criticalSection( void )
{
  InitializeCriticalSection( &cs );
  _beginthread( Thread2, 0, NULL );
    printf("Case 2 :::===>>> critical section ");

  while( cnt2 > 0 )
  {
     EnterCriticalSection( &cs );
     printf( "%d %d %d %d %d\n",
             a[ 0 ], a[ 1 ], a[ 2 ],
             a[ 3 ], a[ 4 ] );
     LeaveCriticalSection( &cs );
     cnt2--;
  }
  return 0;
}

HANDLE hMutex;
int cnt3 = 100;

void Thread3( void* pParams )
{
   int i, num = 0;

   while ( cnt3 > 0 )
   {
      WaitForSingleObject( hMutex, INFINITE );
      for ( i = 0; i < 5; i++ ) a[ i ] = num;
      ReleaseMutex( hMutex );
      num++;
   }
}

int mutexUsage( void )
{
   hMutex = CreateMutex( NULL, FALSE, NULL );
   _beginthread( Thread3, 0, NULL );
    printf("Case 3 :::===>>> Mutex usage ");

   while( cnt3 > 0 )

   {
      WaitForSingleObject( hMutex, INFINITE );
      printf( "%d %d %d %d %d\n",
              a[ 0 ], a[ 1 ], a[ 2 ],
              a[ 3 ], a[ 4 ] );
      ReleaseMutex( hMutex );
      cnt3--;
   }
   return 0;
}

HANDLE hEvent1, hEvent2;
int cnt4 = 100;

void Thread4( void* pParams )
{
   int i, num = 0;

   while ( cnt4 > 0 )
   {
      WaitForSingleObject( hEvent2, INFINITE );
      for ( i = 0; i < 5; i++ ) a[ i ] = num;
      SetEvent( hEvent1 );
      num++;
   }
}

int eventUsage( void )
{
   hEvent1 = CreateEvent( NULL, FALSE, TRUE, NULL );
   hEvent2 = CreateEvent( NULL, FALSE, FALSE, NULL );

   _beginthread( Thread4, 0, NULL );
    printf("Case 4 :::===>>> Event usage ");

   while( cnt4 > 0 )
   {
      WaitForSingleObject( hEvent1, INFINITE );
      printf( "%d %d %d %d %d\n",
              a[ 0 ], a[ 1 ], a[ 2 ],
              a[ 3 ], a[ 4 ] );
      SetEvent( hEvent2 );
      cnt4--;
   }
   return 0;
}

DWORD WINAPI Thread5(LPVOID lpParameter)
{
	unsigned int& myCounter = *((unsigned int*)lpParameter);
	while(myCounter < 0xFFFFFFFF) ++myCounter;
	return 0;
}

int GetCountAtQkeyPress()
{
	using namespace std;

	unsigned int myCounter = 0;
	DWORD myThreadID;
	HANDLE myHandle = CreateThread(0, 0, Thread5, &myCounter, 0, &myThreadID);
	char myChar = ' ';
	while(myChar != 'q') {
		cout << myCounter << endl;
		myChar = getchar();
	}
	
	CloseHandle(myHandle);
	return 0;
}

int threadRun( void )
{
   //   noSync();
   //  criticalSection();
   //  mutexUsage();
   //  eventUsage();
   GetCountAtQkeyPress();
    return 0;
}


// A dummy function
// void foo(int Z)
// {
// 	for (int i = 0; i < Z; i++) {
// 		cout << "Thread using function"
// 			" pointer as callable\n";
// 	}
// }

// // A callable object
// class thread_obj {
// public:
// 	void operator()(int x)
// 	{
// 		for (int i = 0; i < x; i++)
// 			cout << "Thread using function"
// 				" object as callable\n";
// 	}
// };

// int multiThreadFunc()
// {
// 	cout << "Threads 1 and 2 and 3 "
// 		"operating independently" << endl;

// 	// This thread is launched by using
// 	// function pointer as callable
// 	std::thread th1(foo, 3);

// 	// This thread is launched by using
// 	// function object as callable
// 	thread th2(thread_obj(), 3);

// 	// Define a Lambda Expression
// 	auto f = [](int x) {
// 		for (int i = 0; i < x; i++)
// 			cout << "Thread using lambda"
// 			" expression as callable\n";
// 	};

// 	// This thread is launched by using
// 	// lamda expression as callable
// 	thread th3(f, 3);

// 	// Wait for the threads to finish
// 	// Wait for thread t1 to finish
// 	th1.join();

// 	// Wait for thread t2 to finish
// 	th2.join();

// 	// Wait for thread t3 to finish
// 	th3.join();

// 	return 0;
// }
// ************************************************************************************************//
// MFCMultithreadingDlg.cpp : implementation file
//

// #include "stdafx.h"
// #include "MFCMultithreading.h"
// #include "MFCMultithreadingDlg.h"
// #include "afxdialogex.h"

// #ifdef _DEBUG
// #define new DEBUG_NEW
// #endif

// // CMFCMultithreadingDlg dialog

// int currValue;
// int maxValue;
// BOOL stopNow;

// CMFCMultithreadingDlg::CMFCMultithreadingDlg(CWnd* pParent /* = NULL*/)
//    : CDialogEx(IDD_MFCMULTITHREADING_DIALOG, pParent) {
//    m_hIcon = AfxGetApp() -> LoadIcon(IDR_MAINFRAME);
// }
// void CMFCMultithreadingDlg::DoDataExchange(CDataExchange* pDX) {
//    CDialogEx::DoDataExchange(pDX);
//    DDX_Control(pDX, IDC_STATIC_TEXT, m_ctrlStatus);
// }

// BEGIN_MESSAGE_MAP(CMFCMultithreadingDlg, CDialogEx)
//    ON_WM_PAINT()
//    ON_WM_QUERYDRAGICON()
//    ON_BN_CLICKED(IDC_BUTTON_START,
//       &CMFCMultithreadingDlg::OnBnClickedButtonStart)
//    ON_WM_TIMER()
//    ON_BN_CLICKED(IDC_BUTTON_STOP,
//       &CMFCMultithreadingDlg::OnBnClickedButtonStop)
// END_MESSAGE_MAP()

// // CMFCMultithreadingDlg message handlers

// BOOL CMFCMultithreadingDlg::OnInitDialog() {
//    CDialogEx::OnInitDialog();

//    // Set the icon for this dialog. The framework does this automatically
//    // when the application's main window is not a dialog
//    SetIcon(m_hIcon, TRUE);        // Set big icon
//    SetIcon(m_hIcon, FALSE);       // Set small icon

//    // TODO: Add extra initialization here

//    return TRUE; // return TRUE unless you set the focus to a control
// }

// // If you add a minimize button to your dialog, you will need the code below
// // to draw the icon. For MFC applications using the document/view model,
// // this is automatically done for you by the framework.

// void CMFCMultithreadingDlg::OnPaint() {
//    if (IsIconic()) {
//       CPaintDC dc(this); // device context for painting
//       SendMessage(WM_ICONERASEBKGND,
//          reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
			
//       // Center icon in client rectangle
//       int cxIcon = GetSystemMetrics(SM_CXICON);
//       int cyIcon = GetSystemMetrics(SM_CYICON);
//       CRect rect;
//       GetClientRect(&rect);
//       int x = (rect.Width() - cxIcon + 1) / 2;
//       int y = (rect.Height() - cyIcon + 1) / 2;

//       // Draw the icon
//       dc.DrawIcon(x, y, m_hIcon);
//    }else {
//       CDialogEx::OnPaint();
//    }
// }
// // The system calls this function to obtain the cursor to display while the user drags
// // the minimized window.
// HCURSOR CMFCMultithreadingDlg::OnQueryDragIcon() {
//    return static_cast<HCURSOR>(m_hIcon);
// }

// UINT /*CThreadDlg::*/MyThreadProc(LPVOID Param) //Sample function for using in
// AfxBeginThread {
//    while (!stopNow && (currValue < maxValue)) {
//       currValue++;
//       Sleep(50); // would do some work here
//    }
//    return TRUE;
// }
// void CMFCMultithreadingDlg::OnBnClickedButtonStart() {
//    // TODO: Add your control notification handler code here
//    currValue = 0;
//    maxValue = 5000;
//    stopNow = 0;
//    m_ctrlStatus.SetWindowText(L"Starting...");
//    SetTimer(1234, 333, 0); // 3 times per second

//    AfxBeginThread(MyThreadProc, 0); // <<== START THE THREAD
// }

// void CMFCMultithreadingDlg::OnTimer(UINT_PTR nIDEvent) {
//    // TODO: Add your message handler code here and/or call default
//    CString sStatusMsg;
//    sStatusMsg.Format(L"Running: %d", currValue);
//    m_ctrlStatus.SetWindowText(sStatusMsg);

//    CDialogEx::OnTimer(nIDEvent);
// }

// void CMFCMultithreadingDlg::OnBnClickedButtonStop() {
//    // TODO: Add your control notification handler code here
//    stopNow = TRUE;
//    KillTimer(1234);
//    m_ctrlStatus.SetWindowText(L"Stopped");
// }

// // // ******************************************************************************************//
// #include <iostream>
// #include <cstdlib>
// #include <pthread.h>

// using namespace std;

// #define NUM_THREADS 5

// void *Printmsg(void *thread_id)
// {
//   long t_id;
//   t_id = (long)thread_id;
//   cout << "I am a thread and my Thread ID is: " << t_id << endl;
//   pthread_exit(NULL);
// }

// int main()
// {
//   pthread_t threads[NUM_THREADS];
//   int k;
//   int i;

//   for (i = 0; i < NUM_THREADS; i++)
//   {
//     cout << "main() : creating thread, " << i << endl;
//     k = pthread_create(&threads[i], NULL, Printmsg, (void *)i);

//     if (k)
//     {
//       cout << "Error:unable to create thread," << k << endl;
//       exit(-1);
//     }
//   }
//   pthread_exit(NULL);
// }

// // *****************************************************************************
// // C program to show thread functions

// #include <pthread.h>
// #include <stdio.h>
// #include <stdlib.h>

// void* func(void* arg)
// {
// 	// detach the current thread
// 	// from the calling thread
// 	pthread_detach(pthread_self());

// 	printf("Inside the thread\n");

// 	// exit the current thread
// 	pthread_exit(NULL);
// }

// void fun()
// {
// 	pthread_t ptid;

// 	// Creating a new thread
// 	pthread_create(&ptid, NULL, &func, NULL);
// 	printf("This line may be printed"
// 		" before thread terminates\n");

// 	// The following line terminates
// 	// the thread manually
// 	// pthread_cancel(ptid);

// 	// Compare the two threads created
// 	if(pthread_equal(ptid, pthread_self())
// 		printf("Threads are equal\n");
// 	else
// 		printf("Threads are not equal\n");

// 	// Waiting for the created thread to terminate
// 	pthread_join(ptid, NULL);

// 	printf("This line will be printed"
// 		" after thread ends\n");

// 	pthread_exit(NULL);
// }

// // Driver code
// int multiThreadFunc()
// {
// 	fun();
// 	return 0;
// }
