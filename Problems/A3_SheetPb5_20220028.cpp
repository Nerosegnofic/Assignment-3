#include <bits/stdc++.h>
#include <windows.h>
#include <psapi.h>
using namespace std;

class Process {
    string name;
    int PID , mem_usage;
public:
    Process();
    Process(string n , int P , int m);
    void setName(string n);
    void setPID(int id);
    void setMemUsage(int m);
    string getName();
    int getPID();
    int getMemUsage();
    void print();
};

class ProcessList {
    vector<Process>List_of_prcesses;
public:
    void add_new_process(string n , int pid , int m);
    void add_new_process(Process p);
    void sort_by_name();
    void sort_by_PID();
    void sort_by_memUsage();
    void showProcesses();
    void get_from_OS();
};

void Process::setName(string n) {
    name = n;
}

void Process::setPID(int id) {
    PID = id;
}

void Process::setMemUsage(int m) {
    mem_usage = m;
}

string Process::getName() {
    return name;
}

int Process::getPID() {
    return PID;
}

int Process::getMemUsage() {
    return mem_usage;
}

Process::Process() {

}

Process::Process(string n, int p, int m):name(n) , PID(p) , mem_usage(m) {

}

void Process::print() {
    if(name.empty())
        name = "Unknown";
    cout<<"Name: "<<name<<'\n'<<"Process ID: "<<PID<<'\n'<<"Memory used: "<<mem_usage<<"\n\n";
}

void ProcessList::add_new_process(string n, int pid, int m) {
    Process p(n , pid , m);
    List_of_prcesses.emplace_back(p);
}

void ProcessList::add_new_process(Process p) {
    List_of_prcesses.emplace_back(p);
}

void ProcessList::sort_by_name() {
    sort(List_of_prcesses.begin() , List_of_prcesses.end() ,
         [](Process p1 , Process p2){
             return p1.getName() < p2.getName();
         });
}

void ProcessList::sort_by_PID() {
    sort(List_of_prcesses.begin() , List_of_prcesses.end() ,
         [](Process p1 , Process p2){
             return p1.getPID() < p2.getPID();
         });
}

void ProcessList::sort_by_memUsage() {
    sort(List_of_prcesses.begin() , List_of_prcesses.end() ,
         [](Process p1 , Process p2){
             return p1.getMemUsage() < p2.getMemUsage();
         });
}

void ProcessList::showProcesses() {
    for(auto& p : List_of_prcesses)
        p.print();

}

void ProcessList::get_from_OS() {
    List_of_prcesses.clear();
    DWORD processID[1 << 10] , bytes_cnt{};
    if(EnumProcesses(processID , sizeof(processID) , &bytes_cnt))
    {
        // if(successfully got)
        DWORD num_of_prcesses = bytes_cnt / sizeof(DWORD);
        for(DWORD i{} ; i < num_of_prcesses ; ++i)
        {
            HANDLE processHandle = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID[i]);
            // querying info and reading it
            if(processHandle != nullptr)
            {
                // if opened successfully
                wchar_t processName[MAX_PATH] = L"";
                GetModuleBaseName(processHandle, nullptr, reinterpret_cast<LPSTR>(processName), sizeof(processName) / sizeof(wchar_t));
                // Name
                PROCESS_MEMORY_COUNTERS_EX pmc;
                // memory Usage

                if (GetProcessMemoryInfo(processHandle, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc)))
                {
                    // memUsage in KB
                    int memUsage = (pmc.PrivateUsage >> 10);
                    string n = "";

                    for(auto c : processName)
                        if(isalpha(c))  n += c;

                    add_new_process(n, processID[i], memUsage);
                }
                CloseHandle(processHandle);
            }
        }
    }
}

int main() {
    Process p1("ca" , 96 , 8) , p2;
    ProcessList p;
    p2.setMemUsage(4);
    p2.setName("bb");
    p2.setPID(323);
    p.add_new_process(p1);
    p.add_new_process(p2);
    p.add_new_process("aa" , 2 , 16);
    p.sort_by_PID();
    p.showProcesses();
    p.sort_by_memUsage();
    p.showProcesses();
    p.sort_by_name();
    p.showProcesses();
    p.get_from_OS();
    p.showProcesses();
}

