#include <iostream>
using namespace std;
int main() {
srand(time(0)); // seed for randomness
int N = 10; // small number of packets
double currentTime = 0.0;
double routerFreeTime = 0.0;
double totalDelay = 0.0;
cout << "Packet\tArrival\tService\tStart\tFinish\tDelay\n";
for (int i = 1; i <= N; i++) {
// random inter-arrival time (1 to 5 units)
double interArrival = 1 + rand() % 5;
currentTime += interArrival;
// random service time (1 to 4 units)
double serviceTime = 1 + rand() % 4;
// packet starts service when router is free
double startService = max(currentTime, routerFreeTime);
double finishService = startService + serviceTime;
// delay = finish - arrival
double delay = finishService - currentTime;
totalDelay += delay;
routerFreeTime = finishService;
cout << i << "\t"
<< currentTime << "\t"
<< serviceTime << "\t"
<< startService << "\t"
<< finishService << "\t"
<< delay << endl;
}
cout << "\nAverage Packet Delay = "
<< totalDelay / N << endl;
return 0;
}