/*
Name       : Osaid Hasan Nur
ID         : 1210733
Section    : 4
Instructor : Dr.Bashar Tahayna
*/

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

using namespace std;

// this flag will be raised if there is an error in any file
bool error;

// read the three files that contains informations about processes
void readFiles(vector<pair<string, vector<int>>> &request, vector<pair<string, vector<int>>> &alloc, vector<int> &available)
{
    // Create the files and Open it
    ifstream AllocationF ("Allocation.csv");
    ifstream RequestF ("Request.csv");
    ifstream AvailableF ("Available.csv");

    // ifstream AllocationF("C:/Users/SS/Documents/VS Code/OS2/Allocation.csv");
    // ifstream RequestF("C:/Users/SS/Documents/VS Code/OS2/Request.csv");
    // ifstream AvailableF("C:/Users/SS/Documents/VS Code/OS2/Available.csv");

    //*************************************************************************************************
    // read the contents of the Request file
    if (RequestF.is_open())
    {
        string line;
        // read the first line and discard it , because it contains unnecessary informations
        getline(RequestF, line);

        // read the rest of lines , and store it into "line"
        while (getline(RequestF, line))
        {
            // Create a stringstream from the line to make some operations on it
            stringstream ss(line);
            string firstField, restOfLine;

            // read the first field separately and store it into a string varriable called firstField
            getline(ss, firstField, ',');

            // read the rest of the line and store it into a string varriable called restOfLine
            getline(ss, restOfLine);

            // delete the commas and spaces if they exists in the beginning of the string
            while (restOfLine.front() == ',' || restOfLine.front() == ' ')
            {
                restOfLine.erase(0, 1);
            }

            // split the string using a stringstream
            stringstream sss(restOfLine);
            int num;

            // this vector to store all numbers separated by a comma
            vector<int> numbers;

            // extract the pure numbers from the string (without commas)
            while (sss >> num)
            {
                if (sss.peek() == ',' || sss.peek() == ' ')
                {
                    sss.ignore();
                }
                numbers.push_back(num);
            }

            // store the final informations and push it into the request vector
            request.push_back({firstField, numbers});
        }

        // close the file
        RequestF.close();
    }
    else
    {
        cout << "Error opening request file !" << endl;
    }
    //*************************************************************************************************
    // read the contents of the Allocation file
    if (AllocationF.is_open())
    {
        string line;
        // read the first line and discard it , because it contains unnecessary informations
        getline(AllocationF, line);

        // read the rest of lines , and store it into "line"
        while (getline(AllocationF, line))
        {
            // Create a stringstream from the line to make some operations on it
            stringstream ss(line);
            string firstField, restOfLine;

            // read the first field separately and store it into a string varriable called firstField
            getline(ss, firstField, ',');

            // read the rest of the line and store it into a string varriable called restOfLine
            getline(ss, restOfLine);

            // delete the commas and spaces if they exists in the beginning of the string
            while (restOfLine.front() == ',' || restOfLine.front() == ' ')
            {
                restOfLine.erase(0, 1);
            }

            // split the string using a stringstream
            stringstream sss(restOfLine);
            int num;

            // this vector to store all numbers separated by a comma
            vector<int> numbers;

            // extract the pure numbers from the string (without commas)
            while (sss >> num)
            {
                if (sss.peek() == ',' || sss.peek() == ' ')
                {
                    sss.ignore();
                }
                numbers.push_back(num);
            }

            // store the final informations and push it into the allocation vector
            alloc.push_back({firstField, numbers});
        }
        // close the file
        AllocationF.close();
    }
    else
    {
        cout << "Error opening Allocation file !" << endl;
    }

    //*************************************************************************************************
    // read the contents of the Available file
    if (AvailableF.is_open())
    {
        string line;
        // read the first line and discard it , because it contains unnecessary informations
        getline(AvailableF, line);

        // read the second and final line , which contains the important informations
        getline(AvailableF, line);

        // delete the commas and spaces if they exists in the beginning of the string
        while (line.front() == ',' || line.front() == ' ')
        {
            line.erase(0, 1);
        }

        // split the string using a stringstream
        stringstream sss(line);
        int num;

        // this vector to store all numbers separated by a comma
        vector<int> numbers;

        // extract the pure numbers from the string (without commas)
        while (sss >> num)
        {
            if (sss.peek() == ',' || sss.peek() == ' ')
            {
                sss.ignore();
            }
            numbers.push_back(num);
        }

        // store all numbers in the vector called "available"
        available = numbers;

        // close the file
        AvailableF.close();
    }
    else
    {
        cout << "Error opening Available file !" << endl;
    }
}

