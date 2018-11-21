#include <iostream>
#include <fstream>
#include <cstddef>
#include <string>
#include <vector>
#include <list>

using namespace std;

struct stationNode {
	int id;
	string name;
	vector<stationNode*> neighbor;
	vector<int> depart;					// the index of the vector is the station
	vector<int> arrive; 				// the index of the vector is the station
};

int main(int argc, char** argv)
{
        std::ifstream input;
        std::ifstream scheduleInput;
        int cmd, argument;
        string stationName;
        vector<stationNode*> stations;

        if (argc < 3)
        {
                std::cout << "usage: ./a.out <stations.dat> <schedule.dat>\n";
                return 0;
        }

        input.open(argv[1]);

        while (true)
        {

                input >> argument;
                input >> stationName;
                if (input.eof() ) break;
				stations[argument] = new stationNode;
				stations[argument]->id = argument;
				stations[argument]->name = stationName;

        }

        // print test
        
        for (int i = 0; i < stations.size(); i++)
        {
                std::cout << "Station id: " << stations[i]->id << " Station Name: " 
                        << stations[i]->name << std::endl;
        }

        input.close();
        



//        int V = stationList.size();
 //       vector< list< pair<int, int> > > adjacencyList(V+1);




//        scheduleInput.open(argv[2]);
        int src, dst, leave, arrive, weight;
/*

        while (true)
        {
                input >> src;
                input >> dst;
                input >> leave;
                input >> arrive;
                if (input.eof() ) break;
                weight = arrive - leave; 
                adjacencyList[src].push_back(make_pair(dst, weight));


        }
        scheduleInput.close();

        cout << endl << endl;
        // another print test


        // print adjacency list
        adjacencyList[1].push_back(make_pair(2, 300));
        adjacencyList[1].push_back(make_pair(4, 300));
        adjacencyList[2].push_back(make_pair(3, 550));
        adjacencyList[2].push_back(make_pair(4, 400));
        adjacencyList[3].push_back(make_pair(4, 300));
        adjacencyList[3].push_back(make_pair(1, 300));
        adjacencyList[4].push_back(make_pair(1, 550));
        adjacencyList[4].push_back(make_pair(3, 400));

        
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

*/







        return 0;

}




