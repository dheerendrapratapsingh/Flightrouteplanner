#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <limits.h> 
#define NUM_AIRPORTS 14 
#define MAX_AIRPORT_NAME_LENGTH 
50 #define MAX_QUEUE_SIZE 100 const 
char* airports[NUM_AIRPORTS] = { 
"DELHI","PUNE","LUCKNOW","HYDERABAD","MUMBAI","CHENNAI","BENGALURU","BHOP 
AL","JAIPUR","VIJAYAWADA","NOIDA","VIZAG","SRINAGAR","RANCHI", 
}; 
int graph[NUM_AIRPORTS][NUM_AIRPORTS] = { 
// DEL PUN LKO HYD MUM CHE BEN BHO JAI VJY NOI VIZ SRI RAN 
{ 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0 }, // DEL 
{ 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, // PUN 
{ 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1 }, // LKO 
{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0 }, // HYD 
{ 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 }, // MUM 
{ 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0 }, // CHE 
{ 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0 }, // BEN 
{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // BHO 
{ 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 }, // JAI 
{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // VJY 
{ 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 }, // NOI 
{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, // VZY 
{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, // SRI 
{ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } // RAN 
}; 
int findAirportIndex(const char* airport) { 
for (int i = 0; i < NUM_AIRPORTS; i++) { 
if (strcmp(airports[i], airport) == 0) { 
return i; 
} } 
return -1; 
} 
void toUpperCase(char* str) { 
for (int i = 0; str[i]; i++) { 
str[i] = toupper(str[i]); 
} 
} 
void bfs_shortest_path(int graph[NUM_AIRPORTS][NUM_AIRPORTS], int start, int end, int parent[]) { 
int visited[NUM_AIRPORTS] = {0}; 
int queue[MAX_QUEUE_SIZE]; int 
front = 0, rear = 0; 
visited[start] = 1; 
queue[rear++] = start; 
parent[start] = -1; 
while (front < rear) { int current = 
queue[front++]; if (current == end) { 
return; } for (int i = 0; i < 
NUM_AIRPORTS; i++) { 
if (graph[current][i] == 1 && !visited[i]) 
{ visited[i] = 1; queue[rear++] = i; 
parent[i] = current; 
} 
} 
} 
} 
void print_path(int parent[], int j) { 
if (parent[j] == -1) { 
printf("%s", airports[j]); 
return; } 
print_path(parent, parent[j]); 
printf(" -> %s", airports[j]); 
} 
int main() { printf("************\n"); 
printf("> 
Air India Route Planner 
>\n"); printf("***********\n\n"); 
printf("We serve the following airports: DELHI, PUNE, LUCKNOW, HYDERABAD, MUMBAI, 
CHENNAI, BENGALURU, BHOPAL, JAIPUR, VIJAYAWADA, NOIDA, VIZAG, SRINAGAR, and 
RANCHI.\n\n"); 
char airportFrom[MAX_AIRPORT_NAME_LENGTH]; 
char airportTo[MAX_AIRPORT_NAME_LENGTH]; 
int fromIndex = -1; 
int toIndex = -1; 
while (fromIndex == -1) { printf("> Boarding 
from "); scanf("%s", airportFrom); 
toUpperCase(airportFrom); fromIndex = 
findAirportIndex(airportFrom); if 
(fromIndex == -1) { 
printf(">>> Sorry, this airport is not recognised.\n"); 
} } 
while (toIndex == -1) { printf("> FLY 
TO? "); scanf("%s", airportTo); 
toUpperCase(airportTo); toIndex = 
findAirportIndex(airportTo); if 
(toIndex == -1) { 
printf(">>> Sorry, this airport is not recognised.\n"); 
} } printf("> > > Planning your flight path > > >\n"); 
int parent[NUM_AIRPORTS]; 
bfs_shortest_path(graph, fromIndex, toIndex, parent); 
if (parent[toIndex] != -1) { 
printf("Shortest path from %s to %s is:\n", airportFrom, 
airportTo); print_path(parent, toIndex); printf("\n"); 
} else { printf("No path found from %s to %s.\n", airportFrom, 
airportTo); 
} return 
0; 
} 