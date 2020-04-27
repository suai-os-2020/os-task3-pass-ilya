#include "lab3.h"
#include <windows.h>

#include <string>
//
// lab3 code  located here!
//
#define MAX_SEM_COUNT 14

using namespace std;


//Threads 
HANDLE  aThread, 
        bThread, 
        cThread, 
        dThread, 
        eThread,  
        fThread, 
        gThread, 
        hThread, 
        iThread, 
        kThread, 
        mThread, 
        nThread, 
        pThread, 
        rThread;

//Mutex
HANDLE stdout_mutex;
DWORD IDThread;

//Semaphors
HANDLE sem_C, 
       sem_E, 
       sem_F, 
       sem_G, 
       sem_K, 
       sem_M, 
       sem_N, 
       sem_R, 
       time2, 
       time3, 
       time4;

unsigned int lab3_thread_graph_id() 
{
    return 20;
}

const char* lab3_unsynchronized_threads()
{
    return "bcf";
}

const char* lab3_sequential_threads()
{
    return "gkmn";
}



DWORD WINAPI a(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "a"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();

    }

    return 0;
}

DWORD WINAPI b(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "b"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}

DWORD WINAPI c(LPVOID pVoid)
{

    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "c"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(time2, 1, NULL);
    
        WaitForSingleObject(sem_C, INFINITE);
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "c"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
    

    return 0;
}


DWORD WINAPI d(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "d"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}



DWORD WINAPI e(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "e"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(time3, 1, NULL);
        
        WaitForSingleObject(sem_E, INFINITE);
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "e"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

        ReleaseSemaphore(time4, 1, NULL);

        WaitForSingleObject(sem_E, INFINITE);
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "e"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}


DWORD WINAPI f(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "f"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(time2, 1, NULL);
        
        WaitForSingleObject(sem_F, INFINITE);
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "f"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

        ReleaseSemaphore(time3, 1, NULL);

        WaitForSingleObject(sem_F, INFINITE);
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "f"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}


DWORD WINAPI g(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g" << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

        ReleaseSemaphore(time3, 1, NULL);

        WaitForSingleObject(sem_G, INFINITE);
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }
    
        ReleaseSemaphore(time4, 1, NULL);
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_G, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_M, 1, NULL);
    }
    
            //ReleaseSemaphore(time5, 1, NULL);
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_G, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_K, 1, NULL);
    }
    
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_G, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "g"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_N, 1, NULL);
    }
    
    
    
    return 0;
}

DWORD WINAPI h(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "h"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}

DWORD WINAPI i(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "i"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}


DWORD WINAPI k(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_K, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "k"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_M, 1, NULL);
    }

    return 0;
}

DWORD WINAPI m(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_M, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "m"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_N, 1, NULL);
    }
    
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_M, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "m"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_N, 1, NULL);
    }

    return 0;
}


DWORD WINAPI n(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_N, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "n"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_G, 1, NULL);
    }
    
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_N, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "n"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_G, 1, NULL);
    }
    
    
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(sem_N, INFINITE);
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "n"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
        ReleaseSemaphore(sem_G, 1, NULL);
    }

    return 0;
}

DWORD WINAPI p(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "p"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

    return 0;
}


DWORD WINAPI r(LPVOID pVoid)
{
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "r"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }

        ReleaseSemaphore(time4, 1, NULL);

        WaitForSingleObject(sem_R, INFINITE);
    for (int i = 0;i < 3;i++) {
        WaitForSingleObject(stdout_mutex, INFINITE);
        cout << "r"  << flush;
        ReleaseMutex(stdout_mutex);
        computation();
    }


    return 0;
}


