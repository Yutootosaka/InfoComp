#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <windows.h>
#include <Winsock2.h>
#include <Ws2tcpip.h>
#include <iphlpapi.h>
#include <lmcons.h>
#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "ws2_32.lib")

using namespace std;

class SysInfo
{

public:
    char hostname[MAX_COMPUTERNAME_LENGTH + 1];
    OSVERSIONINFOEX osvi;
    char buffer[UNLEN + 1];
    DWORD size = UNLEN + 1;
    SYSTEM_INFO sysInfo1;
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    char hostname1[256];

    void getHostname(ofstream &outfile)
    {

        if (outfile.is_open())
        {

            DWORD length1 = sizeof(hostname) / sizeof(*hostname);
            GetComputerName(hostname, &length1);

            puts("");

            outfile << " Host name              : " << hostname << endl
                    << endl;

            puts("");

            cout << ends << "Host name              :" << ends << "Successfully get Host Name" << endl
                 << endl;
        }
        else
        {

            puts("");

            cout << ends << "Host name              :" << ends << "Failed to get Host Name" << endl
                 << endl;
        }
    }

    void getOsName()
    {
        ZeroMemory(&osvi, sizeof(osvi));
        osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    }

    void registeredowner(ofstream &outfile)
    {

        GetUserName(buffer, &size);

        if (outfile.is_open())
        {

            outfile << " Registered Owner       : " << buffer << endl
                    << endl;
            outfile.close();

            cout << ends << "Registered Owner       :" << ends << "Successfully get registered Owner" << endl
                 << endl;
        }
        else
        {

            cout << ends << " Registered Owner       : Failed to get registered owner" << endl
                 << endl;
        }
    }

    void Processorarchitecture(ofstream &outfile)
    {

        if (outfile.is_open())
        {

            GetSystemInfo(&sysInfo1);

            outfile << ends << "Processor architecture : " << ends;

            cout << ends << "Processor architecture :" << ends << "Successfully get Processor architecture" << endl
                 << endl;

            switch (sysInfo1.wProcessorArchitecture)
            {

            case PROCESSOR_ARCHITECTURE_AMD64:

                outfile << "x64 (AMD or Intel)" << endl
                        << endl;

                break;

            case PROCESSOR_ARCHITECTURE_ARM:

                outfile << "ARM" << endl
                        << endl;

                break;

            case PROCESSOR_ARCHITECTURE_IA64:

                outfile << "Intel Itanium-based" << endl
                        << endl;

                break;

            case PROCESSOR_ARCHITECTURE_INTEL:

                outfile << "x86" << endl
                        << endl;

                break;

            case PROCESSOR_ARCHITECTURE_UNKNOWN:

                outfile << "Unknown architecture" << endl
                        << endl;

                break;

            default:

                outfile << "Unrecognized architecture" << endl
                        << endl;

                break;
            }
        }
        else
        {

            cout << ends << "Processor architecture :" << ends << "Failed to get Processor architecture" << endl
                 << endl;
        }
    }

    void ip4addres(ofstream &outfile)
    {

        if (outfile.is_open())
        {

            outfile << " IPv4 Address           : ";

            cout << ends << "IPv4 Address           :" << ends << "Successfully get IPv4 Address" << endl
                 << endl;

            struct hostent *host = gethostbyname(hostname1);
            struct in_addr **addr_list = (struct in_addr **)host->h_addr_list;

            for (int i = 0; addr_list[i] != NULL; i++)
            {

                outfile << inet_ntoa(*addr_list[i]) << ends;
            }

            WSACleanup();

            outfile << endl
                    << endl;
        }
        else
        {

            cout << ends << "IPv4 Address           :" << ends << "Failed to get IPv4 Address" << endl
                 << endl;
        }
    }
};

