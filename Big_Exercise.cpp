#include <bits/stdc++.h>
using namespace std;

struct Flight{
    string FlightNumber;
    int ticketPrice;
    int Seat;

    void show() const{
        cout<<"Flight: "<<FlightNumber<<setw(15)<<"ticketPrice: "<<ticketPrice<<setw(10)<<"Seat: "<<Seat<<endl;
    }
};

void PriceFinding(vector<Flight> Flights, int index)
{
    if(index > Flights.size())
        return;
    if(Flights[index].ticketPrice > 700000)
        Flights[index].show();
    PriceFinding(Flights, index + 1);
}

Flight findCheapestFlight(const vector<Flight>& flights, int left, int right) {
    if (left == right) return flights[left];  // Nếu chỉ có 1 chuyến bay, trả về chuyến bay đó

    int mid = (left + right) / 2;
    Flight leftMin = findCheapestFlight(flights, left, mid);
    Flight rightMin = findCheapestFlight(flights, mid + 1, right);

    return (leftMin.ticketPrice < rightMin.ticketPrice) ? leftMin : rightMin;  // Trả về chuyến bay có giá vé thấp hơn
}

void ListCombination(const vector<Flight>& flights, vector<Flight>& combination, int start, int k)
{
    if(combination.size() == k)
    {
        for(const auto& flight : combination)
        {
            flight.show();
        }
        cout<<"\n\t\t------------------"<<endl;
        return;
    }
    for(int i=start; i<flights.size(); i++)
    {
        combination.push_back(flights[i]);
        ListCombination(flights, combination, i + 1, k);
        combination.pop_back();
    }
}

int main()
{
    vector<Flight> flights = {
    {"VN101", 750000, 180},
    {"VN102", 500000, 150},
    {"VN103", 1200000, 200},
    {"VN104", 650000, 170},
    {"VN105", 850000, 190},
    {"VN106", 680000, 160},
    {"VN107", 1400000, 180},
    {"VN108", 730000, 140}
    };
    cout<<"\t\tDanh sach cac chuyen bay"<<endl;
    for(const auto& flight : flights)
    {
        flight.show();
    }
    cout<<"\n\t\tDanh sach cac chuyen bay co gia ve > 700000"<<endl;
    PriceFinding(flights, 0);

    cout<<"\n\t\tChuyen bay co gia ve thap nhat"<<endl;
    Flight cheapest_flight = findCheapestFlight(flights, 0, flights.size() - 1);
    cheapest_flight.show();

    cout<<"\n\t\tCac phuong an chon ra 4 chuyen bay"<<endl;
    vector<Flight> Combination;
    ListCombination(flights, Combination, 0, 4);
}