int lab3_init()
{

    int inc = 14;

    stdout_mutex = CreateMutex(NULL, false, NULL);
    if (stdout_mutex == NULL)
        return GetLastError();

   
    sem_C = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_C == NULL)
        return GetLastError();
    
    sem_E = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_E == NULL)
        return GetLastError();
    
    sem_F = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_F == NULL)
        return GetLastError();
    
    sem_G = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_G == NULL)
        return GetLastError();
    
    sem_K = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_K == NULL)
        return GetLastError();
    
    sem_M = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_M == NULL)
        return GetLastError();
    
    sem_N = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_N == NULL)
        return GetLastError();
    
    sem_R = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (sem_R == NULL)
        return GetLastError();
    
    
    time2 = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (time2 == NULL)
        return GetLastError();
    time3 = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (time3 == NULL)
        return GetLastError();
    time4 = CreateSemaphore(NULL, 0, MAX_SEM_COUNT, NULL);
    if (time4 == NULL)
        return GetLastError();
    


    aThread = CreateThread(NULL, 0, (a), 0, 0, &IDThread);
    if (aThread == NULL)
        return GetLastError();

    WaitForSingleObject(aThread, INFINITE);

    
    bThread = CreateThread(NULL, 0,(b),0, 0, &IDThread);
    if (bThread == NULL)
        return GetLastError();    
    cThread = CreateThread(NULL, 0,(c),0, 0, &IDThread);
    if (cThread == NULL)
        return GetLastError();
    fThread = CreateThread(NULL, 0,(f),0, 0, &IDThread);
    if (fThread == NULL)
        return GetLastError();
    
    WaitForSingleObject(bThread, INFINITE);
    
    WaitForSingleObject(time2, INFINITE);    
    WaitForSingleObject(time2, INFINITE);    
    
    
    
    ReleaseSemaphore(sem_C, 1, NULL);
    ReleaseSemaphore(sem_F, 1, NULL);        
    
    dThread = CreateThread(NULL, 0,(d),0, 0, &IDThread);
    if (dThread == NULL)
        return GetLastError();
    eThread = CreateThread(NULL, 0,(e),0, 0, &IDThread);
    if (eThread == NULL)
        return GetLastError();
    gThread = CreateThread(NULL, 0,(g),0, 0, &IDThread);
    if (gThread == NULL)
        return GetLastError();

    WaitForSingleObject(cThread, INFINITE);
    WaitForSingleObject(dThread, INFINITE);    
    
    
    WaitForSingleObject(time3, INFINITE);    
    WaitForSingleObject(time3, INFINITE);    
    WaitForSingleObject(time3, INFINITE);
    
    
    ReleaseSemaphore(sem_E, 1, NULL);
    ReleaseSemaphore(sem_F, 1, NULL);
    ReleaseSemaphore(sem_G, 1, NULL);
    
    hThread = CreateThread(NULL, 0,(h),0, 0, &IDThread);
    if (hThread == NULL)
        return GetLastError();
    rThread = CreateThread(NULL, 0,(r),0, 0, &IDThread);
    if (rThread == NULL)
        return GetLastError();
    
    WaitForSingleObject(fThread, INFINITE);
    WaitForSingleObject(hThread, INFINITE);
    
    WaitForSingleObject(time4, INFINITE);    
    WaitForSingleObject(time4, INFINITE);    
    WaitForSingleObject(time4, INFINITE);    

    ReleaseSemaphore(sem_E, 1, NULL);
    ReleaseSemaphore(sem_G, 1, NULL);
    ReleaseSemaphore(sem_R, 1, NULL);

        
    iThread = CreateThread(NULL, 0,(i),0, 0, &IDThread);
    if (iThread == NULL)
        return GetLastError();
    mThread = CreateThread(NULL, 0,(m),0, 0, &IDThread);
    if (mThread == NULL)
        return GetLastError();
    nThread = CreateThread(NULL, 0,(n),0, 0, &IDThread);
    if (nThread == NULL)
        return GetLastError();

    
    WaitForSingleObject(iThread, INFINITE);
    WaitForSingleObject(rThread, INFINITE);
    WaitForSingleObject(eThread, INFINITE);
        
    
    kThread = CreateThread(NULL, 0,(k),0, 0, &IDThread);
    if (kThread == NULL)
        return GetLastError();

    WaitForSingleObject(kThread, INFINITE);
    WaitForSingleObject(mThread, INFINITE);    
    
    pThread = CreateThread(NULL, 0,(p),0, 0, &IDThread);
    if (pThread == NULL)
        return GetLastError();
        
    WaitForSingleObject(pThread, INFINITE);
    WaitForSingleObject(nThread, INFINITE);
    WaitForSingleObject(gThread, INFINITE);

    
    
   
    // закрываем дескриптор
    
    CloseHandle(sem_C);
    CloseHandle(sem_E);
    CloseHandle(sem_F);
    CloseHandle(sem_G);
    CloseHandle(sem_K);
    CloseHandle(sem_M);
    CloseHandle(sem_N);
    CloseHandle(sem_R);

    CloseHandle(time2);
    CloseHandle(time3);    
    CloseHandle(time4);    

    CloseHandle(aThread);
    CloseHandle(bThread);
    CloseHandle(cThread);
    CloseHandle(dThread);
    CloseHandle(eThread);
    CloseHandle(fThread);
    CloseHandle(gThread);
    CloseHandle(hThread);
    CloseHandle(iThread);
    CloseHandle(kThread);
    CloseHandle(mThread);
    CloseHandle(nThread);
    CloseHandle(pThread);
    CloseHandle(rThread);

    CloseHandle(stdout_mutex);

    return 0;
}