class GetOsName : public SysInfo
{
public:
    void checkOsVersion(ofstream &outfile)
    {

        if (GetVersionEx((LPOSVERSIONINFO)&osvi))
        {

            if (outfile.is_open())
            {

                outfile << " OS Name                :";
                cout << " Os Name                : Successfully get Os Name" << endl
                     << endl;

                switch (osvi.dwMajorVersion)
                {

                case 4:

                    outfile << " Windows 95/98/ME" << endl
                            << endl;

                    break;

                case 5:

                    if (osvi.dwMinorVersion == 0)
                    {

                        outfile << " Windows 2000" << endl
                                << endl;
                    }
                    else if (osvi.dwMinorVersion == 1)
                    {

                        outfile << " Windows XP" << endl
                                << endl;
                    }
                    else if (osvi.dwMinorVersion == 2)
                    {

                        if (osvi.wProductType == VER_NT_WORKSTATION)
                        {

                            outfile << " Windows XP Professional x64 Edition" << endl
                                    << endl;
                        }
                        else
                        {

                            outfile << " Windows Server 2003" << endl
                                    << endl;
                        }
                    }

                    break;

                case 6:

                    if (osvi.dwMinorVersion == 0)
                    {

                        if (osvi.wProductType == VER_NT_WORKSTATION)
                        {

                            outfile << " Windows Vista" << endl
                                    << endl;
                        }
                        else
                        {

                            outfile << " Windows Server 2008" << endl
                                    << endl;
                        }
                    }
                    else if (osvi.dwMinorVersion == 1)
                    {

                        if (osvi.wProductType == VER_NT_WORKSTATION)
                        {

                            outfile << " Windows 7" << endl
                                    << endl;
                        }
                        else
                        {

                            outfile << " Windows Server 2008 R2" << endl
                                    << endl;
                        }
                    }
                    else if (osvi.dwMinorVersion == 2)
                    {

                        if (osvi.wProductType == VER_NT_WORKSTATION)
                        {

                            outfile << " Windows 11" << endl
                                    << endl;
                        }
                    }
                    else if (osvi.dwMinorVersion == 3)
                    {

                        if (osvi.wProductType == VER_NT_WORKSTATION)
                        {

                            outfile << " Windows 8.1" << endl
                                    << endl;
                        }
                        else
                        {

                            outfile << " Windows Server 2012 R2" << endl
                                    << endl;
                        }
                    }
                    else if (osvi.dwMinorVersion == 4)
                    {

                        if (osvi.wProductType == VER_NT_WORKSTATION)
                        {

                            outfile << " Windows 10" << endl
                                    << endl;
                        }
                        else
                        {

                            outfile << "Windows Server 2016" << endl;
                        }
                    }
                    else if (osvi.dwMinorVersion == 5)
                    {

                        if (osvi.wProductType == VER_NT_WORKSTATION)
                        {

                            outfile << " Windows 8" << endl
                                    << endl;
                        }
                        else
                        {

                            outfile << " Windows Server 2012" << endl
                                    << endl;
                        }
                    }

                    break;

                default:

                    outfile << " Cannot Detect" << endl;

                    break;
                }
            }
            else if (osvi.dwMinorVersion == 5)
            {

                if (osvi.wProductType == VER_NT_WORKSTATION)
                {

                    outfile << ends << " Windows 11" << endl
                            << endl;
                }
                else
                {

                    outfile << ends << " Windows Server Unknown Version" << endl
                            << endl;
                }
            }
            else
            {

                cout << " Os Name                : failed to get Os Name" << endl
                     << endl;
            }
        }
    }
};

class GetSystemModel : public SysInfo
{

public:
    HKEY hKey1;
    LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_READ, &hKey1);
    char product_name[1024];
    DWORD product_name_size = sizeof(product_name);

    void systemModel(ofstream &outfile)
    {

        if (outfile.is_open())
        {

            outfile << ends << "System Model           :" << ends;

            result = RegQueryValueEx(hKey1, "ProductName", 0, NULL, (LPBYTE)&product_name, &product_name_size);

            outfile << product_name << endl
                    << endl;

            RegCloseKey(hKey1);

            cout << ends << "System Model           :" << ends << "Successfully get System Model" << endl
                 << endl;
        }
        else
        {

            cout << ends << "System Model              :" << ends << "Failed to get System Model" << endl
                 << endl;
        }
    }
};

int main()
{

    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    SYSTEM_INFO sysInfo1;
    GetSystemInfo(&sysInfo1);
    ofstream outfile;
    outfile.open("Info.txt");

    outfile << endl;
    outfile << " SYSTEM INFORMATION" << endl
            << " ==================" << endl
            << endl;

    SysInfo OutputHostname;
    GetOsName OutputOsName;
    SysInfo Outputregisteredowner;
    GetSystemModel OutputSystemmodel;
    SysInfo OutputProcessorarchitecture;
    SysInfo Outputip4addres;
    OutputOsName.getOsName();

    OutputHostname.getHostname(outfile);
    OutputOsName.checkOsVersion(outfile);
    OutputSystemmodel.systemModel(outfile);
    OutputProcessorarchitecture.Processorarchitecture(outfile);
    Outputip4addres.ip4addres(outfile);
    Outputregisteredowner.registeredowner(outfile);

    puts("");
    puts("");

    cout << ends << "Enter to exit..." << ends;

    system("pause>null");

    return 0;
}