// compare two vectors and check if vector a less than b
bool lessThan(vector<int> &a, vector<int> &b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] > b[i])
            return 0;
    }
    return 1;
}

// Check the validity of the vectors and informations
bool checkInfo(vector<pair<string, vector<int>>> &request, vector<pair<string, vector<int>>> &alloc, vector<int> &available)
{
    // Test #1 > check if the number of resources in all files is the same
    int m = 0;
    // check the # of resources in "allocation" vector
    if (!alloc.empty())
        m = alloc[0].second.size();

    // check the # of resources in "request" vector
    if (!request.empty())
        if (request[0].second.size() != m)
        {
            cout << "ERROR in the number of resources in request file !" << endl;
            return 0;
        }

    // check the # of resources in "available" string
    if (available.size() != m)
    {
        cout << "ERROR in the number of resources in available file !" << endl;
        return 0;
    }

    // Test #2 > check if the number of resources is equal for all processes in each file

    // Test the request vector
    for (int i = 0; i < request.size() - 1; i++)
    {
        if (request[i].second.size() != request[i + 1].second.size())
        {
            cout << "The number of resources in the request file is different in some processes !" << endl;
            return 0;
        }
    }

    // Test the allocation vector
    for (int i = 0; i < alloc.size() - 1; i++)
    {
        if (alloc[i].second.size() != alloc[i + 1].second.size())
        {
            cout << "The number of resources in the allocation file is different in some processes !" << endl;
            return 0;
        }
    }

    // Test #3 > check if the number of processes(allocation) is equal to the number of requests
    if (request.size() != alloc.size())
    {
        cout << "The number of processes and requests is not the same !" << endl;
        return 0;
    }

    return 1;
}

// collect the Resources from the process after it finished execution
void addResources(vector<int> &available, vector<int> &finished)
{
    for (int i = 0; i < available.size(); i++)
    {
        available[i] += finished[i];
    }
}

// print the result of the system (if it's deadlocked or not ,with details)
void printResults(bool finished[], vector<string> &safeSeq, vector<pair<string, vector<int>>> &request)
{
    int deadlock = 0;
    vector<string> deadLocked;
    for (int i = 0; i < request.size(); i++)
    {
        if (finished[i] == false)
        {
            deadLocked.push_back(request[i].first);
            deadlock++;
        }
    }

    if (deadlock == 0 && safeSeq.size() != 0)
    {
        cout << "No Deadlock occured ...\n"
             << "Safe Sequence >> ";
        for (int i = 0; i < safeSeq.size(); i++)
        {
            if(i==safeSeq.size()-1)cout << safeSeq[i] ;
            else cout << safeSeq[i] << " - ";
        }
        cout << endl;
    }
    else if (deadlock != 0 && safeSeq.size() != 0)
    {
        cout << "Deadlock occured !!!\n";
        cout << "Deadlocked Processes >> ";
        for (int i = 0; i < deadLocked.size(); i++)
        {
            if(i==deadLocked.size()-1) cout << deadLocked[i] ;
            else cout << deadLocked[i] << " - ";
        }
        cout << "\nSafe Sequence >> ";
        for (int i = 0; i < safeSeq.size(); i++)
        {
            if(i==safeSeq.size()-1)cout << safeSeq[i] ;
            else cout << safeSeq[i] << " - ";
        }
    }
    else
    {
        cout << "The whole System is Deadlocked !!!!!\n";
        cout << "Deadlocked Processes >> ";
        for (int i = 0; i < deadLocked.size(); i++)
        {
            if(i==deadLocked.size()-1) cout << deadLocked[i] ;
            else cout << deadLocked[i] << " - ";
        }
    }
}

