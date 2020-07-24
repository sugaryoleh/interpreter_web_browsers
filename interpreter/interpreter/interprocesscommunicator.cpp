#include "interprocesscommunicator.h"


const wchar_t* InterProcessCommunicator::GetWC(const char* c)
{
    const size_t cSize = strlen(c) + 1;
    wchar_t* wc = new wchar_t[cSize];
    mbstowcs(wc, c, cSize);
    return wc;
}

int InterProcessCommunicator::init(const string& name)
{
    this->fmo = name;
    //cout << this->fmo << endl;
    LPCWSTR lpcwstr = (LPCWSTR)GetWC(this->fmo.c_str());
    //TCHAR _name[] = TEXT("Global\fmo");
    this->hMapFile = CreateFileMapping(
		INVALID_HANDLE_VALUE,    // use paging file
		NULL,                    // default security
		PAGE_READWRITE,          // read/write access
		0,                       // maximum object size (high-order DWORD)
		BUF_SIZE,                // maximum object size (low-order DWORD)
        lpcwstr);                 // name of mapping object
	if (hMapFile == NULL)
	{
		_tprintf(TEXT("Could not create file mapping object (%d).\n"),
			GetLastError());
		return 2;
	}
	this->pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,
		0,
		BUF_SIZE);
	if (pBuf == NULL)
	{
		_tprintf(TEXT("Could not map view of file (%d).\n"),
			GetLastError());

		CloseHandle(hMapFile);

		return 3;
	}if (hMapFile == NULL)
	{
		_tprintf(TEXT("Could not create file mapping object (%d).\n"),
			GetLastError());
		return 4;
	}
	pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
		FILE_MAP_ALL_ACCESS, // read/write permission
		0,
		0,
		BUF_SIZE);
	if (pBuf == NULL)
	{
		//_tprintf(TEXT("Could not map view of file (%d).\n"),
			//GetLastError());

		CloseHandle(hMapFile);
		throw("Could not map view of file");
		return 5;
	}
    return 1;
}

int InterProcessCommunicator::run(istream& stream)
{
    auto ptr = pBuf;
    CopyMemory((PVOID)pBuf, GetWC("10@"), 3 * sizeof(TCHAR));
    STARTUPINFO cif;
    ZeroMemory(&cif, sizeof(STARTUPINFO));
    PROCESS_INFORMATION pi;
    string cmd = "C:\\Users\\sugar\\source\\repos\\interpreter\\browser_manager\\bin\\Debug\\browser_manager.exe ";
    cmd += this->fmo;
    LPWSTR lpwstr = (LPWSTR)(GetWC(cmd.c_str()));

    string str;
    if (CreateProcess(NULL, lpwstr,
        NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE)
        {
        WebException::init();
        while (true) {
            cout << ">>\t";
            getline(stream, str);
            if (stream.eof()) break;
            if (str == "help")
            {
                help();
                continue;
            }
            else if (str == "exit")
            {
                TerminateProcess(pi.hProcess, NO_ERROR);	
                UnmapViewOfFile(pBuf);
                CloseHandle(hMapFile);
                break;
            }
            else
            {
                auto ptr = pBuf;
                ptr += 1;
                str = "10" + str + "@";
                CopyMemory((PVOID)pBuf, GetWC(str.c_str()), str.size() * sizeof(TCHAR));
                cout << "processing";
                int time = 0;
                while ((char)*(ptr) == '0')
                {
                    cout << '.';
                    Sleep(250);
                    time += 250;
                    if (time > 20000)
                    {
                        TerminateProcess(pi.hProcess, NO_ERROR);
                        UnmapViewOfFile(pBuf);
                        CloseHandle(hMapFile);
                        cout << "process stopped" << endl;
                    }
                }
                cout << endl;
                if (int((char)*(ptr)) == 1) continue;
                else
                {
                    WebException we(int((char)*(ptr)));
                    cout << we.what();
                }
                cout << endl; // TODO: implement returned codes
            }
        }
    }
    else
    {
        cout << "Cannot create process" << endl;
    }
    return 0;
}

int InterProcessCommunicator::run(const list<string>& stream)
{

    auto ptr = pBuf;
    CopyMemory((PVOID)pBuf, GetWC("10@"), 3 * sizeof(TCHAR));
    STARTUPINFO cif;
    ZeroMemory(&cif, sizeof(STARTUPINFO));
    PROCESS_INFORMATION pi;
    string cmd = "C:\\Users\\sugar\\source\\repos\\interpreter\\browser_manager\\bin\\Debug\\browser_manager.exe ";
    cmd += this->fmo;
    LPWSTR lpwstr = (LPWSTR)(GetWC(cmd.c_str()));
    string str;
    if (CreateProcess(NULL, lpwstr,
        NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE)
    {
     //   cout << "process handle " << pi.hProcess << endl;
        WebException::init();
        for (auto it = stream.begin(); it != stream.end(); it++)
        {
             if (*it == "help")
            {
                help();
                continue;
            }
            else
            {
                string str;
                auto ptr = pBuf;
                ptr += 1;
                str = "10" + *it+ "@";
                CopyMemory((PVOID)pBuf, GetWC(str.c_str()), str.size() * sizeof(TCHAR));
                cout << "processing";
                int time = 0;
                while ((char)*(ptr) == '0')
                {
                    cout << '.';
                    Sleep(250);
                    time += 250;
                    if (time > 20000)
                    {
                        TerminateProcess(pi.hProcess, NO_ERROR);	
                        UnmapViewOfFile(pBuf);
                        CloseHandle(hMapFile);
                        cout << "process stopped" << endl;
                    }
                }
                if (*it == "quit")
                {
                    TerminateProcess(pi.hProcess, NO_ERROR);	
                    UnmapViewOfFile(pBuf);
                    CloseHandle(hMapFile);
                    cout << "process stopped" <<endl;
                }
                cout << endl;

                if (int((char)*(ptr)) == 1) continue;
                else
                {
                    WebException we(int((char)*(ptr)));
                    cout << we.what();
                }
                cout << endl; // TODO: implement returned codes
                TerminateProcess(pi.hProcess, NO_ERROR);
                UnmapViewOfFile(pBuf);
                CloseHandle(hMapFile);
                cout << "process stopped" << endl;
            }
        }
    }
    else
    {
        cout << "Cannot create process" << endl;
    }
    return 0;
}

void InterProcessCommunicator::help()
{
    ifstream fin("manual.txt");
    string text, line;
    if (fin.is_open()) {
        while (getline(fin, line))
        {
            text += line + "\n";
        }
        fin.close();
        cout << text;
    }
    else cout << "no file manual.txt in current directory" << endl;
}