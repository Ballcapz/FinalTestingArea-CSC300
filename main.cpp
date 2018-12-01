#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <vector>
#include <list>

using namespace std;

void printCompleteSchedule();

int main(int argc, char** argv)
{
        std::ifstream input;
        std::ifstream scheduleInput;
        int cmd, argument;
        string station;
        vector<int> stationList;
        vector<string> stationNames;

        if (argc < 3)
        {
                std::cout << "usage: ./a.out <stations.dat> <schedule.dat>\n";
                return 0;
        }

        input.open(argv[1]);

        while (true)
        {

                input >> argument;
                input >> station;
                if (input.eof() ) break;
                stationList.push_back(argument);
                stationNames.push_back(station);

        }

        // print test
        
        for (int i = 0; i < stationList.size(); i++)
        {
                std::cout << "Station id: " << stationList[i] << " Station Name: " 
                        << stationNames[i] << std::endl;
        }

        input.close();
        



        int V = stationList.size();
        // the og station is the source, p(0) is the destination station
        // p(1) is the weight of the distance between the stations
        vector< list< pair<int, int> > > adjacencyList(V+1);
        // p(1) is the time the train leaves from s1 going to s2 which is held in p(0)
        vector< list< pair<int, int> > > leaveTime(V+1);
        // p(1) is the time the train arrives at s2
        vector< list< pair<int, int> > > arriveTime(V+1);




        scheduleInput.open(argv[2]);
        int src, dst, leave, arrive, weight;


       while (true)
        {
                scheduleInput >> src;
                scheduleInput >> dst;
                scheduleInput >> leave;
                scheduleInput >> arrive;
                if (scheduleInput.eof() ) break;
                weight = arrive - leave; 
                adjacencyList[src].push_back(make_pair(dst, weight));
                leaveTime[src].push_back(make_pair(dst, leave));
                arriveTime[src].push_back(make_pair(dst, arrive));


        }
        scheduleInput.close();

        cout << endl << endl;
        
        cout << "\nThe Adjacency List of Stations(time it takes between)-\n";

        for (int i = 1; i < adjacencyList.size(); ++i)
        {
                cout << "adjacencyList[" << i << "]";

                list< pair<int, int> >::iterator itr = adjacencyList[i].begin();

                while(itr != adjacencyList[i].end())
                {
                        cout << "->" << (*itr).first << "(" << (*itr).second << ")";
                        ++itr;
                }
                cout << endl;
        }


        cout << "\nThe Adjacency List of Stations(time it leaves)-\n";

        for (int i = 1; i < leaveTime.size(); ++i)
        {
                cout << "leaveTime[" << i << "]";

                list< pair<int, int> >::iterator itr = leaveTime[i].begin();

                while(itr != leaveTime[i].end())
                {
                        cout << "->" << (*itr).first << "(" << (*itr).second << ")";
                        ++itr;
                }
                cout << endl;
        }

        cout << "\nThe Adjacency List of Stations(time it arrives)-\n";

        for (int i = 1; i < arriveTime.size(); ++i)
        {
                cout << "arriveTime[" << i << "]";

                list< pair<int, int> >::iterator itr = arriveTime[i].begin();

                while(itr != arriveTime[i].end())
                {
                        cout << "->" << (*itr).first << "(" << (*itr).second << ")";
                        ++itr;
                }
                cout << endl;
        }






        return 0;

}


void printCompleteSchedule()
{
     cout << "The complete schedule\n";   
        


}


