// Detection Algorithm
void detectionAlgorithm(vector<pair<string, vector<int>>> &request, vector<pair<string, vector<int>>> &alloc, vector<int> &available, bool finished[], vector<string> &safeSeq)
{
    // the first and most important thing to do , is to check the validity of the data read
    // from the file . If it's true, it will continue . and if not , it will display
    // the error message and terminates the program
    if (checkInfo(request, alloc, available))
    {
        // it will still checking the request vector until a deadlock occured , then it will break this loop
        while (true)
        {
            bool requestDone = false, terminate = false;
            for (int i = 0; i < request.size(); i++)
            {
                // check if the process is still running , and it's request is less that available
                if (finished[i] == false && lessThan(request[i].second, available))
                {
                    // the first case is that the allocation file is sorted , for example if the request i in
                    // is at the row 2 from the request file , the row 2 in allocation file contains the allocations
                    // for the same process
                    if (request[i].first == alloc[i].first)
                    {
                        addResources(available, alloc[i].second);
                        safeSeq.push_back(request[i].first);
                        finished[i] = true;

                        // we need to rise a flag if a process finished, because we want to return from the
                        // beginning of the request vector
                        requestDone = true;
                    }
                    // the second case is that the allocation file is shuffled , so that we need to check the
                    // process in the request file , and search for the same process in the allocation file
                    // to get it's information
                    else
                    {
                        // The allocation vector is not sorted , for example , in the request file ,
                        // the first request is for P1  , but the first row of allocation file is P2 for example
                        int idx = i;
                        for (int k = 0; k < alloc.size(); k++)
                        {
                            if (alloc[k].first == request[i].first)
                            {
                                idx = k;
                                break;
                            }
                        }
                        addResources(available, alloc[idx].second);
                        safeSeq.push_back(request[i].first);
                        finished[i] = true;

                        // we need to rise a flag if a process finished, because we want to return from the
                        // beginning of the request vector
                        requestDone = true;
                    }
                }
                // if the request is done , we need to bread return to the beginning of the request vector
                if (requestDone)
                    break;

                // we will read the following if statement only in two cases , the first case is when
                // all requests are done . Then , the loop will reach the end of the request vector without
                // rising the flag "requestDone" , so that we can terminate the programe . The second case
                // is when we have a deadlock , as a result of that , we will reach the end of request
                // vector without rising the flag "requestDone"
                if (i == request.size() - 1)
                {
                    terminate = true;
                    break;
                }
            }
            // break the loop and end the algorithm
            if (terminate)
                break;
        }
    }
    else
        error = true;
}

int main()
{
    // define the vectors that will contain informations about processes
    vector<pair<string, vector<int>>> request;
    vector<pair<string, vector<int>>> allocation;
    vector<int> available;

    // read the files and fill the vectors with the required informations
    readFiles(request, allocation, available);

    // let the user decide if he want to preview the contents of the file or not
    // if yes, it will print the content of all files with a beautiful format
    char ans;
    while (true)
    {
        cout << "Do you want to preview the content of the files ? (y/n) : ";
        cin >> ans;
        if (ans == 'y')
        {
            cout << "Process\t Allocation\tRequest       Available" << endl;
            for (int i = 0; i < allocation.size(); i++)
            {
                cout << "  " << allocation[i].first << "\t ";
                for (int j = 0; j < allocation[i].second.size(); j++)
                {
                    cout << allocation[i].second[j] << " ";
                }
                for (int l = 0; l < 15-2*available.size(); l++) cout<<" " ;
                for (int j = 0; j < request[i].second.size(); j++)
                {
                    cout << request[i].second[j] << " ";
                }
                if (i == 0)
                {
                    int spaces = 14 - 2 * available.size();
                    for (int k = 0; k < spaces; k++)
                        cout << " ";
                    for (int j = 0; j < available.size(); j++)
                        cout << available[j] << " ";
                }
                cout << endl;
            }
            break;
        }
        else if (ans == 'n')
        {
            break;
        }
        else
            cout << "please enter 'y' if yes , and 'n' if no " << endl;
    }

    // this array will be passed to the Detection algorithm function and will be updated
    // with the status of all processes (True if the process finished and false if not)
    bool finished[allocation.size()] = {false};

    // this vector to store the safe sequence of the processes that will not cause deadlock
    vector<string> safeSeq;

    // call the Detection Algorithm function, and give it all required vectors to work
    // the main purpose from this call is to fill the vectors "finished" and "safeSeq"
    // depending on the result from this algorithm
    detectionAlgorithm(request, allocation, available, finished, safeSeq);

    // if there is no errors Print the final status of our system (deadlocked or not), depending on 
    //the previous produced vectors (finished and safeSeq) , and print the detailed status of each process
    if (!error)
        printResults(finished, safeSeq, request);

    return 0;
}
