//RUNTIME: 15 - 41 MS
//TIME COMPLEXITY: O(n + E * k log(e * k), where e is the number of edges (value of parameter flights),
// n is the value of the parameter n, and k is the value of the parameter k
//SPACE COMPLEXITY: O(n + e * k), where e is the number of edges (value of parameter flights),
// n is the value of the parameter n, and k is the value of the parameter k
class Solution {
public:
    struct Flight{
        int dstNode;
        int steps;
        int price;

        Flight(int dst, int stp, int cost) : dstNode(dst), steps(stp), price(cost)
        {}

        bool operator >(const Flight& rhs) const
        {
            return price > rhs.price;
        }
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        std::vector<std::vector<std::pair<int, int>>> adjacencyList(n);
        for (int i = 0; i < flights.size(); i++)
        {
            //src.emplace_back(dst, price)
            adjacencyList[flights[i][0]].emplace_back(flights[i][1], flights[i][2]);
        }

        std::priority_queue<Flight, std::vector<Flight>, std::greater<Flight>> flightPQ;
        std::vector<int> stops(n, INT_MAX);


        for (int i = 0; i < adjacencyList[src].size(); i++)
        {
            Flight newFlight(adjacencyList[src][i].first, 0, adjacencyList[src][i].second);
            flightPQ.emplace(newFlight);
        }

        while (flightPQ.empty() == false)
        {
            int pqSize = flightPQ.size();

            for (int i = 0; i < pqSize; i++)
            {
            Flight newFlight = flightPQ.top();
            flightPQ.pop();

            if (newFlight.dstNode == dst)
            {
                return newFlight.price;
            }

            //If we've went over the amount of steps available to us OR
            //if we've reached this node before in a shorter amount of time
            if (newFlight.steps >= k || newFlight.steps > stops[newFlight.dstNode])
            {
                continue;
            }
            stops[newFlight.dstNode] = newFlight.steps;

            for (auto& dstAndPrice : adjacencyList[newFlight.dstNode])
            {
                flightPQ.emplace(dstAndPrice.first, newFlight.steps + 1, dstAndPrice.second + newFlight.price);
            }
            }
        }

        return -1;
    }
};