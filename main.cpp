#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <vector>
#include <list>

using namespace std;



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
        vector< list< pair<int, int> > > adjacencyList(V+1);




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


        }
        scheduleInput.close();

        cout << endl << endl;
        // another print test

/*
        // print adjacency list
        adjacencyList[1].push_back(make_pair(2, 300));
        adjacencyList[1].push_back(make_pair(4, 300));
        adjacencyList[2].push_back(make_pair(3, 550));
        adjacencyList[2].push_back(make_pair(4, 400));
        adjacencyList[3].push_back(make_pair(4, 300));
        adjacencyList[3].push_back(make_pair(1, 300));
        adjacencyList[4].push_back(make_pair(1, 550));
        adjacencyList[4].push_back(make_pair(3, 400));

 */       
        cout << "\nThe Adjacency List-\n";

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









        return 0;

}




